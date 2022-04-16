#include "heapSort.h"
#include <iostream>

void heapMaker(int *arr, int n, int i)
{
    while (2 * i + 1 < n)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (right < n && arr[right] >= arr[left])
        {
            left = right;
        }
        if (arr[i] < arr[left])
        {
            std::swap(arr[i], arr[left]);
            i = left;
        }
        else
        {
            break;
        }
    }
}

void heapSort(int *row, int lenght)
{
    for (int i = lenght / 2 - 1; i >= 0; i--)
    {
        heapMaker(row, lenght, i);
    }
    while (lenght > 0)
    {
        std::swap(row[0], row[lenght - 1]);
        lenght--;
        heapMaker(row, lenght, 0);
    }
}
