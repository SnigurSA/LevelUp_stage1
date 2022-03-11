/*
Задача 4.
Дан массив длиной size. Массив состоит из целых чисел. Дано целое число K. Найти в этом массиве такой интервал, что бы сумма элементов в нем равнялась K.

struct Pair
{
 int first;
 int second;
};

Pair find( int* mass, int size, int k );
*/


#include <stdio.h>
const int size = 10;

struct Pair
{
    int first;
    int second;
};

Pair find( int* mass, int size, int k )
{
    Pair Res;
    Res.first = -1;
    Res.second = -1;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += mass[j];
            if (sum == k)
            {
                Res.first = i;
                Res.second = j;
            }
        }


    }
return Res;
}


int main()
{
    int mass[size] = {1,2,3,4,5,6,7,8,9,10};
    int K;
    printf ("enter number");
    scanf("%d", &K);
    Pair rez;
    rez = find(mass, size, K);
    printf ("diapazon from %d", rez.first);
    printf(" to %d", rez.second);
}

