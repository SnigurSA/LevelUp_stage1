//Поменять местами максимальный и последний отрицательный элементы массива M(40).

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
   const int size = 40;

    int M[size];
   srand(time(0));

   for(int i=0; i <= size; ++i)
   {
       //srand(time(0));
       M[i] = rand() %100 - 50;
   }

   printf("vyvod nachalnogo masssiva M:");
   for(int i = 0; i <= size; ++i)
       {
           printf("%d ", M[i]);
       }
   printf("\n");
   int maxi, negi; //переменные для хранения номеров максимального и последнего положительного элементов массива М
   maxi = 0; // предполагаем, что первый элемент массива является максимальнм
   if (M[0] < 0) // проверяем на отрицательность первый элемент массива
       negi = 0;

   int tempM; //временная переменная для замен элементов массива

   for(int i = 1; i < size; ++i)
   {
     if (M[i] > M[maxi]) // находим максимальный элеммент массима М
         maxi = i;
     if (M[i] < 0)       // проверяем элемент массива на отрицательность
         negi = i;
   }
   printf("Mmax= %d maxi=  %d \n", M[maxi], maxi);
   printf("Mneg= %d negi=  %d \n", M[negi], negi);

   tempM = M[maxi];
   M[maxi] = M[negi];
   M[negi] = tempM;

   printf("vyvod preobrazovannogo masssiva M:");
   for(int i = 0; i < size; ++i)
       {
           printf("%d ", M[i]);
       }

}

