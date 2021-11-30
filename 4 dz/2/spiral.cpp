#include "spiral.h"

void spiral(int **arrOfInt, int sizeOfArray)
{
    int centr = sizeOfArray / 2;
    int step = 1;
    int n = centr;
    int m = centr;
    std::cout << arrOfInt[n][m] << ", ";
    for (int i = 1; i < sizeOfArray; i++)
    {
        for (int a = 0 ; a < i; a++)
        {
            std::cout << arrOfInt[n][m += step] << ", ";
        }
        for (int a = 0 ; a < i; a++)
        {
            std::cout << arrOfInt[n += step][m] << ", ";
        }
        step = -step;
    }
    for (int i = 1; i < sizeOfArray; i++)
    {
        std::cout << arrOfInt[n][i] << ", ";
    }
}
