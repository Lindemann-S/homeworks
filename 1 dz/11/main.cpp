/*Реализовать быструю сортировку (в рекурсивном варианте).*/

#include <iostream>

using namespace std;

void quicksort(int *mas, int first, int last) //функция сортировки
{
    int mid = 0;
    int f = first;
    int l = last;
    mid = mas[(f + l) / 2]; //вычисление опорного элемента
    do
    {
        while (mas[f] < mid)
        {
            f++;
        }
        while (mas[l] > mid)
        {
            l--;
        }
        if (f <= l) //перестановка элементов
        {
            swap(mas[f], mas[l]);
            f++;
            l--;
        }
    }
    while (f < l);
    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);
}

int main() //главная функция
{
    const int size_of_the_array = 10;
    int *A = new int[size_of_the_array];
    cout << "Original array: ";
    for (int i = 0; i < size_of_the_array; i++)
    {
        A[i] = rand() % 10;
        cout << A[i] << " ";
    }
    int first = 0;
    int last = size_of_the_array - 1;
    quicksort(A, first, last);
    cout << endl << "Resulting array: ";
    for (int i = 0; i < size_of_the_array; i++)
    {
        cout << A[i] << " ";
    }
}
