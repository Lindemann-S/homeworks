/*Напечатать все представления натурального числа N суммой натуральных слагаемых. Перестановка слагаемых нового способа не дает.*/

#include <iostream>

using namespace std;

void the_executor(int *a, int n1, int pos, int N)
{
    for (int i = n1; i <= N / 2; i++)
    {
        a[pos] = i;
        the_executor(a, i, pos + 1, N - i);
    }
    for (int i = 0; i < pos; i++)
    {
        cout << a[i] << " + ";
    }
    cout << N;
    cout << endl;
}

void representation_of_number(int N)
{
    int arr_of_term[150] = {};
    int first_term = 1;
    int pos = 0;
    the_executor(arr_of_term, first_term, pos, N);
}

int main()
{
    int number = 0;
    cout << "Enter your number: ";
    cin >> number;
    representation_of_number(number);
    return 0;
}
