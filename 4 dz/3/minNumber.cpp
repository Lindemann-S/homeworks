#include "minNumber.h"

int lengthOfNumber(long long int n)
{
    int length = 0;
    while (n != 0)
    {
        length++;
        n /= 10;
    }
    return length;
}

int answer(int *number, int length)
{
    int i = 0;
    long long int ans = 0;
    int a = pow(10, length - 1);
    while (i < length)
    {
        if (number[i] != 0)
        {
            ans += number[i] * a;
        }
        i++;
        a /= 10;
    }
    return ans;
}

void minNumber(long long int num)
{
    int length = lengthOfNumber(num);
    int *number = new int [length];
    int i = length - 1;
    while (num)
    {
        int c = num % 10;
        number[i] = c;
        i--;
        num /=10;
    }
    countingSort(number, length);
    long long int ans = answer(number, length);
    printf("%lld\n", ans);
    delete []number;
}
