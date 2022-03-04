// вычисления суммы ряда для заданного Х (0,05<X<1) с точностью до 5 знака после запятой

#include <stdio.h>
#include "func3-5.h"

int main()
{
    double x;
    printf ("Enter X (0.05<X<1): ");
    scanf ("%lf", &x);

    printf ("Summa rjada: %f", func3_5(x));
}

