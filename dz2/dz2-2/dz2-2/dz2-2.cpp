#include <iostream>
#include <math.h> // подключаем math.h
using namespace std;
double R, a, d, pi = 3.1415926, SR, Sa, Sd;
int main()
{
    while (1)

{
  printf("input radius kruga R=");
  scanf("%lf", &R);

  printf("input dlinu storony treugolnika a=");
  scanf("%lf", &a);

  printf("input dlinu storony kvadrata d=");
  scanf("%lf", &d);

  SR = pow(R,2) * pi;
  Sa = pow(a,2) * sqrt(3) / 4;
  Sd = pow(d,2);
  printf(" SR = %lf Sa = %lf Sd = %lf\n ", SR, Sa, Sd);
  if (SR > Sa)
  {
      if (SR > Sd)
      {
          printf("Ploshad kruga naibolshaya");
      }
      else
      {
          printf("Ploshad kvadrata naibolshaya");
      }
  }
  else
    {
      if (Sa > Sd)
       {
          printf("Ploshad treugolnika naibolshaya");
       }
      else
      {
          printf("Ploshad kvadrata naibolshaya       ");
      }
  }

}
}

