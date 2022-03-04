#include "func2-1.h"
#include <math.h>

double func2_1(double a)
    {
         a *= M_PI / 180;
         return (2 * cos(a - M_PI / 6) + sqrt(2)) / (1 / 2 / log(a) + pow(sin(pow(a,2)),2)) * exp(3 * a);
    }
