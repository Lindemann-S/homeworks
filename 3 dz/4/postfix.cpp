#include "postfix.h"


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

char *postfix(char *inputString)
{
    int i = 0;
    int k = 0;
    bool lastIsDigit = false;
    MyCharStackNode *stack = nullptr;
    char *postfixString = new char[100];
    while (inputString[i] != '\0')
    {
        if ((inputString[i] < 48 || inputString[i] > 57) && lastIsDigit == true)
        {
            postfixString[k] = ' ';
            k++;
            lastIsDigit = false;
        }
        if (inputString[i] == ' ')
        {
            while (inputString[i] == ' ')
            {
                i++;
            }
        }
        if (inputString[i] >= 48 && inputString[i] <= 57)
        {
            postfixString[k] = inputString[i];
            k++;
            lastIsDigit = true;
        }
        if (inputString[i] == '+' || inputString[i] == '-' || inputString[i] == '*' || inputString[i] == '/')
        {
            if (is_empty(stack))
            {
                push(&stack, inputString[i]);
            }
            else if (top(stack) == '(')
            {
                push(&stack, inputString[i]);
            }
            else if (prior(inputString[i]) > prior(top(stack)))
            {
                push(&stack, inputString[i]);
            }
            else
            {
                while (!is_empty(stack) && top(stack) != '(' && prior(top(stack)) >= prior(inputString[i]))
                {
                    postfixString[k] = top(stack);
                    k++;
                    postfixString[k] = ' ';
                    k++;
                    pop(&stack);
                }
                push(&stack, inputString[i]);
            }
        }
        if (inputString[i] == '(')
        {
            push(&stack, inputString[i]);
        }
        if (inputString[i] == ')')
        {
            while (top(stack) != '(')
            {
                postfixString[k] = top(stack);
                k++;
                postfixString[k] = ' ';
                k++;
                pop(&stack);
            }
            pop(&stack);
        }
        i++;
    }
    if (lastIsDigit)
    {
        postfixString[k] = ' ';
        k++;
    }
    while (!is_empty(stack))
    {
        postfixString[k] = top(stack);
        k++;
        postfixString[k] = ' ';
        k++;
        pop(&stack);
    }
    return postfixString;
    delete []postfixString;
}
