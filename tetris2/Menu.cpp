#include "Menu.h"

#include "key.h"
#include "state.h"
#include "record.h"

#include <string.h>
#include <curses.h>

int Np;
char filename[20] = {};

State main_menu()
{
    return MENU;
}

State start_menu()
{
    return STARTMENU;
}

State exit_from_game()
{
    return EXIT;
}

State start_game()
{
    return NEWGAME;
}

State save_game_quit()
{
    return SAVEMENU;
}

State save_quit()
{
    return SAVEQUIT;
}


State continue_game()
{
    return CONTGAME;
}

State none()
{
    return state;
}

State start_saved_game()
{
    return STARTSAVEGAME;
}
State player_name()
{
    return PLAYERNAME;
}

void init_menu(Menu* menu )
{
    strcpy(menu->menu_point[0].name, "Start game");
    menu->menu_point[0].fun = &player_name;

    strcpy(menu->menu_point[1].name, "Exit");
    menu->menu_point[1].fun = &exit_from_game;
    menu->current_point = 0;
}

void init_startmenu(Menu* menu )
{
    strcpy(menu->menu_point[0].name, "New game");
    menu->menu_point[0].fun = &start_game;

    strcpy(menu->menu_point[1].name, "Continue");
    menu->menu_point[1].fun = &start_saved_game;
    menu->current_point = 0;
}

void init_pausemenu(Menu* menu )
{
    strcpy(menu->menu_point[0].name, "Continue");
    menu->menu_point[0].fun = &continue_game;

    strcpy(menu->menu_point[1].name, "Quit");
    menu->menu_point[1].fun = &save_game_quit;
    menu->current_point = 0;
}

void init_savemenu(Menu* menu )
{
    strcpy(menu->menu_point[0].name, "Save and go to main menu");
    menu->menu_point[0].fun = &save_quit;

    strcpy(menu->menu_point[1].name, "Quit");
    menu->menu_point[1].fun = &exit_from_game;
    menu->current_point = 0;
}

void init_gameovermenu(Menu* menu )
{
    strcpy(menu->menu_point[0].name, "Start new game");
    menu->menu_point[0].fun = &start_game;

    strcpy(menu->menu_point[1].name, "Go to main menu");
    menu->menu_point[1].fun = &main_menu;
    menu->current_point = 0;
}


void print_menu(Menu menu)
{
    mvprintw(5, 5, menu.menu_point[0].name);
    mvprintw(6, 5, menu.menu_point[1].name);
    mvaddch(5 + menu.current_point, 4, '*');
}

State move_menu(Menu* menu, int key)
{
    mvaddch(5 + menu->current_point, 4, ' ');
    switch(key)
    {
    case MY_KEY_UP:
    case MY_KEY_DOWN:
        menu->current_point = menu->current_point == 0 ? 1 : 0;
        break;
    case MY_KEY_ENTER:
        return menu->menu_point[menu->current_point].fun();
    }
    return none();
}

void file_name(void)
{
    strcat(filename,NRnew.name);
    strcat(filename,".txt");
}

State playername(void)
{
    mvaddstr (2, 3, "Choose player");
    mvaddstr (3,4, "New player");
    for(int i = 0; i < m; i++)
    {
        move(4 + i,4);
        printw("%s", NR[i].name);
    }

    int Y = 3;
    mvaddch(Y, 3, '*');
    refresh();

    bool f = true;
    while(f)

    switch(getch())
    {
    case KEY_UP:
        mvaddch(Y, 3, ' ');
        Y == 3 ? Y = 3 + m : --Y;
        mvaddch(Y, 3, '*');
        break;
    case KEY_DOWN:
        mvaddch(Y, 3, ' ');
        Y == 3 + m ? Y = 3 : ++Y;
        mvaddch(Y, 3, '*');
        break;
    case 10:
        if (Y > 3)
        {
            Np = Y - 4;
            strcpy(NRnew.name, NR[Np].name);
            NRnew.rec = NR[Np].rec;
            clear();

        }
        else
        {
            clear();
            curs_set(1);
            echo();
            nocbreak();
            mvprintw(3, 3, "Enter your name: ");
            getstr(NRnew.name);
            noecho();
            NRnew.rec = 0;
            curs_set(0);
            cbreak();
            Np = m + 1;

            // еще  проверка совпадения имени нового игрока
            for(int i = 0; i < m; i++)
                if (strcmp(NR[i].name, NRnew.name) == 0)
                    Np = i;
        }
        f = false;
        break;
    }

   file_name();
   FILE* file;
   if ((file = fopen(filename,"r+")) != NULL)
       return STARTMENU;
   else
       return NEWGAME;
}
