/*Напечатать в порядке возрастания все простые несократимые дроби, заключенные между 0 и 1, знаменатели которых не превышают n.*/

#include <iostream>
#include <iomanip>

using namespace std;

struct Fraction
{
    double numerator;
    double denominator;
    double arrvalue;
};
Fraction *Fr = new Fraction[1000];

int gcd(int a, int b)
{
   int c = 0;
   while (b)
   {
      c = a % b;
      a = b;
      b = c;
   }
   return abs(a);
}

void quicksort(double *row, int first, int last) //функция сортировки
{
    if (first >= last)
    {
        return;
    }
    double mid = 0;
    int f = first;
    int l = last;
    mid = row[(f + l) / 2];
    while (f < l)
    {
        while (row[f] < mid)
        {
            f++;
        }
        while (row[l] > mid)
        {
            l--;
        }
        if (f <= l) //перестановка элементов
        {
            swap(row[f], row[l]);
            f++;
            l--;
        }
    }
    quicksort(row, first, l);
    quicksort(row, f, last);
}

void val(int denominator)
{
    double *value = new double[1000];
    int index = -1;
    for (double den = 2; den <= denominator; den++)
    {
        for (double num = 1; num < denominator; num++)
        {
            int c = gcd(num, den);
            if (num < den && c == 1)
            {
                index++;
                Fr[index].numerator = num;
                Fr[index].denominator = den;
                Fr[index].arrvalue = num / den;
                value[index] = Fr[index].arrvalue;
            }
        }
    }
    int first_index = 0;
    quicksort(value, first_index, index);
    for (int i = 0; i < index; i++)
    {
        for (int j = 0; j < index; j++)
        {
            if (Fr[j].arrvalue == value[i])
            {
                cout << Fr[j].numerator << "/" << Fr[j].denominator << "; ";
            }
        }
    }
    delete []value;
}
int main()
{
    int denominator = 0;
    cout << "set the maximum denominator: ";
    cin >> denominator;
    val(denominator);
    return 0;
}
