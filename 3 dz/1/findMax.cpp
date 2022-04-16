#include "findMax.h"

void findMax(int *array, int size)
{
    heapSort(array, size);
    for (int i = size - 1; i > 0; i--)
    {
        if (array[i] == array[i - 1])
        {
            printf("\nResult: %d", array[i]);
            return;
        }
    }
    printf("\nelements not found \n");
}
