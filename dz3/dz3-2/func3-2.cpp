#include "func3-2.h"
#include <math.h>
int j = 1;
int min_ob_del(int N1, int N2, int N3)
{
    int N_min = fmin(N1, fmin(N2, N3));
    for (int i = N_min; i > 1; --i)
    {
        if ( ( N1 % i == 0 ) && ( N2 % i == 0 )  && ( N3 % i == 0 ) )
        {
            j = i;
            //break;
        }
    }
    return j;
}
