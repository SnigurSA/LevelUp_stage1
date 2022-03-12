#include"func4_2.h"

void func4_2(int mass1[], int size1, int mass2[], int size2, int mass3[], int *size3)
{
    int k = 0;
    bool temp;
    for(int i = 0; i < size1; ++i)
    {
        temp = true;
        for(int j=0; j < size2; ++j)
        {


            if (mass1[i] == mass2[j])
            {
                temp = false;
                break;
            }

        }
        if (temp)
        {
            mass3[k] = i;
            ++k;
        }
    }
    *size3 = k;
}
