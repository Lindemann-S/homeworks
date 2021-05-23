/*Реализовать программу, вычисляющую значение выражения в постфиксной записи с помощью стека.*/
#include <iostream>
#include <cstring>

using namespace std;

void calculate(double *operands, char sign, int n)
{
    if (sign == '+')
    {
        operands[n - 2] = operands[n - 2] + operands[n - 1];
    }
    if (sign == '-')
    {
        operands[n - 2] = operands[n - 2] - operands[n - 1];
    }
    if (sign == '*')
    {
        operands[n - 2] = operands[n - 2] * operands[n - 1];
    }
    if (sign == '/')
    {
        if (operands[n - 1] != 0)
        {
            operands[n - 2] = operands[n - 2] / operands[n - 1];
        }
    }
    operands[n - 1] = 0;
}

int solution(char *QUEUE)
{
    double operands[50] = {0};
    int n = 0;
    int size = strlen(QUEUE);
    for (int i = 0; i < size; i++)
    {
        if (QUEUE[i] >= 48 && QUEUE[i] <= 57)
        {
            operands[n] = QUEUE[i] - '0';
            n++;
        }
        if (QUEUE[i] == '+' || QUEUE[i] == '-' || QUEUE[i] == '*' ||QUEUE[i] == '/')
        {
            calculate(operands, QUEUE[i], n);
            n--;
        }
    }
    return operands[0];
}

int main()
{
    char QUEUE[50] = "";
    cout << "enter your line =)" << endl;
    cin.getline(QUEUE, 50);
    int ans = solution(QUEUE);
    cout << ans;
    return 0;
}
