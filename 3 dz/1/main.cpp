/*Найдите максимальный элемент массива, встречающийся более одного раза (массив неупорядоченный).*/

#include <iostream>
#include "findMax.h"

using namespace std;

int main()
{
    int lenghtOfArray = 0;
    printf("Enter lenghtOfArray: ");
    scanf("%d", &lenghtOfArray);
    srand(time(NULL));
    int *array = new int [lenghtOfArray];
    for (int i = 0; i < lenghtOfArray; i++)
    {
        array[i] = rand() % 100;
    }
    printf("Array: ");
    for (int i = 0; i < lenghtOfArray; i++)
    {
        printf("%d", array[i]);
        printf(", ");
    }
    findMax(array, lenghtOfArray);
    return 0;
}
