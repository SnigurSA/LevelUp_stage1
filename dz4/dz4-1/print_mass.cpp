#include "print_mass.h"
#include <stdio.h>

void print_mass(int Mass[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", Mass[i]);
    }
}
