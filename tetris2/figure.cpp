#include<curses.h>

#include"figure.h"

const int N = 7, Fi = 4, Fj = 4;

int Allfigures[N][Fi][Fj] ={{{0,1,0,0},
                                    {0,1,0,0},
                                    {0,1,0,0},
                                    {0,1,0,0}},
                                   {{0,0,1,0},
                                    {0,1,1,0},
                                    {0,1,0,0},
                                    {0,0,0,0}},
                                   {{0,1,0,0},
                                    {0,1,1,0},
                                    {0,0,1,0},
                                    {0,0,0,0}},
                                   {{0,1,1,0},
                                    {0,1,0,0},
                                    {0,1,0,0},
                                    {0,0,0,0}},
                                   {{0,1,1,0},
                                    {0,0,1,0},
                                    {0,0,1,0},
                                    {0,0,0,0}},
                                   {{0,0,0,0},
                                    {1,1,1,0},
                                    {0,1,0,0},
                                    {0,0,0,0}},
                                   {{0,0,0,0},
                                    {0,1,1,0},
                                    {0,1,1,0},
                                    {0,0,0,0}}};

//функция печати (sim = 8) и стирания (sim = 0x0020) фигуры
void print_erase_figure(int *mass, int number_figure, int number_position, int X, int Y, int sim)
{
    int dX, dY;
    switch (number_position)
    {
    case 1:
        dY = 0;
        for(int i = 0; i < Fi; ++i)
        {
            dX = 0;
            for(int j = 0; j < Fj; ++j)
            {
                if (mass[number_figure * Fi * Fj + Fi * i + j])
                    mvvline(Y + dY, X + dX, sim, 1);
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
                if (mass[number_figure * Fi * Fj + Fi * i + j])
                    mvvline(Y + dY, X + dX, sim, 1);
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
                if (mass[number_figure * Fi * Fj + Fi * i + j])
                    mvvline(Y + dY, X + dX, sim, 1);
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
                if (mass[number_figure * Fi * Fj + Fi * i + j])
                    mvvline(Y + dY, X + dX, sim, 1);
                ++dX;
            }
            ++dY;
        }

        break;
    }
};
