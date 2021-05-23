/*Найдите максимальный элемент массива, встречающийся более одного раза (массив неупорядоченный).*/

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
void find_max(int *arr, int size)
{
    heapsort(arr, size);
    for (int i = size - 1; i > 0; i--)
    {
        if (arr[i] == arr[i - 1])
        {
            cout << arr[i];
            return;
        }
    }
    cout << "elements not found";
}

int main()
{
    int arr_of_el[] = {3, 8, -4, -10 , 10, 11, 3};
    int size = sizeof(arr_of_el) / sizeof(arr_of_el[0]);
    find_max(arr_of_el, size);
    return 0;
}
