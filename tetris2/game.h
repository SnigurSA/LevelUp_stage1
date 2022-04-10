#ifndef GAME_H
#define GAME_H

#include "state.h"

extern int position, next_position, current_f, next_f, ds, score, level;

int dscore(int K);
bool level_up(int score, int* level);
void newgame(void);
void savegame(void);
void nosavinggame(void);
void contgame(void);
void erasesavefile(void);

State game(void);

#endif // GAME_H
