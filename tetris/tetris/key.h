#ifndef KEY_H
#define KEY_H

#include <curses.h>

enum KEY
{
    MY_KEY_UP = KEY_UP,
    MY_KEY_DOWN = KEY_DOWN,
    MY_KEY_LEFT = KEY_LEFT,
    MY_KEY_RIGHT = KEY_RIGHT,
    MY_KEY_ENTER = 10,
    MY_KEY_ESC = 27,
    MY_KEY_SPACE = 32
};

#endif // KEY_H
