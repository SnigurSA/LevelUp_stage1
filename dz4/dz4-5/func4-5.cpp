#include "func4-5.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void func4_5(char *STR, char *RES_STR)
{

    for(unsigned int i = 0; i < strlen(STR); )
    {

        char word[255] = {};
        sscanf(STR + i, "%s", word); // считваем очередное слово в word
        //printf ("W= %s ", word);
        //printf ("L_Word = %d \n", strlen(word));
        if ((strlen(word) % 2) == 0)   // определяем четность количества символов в слове
        {
            strcat(RES_STR, word); // копируем строку word в конец строки result_str
            strcat(RES_STR, " ");  // добавляем пробел в конце строки  result_str
        }
        //printf ("R_S= %s \n", result_str);
        i += strlen(word) + 1;
    }

}
