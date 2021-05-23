/*Реализовать алгоритм пирамидальной сортировки.*/
#include <iostream>

using namespace std;

void max_heap(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heap(arr, n, largest);
    }
}

void heapsort(int *row, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heap(row, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(row[0], row[i]);
        max_heap(row, i, 0);
    }
}

int main()
{
    int row_of_int[] = {-3, 17, 5, 50, 2, -1, 5, 3, 50};
    int size_of_the_array = sizeof(row_of_int) / sizeof(row_of_int[0]);
    cout << "Original array: ";
    for (int i = 0; i < size_of_the_array; i++)
    {
        cout << row_of_int[i] << " ";
    }
    heapsort(row_of_int, size_of_the_array);
    cout << endl << "Resulting array: ";
    for (int i = 0; i < size_of_the_array; i++)
    {
        cout << row_of_int[i] << " ";
    }
}
