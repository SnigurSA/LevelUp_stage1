
#include "print_qmatr.h"
#include<stdio.h>

void print_qmatr (const int size, int* matr)
{
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
        {
            printf("  %d ", matr[i * size + j]);
            if (j == size - 1)
            printf("\n");
        }

}
