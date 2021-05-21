#include <iostream>

using namespace std;

int fun(int a, int b)
{
    int isp = 1;
    if (a < 0 || b < 0)
    {
        isp = -1;
    }
    if (a < 0 && b < 0)
    {
        isp = 1;
    }
    if (a < 0)
    {
        a = a * -1;
    }
    if (b < 0)
    {
        b = b * -1;
    }
    int count = 0;
    for (count = 0; a >= b; count++)
    {
        a = a - b;
    }
    return count * isp;
}

int main()
{
    int a = 0;
    int b = 0;
    cout << "Vvedite chisla: ";
    cin >> a >> b;
    if (b == 0)
    {
        cout << "pshel_nahoi. ";
        return 0;
    }
    int result = 0;
    result = fun(a, b);
    cout << result;
    return 0;
}
