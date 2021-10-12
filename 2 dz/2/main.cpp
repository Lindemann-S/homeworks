/*Реализовать возведение в целую степень (с логарифмической сложностью алгоритма).

*/

#include <iostream>

using namespace std;

double power(double a, int n)
{
    bool invert = false;
    if (n < 0)
    {
        invert = true;
        n = n * -1;
    }
    double result = 1;
    while (n != 0)
    {
        if (n & 1)
        {
            result *= a;
        }
        n = n >> 1;
        a *= a;
    }
    if (invert)
    {
        result = 1 / result;
    }
    return result;
}

int main()
{
    double dergreeBasis = 0;
    cout << "enter the base of power: ";
    cin >> dergreeBasis;
    int degreeIndicator = 0;
    cout << "enter the degree indicator: ";
    cin >> degreeIndicator;
    double answer = power(dergreeBasis, degreeIndicator);
    cout << "your answer: " << answer << endl;
    return 0;
}
