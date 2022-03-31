#include "Menu.h"

#include "key.h"
#include "state.h"

#include <string.h>
#include <curses.h>

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

void init_menu(Menu* menu )
{
    strcpy(menu->menu_point[0].name, "Start game");
    menu->menu_point[0].fun = &start_menu;

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
    strcpy(menu->menu_point[0].name, "Save and Quit");
    menu->menu_point[0].fun = &save_quit;

    strcpy(menu->menu_point[1].name, "Quit");
    menu->menu_point[1].fun = &exit_from_game;
    menu->current_point = 0;
}

void init_gameovermenu(Menu* menu )
{
    strcpy(menu->menu_point[0].name, "Start new game");
    menu->menu_point[0].fun = &start_game;

    strcpy(menu->menu_point[1].name, "Quit");
    menu->menu_point[1].fun = &exit_from_game;
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
void erasesavefile(void)
{
    FILE* file;
    file = fopen("tetris.txt", "w");
    fprintf(file, "%d\n", 0);
    fclose(file);
}
