/*Реализовать рекурсивный и итеративный подсчет чисел Фибоначчи.*/
#include <iostream>

using namespace std;

unsigned long long iterativeFibonacci(int num)
{
    unsigned long long n1 = 0;
    unsigned long long n2 = 1;
    unsigned long long sum = 0;
    if (num < 0)
    {
        cout << "negative value ";
        return 0;
    }
    if (num == 0)
    {
        return 0;
    }
    for (int i = 0; i < num - 1; i++)
    {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
    }
    return n2;
}

unsigned long long recursiveFibonacci(int num)
{
    if (num < 0)
    {
        cout << "negative value ";
        return 0;
    }
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
    {
        return 1;
    }
    return recursiveFibonacci(num - 1) + recursiveFibonacci(num - 2);
}

int main()
{
    int num = 0;
    cout << "enter the number of the Fibonacci number: ";
    cin >> num;
    unsigned long long result = iterativeFibonacci(num);
    cout << result;
    return 0;
}
