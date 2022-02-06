#include <iostream>
#include <math.h> // подключаем math.h
using namespace std;
double y, x, x1;
int main()
{
    while(1) //цикл для автозапуска вычисления
    {
    printf("Enter x=");
      scanf("%lf", &x);
    x1 = x * M_PI / 180;
    y = (2 * cos(x1 - M_PI / 6) + sqrt(2)) / (1 / 2 / log(x1) + pow(sin(pow(x1,2)),2)) * exp(3 * x1);
    printf(" y = %lf\n ", y);
    //return(0);
    }
}
