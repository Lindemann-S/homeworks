#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    cout << "entered value X: ";
    cin >> x;
    int a = x * x;
    int result = (a + 1) * (a + x) + 1;
    cout << result;
    return 0;
}
