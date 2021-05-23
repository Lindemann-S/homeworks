#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

bool check(char *str)
{
    int count = 0;
    int lenght = strlen(str);
    for (int i = 0; i < lenght; i++)
    {
        if (str[i] == '(')
        {
            count++;
        }
        if (str[i] == ')')
        {
            count--;
        }
        if (count == -1)
        {
            return false;
        }
    }
    return count == 0;
}

int prior(char ch)
{
    int check = 0;
    if (ch == '/' || ch == '*')
    {
         check = 2;
    }
    if (ch == '+' || ch == '-')
    {
        check = 1;
    }
    return check;
}

void postfix(char *istr, queue <char> *str)
{
    stack <char> steck;
    int i = 0;
    while (istr[i] != '\0')
    {
        if (istr[i] >= 48 && istr[i] <= 57)
        {
            str->push(istr[i]);
        }
        if (istr[i] == '+' || istr[i] == '-' || istr[i] == '*' ||istr[i] == '/')
        {
            if (steck.empty())
            {
                steck.push(istr[i]);
            }
            else if (steck.top() == '(')
            {
                steck.push(istr[i]);
            }
            else if (prior(istr[i]) > prior(steck.top()))
            {
                steck.push(istr[i]);
            }
            else
            {
                while (!steck.empty() && steck.top() != '(' && prior(steck.top()) >= prior(istr[i]))
                {
                    str->push(steck.top());
                    steck.pop();
                }
                steck.push(istr[i]);
            }
        }
        if (istr[i] == '(')
        {
            steck.push(istr[i]);
        }
        if (istr[i] == ')')
        {
            while (steck.top() != '(')
            {
                str->push(steck.top());
                steck.pop();
            }
            steck.pop();
        }
        i++;
    }
    while (!steck.empty())
    {
        str->push(steck.top());
        steck.pop();
    }
}

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
        operands[n - 2] = operands[n - 2] / operands[n - 1];
    }
    operands[n - 1] = 0;
}

void solution(queue <char> str)
{
    double operands[50] = {0};
    int n = 0;
    while (!str.empty())
    {
        if (str.front() >= 48 && str.front() <= 57)
        {
            operands[n] = str.front() - '0';
            str.pop();
            n++;
        }
        if (str.front() == '+' || str.front() == '-' || str.front() == '*' || str.front() == '/')
        {
            if (str.front() == '/' && operands[n - 1] == 0)
            {
                cout << "error: division by 0, you gay !" << endl;
                return;
            }
            calculate(operands, str.front(), n);
            str.pop();
            n--;
        }
    }
    cout << "your answer: " << operands[0] << endl;
}

void start(char *istr)
{
    if (!check (istr))
    {
        cout << "the nesting rule is not met, you gay !" << endl;
        return;
    }
    queue <char> str;
    postfix(istr, &str);
    solution(str);
}

int main()
{
    char istr[50] = "";
    cout << "enter your expression =)" << endl;
    cin.getline(istr, 50);
    start(istr);
    return 0;
}
