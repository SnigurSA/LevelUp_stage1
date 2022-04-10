#include<curses.h>
#include<string.h>

#include"record.h"

namerec NR[10];


int m;
// функция открытия файла рекордов
void print_recordlist(void)
{
    FILE* file;
    if ((file = fopen("recordlist.txt","r")) != NULL)
    {
        for(m = 0; !feof(file) && m <= 10; m++)
        {
            fscanf(file, "%s", NR[m].name);
            fscanf(file, "%d", &NR[m].rec);
        }
        fclose(file);

        --m;
        mvprintw(8, 5, "Ten best players:");
        int ym = 9;
        for(int i = 0; i < m; i++)
        {
            move(ym + i, 5);
            printw ("%d) %s", i + 1, NR[i].name);
            move(ym + i, 20);
            printw ("%d", NR[i].rec);
        }
    }
    else
    {
        mvprintw(8, 5, "No players yet");
        mvprintw(9, 5, "You're the fisrt");
    }
}

void resaverecordlist(void)
{

    if(Np > 10)
    {
        if (NRnew.rec > NR[m - 1].rec)
        {
            NR[m - 1].rec = NRnew.rec;
            strcpy(NR[m - 1].name ,NRnew.name);
        }
    }
    else
    {
        if (Np > m)
        {
            m = Np;
            strcpy(NR[Np - 1].name, NRnew.name);
            NR[Np - 1].rec = NRnew.rec;
        }
        else
            if (NR[Np].rec < NRnew.rec)
                NR[Np].rec = NRnew.rec;
    }

    namerec temp;
    bool usl = true;
    while(usl)//сортировка списка рекордов
    {
        usl = false;
        int ms = m;
        for(int i = 0; i + 1 < ms; i++)
            if (NR[i].rec < NR[i + 1].rec)
            {
                usl = true;
                temp.rec = NR[i].rec;
                strcpy(temp.name,NR[i].name);
                NR[i].rec = NR[i + 1].rec;
                strcpy(NR[i].name,NR[i + 1].name);
                NR[i + 1].rec = temp.rec;
                strcpy(NR[i + 1].name,temp.name);
            }
        ms--;
    }
    //запись списка рекордов в файл
    FILE* file = fopen("recordlist.txt", "w");
    for (int i = 0; i < m; ++i)
    {
        fprintf(file, "%s ", NR[i].name);
        fprintf(file, "%d\n", NR[i].rec);
    }
    fclose(file);
}



