/*Реализовать программу, вычисляющую значение выражения в постфиксной записи с помощью стека.*/
#include "calculator.h"


int main()
{
    char inputExpression[50] = {'\0'};
    printf("%s\n", "enter your line =)");
    std::cin.getline(inputExpression, 50);
    int answer = solution(inputExpression);
    printf("%d\n", answer);
    return 0;
}
