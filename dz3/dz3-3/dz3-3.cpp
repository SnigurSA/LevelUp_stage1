//Поменять местами цифры старшего и младшего разрядов данного натурального числа (например, из числа 3879 получится 9873)

#include "../dz3-1/func3-1.h"
#include "func3-3.h"
#include <stdio.h>


int main()
{
    int N;
    int R;  //разрядность числа N

    printf("Vvedite chislo N = ");
    scanf("%d", &N);
    R = func3_1(N); // находим разрядность числа через ранее написанную функцию к задаче 3-1
    printf("R= %d", R);

    N = func3_3(N,R); // преобразование числа с помощью функции

    printf("Preobrazovannoe chilo %d", N); // вывод ответа
}
