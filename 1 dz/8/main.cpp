/*Реализовать подсчет факториала (рекурсивно и итеративно).*/

#include <iostream>

using namespace std;

unsigned long long recfuckt(int num)
{
    if (num < 2)
    {
        return 1;
    }
    return num * recfuckt(num - 1);
}

unsigned long long fuckt(int n)
{
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    int num = 0;
    cout << "enter your number: ";
    cin >> num;
    if (num < 0)
    {
        cout << "expected non negative value, got";
        return 0;
    }
    if (num < 2)
    {
        cout << 1;
        return 0;
    }
    cout << recfuckt(num) << ", " << fuckt(num) << endl;;
    return 0;
}
