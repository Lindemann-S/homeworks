#include <iostream>
#include "postfix.h"
#include "nestingRuleCheck.h"


int main()
{
    char *inputString = new char[100];
    printf("Enter your expression =)\n");
    std::cin.getline(inputString, 100);
    if (!nestingRuleCheck(inputString))
    {
        printf("The nesting rule is not met =(\n");
        return 0;
    }
    char *postfixExpresion = postfix(inputString);
    int k = 0;
    while (postfixExpresion[k] != '\0')
    {
        std::cout << postfixExpresion[k];
        k++;
    }
    std::cout << std::endl;
    int answer = solution(postfixExpresion);
    printf("Your answer is: ");
    printf("%d\n", answer);
    delete []inputString;
    return 0;
}
