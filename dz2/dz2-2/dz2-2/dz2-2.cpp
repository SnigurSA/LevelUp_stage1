
#include <stdio.h>
#include "func2-2.h"
double R, a, d;
int main()
{
  printf("Vvedite radius kruga R=");
  scanf("%lf", &R);

  printf("Vvedite dlinu storony treugolnika a=");
  scanf("%lf", &a);

  printf("Vvedite dlinu storony kvadrata d=");
  scanf("%lf", &d);

  func2_2(R, a, d);

}

