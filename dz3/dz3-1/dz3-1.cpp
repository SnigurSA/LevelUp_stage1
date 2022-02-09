//определение количества цифр (разрядов) в введенном натуральном числе

#include <iostream>

int main()
{
    int N;
    int i;

      printf("Vvedite  natulnoe chislo N=");
       scanf("%d", &N);

      for ( i = 1; N >= 1; i ++ )
          N = N / 10;

       printf("V chisle N: ");
       printf(" %d", i-1);
       printf("  tsyfr \n");

}
