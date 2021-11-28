#include "heapSort.h"
#include <iostream>

void heapMaker(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest  = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapMaker(arr, n, largest);
    } 
}

void heapSort(int *row, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapMaker(row, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(row[0], row[i]);
        heapMaker(row, i, 0);
    }
}
