#include <iostream>
#include <cstring>

using namespace std;

bool check(const char *str)
{
    int count = 1;
    int a = strlen(str);
    for (int i = 0; i < a; i++)
    {
        if (str[i] == '(')
        {
            count++;
        }
        if (str[i] == ')')
        {
            count--;
        }
        if (count == 0)
        {
            return false;
        }
    }
    return count == 1;
}

int main()
{
    const char *str = "( (s) )";
    bool c = check(str);
    if (c == true)
        cout << "the nesting rule is executed" << endl;
    else
        cout << "the nesting rule is not met" << endl;

    return 0;
}
