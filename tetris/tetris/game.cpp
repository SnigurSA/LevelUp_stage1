#include <curses.h>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

#include"figure.h"
#include"field.h"
#include"key.h"
#include"game.h"
#include"state.h"


int position, next_position, current_f, next_f, ds, score, level;

void newgame(void)
{
    position = rand() % 3 + 1; //определяем позицию текущей фигуры перед началом игры
    current_f = rand() % 7;    //определяем номер текущей (первой) фигуры перед началом игры
    next_f = rand() % 7; //определяем номер следующей фигуры перед началом игры
    next_position = rand() % 3 + 1; //определяем позицию следующей фигуры перед началом игры
    score = 0;
    level = 1;

    memcpy(Curent_Field, Start_Field, sizeof(Start_Field)); //копирование пустого поля в текущее
}

void savegame(void)
{
    FILE* file = fopen("tetris.txt", "w");
    for (int i = 0; i < 21; ++i)
        for (int j = 0; j < 12; ++j)
        {
            fprintf(file, "%d\n", Curent_Field[i][j]);
        }
    fprintf(file, "%d\n", position);
    fprintf(file, "%d\n", current_f);
    fprintf(file, "%d\n", next_f);
    fprintf(file, "%d\n", next_position);
    fprintf(file, "%d\n", score);
    fprintf(file, "%d\n", level);
    fclose(file);

}

void nosavinggame(void)
{
    mvaddstr (5, 5, "There is no saving game");
    mvaddstr (6, 5, "Starting the new game");
    refresh();
    napms(3000);
    erase();
    refresh();
    newgame();
}

void contgame(void /*int *field, int pos, int cf, int nf, int nextpos*/)
{


    int u;
    FILE *file;
    int c[259];

    if ((file=fopen("tetris.txt","r+")) == NULL)
        nosavinggame();
    else
    {
        fscanf(file, "%d", &u);

        if (u == 0)
            nosavinggame();

        else
        {
            rewind(file);
            for(int i = 0;i < 258; i++)
                fscanf(file, "%d", &c[i]);
            memcpy(Curent_Field, c, sizeof(Start_Field));
            position = c[252];
            current_f = c[253];
            next_f = c[254];
            next_position = c[255];
            score = c[256];
            level = c[257];
            fclose(file);
        }
    }
}


// функция увеличения счета.
int dscore(int K)
{
   //int ds;

   switch ( K ) //определяем величину увеличения счета в зависимости от количества полных рядов
   {
   case 0:
       ds = 0;
       break;
   case 1:
       ds = 10;
       break;
   case 2:
       ds = 30;
       break;
   case 3:
       ds = 60;
       break;
   case 4:
       ds = 100;
       break;
   }
   return ds;
}


bool level_up(int score, int* level)
{
    int level_up = *level * 1000;
    if (level_up <= score)
        return true;
    else
        return false;
}


