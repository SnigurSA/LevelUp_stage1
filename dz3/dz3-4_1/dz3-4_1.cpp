#include <iostream>
#include <math.h>
int main ()
{
    long long int i, N;
    bool flag1 = 0;

    printf("Vvedite chilo N= ");
    scanf("%lld", &N);

    printf("V dvoichnom formate N= ");


    for (int r = 63; r > 0; r--)
    {
        i = 1;
        i <<= r;
        if (N & i)        // битовое И - в данном случае вернет 2^i - если i-ый бит 1
        {
            printf("1");
            flag1 = 1;

        }
        else
            if (flag1) // чтобыы не печатать лишние нули слева
                printf("0");

    }

}
