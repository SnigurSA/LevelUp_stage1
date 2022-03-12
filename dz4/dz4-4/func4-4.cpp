#include "func4-4.h"

int func4_4(const int size, int* matr)
{
    int X = size - 1;
    int Y = size - 1;
    int Sum = 0;

    for(int i=0; i < X; ++i)             //сложение элементов матрицы слева от побочной диагонали
       {
           for(int j=0; j < Y; ++j)
               Sum += matr[i * size + j];
           Y--;
       }
    return Sum;
}
