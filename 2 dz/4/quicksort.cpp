#include "functions.h"

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