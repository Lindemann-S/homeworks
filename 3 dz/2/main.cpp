#include <iostream>
#include "postfix.h"

int main()
{
    char *inputString = new char[100];
    std::cout << "Enter your line =)" << std::endl;
    std::cin.getline(inputString, 100);
    char *postfixExpresion = postfix(inputString);
    int i = 0;
    while (postfixExpresion[i] != '\0')
    {
        std::cout << postfixExpresion[i];
        i++;
    }
    std::cout << std::endl;
    delete []inputString;
    return 0;
}
