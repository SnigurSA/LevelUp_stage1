//Определить местоположение элементов массива А (30), не встречающихся в массиве В (15).

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
   int size1 = 30; // размер массива А
   int size2 = 15; // размер массива В

   int A[size1], B[size2], Ai[size1];

   srand(time(0));

   for(int i=0; i <= size1; ++i)  //заполнение массива А
   {
       A[i] = rand() %20  - 10;
   }

   for(int i=0; i <= size2; ++i)  //заполнение массива В
   {
       B[i] = rand() %20  - 10;
   }


   printf("vyvod masssiva A:");      //вывод на экран массива А
   for(int i = 0; i <= size1; ++i)
       {
           printf("%d ", A[i]);
       }
   printf("\n");

   printf("vyvod masssiva B:");     //вывод на экран массива В
   for(int i = 0; i <= size2; ++i)
       {
           printf("%d ", B[i]);
       }
   printf("\n");

   int k = 0;
   bool temp;
   for(int i=0; i <= size1; ++i)
      {
           temp = true;
           for(int j=0; i <= size2; ++j)
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
      }
   printf("kolichetvo unikalnyh elevtntov k= %d \n", k);
   printf("vyvod noverov elementov:");     //вывод на экран местоположения элементов
   for(int i = 0; i <= k-1; ++i)
       {
           printf("%d ", Ai[i]);
       }
}
