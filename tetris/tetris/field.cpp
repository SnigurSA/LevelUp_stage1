#include<curses.h>

#include"field.h"



int check[4] = {};

// массив, описывающий начальное значение поля:
int Start_Field[22][12] = {{1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,0,0,0,0,0,0,0,0,0,0,1},
                           {1,1,1,1,1,1,1,1,1,1,1,1},
                           {1,1,1,1,1,1,1,1,1,1,1,1}};

int Curent_Field[22][12];

// функция отрисовки игрового поля
void print_field(int *mass)
{
    for(int i = 0; i < 20; ++i)
    {
        for(int j = 1; j < 11; ++j)
        {
            if (mass[12 * i + j])
            {
                attron(COLOR_PAIR(5));
                mvvline(2 + i, 10 + j, 8, 1);
                attroff(COLOR_PAIR(5));
            }
            else
               mvvline(2 + i, 10 + j, 0x0020, 1);
        }
    }
};

//функция проверки пересечения фигур с игровым полем:
bool intercept(int *field, int *figure, int number_figure, int number_position, int X, int Y)
{
    bool res = true;
    int dY, dX;
    switch (number_position)
    {
    case 1:
        dY = 0;
        for(int i = 0; i < 4; ++i)
        {
            dX = 0;
            for(int j = 0; j < 4; ++j)
            {
                if ((field[(Y - 2 + dY) * 12 + X - 10 + dX] + figure[number_figure * 16 + 4 * i + j]) > 1)
                    res = false;
                ++dX;
            }
            ++dY;
        }
        break;
    case 3:
        dY = 0;
        for(int i = 3; i >= 0; --i)
        {
            dX = 0;
            for(int j = 3; j >= 0; --j)
            {
                if ((field[(Y - 2 + dY) * 12 + X - 10 + dX] + figure[number_figure * 16 + 4 * i + j]) > 1)
                    res = false;
                ++dX;
            }
            ++dY;
        }
        break;
    case 2:
        dY = 0;
        for(int j = 0; j < 4; ++j)
        {
            dX = 0;
            for(int i = 3; i >= 0; --i)
            {
                if ((field[(Y - 2 + dY) * 12 + X - 10 + dX] + figure[number_figure * 16 + 4 * i + j]) > 1)
                    res = false;
                ++dX;

            }
            ++dY;
        }
        break;
    case 4:
        dY = 0;
        for(int j = 3; j >= 0; --j)
        {
            dX = 0;
            for(int i = 0; i < 4 ; ++i)
            {
                if ((field[(Y - 2 + dY) * 12 + X - 10 + dX] + figure[number_figure * 16 + 4 * i + j]) > 1)
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
        for(int i = 0; i < 4; ++i)
        {
            dX = 0;
            for(int j = 0; j < 4; ++j)
            {
                field[(Y - 2 + dY) * 12 + X - 10 + dX] += figure[number_figure * 16 + 4 * i + j];
                ++dX;
            }
            ++dY;
        }
        break;
    case 3:
        dY = 0;
        for(int i = 3; i >= 0; --i)
        {
            dX = 0;
            for(int j = 3; j >= 0; --j)
            {
                field[(Y - 2 + dY) * 12 + X - 10 + dX] += figure[number_figure * 16 + 4 * i + j];
                ++dX;
            }
            ++dY;
        }
        break;
    case 2:
        dY = 0;
        for(int j = 0; j < 4; ++j)
        {
            dX = 0;
            for(int i = 3; i >= 0; --i)
            {
                field[(Y - 2 + dY) * 12 + X - 10 + dX] += figure[number_figure * 16 + 4 * i + j];
                ++dX;
            }
            ++dY;
        }
        break;
    case 4:
        dY = 0;
        for(int j = 3; j >= 0; --j)
        {
            dX = 0;
            for(int i = 0; i < 4 ; ++i)
            {
                field[(Y - 2 + dY) * 12 + X - 10 + dX] += figure[number_figure * 16 + 4 * i + j];
                ++dX;
            }
            ++dY;
        }
        break;
    }
};

//функция проверки полных линий
   //возвращает их количество и записывает в массив check номера полных линий.
int check_field(int *field,int check[])
{
    int S, k = 0;
    for(int i = 0; i < 20; ++i)
    {
        S = 0;
        for(int j = 1; j < 11; ++j)
            S += field[12 * i + j];
        if (S == 10)
        {
            check[k] = i;
            ++k;
        }
    }
    return k;
}

//мигает полными линиями 3 раза и перезаписывает массив игрового поля, исключая заполненные поля
void crash_lines(int *field, int *check, int K)
{
    for(int n = 0; n < 3; ++n)
    {
        for(int i = 0; i < K; ++i)
            mvhline(2 + check[i], 11, 0x0020, 10);
        refresh();
        napms(100);
        attron(COLOR_PAIR(5));
        for(int i = 0; i < K; ++i)
            mvhline(2 + check[i], 11, 8, 10);
        attroff(COLOR_PAIR(5));
        refresh();
        napms(100);
    }
    for(int n = 0; n < K; ++n)
    {
        for(int i = check[n]; i >= 1; --i)
            for(int j = 1; j < 11; ++j)
                field[12 * i + j] = field[12 * (i - 1) + j];
    }
};
