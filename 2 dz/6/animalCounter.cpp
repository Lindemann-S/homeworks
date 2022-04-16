#include "animalCounter.h"

int numberOfBulls(int *hiddenNumber, int *newNumber, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (hiddenNumber[i] == newNumber[i])
        {
            n++;
        }
    }
    return n;
}

int numberOfCows(int *hiddenNumber, int *newNumber, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j && i == size - 1)
            {
                break;
            }
            if (i == j)
            {
                j++;
            }
            if (hiddenNumber[i] == newNumber[j])
            {
                n++;
            }
        }
    }
    return n;
}
