#include <iomanip>

#include "quicksort.h"


void quickSort(double *row, int first, int last) //функция сортировки
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
            std::swap(row[f], row[l]);
            f++;
            l--;
        }
    }
    quickSort(row, first, l);
    quickSort(row, f, last);
}

void fractionQuickSort(Fraction *row, int first, int last) //функция сортировки
{
    if (first >= last)
    {
        return;
    }
    int f = first;
    int l = last;
    double mid = row[(f + l) / 2].value;
    while (f < l)
    {
        while (row[f].value < mid)
        {
            f++;
        }
        while (row[l].value > mid)
        {
            l--;
        }
        if (f <= l) //перестановка элементов
        {
            std::swap(row[f], row[l]);
            f++;
            l--;
        }
    }
    fractionQuickSort(row, first, l);
    fractionQuickSort(row, f, last);
}
