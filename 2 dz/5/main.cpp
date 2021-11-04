/*Реализовать алгоритм пирамидальной сортировки.*/
#include <iostream>

#include "heapSort.h"


int main()
{
    int arrayLength = 0;
    std::cout << "Enter length of array: ";
    std::cin >> arrayLength;
    int *array = new int[arrayLength];
    srand (time(NULL));
    for (int i = 0; i < arrayLength; i++)
    {
        array[i] = rand() % 100;
    }
    std::cout << "Original array: ";
    for (int i = 0; i < arrayLength; i++)
    {
        std::cout << array[i] << ", ";
    }
    heapSort(array, arrayLength);
    std::cout << "\n" << "Resulting array: ";
    for (int i = 0; i < arrayLength; i++)
    {
        std::cout << array[i] << ", ";
    }
    delete []array;
}
