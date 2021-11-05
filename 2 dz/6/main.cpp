/*Реализовать консольную игру "Быки и коровы"*/

#include "numberGenerator.h"
#include "bullsAndCows.h"

void startTheGame()
{
    unsigned int size = 0;
    std::cout << "enter the number of digits (no more than 10)" << std::endl;
    std::cin >> size;
    if (size >= 10)
    {
        std::cout << "Why are you gay?" << std::endl;
        return;
    }
    if (size > 5)
    {
        std::cout << "Are you realy want it ?" << std::endl
            << "We strongly recomended not to set the number more than 5 digits" << std::endl
            << "if you want to continue press any key, if you want to change the number of digits press 1" << std::endl;;
        unsigned int answer = 0;
        std::cin >> answer;
        if (answer == 1)
        {
            std::cout << "enter the number of digits (less than 5)" << std::endl;
            std::cin >> size;
        }
        if (size > 5)
        {
            std::cout << "you wanted it yourself" << std::endl;
        }
    }
    int *hiddenNumber = new int[size];
    numberGenerator(hiddenNumber, size);
    int count = 1;
    game(hiddenNumber, size, count);
    delete []hiddenNumber;
}

int main()
{
    std::cout << "Welcome to the game Bulls and Cows. " << std::endl
         << "You have a four-digit number to guess. " << std::endl
         << "The number of bulls indicates the number of guessed numbers that are in their place, " << std::endl
         << "the number of cows indicates the number of guessed numbers that are not in their place" << std::endl
         << "(enter 1 to continue, or 0 to exit the game)" << std::endl;;
    unsigned int check = 0;
    std::cin >> check;
    while(check != 0)
    {
        startTheGame();
        std::cout << "do you want to continue playing ?" << std::endl
             << "(enter 1 to continue, or 0 to exit the game)" << std::endl;;
        std::cin >> check;
    }
    return 0;
}
