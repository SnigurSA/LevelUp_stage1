#include <math.h>
#include <stdio.h>
#include "func2-2.h"
void func2_2(double R, double a, double d)
{
    double SR = pow(R,2) * M_PI;
    double Sa = pow(a,2) * sqrt(3) / 4;
    double Sd = pow(d,2);
    printf(" SR = %lf Sa = %lf Sd = %lf\n ", SR, Sa, Sd);
    SR > Sa ? (SR > Sd ? printf("Ploshad kruga naibolshaya \n ") : printf("Ploshad kvadrata naibolshaya \n "))
            : (Sa > Sd ? printf("Ploshad treugolnika naibolshaya \n ") : printf("Ploshad kvadrata naibolshaya \n "));
}
