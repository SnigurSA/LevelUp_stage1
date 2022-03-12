#include "func4-3.h"

void func4_3 (const int size, int* matr, int k)
{
    int temp;
    for (int i = 0; i < size; ++i)
    {
        temp = matr[i * size + k - 1];
        matr[i * size + k - 1] = matr[size * (k - 1) + i];
        matr[size * (k - 1) + i] = temp;
    }
}
