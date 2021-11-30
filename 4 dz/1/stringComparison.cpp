#include "stringComparison.h"


int stringLenght(char *string)
{
    int count = 0;
    while (string[count] != '\0')
    {
        count++;
    }
    return count;
}

void countingSort(char *arrayOfChar, int size)
{
    int charCounter[256] = {0};
    for (int i = 0; i < size; i++)
    {
        int a = arrayOfChar[i];
        charCounter[a]++;
    }
    int index = 0;
    for (int i = 0; i < 256; i++)
    {
        int count = charCounter[i];
        for (int j = 0; j < count; j++)
        {
            arrayOfChar[index] = i;
            index++;
        }
    }
}

void checkString (char* firstString, char* secondString)
{
    bool check = true;
    if (stringLenght(firstString) != stringLenght(secondString))
    {
        printf("%s\n", "strings are of different length");
        check = false;
    }
    else
    {
        int n = stringLenght(firstString);
        countingSort(firstString, n);
        countingSort(secondString, n);
        for (int i = 0; i < n; i++)
        {
            if (firstString[i] != secondString[i])
            {
                check = false;
            }
        }
    }
    if (check)
    {
        printf("%s\n", "possible");
    }
    else
    {
        printf("%s\n", "you can't get the string");
    }
}
