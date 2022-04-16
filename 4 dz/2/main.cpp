/*Дан массив размерностью N x N, N — нечетное число. Вывести элементы массива при обходе его по спирали, начиная с центра*/

#include "spiral.h"


int main()
{
    int sizeOfArray= 0;
    printf("%s", "enter size of array: ");
    scanf("%d", &sizeOfArray);
    int** arrOfInt = new int* [sizeOfArray];
    for (int i = 0; i < sizeOfArray; i++)
    {
        arrOfInt[i] = new int [sizeOfArray];
    }
    int count = 1;
    for (int i = 0; i < sizeOfArray; i++ )
    {
        for (int j = 0; j < sizeOfArray; j++)
        {
            arrOfInt[i][j] = count;
            count++;
        }
    }
    for (int i = 0; i < sizeOfArray; i++ )
    {
        for (int j = 0; j < sizeOfArray; j++)
        {
            std::cout << std::setw(5) << arrOfInt[i][j];
        }
        std::cout << std::endl;
    }
    spiral(arrOfInt, sizeOfArray);
    for (int i = 0; i < 5; i++)
    {
        delete []arrOfInt[i];
    }
    delete []arrOfInt;
    return 0;
}
