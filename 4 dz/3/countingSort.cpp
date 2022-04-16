#include "countingSort.h"


void countingSort(int *array, int size)
{
    int intCounter[10] = {0};
    for (int i = 0; i < size; i++)
    {
        int a = array[i];
        intCounter[a]++;
    }
    int index = 0;
    if (intCounter[0] > 0)
    {
        int i = 1;
        while (intCounter[i] == 0)
        {
            i++;
        }
        array[index] = i;
        index++;
        intCounter[i]--;
    }
    for (int i = 0; i < 10; i++)
    {
        int count = intCounter[i];
        for (int j = 0; j < count; j++)
        {
            array[index] = i;
            index++;
        }
    }
}
