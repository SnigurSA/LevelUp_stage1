//Определить местоположение элементов массива А (30), не встречающихся в массиве В (15).

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../dz4-1/print_mass.h"
#include"func4_2.h"

int main()
{
   int size1 = 30; // размер массива А
   int size2 = 15; // размер массива В
   int size3;
   int A[size1], B[size2], Ai[size1];

   srand(time(0));

   for(int i=0; i < size1; ++i)  //заполнение массива А
   {
       A[i] = rand() %20  - 10;
   }

   for(int i=0; i < size2; ++i)  //заполнение массива В
   {
       B[i] = rand() %20  - 10;
   }


   printf("vyvod masssiva A: \n");      //вывод на экран массива А
   print_mass(A, size1);
   printf("\n");

   printf("vyvod masssiva B: \n");     //вывод на экран массива В
   print_mass(B, size2);
   printf("\n");

   func4_2(A, size1, B, size2, Ai, &size3);

   /*int k = 0;
   bool temp;
   for(int i=0; i < size1; ++i)
      {
           temp = true;
           for(int j=0; i < size2; ++j)
              {
                 if (B[j] == A[i])
                    {
                       temp = false;
                       break;
                    }
              }
           if (temp == true)
               {
               Ai[k] = i;
               ++k;
               }
      }*/
   printf("kolichetvo unikalnyh elevtntov k= %d \n", size3);
   printf("vyvod nomerov elementov:");     //вывод на экран местоположения элементов
   print_mass(Ai, size3);
   /*for(int i = 0; i < si; ++i)
       {
           printf("%d ", Ai[i]);
       }*/
}
