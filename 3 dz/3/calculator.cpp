#include "calculator.h"


int stringLenght(char *string)
{
    int lenght = 0;
    while (string[lenght] != '\0')
    {
        lenght++;
    }
    return lenght;
}

void calculate(MyStackNode **operands, char sign, bool *errorFlag)
{
    int secondValue = pop(&*operands);
    int firstValue = pop(&*operands);
    int result = 0;
    if (sign == '+')
    {
        result = firstValue + secondValue;
    }
    if (sign == '-')
    {
        result = firstValue - secondValue;
    }
    if (sign == '*')
    {
        result = firstValue * secondValue;
    }
    if (sign == '/')
    {
        if (secondValue != 0)
        {
            result = firstValue / secondValue;
        }
        else
        {
            printf("%s\n", "Error: division by 0");
            *errorFlag = true;
            return;
        }
    }
    push(&*operands, result);
}

int solution(char *inputExpression)
{
    MyStackNode *operands = nullptr;
    bool lastIsDigit = false;
    int value = 0;
    int secondValue = 0;
    int sizeOfExpression = stringLenght(inputExpression);
    bool errorFlAG = false;
    for (int i = 0; i < sizeOfExpression; i++)
    {
        if (inputExpression[i] == ' ')
        {
            lastIsDigit = false;
        }
        if (inputExpression[i] >= 48 && inputExpression[i] <= 57 && lastIsDigit == true)
        {
            value = inputExpression[i] - '0';
            secondValue = pop(&operands);
            value = secondValue * 10 + value;
            push(&operands, value);
        }
        if (inputExpression[i] >= 48 && inputExpression[i] <= 57 && lastIsDigit == false)
        {
            value = inputExpression[i] - '0';
            push(&operands, value);
            lastIsDigit = true;
        }
        if (inputExpression[i] == '+' || inputExpression[i] == '-' || inputExpression[i] == '*' || inputExpression[i] == '/')
        {
            calculate(&operands, inputExpression[i], &errorFlAG);
            lastIsDigit = false;
            if (errorFlAG)
            {
                return 0;
            }
        }
    }
    return pop(&operands);
}
