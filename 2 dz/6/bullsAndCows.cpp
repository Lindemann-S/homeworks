#include "bullsAndCows.h"

void game(int *hiddenNumber, int size, int count)
{
    bool check = true;
    while (check)
    {
        int testNumber = 0;
        std::cout << count << ". " << "enter your number of " << size << " different digits" << std::endl;
        std::cin >> testNumber;
        if (testNumber / pow (10, size) > 1)
        {
            std::cout << "you entered an incorrect number, please try again" << std::endl;
            continue;
        }
        int newNumber[10] = {0};
        int a = pow (10, (size - 1));
        for (int i = 0; i < size; i++)
        {
            newNumber[i] = testNumber / a;
            testNumber %= a;
            a /= 10;
        }
        for (int i = 0; i < size - 1; i++) // проверка на дурака
        {
            for (int j = i + 1; j < size; j++)
            {
                if (newNumber[i] == newNumber[j])
                {
                    std::cout << "you entered an incorrect number, please enter a number from different values" << std::endl;
                    break;
                }
            }
        }
        int nob = numberOfBulls(hiddenNumber, newNumber, size);
        int noc = numberOfCows(hiddenNumber, newNumber, size);
        std::cout << "number_of_bulls = " << nob << std::endl
                  << "number_of_cows = " << noc << std::endl;
        if (nob == size)
        {
            std::cout << "you won in " << count << " attempts" << std::endl;
            check = false;
        }
        else
        {
            count++;
        }
    }
}
