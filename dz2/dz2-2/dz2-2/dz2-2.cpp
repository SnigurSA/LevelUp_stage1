#include <iostream>
#include <math.h> // подключаем math.h
//using namespace std; отключил элементы С++
double R, a, d, SR, Sa, Sd;
int main()
{
    while (1)

{
  printf("Vvedite radius kruga R=");
  scanf("%lf", &R);

  printf("Vvedite dlinu storony treugolnika a=");
  scanf("%lf", &a);

  printf("Vvedite dlinu storony kvadrata d=");
  scanf("%lf", &d);

  SR = pow(R,2) * M_PI;
  Sa = pow(a,2) * sqrt(3) / 4;
  Sd = pow(d,2);
  printf(" SR = %lf Sa = %lf Sd = %lf\n ", SR, Sa, Sd);
  SR > Sa ? (SR > Sd ? printf("Ploshad kruga naibolshaya \n ") : printf("Ploshad kvadrata naibolshaya \n "))
          : (Sa > Sd ? printf("Ploshad treugolnika naibolshaya \n ") : printf("Ploshad kvadrata naibolshaya \n "));
 }
}

