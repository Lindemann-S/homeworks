/*Реализовать возведение в целую степень (с логарифмической сложностью алгоритма).

*/

#include <iostream>

using namespace std;

double power(double a, int n)
{
    double result = 1;
    while(n > 0)
    {
        if (n & 1)
        {
            result *= a;
        }
        n = n >> 1;
        a *= a;
    }
    return result;
}

int main()
{
    double the_basis_of_the_degree = 0;
    cout << "enter the base of power: ";
    cin >> the_basis_of_the_degree;
    int the_degree_indicator = 0;
    cout << "enter the degree indicator: ";
    cin >> the_degree_indicator;
    int answer = power (the_basis_of_the_degree, the_degree_indicator);
    cout << "your answer: " << answer << endl;
    return 0;
}
