#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if ((i / 100) + ((i % 100) / 10) + (i % 10) == (j / 100) + ((j % 100) / 10) + (j % 10))
            {
                count++;
            }
        }
    }
    cout << count;
}
