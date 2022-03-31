#include<curses.h>

const int Nf = 7, Fij = 4;

int Allfigures[Nf][Fij][Fij] ={{{0,1,0,0},
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


void print_figure(int *mass, int number_figure, int number_position, int X, int Y)
{
    int dX, dY;
    switch (number_position)
    {
    case 1:
        dY = 0;
        for(int i = 0; i < Fij; ++i)
        {
            dX = 0;
            for(int j = 0; j < Fij; ++j)
            {
                if (mass[number_figure * 16 + 4 * i + j])
                {
                    mvvline(Y + dY, X + dX, 8, 1);
                }
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
                if (mass[number_figure * 16 + 4 * i + j])
                {
                    mvvline(Y + dY, X + dX, 8, 1);
                }
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
                if (mass[number_figure * 16 + 4 * i + j])
                {
                    mvvline(Y + dY, X + dX, 8, 1);
                }
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
                if (mass[number_figure * 16 + 4 * i + j])
                {
                    mvvline(Y + dY, X + dX, 8, 1);
                }
                ++dX;
            }
            ++dY;
        }

        break;

    }
};

void erase_figure(int *mass, int number_figure, int number_position, int X, int Y)
{
    int dX, dY;
    switch (number_position)
    {
    case 1:
        dY = 0;
        for(int i = 0; i < Fij; ++i)
        {
            dX = 0;
            for(int j = 0; j < Fij; ++j)
            {
                if (mass[number_figure * 16 + 4 * i + j])
                    mvvline(Y + dY, X + dX, 0x0020, 1);
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
                if (mass[number_figure * 16 + 4 * i + j])
                    mvvline(Y + dY, X + dX, 0x0020, 1);
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
                if (mass[number_figure * 16 + 4 * i + j])
                    mvvline(Y + dY, X + dX, 0x0020, 1);
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
                if (mass[number_figure * 16 + 4 * i + j])
                    mvvline(Y + dY, X + dX, 0x0020, 1);
                ++dX;
            }
            ++dY;
        }

        break;

    }
};
