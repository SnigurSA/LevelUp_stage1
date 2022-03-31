#ifndef STATE_H
#define STATE_H

enum State
{
    NEWGAME,
    STARTSAVEGAME,
    CONTGAME,
    MENU,
    STARTMENU,
    PAUSEMENU,
    SAVEMENU,
    GAMEOVER,
    SAVEQUIT,
    EXIT
};

extern State state;

#endif // STATE_H
