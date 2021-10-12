/*Напечатать в порядке возрастания все простые несократимые дроби, заключенные между 0 и 1, знаменатели которых не превышают n.*/

#include <iostream>

#include "fraction.h"
#include "quicksort.h"


Fraction fractions[1000];

void val(int denominator)
{
    int index = 0;
    for (int den = 2; den <= denominator; den++)
    {
        for (int num = 1; num < den; num++)
        {
            int c = gcd(num, den);
            if (num < den && c == 1)
            {
                fractions[index].numerator = num;
                fractions[index].denominator = den;
                fractions[index].value = (double) num / den;
                index++;
            }
        }
    }
    int firstIndex = 0;
    index -= 1;
    fractionQuickSort(fractions, firstIndex, index);
    for (int i = 0; i <= index; i++)
    {
        std::cout << fractions[i].numerator << "/" << fractions[i].denominator << "; ";
    }
}
int main()
{
    int denominator = 0;
    std::cout << "set the maximum denominator: ";
    std::cin >> denominator;
    val(denominator);
    return 0;
}
