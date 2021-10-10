/*Напечатать в порядке возрастания все простые несократимые дроби, заключенные между 0 и 1, знаменатели которых не превышают n.*/

#include <iostream>
#include "functions.h"

Fraction fractions[1000];

void val(int denominator)
{
    double *fractionValues = new double[1000];
    int index = 0;
    for (double den = 2; den <= denominator; den++)
    {
        for (double num = 1; num < den; num++)
        {
            int c = gcd(num, den);
            if (num < den && c == 1)
            {
                fractions[index].numerator = num;
                fractions[index].denominator = den;
                fractions[index].arrValue = num / den;
                fractionValues[index] = fractions[index].arrValue;
                index++;
            }
        }
    }
    int firstIndex = 0;
    index -= 1;
    quicksort(fractionValues, firstIndex, index);
    for (int i = 0; i <= index; i++)
    {
        for (int j = 0; j <= index; j++)
        {
            if (fractions[j].arrValue == fractionValues[i])
            {
                cout << fractions[j].numerator << "/" << fractions[j].denominator << "; ";
            }
        }
    }
    delete []fractionValues;
}
int main()
{
    int denominator = 0;
    cout << "set the maximum denominator: ";
    cin >> denominator;
    val(denominator);
    return 0;
}
