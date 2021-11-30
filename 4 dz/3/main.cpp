/*Написать программу, которая переставляет цифры натурального числа таким образом,
 * чтобы образовалось наименьшее число, записанное этими же цифрами.*/

#include "minNumber.h"


int main()
{
    long long int num = 0;
    printf("%s", "enter your natural number: ");
    scanf("%lld", &num);
    minNumber(num);
    return 0;
}
