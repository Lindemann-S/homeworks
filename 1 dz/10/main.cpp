/*Реализовать программу, проверяющую, является ли строка палиндромом.*/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool check2(char *str)
{
    int l = 0;
    int r = strlen(str) - 1;
    while(l < r)
    {
        while(!isalpha(str[l]))
        {
            l++;
        }
        while(!isalpha(str[r]))
        {
            r--;
        }
        if (l < r && tolower(str[l]) != tolower(str[r]))
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

bool palindrom_check(char *str) // проверка палиндромности
{
    int j = strlen(str) - 1;
    int i = 0;
    while (i < j)
    {
        if (!isalpha(str[i]))
        {
            i++;
            continue;
        }
        if (!isalpha(str[j]))
        {
            j--;
            continue;
        }
        if (tolower(str[i]) == tolower(str[j]))
        {
            i++;
            j--;
        }
        else
        {
            break;
        }
    }
    return i >= j;
}

int main()
{
    char *str = new char[100];
    cout << "enter your line =)" << endl;
    cin.getline(str, 100);
    bool answer = palindrom_check(str);
    if (answer)
    {
        cout << "the string is a palindrome" << endl;
    }
    else
    {
        cout << "the string is not a palindrome" << endl;
    }
    delete [] str;
    return 0;
}
