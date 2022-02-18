//Вычислить сумму элементов матрицы? лежащих сслева от побочной диагонали.

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

   int X = size - 1;
   int Y = size - 1;
   int Sum = 0;

   for(int i=0; i < X; ++i)             //сложение элементов матрицы слева от побочной диагонали
      {
          for(int j=0; j < Y; ++j)
              Sum += A[i][j];
          Y--;
      }


   printf("Sum= %d \n", Sum);      //вывод на экран суммы

}
