#include "func2-1.h"

#include <stdio.h>

double y, x;

int main()
{
    printf("Enter x=");
    scanf("%lf", &x);
    y = func2_1(x);
    printf(" y = %lf\n ", y);
}
