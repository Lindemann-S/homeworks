/*Посчитать целую степень числа: a^n */

#include <iostream>

using namespace std;

double fun(double num, int deg )
{
    double result = 1;
    while (deg)
    {
        if (deg % 2 == 0)
        {
            deg /= 2;
            num *= num;
        }
        else
        {
            deg--;
            result *= num;
        }
    }
    return result;
}

int main()
{
    double num = 0;
    int deg = 0;
    cout << "enter your number and degree" << endl;
    cin >> num >> deg;
    if (deg < 0)
    {
        deg = - deg;
        cout << 1/fun(num, deg);
        return 0;
    }
    cout << fun(num, deg);
    return 0;
}
