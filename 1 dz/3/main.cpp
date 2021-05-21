/*Дан массив целых чисел x[1]...x[m+n], рассматриваемый как соединение двух его отрезков: начала x[1]...x[m] длины m и конца x[m+1]...x[m+n] длины n.
 *Не используя дополнительных массивов, переставить начало и конец.*/

#include <iostream>

using namespace std;

void reverse(int *a, int *b)
{
    while (a < b)
    {
        swap(*a, *b);
        a++;
        b--;
    }
}

int main()
{
    int n = 4;
    int m = 7;
    int size = n + m;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    reverse(a, a + n - 1);
    reverse(a + n, a + size - 1);
    reverse(a, a + size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