State game(void)
{

    halfdelay(1);         //Устанавливаем ограничение по времени ожидания getch() в 0.1 сек


    const int next_y = 6, next_x = 25;

    bool endgame = true;

    int msec, accel = 25;
    double trigger;



    //рисуем границы игрового поля:
    attron(COLOR_PAIR(2));  //включаем цветовую пару 2: зеленый фон, зеленый символ
    mvvline(2,10,7,20);      // устанавливает новую позицию и рисует вертикальную линию, используя атрибуированный символ и max. n длину символов
    mvhline(22,10,7,12);     //устанавливает новую позицию рисует горизонтальную линию, используя атрибуированный символ и max. n длину символов
    mvvline(2,21,7,20);     // устанавливает новую позицию и рисует вертикальную линию, используя атрибуированный символ и max. n длину символов
    //attroff(COLOR_PAIR(2)); //отключаем цветовую пару 2

    // добавляем надпись NEXT над полем отображения следующего элемента
    attron(COLOR_PAIR(1)); //включаем цветовую пару 1: черный фон,бирюзовый символ
    mvaddstr (4, 25, "NEXT");

    // добавляем надпись SCORE над полем отображения счёта
    mvaddstr (12, 25, "SCORE");
    move (13, 26);
    printw("%d", score); //отображение начального счета

    mvaddstr (15, 25, "LEVEL"); // надпись LEVEL над значением уровня
    move (16, 27);
    printw("%d", level);
    attroff(COLOR_PAIR(1));
    refresh();

    print_field(&Curent_Field[0][0]);
    refresh();

    // ////////////////////////////////////////////
    // цикл игры
    while(endgame)
    {
        // отрисовка фигуры в поле NEXT:

        attron(COLOR_PAIR(3));
        print_figure(&Allfigures[0][0][0], next_f, next_position, next_x, next_y);
        attroff(COLOR_PAIR(3));
        refresh();


        bool falling = true;
        //keypad(stdscr, TRUE);
        trigger = 100 * ( 11 - level);
        int key;

        int y = 2, x = 14; //координаты начала падения фигуры
        while(falling)
        {
            attron(COLOR_PAIR(4));
            print_figure(&Allfigures[0][0][0], current_f, position, x, y);
            attroff(COLOR_PAIR(4));
            refresh();
            endgame = intercept(&Curent_Field[0][0],&Allfigures[0][0][0], current_f, position, x, y);
            if (!endgame)
                break;


            msec = 0;
            clock_t before = clock();

            while ( msec < trigger )
            {
                if (trigger > accel)
                    key = getch();
                else
                    //keypad(stdscr, false);
                    key = 0;

                switch ( key )
                {
                case MY_KEY_LEFT:
                    if (intercept(&Curent_Field[0][0],&Allfigures[0][0][0], current_f, position, x - 1, y))
                    {
                        erase_figure(&Allfigures[0][0][0], current_f, position, x, y);
                        --x;
                        attron(COLOR_PAIR(4));
                        print_figure(&Allfigures[0][0][0], current_f, position, x, y);
                        attroff(COLOR_PAIR(4));
                        refresh();
                    }
                    break;
                case MY_KEY_RIGHT:
                    if (intercept(&Curent_Field[0][0],&Allfigures[0][0][0], current_f, position, x + 1, y))
                    {
                        erase_figure(&Allfigures[0][0][0], current_f, position, x, y);
                        ++x;
                        attron(COLOR_PAIR(4));
                        print_figure(&Allfigures[0][0][0], current_f, position, x, y);
                        attroff(COLOR_PAIR(4));
                        refresh();
                    }
                    break;
                case MY_KEY_UP:
                case MY_KEY_SPACE:
                {
                    int new_position = (position % 4) ? position + 1 : 1;

                    if (intercept(&Curent_Field[0][0],&Allfigures[0][0][0], current_f, new_position, x, y))
                    {
                        erase_figure(&Allfigures[0][0][0], current_f, position, x, y);
                        position = new_position;
                        attron(COLOR_PAIR(4));
                        print_figure(&Allfigures[0][0][0], current_f, position, x, y);
                        attroff(COLOR_PAIR(4));
                        refresh();
                    }
                }
                    break;
                case MY_KEY_DOWN:
                     trigger = accel;
                    break;
                case MY_KEY_ESC:
                    return PAUSEMENU;
                    break;
                default:
                    break;
                }

                clock_t difference = clock() - before;
                msec = difference * 1000 / CLOCKS_PER_SEC;
            }


            falling = intercept(&Curent_Field[0][0],&Allfigures[0][0][0], current_f, position, x, y + 1);


            erase_figure(&Allfigures[0][0][0], current_f, position, x, y);
            ++y;
        }

        erase_figure(&Allfigures[0][0][0], current_f, position, x, y - 1);
        summ_field(&Curent_Field[0][0], &Allfigures[0][0][0], current_f, position, x, y - 1);
        print_field(&Curent_Field[0][0]);
        refresh();


        int K = check_field(&Curent_Field[0][0], &check[0]); //нахождение полных строк
        crash_lines(&Curent_Field[0][0], &check[0], K);      //мигание полными линиями и пересчет игрового поля.
        print_field(&Curent_Field[0][0]);
        refresh();


        //подсчет очков
        score += dscore(K);
        attron(COLOR_PAIR(1));
        move (13, 26);
        printw("%d", score);
        refresh();
        attroff(COLOR_PAIR(1));

        if (level_up(score, &level))
        {
            ++level;
            print_field(&Start_Field[0][0]);
            refresh();
            attron(COLOR_PAIR(1)); //включаем цветовую пару 1: черный фон,бирюзовый символ
            mvaddstr (10, 14, "NEXT");
            mvaddstr (11, 13, "LEVEL");
            attroff(COLOR_PAIR(1));
            attron(COLOR_PAIR(6));
            move (16, 27);
            printw("%d", level);
            refresh();
            napms(1000);
            attron(COLOR_PAIR(1));
            move (16, 27);
            printw("%d", level);
            attron(COLOR_PAIR(1));
            refresh();
            napms(1000);
            print_field(&Curent_Field[0][0]);
            refresh();
        }
        else
        {
            print_field(&Curent_Field[0][0]);
            refresh();
        }

        // стирание фигуры в поле NEXT:
        erase_figure(&Allfigures[0][0][0], next_f, next_position, next_x, next_y);
        refresh();
        position = next_position; //передаем значения следующей фигуры в текущую для следующего круга
        current_f = next_f;
        next_f = rand() % 7;
        next_position = rand() % 3 + 1;


    }
    return(GAMEOVER);

}
