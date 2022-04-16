#include "numberGenerator.h"

void numberGenerator(int *hiddenNumber, int size)
{
    int i = 0;
    while (true)
    {
        srand(time(NULL));
        if (i == size)
        {
            break;
        }
        for (i = 0; i < size; i++)
        {
            if (i == 0)
            {
                hiddenNumber[i] = 1 + rand() % 9;
                continue;
            }
            hiddenNumber[i] = rand() % 9;
            for (int j = i - 1; j >= 0; j--)
            {
                if (hiddenNumber[i] == hiddenNumber[j])
                {
                    i = 0;
                    break;
                }

            }
        }
    }
}