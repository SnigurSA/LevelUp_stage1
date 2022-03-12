// Дана строка символов. Удалить из нее все слова нечетной длины.
// Слова отделяются друг от друга одним пробелом.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func4-5.h"

int main()
{
    char str[255] = {};
    char result_str[255] = {};
    fgets(str, 254, stdin);

    /*
    for(unsigned int i = 0; i < strlen(str); )
    {
        char word[255] = {};
        sscanf(str + i, "%s", word); // считваем очередное слово в word
        //printf ("W= %s ", word);
        //printf ("L_Word = %d \n", strlen(word));
        if ((strlen(word) % 2) == 0)   // определяем четность количества символов в слове
        {
            strcat(result_str, word); // копируем строку word в конец строки result_str
            strcat(result_str, " ");  // добавляем пробел в конце строки  result_str
        }
        //printf ("R_S= %s \n", result_str);
        i += strlen(word) + 1;
    }

    //printf ("%s \n", result_str);
    */
    //result_str = func4_5(str);
    func4_5(str, result_str);
    puts(result_str);

}
