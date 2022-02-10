#include <iostream>

int main ()
{
long long int i, N, flag1 = 0;

    printf("Vvedite chilo N= ");
    scanf("%lld", &N);
    // printf("%lld", N);
    i = 1; // записываем "1" в нулевой бит переменной i
    i <<= 62; // сдвигаем "1" на 62 позиции влево, при сдвиге на 63 получается бесконечный цикл вывода "1" или не считает вообще

    //printf ("%lld", i);
    printf("V dvoichnom formate N= ");


    while (i > 0)
     {
       if (N & i)        // битовое И - в данном случае вернет 2^i - если i-ый бит 1
          {
             printf("1");
             flag1 = 1;
          }
       else
           if (flag1 == 1) // чтобыы не печатать лишние нули слева
              printf("0");
       i >>= 1;         // битовый сдвиг, запись числа смещается на один бит
     }

}
