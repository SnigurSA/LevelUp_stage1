//Найти наименьший общий делитель трех натуральных чисел

#include <stdio.h>
#include "func3-2.h"
int main()
{
    int N1, N2, N3;
    //int j = 1;  //переменная j - наименьший общий делитель

    printf("Vvedite  natulnoe chislo N1=");
    scanf("%d", &N1);
    printf("Vvedite  natulnoe chislo N2=");
    scanf("%d", &N2);
    printf("Vvedite  natulnoe chislo N3=");
    scanf("%d", &N3);
    /*
    int N_min = fmin(N1, fmin(N2, N3));

    for (int i = N_min; i > 0; --i)
    {
        if ( ( N1 % i == 0 ) && ( N2 % i == 0 )  && ( N3 % i == 0 ) )
        {
            j = i;
            break;
        }
    }*/


    printf("Naimenshyi obshii delitel: ");
    printf(" %d", min_ob_del(N1, N2, N3));

}
