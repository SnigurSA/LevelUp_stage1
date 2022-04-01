#include <curses.h>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

//#include"figure.h"
#include"field.h"
#include"key.h"
#include"game.h"
#include"state.h"
#include"Menu.h"

State state = MENU;

int main(void)
{
    srand(time(0));
    initscr();			//Инициализация curses
    curs_set(0);
    start_color();			//Включаем режим управления цветом

    keypad(stdscr, TRUE);		//Включаем режим чтения функциональных клавиш
    //noecho();
    halfdelay(1);         //Устанавливаем ограничение по времени ожидания getch() в 0.1 сек
    //nodelay(stdscr, TRUE);  //отменяем ожидание нажатия клавиши функцией getch()


    init_pair(1, COLOR_CYAN, COLOR_BLACK);  //задаем цветовую пару 1: фиолетовый символ, черный фон
    init_pair(2, COLOR_GREEN, COLOR_GREEN); //задаем цветовую пару 2: зеленый символ, зеленый фон
    init_pair(3, COLOR_MAGENTA, COLOR_MAGENTA); //задаем цветовую пару 3: MAGENTA символ, MAGENTA фон
    init_pair(4, COLOR_RED, COLOR_RED); //задаем цветовую пару 4: красный символ, красный фон
    init_pair(5, COLOR_YELLOW, COLOR_YELLOW); //задаем цветовую пару 5: желтый символ, желтый фон
    init_pair(6, COLOR_RED, COLOR_BLACK);//задаем цветовую пару 6: красный символ,черный фон

    Menu menu, startmenu, savemenu, pausemenu, gameover;

    init_menu(&menu);
    init_savemenu(&savemenu);
    init_startmenu(&startmenu);
    init_pausemenu(&pausemenu);
    init_gameovermenu(&gameover);



    State lastState = state;
    do
    {
        switch(state)
        {
        case MENU:
            print_menu(menu);
            state = move_menu(&menu, getch());
            break;
        case SAVEMENU:
            print_menu(savemenu);
            state = move_menu(&savemenu, getch());
            break;
        case STARTMENU:
            print_menu(startmenu);
            state = move_menu(&startmenu, getch());
            break;
        case PAUSEMENU:
            attron(COLOR_PAIR(1));
            mvaddstr (3, 5, "PAUSE");
            attroff(COLOR_PAIR(1));
            print_menu(pausemenu);
            state = move_menu(&pausemenu, getch());
            break;
        case NEWGAME:
            newgame(); //функция формирует текущее поле и фигуру из стандартных
            state = game();
            break;
        case CONTGAME:
            state = game();
            break;
        case STARTSAVEGAME:
            contgame(); // функция считывает из файла текущее поле и параметры текущей и следующей фигуры, счет и уровень
                        // если нет сохраненных данных начинается новая игра
            state = game();
            break;
        case GAMEOVER:
            attron(COLOR_PAIR(1));
            mvaddstr (2, 5, "GAME OVER");
            mvaddstr (3, 3, "All progress lost");
            attroff(COLOR_PAIR(1));
            refresh();
            erasesavefile();
            print_menu(gameover);
            state = move_menu(&gameover, getch());
            break;
        case SAVEQUIT:
            savegame(); //функция сохраняет текущее поле и парамметры текущей и следующей фигуры, счет и уровень
            exit(0);
            break;
        case EXIT:
            exit(0);
        }

        if (lastState != state)
        {
            clear();
            lastState = state;
        }


        refresh();
    }while(true);




    endwin();
}
