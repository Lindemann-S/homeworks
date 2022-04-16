/*Даны две строки. Определить, можно ли, переставляя символы в первой строке, получить вторую строку.
 *Хочется решение быстрее, чем за O(n^2).*/

#include "stringComparison.h"


int main()
{
    char firstString[50] = {'\0'};
    char secondString[50] = {'\0'};
    printf("%s\n", "enter first line");
    std::cin.getline(firstString, 50);
    printf("%s\n", "enter second line");
    std::cin.getline(secondString, 50);
    checkString (firstString, secondString);
    return 0;
}
