#include "adtString.h"

struct String
{
    char *string;
    int length;
};

String *createString()
{
    String *str = new String;
    str->string = nullptr;
    str->length = 0;
    return str;
}

String *createString(char *string)
{
    String *str = createString();
    concatenation(str, string);
    return str;
}

int strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
        i++;
    }
    return i;
}

int stringLength(String *str)
{
    return str->length;
}

void deleteString(String *str)
{
    if (!isEmpty(str))
    {
        delete []str->string;
    }
    delete []str;
}

void concatenation(String *&str1, String *str2)
{
    concatenation(str1, str2->string);
}

void concatenation(String *&str, char *string)
{
    int length = strlen(string);
    length++;
    if (str->string == nullptr)
    {
        char *newString = new char[length];
        for (int i = 0; i < length; i++)
        {
            newString[i] = string[i];
        }
        newString[length] = '\0';
        str->string = newString;
        str->length = length - 1;
    }
    else
    {
        char *newString = new char[str->length + length];
        int i = 0;
        int j = 0;
        while (i < str->length)
        {
            newString[i] = str->string[i];
            i++;
        }
        while (i < str->length + length)
        {
            newString[i] = string[j];
            i++;
            j++;
        }
        newString[i] = '\0';
        char *deletePointer = str->string;
        str->string = newString;
        str->length = str->length + length - 1;
        delete []deletePointer;
    }
}

char *stringToChar(String *str)
{
    char *result = new char[str->length + 1];
    for (int i = 0; i <= str->length + 1; i++)
    {
        result[i] = str->string[i];
    }
    return result;
}

bool comparsion(String *str1, String *str2)
{
    if (str1->length != str2->length)
    {
        return false;
    }
    for (int i = 0; i < str1->length; i++)
    {
        if (str1->string[i] != str2->string[i])
        {
            return false;
        }
    }
    return true;
}

char *substringSelection(String *str, int begin, int end)
{
    if (end > str->length || begin > end || begin < 0)
    {
        std::cout << "entered incorrect data" << std::endl;
        return nullptr;
    }
    char *locString = new char[end - begin + 2];
    int j = 0;
    for (int i = begin; i <= end; i++)
    {
        locString[j] = str->string[i];
        j++;
    }
    locString[j] = '\0';
    return locString;
}

bool isEmpty(String *str)
{
    return str->string == nullptr;
}

String *clone(String *str)
{
    String *cloneStr = createString(str->string);
    return cloneStr;
}

void printString(String *str)
{
    printString(str->string);
}

void printString(char *str)
{
    if (str == nullptr)
    {
        std::cout << "string is empty" << std::endl;
        return;
    }
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
        std::cout << str[i];
        i++;
    }
    std::cout << std::endl;
}

bool isAlpha(char ch)
{
    int a = (int) ch;
    return (65 <= a && a <= 90);
}

char toLower(char ch)
{
    ch = ch + 32;
    return ch;
}

bool isLetter(char ch)
{
    int a = (int) ch;
    if (48 <= a && a <= 57)
    {
        return true;
    }
    if ((65 <= a && a <= 90) || (97 <= a && a <= 122) || (192 <= a && a <= 255))
    {
        return true;
    }
    return false;
}

char *wordRepair(char *buffer, int i, int maxIndex)
{
    char *newWord = new char[maxIndex];
    int j = 0;
    while (i < maxIndex)
    {
        if (isLetter(buffer[i]))
        {
            newWord[j] = buffer[i];
            j++;
        }
        i++;
    }
    newWord[j] = '\0';
    buffer = newWord;
    return buffer;
}
