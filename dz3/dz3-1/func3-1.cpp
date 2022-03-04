#include "func3-1.h"

int func3_1(int N)
{
    int r = 0;
    for ( int i = 1; N >= 1; i ++ )
    {
        N = N / 10;
        ++r;
    }
    return r;
}
