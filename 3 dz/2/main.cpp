/*Написать программу преобразования инфиксной формы выражения в постфиксную.
 * Известно, что каждый операнд занимает один символ.
 * В выражении могут быть знаки +, -, *, /, скобки и цифры.
 * Пример: (1 + 1) * 2 должно преобразовываться в 1 1 + 2 *.
 * Алгоритм перевода предлагается найти самостоятельно (алгоритм "сортировочной станции" Э. Дейкстры).*/
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

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

void prefix(char *istr, queue <char> *str)
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

int main()
{
    queue <char> str;
    char inp_str[30] = "";
    cout << "enter your line =)" << endl;
    cin.getline(inp_str, 50);
    prefix(inp_str, &str);
    while (!str.empty())
    {
        cout << str.front();
        str.pop();
    }
    return 0;
}
