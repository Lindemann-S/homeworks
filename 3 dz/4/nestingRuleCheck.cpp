#include "nestingRuleCheck.h"

bool nestingRuleCheck(char *string)
{
    int count = 0;
    int lenght = stringLenght(string);
    for (int i = 0; i <= lenght; i++)
    {
        if (string[i] == '(')
        {
            count++;
        }
        if (string[i] == ')')
        {
            count--;
        }
    }
    if (count != 0)
    {
        return false;
    }
    return count == 0;
}
