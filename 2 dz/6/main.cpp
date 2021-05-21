#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void num_gen(int *hidden_number, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        hidden_number[i] = rand() % 10;
        if (hidden_number[0] == 0)
        {
            i = -1;
            break;
        }
        if (i > 0)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (hidden_number[i] == hidden_number[j])
                {
                    i = -1;
                    break;
                }
            }
        }
    }
}

int nob(int *hidden_number, int *new_number, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (hidden_number[i] == new_number[i])
        {
            n++;
        }
    }
    return n;
}

int noc(int *hidden_number, int *new_number, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                j++;
            }
            if (hidden_number[i] == new_number[j])
            {
                n++;
            }
        }
    }
    return n;
}

void game(int *hidden_number, int size, int count)
{
    int test_number = 0;
    cout << count << ". " << "enter your number of " << size << " different characters" << endl;
    cin >> test_number;
    int *new_number = new int[size];
    int a = pow(10, (size - 1));
    for (int i = 0; i < size; i++)
    {
        new_number[i] = test_number / a;
        test_number %= a;
        a /= 10;
    }
    for (int i = 0; i < size - 1; i++) // проверка на дурака
    {
        for (int j = i + 1; j < size; j++)
        {
            if (new_number[i] == new_number[j])
            {
                cout << "you entered an incorrect number, please enter a number from different values" << endl;
                game(hidden_number, size, count);
            }
        }
    }
    int number_of_bulls = nob(hidden_number, new_number, size);
    int number_of_cows = noc(hidden_number, new_number, size);
    cout << "number_of_bulls = " << number_of_bulls << endl
         << "number_of_cows = " << number_of_cows << endl;
    if (number_of_bulls == size)
    {
        cout << "you won in " << count << " attempts" << endl;
    }
    else
    {
        count++;
        game(hidden_number, size, count);
    }
    delete []new_number;
}

void start_the_game()
{
    unsigned int size = 0;
    cout << "enter the number of numbers to guess" << endl;
    cin >> size;
    int *hidden_number = new int[size];
    num_gen(hidden_number, size);
//    for (int i = 0; i < size; i++)
//    {
//        cout << hidden_number[i];
//    }
//    cout << endl;
    int count = 1;
    game(hidden_number, size, count);
    delete []hidden_number;
}

int main()
{
    cout << "Welcome to the game Bulls and Cows. " << endl
         << "You have a four-digit number to guess. " << endl
         << "The number of bulls indicates the number of guessed numbers that are in their place, " << endl
         << "the number of cows indicates the number of guessed numbers that are not in their place" << endl
         << "(enter 1 to continue, or 0 to exit the game)" << endl;
    unsigned int check = 0;
    cin >> check;
    if (check == 1)
    {
        start_the_game();
    }
    cout << "do you want to continue playing ?" << endl
         << "(enter 1 to continue, or 0 to exit the game)" << endl;;
    cin >> check;
    if (check == 1)
    {
        main();
    }
    return 0;
}
