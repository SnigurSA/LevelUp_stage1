// вычисления суммы ряда для заданного Х (0,05<X<1) с точностью до 5 знака после запятой

#include<math.h>

double func3_5(double a)
{
double Sum = a; // присваиваем сумме значение первого слагаемого
const double eps = 1e-5;
double step = 0;
long long int F_chet = 1;
long long int F_nechet = 1;

for (int n=1; true  ;++n) //цикл вычисления очередного слагаемого сумм ряда
    {
        //printf("n= %d \n", n);
        F_chet *= 2 * n;
        //printf("F_chet= %lld \n", F_chet);
        F_nechet *= (2 * n - 1);
        //printf("F_nechet= %lld \n", F_nechet);
        step = F_nechet * pow(a,(2 * n + 1)) / F_chet / (2 * n + 1);
        //printf("%f \n", step);
        if ((step < eps) ^ (n == 16)) // ограничение по диапазону n, т.к. значения факториалов выходят за 64 бита
            break;
        Sum += step;
}
return Sum;
}
