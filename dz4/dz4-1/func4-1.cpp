#include "func4-1.h"
#include <stdio.h>

void func4_1(int size, int Mass[])
{

int maxi = 0, negi; //переменные для хранения номеров максимального и последнего положительного элементов массива М

if (Mass[0] < 0) // проверяем на отрицательность первый элемент массива
    negi = 0;

int tempM; //временная переменная для замен элементов массива

for(int i = 1; i < size; ++i)
{
  if (Mass[i] > Mass[maxi]) // находим максимальный элеммент массима М
      maxi = i;
  if (Mass[i] < 0)       // проверяем элемент массива на отрицательность
      negi = i;
}
printf("Mmax= %d maxi=  %d \n", Mass[maxi], maxi);
printf("Mneg= %d negi=  %d \n", Mass[negi], negi);

tempM = Mass[maxi];
Mass[maxi] = Mass[negi];
Mass[negi] = tempM;
}
