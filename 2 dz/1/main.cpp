/*Реализовать рекурсивный и итеративный подсчет чисел Фибоначчи.*/
#include <iostream>

using namespace std;

unsigned long long itfib(int num)
{
    unsigned long long n1 = 0;
    unsigned long long n2 = 1;
    unsigned long long sum = 0;
    if (num == 0)
    {
        n2 = 0;
        return n2;
    }
    for (int i = 0; i < num - 1; i++)
    {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
    }
    return n2;
}

unsigned long long recfib(int num)
{
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
    {
        return 1;
    }
    return recfib(num - 1) + recfib(num - 2);
}

int main()
{
    int num = 0;
    cout << "enter the number of the Fibonacci number: ";
    cin >> num;
    unsigned long long result1 = itfib(num);
//    unsigned long long result2 = recfib(num);
//    cout << result1 << ", " << result2 << endl;
    cout << result1;
    return 0;
}
