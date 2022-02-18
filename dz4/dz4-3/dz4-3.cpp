//Дана матрица размером 7х7. Поменять местами k-й столбец с k-ой строкой

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
   const int size = 7; // размер матрицы А

   int A[size][size]; /*= {{2, 4, 3, 6, 9, 5, -3},
                         {8, 3, -7, 3, 1, 0, 6},
                         {-5, 9, 0, 7, -6, -3, 4},
                         {5, 8, -8, 4, 9, 1, 0},
                         {6, -4, 1, 3, 0, 8, -7},
                         {8, 5, -2, 0, 4, 9, -4},
                         {7, 5, -9, 4, 6, 3, 0}};*/

   /**/
   srand(time(0));

   for(int i=0; i <= size; ++i)  //заполнение матрицы А
      for(int j=0; j <= size; ++j)
          {
          A[i][j] = rand() %20  - 10;
          }
   /**/
   printf("vyvod matritsy \n");      //вывод на экран матрицы А
   for(int i = 0; i < size; ++i)
       {
           for(int j=0; j < size; ++j)
               printf("  %d ", A[i][j]);

           printf("\n");
       }

   int k;

   printf("Enter K (0...7) K= ");  //ввод значения К для замены строки а столбец
   scanf(" %d", &k);

   int temp;
   for(int i=0; i < size; ++i)
      {
           temp = A[i][k-1];
           A[i][k-1] = A[k-1][i];
           A[k-1][i] = temp;
      }


   printf("vyvod preobrazovannoi matritsy \n");      //вывод на экран матрицы А
   for(int i = 0; i < size; ++i)
       {
           for(int j=0; j < size; ++j)
               printf("  %d ", A[i][j]);

           printf("\n");
       }

}
