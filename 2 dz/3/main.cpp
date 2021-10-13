/*Напечатать все представления натурального числа N суммой натуральных слагаемых. Перестановка слагаемых нового способа не дает.*/

#include <iostream>

using namespace std;

void executor(int *arr, int minNumber, int pos, int currentSum)
{
    for (int i = minNumber; i <= currentSum / 2; i++)
    {
        arr[pos] = i;
        executor(arr, i, pos + 1, currentSum - i);
    }
    for (int i = 0; i < pos; i++)
    {
        cout << arr[i] << " + ";
    }
    cout << currentSum << endl;
}

void numberRepresentation(int N)
{
    const int maxBuffsuze = 150;
    int arrTerm[maxBuffsuze] = {};
    int minNumber = 1;
    int pos = 0;
    executor(arrTerm, minNumber, pos, N);
}

int main()
{
    int number = 0;
    cout << "Enter your number: ";
    cin >> number;
    numberRepresentation(number);
    return 0;
}
