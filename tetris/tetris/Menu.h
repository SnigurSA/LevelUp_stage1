#ifndef MENU_H
#define MENU_H

#include "State.h"

struct MenuPoint
{
    char name[255];
    State (*fun)();
};

struct Menu
{
    MenuPoint menu_point[2];
    int current_point;
};

void init_menu(Menu* menu);
void print_menu(Menu menu);
State move_menu(Menu* menu, int key);
void init_savemenu(Menu* menu);
void init_startmenu(Menu* menu);
void init_pausemenu(Menu* menu);
void init_gameovermenu(Menu* menu);
void erasesavefile(void);


#endif // MENU_H
