/*Написать программу, печатающую все простые числа, не превосходящие заданного числа*/

#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    int num = 10;
    cout << "enter your number: ";
    cin >> num;
    for (i = 1; i <= num; i++)
    {
        int count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count == 2)
        {
            cout << i << ',' << ' ';
        }
    }
    return 0;
}
