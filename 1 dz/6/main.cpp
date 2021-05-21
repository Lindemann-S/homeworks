/*Заданы две строки: s и s1. Найти количество вхождений s1 в s как подстроки.*/

#include <iostream>
#include <cstring>

using namespace std;

int findsub(char *s, char *s1)
{
    int count = 0;
    int i = 0;
    int j = 0;
    while (s[i] != '\0')
    {
        if (s[i] != s1[j])
        {
           i++;
           j = 0;
           continue;
        }
        while (s1[j] != '\0' && s[i + j] != '\0' && s[i + j] == s1[j])
            j++;
        if (s1[j] == '\0')
        {
            count++;
        }
        i += j;
        j = 0;
    }
    return count;
}

int main()
{
    char *str = new char[100];
    cout << "enter your first line =)" << endl;
    cin.getline(str, 100);
    char *substr = new char[100];
    cout << "enter your second line =)" << endl;
    cin.getline(substr, 100);
    int c = findsub(str, substr);
    cout << "substring is included in main string " << c << " times" << endl;
    return 0;
}
