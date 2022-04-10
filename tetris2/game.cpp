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
#include"record.h"


int position, next_position, current_f, next_f, ds, score, level;
int lev_lim = 1000; //лимит счета на уровне


void newgame(void)
{
    position = rand() % 4 + 1; //определяем позицию текущей фигуры перед началом игры
    current_f = rand() % 7;    //определяем номер текущей (первой) фигуры перед началом игры
    next_f = rand() % 7; //определяем номер следующей фигуры перед началом игры
    next_position = rand() % 4 + 1; //определяем позицию следующей фигуры перед началом игры
    score = 0;
    level = 1;

    memcpy(Curent_Field, Start_Field, sizeof(Start_Field)); //копирование пустого поля в текущее
}

void savegame(void)
{
    NRnew.rec = score;

    FILE* file = fopen(filename, "w");
    for (int i = 0; i < H + 2; ++i)
        for (int j = 0; j < W; ++j)
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

void erasesavefile(void)
{
    FILE* file = fopen(filename, "w");
    fprintf(file, "%d\n", 0);
    fclose(file);
    NRnew.rec = score;
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

void contgame(void)
{
    int u;
    FILE *file;
    int c[271];

    if ((file = fopen(filename,"r+")) == NULL)
        nosavinggame();
    else
    {
        fscanf(file, "%d", &u);

        if (u == 0)
            nosavinggame();
        else
        {
            rewind(file);
            for(int i = 0;i < 270; i++)
                fscanf(file, "%d", &c[i]);
            memcpy(Curent_Field, c, sizeof(Start_Field));
            position = c[264];
            current_f = c[265];
            next_f = c[266];
            next_position = c[267];
            score = c[268];
            level = c[269];
            fclose(file);
        }
    }
}

//функция проверки пересечения фигур с игровым полем:
bool intercept(int *field, int *figure, int number_figure, int number_position, int X, int Y)
{
    bool res = true;
    int dY, dX;
    switch (number_position)
    {
    case 1:
        dY = 0;
        for(int i = 0; i < Fi; ++i)
        {
            dX = 0;
            for(int j = 0; j < Fj; ++j)
            {
                if ((field[(Y - Yfo + dY) * W + X - Xfo + dX] + figure[number_figure * Fi * Fj + Fi * i + j]) > 1)
                    res = false;
                ++dX;
            }
            ++dY;
        }
        break;
    case 3:
        dY = 0;
        for(int i = Fi - 1; i >= 0; --i)
        {
            dX = 0;
            for(int j = Fj - 1; j >= 0; --j)
            {
                if ((field[(Y - Yfo + dY) * W + X - Xfo + dX] + figure[number_figure * Fi * Fj + Fi * i + j]) > 1)
                    res = false;
                ++dX;
            }
            ++dY;
        }
        break;
    case 2:
        dY = 0;
        for(int j = 0; j < Fj; ++j)
        {
            dX = 0;
            for(int i = Fi - 1; i >= 0; --i)
            {
                if ((field[(Y - Yfo + dY) * W + X - Xfo + dX] + figure[number_figure * Fi * Fj + Fi * i + j]) > 1)
                    res = false;
                ++dX;

            }
            ++dY;
        }
        break;
    case 4:
        dY = 0;
        for(int j = Fj - 1; j >= 0; --j)
        {
            dX = 0;
            for(int i = 0; i < Fi ; ++i)
            {
                if ((field[(Y - Yfo + dY) * W + X - Xfo + dX] + figure[number_figure * Fi * Fj + Fi * i + j]) > 1)
                    res = false;
                ++dX;
            }
            ++dY;
        }

        break;
    }
    return res;
};



//функция объединения фигуры и игрового поля
void summ_field(int *field, int *figure, int number_figure, int number_position, int X, int Y)
{
    int dY, dX;
    switch (number_position)
    {
    case 1:
        dY = 0;
        for(int i = 0; i < Fi; ++i)
        {
            dX = 0;
            for(int j = 0; j < Fj; ++j)
            {
                field[(Y - Yfo + dY) * W + X - Xfo + dX] += figure[number_figure * Fi * Fj + Fi * i + j];
                ++dX;
            }
            ++dY;
        }
        break;
    case 3:
        dY = 0;
        for(int i = Fi - 1; i >= 0; --i)
        {
            dX = 0;
            for(int j = Fj - 1; j >= 0; --j)
            {
                field[(Y - Yfo + dY) * W + X - Xfo + dX] += figure[number_figure * Fi * Fj + Fi * i + j];
                ++dX;
            }
            ++dY;
        }
        break;
    case 2:
        dY = 0;
        for(int j = 0; j < Fj; ++j)
        {
            dX = 0;
            for(int i = Fi - 1; i >= 0; --i)
            {
                field[(Y - Yfo + dY) * W + X - Xfo + dX] += figure[number_figure * Fi * Fj + Fi * i + j];
                ++dX;
            }
            ++dY;
        }
        break;
    case 4:
        dY = 0;
        for(int j = Fj - 1; j >= 0; --j)
        {
            dX = 0;
            for(int i = 0; i < Fi ; ++i)
            {
                field[(Y - Yfo + dY) * W + X - Xfo + dX] += figure[number_figure * Fi * Fj + Fi * i + j];
                ++dX;
            }
            ++dY;
        }
        break;
    }
};


// функция увеличения счета.
int dscore(int K)
{
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
    int level_up = *level * lev_lim;
    if (level_up <= score)
        return true;
    else
        return false;
}

void init_game_field(void)
{
    //рисуем границы игрового поля:
    attron(COLOR_PAIR(2));  //включаем цветовую пару 2: зеленый фон, зеленый символ
    mvvline(2,10,7,20);      // устанавливает новую позицию и рисует вертикальную линию, используя атрибуированный символ и max. n длину символов
    mvhline(22,10,7,12);     //устанавливает новую позицию рисует горизонтальную линию, используя атрибуированный символ и max. n длину символов
    mvvline(2,21,7,20);     // устанавливает новую позицию и рисует вертикальную линию, используя атрибуированный символ и max. n длину символов

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
}


State game(void)
{
    const int next_y = 6, next_x = 25;
    bool endgame = true, falling;
    int msec, accel = 25, trigger, key;
    int Yo = Yfo, Xo = Xfo + 4; //координаты начала падения фигуры
    init_game_field();
    halfdelay(1);
    noecho();

    // ////////////////////////////////////////////
    // цикл игры
    while(endgame)
    {
        // отрисовка фигуры в поле NEXT:

        attron(COLOR_PAIR(3));
        print_erase_figure(&Allfigures[0][0][0], next_f, next_position, next_x, next_y, 8);
        attroff(COLOR_PAIR(3));
        refresh();

        falling = true;
        trigger = 100 * ( 11 - level);

        int y = Yo, x = Xo; //координаты начала падения фигуры
        while(falling)
        {
            endgame = intercept(&Curent_Field[0][0],&Allfigures[0][0][0], current_f, position, x, y);
            if (!endgame)
                break;
            attron(COLOR_PAIR(4));
            print_erase_figure(&Allfigures[0][0][0], current_f, position, x, y, 8);
            attroff(COLOR_PAIR(4));
            refresh();

            msec = 0;
            clock_t before = clock();

            while ( msec < trigger )
            {
                if (trigger > accel)
                    key = getch();
                else

                    key = 0;

                switch ( key )
                {
                case MY_KEY_LEFT:
                    if (intercept(&Curent_Field[0][0],&Allfigures[0][0][0], current_f, position, x - 1, y))
                    {
                        print_erase_figure(&Allfigures[0][0][0], current_f, position, x, y, 0x0020);
                        --x;
                        attron(COLOR_PAIR(4));
                        print_erase_figure(&Allfigures[0][0][0], current_f, position, x, y, 8);
                        attroff(COLOR_PAIR(4));
                        refresh();
                    }
                    break;
                case MY_KEY_RIGHT:
                    if (intercept(&Curent_Field[0][0],&Allfigures[0][0][0], current_f, position, x + 1, y))
                    {
                        print_erase_figure(&Allfigures[0][0][0], current_f, position, x, y, 0x0020);
                        ++x;
                        attron(COLOR_PAIR(4));
                        print_erase_figure(&Allfigures[0][0][0], current_f, position, x, y, 8);
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
                        print_erase_figure(&Allfigures[0][0][0], current_f, position, x, y, 0x0020);
                        position = new_position;
                        attron(COLOR_PAIR(4));
                        print_erase_figure(&Allfigures[0][0][0], current_f, position, x, y, 8);
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
            print_erase_figure(&Allfigures[0][0][0], current_f, position, x, y, 0x0020);
            ++y;
        }

        print_erase_figure(&Allfigures[0][0][0], current_f, position, x, y - 1, 0x0020);
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
        print_erase_figure(&Allfigures[0][0][0], next_f, next_position, next_x, next_y, 0x0020);
        refresh();
        position = next_position; //передаем значения следующей фигуры в текущую для следующего круга
        current_f = next_f;
        next_f = rand() % 7;
        next_position = rand() % 3 + 1;

    }
    return(GAMEOVER);
}
