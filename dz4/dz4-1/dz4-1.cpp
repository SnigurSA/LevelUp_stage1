//Поменять местами максимальный и последний отрицательный элементы массива M(40).

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "func4-1.h"
#include "print_mass.h"

int main()
{
   const int size = 30;

   int M[size];
   srand(time(0));

   for(int i=0; i < size; ++i)
   {
       //srand(time(0));
       M[i] = rand() %100 - 50;
   }

   printf("vyvod nachalnogo masssiva M:\n");
   print_mass(M, size);
   printf("\n");

   func4_1(size, M);

   printf("vyvod preobrazovannogo masssiva M:\n");
   print_mass(M, size);

}

