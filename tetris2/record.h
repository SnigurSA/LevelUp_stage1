#ifndef RECORD_H
#define RECORD_H

#include<stdio.h>

#include "State.h"
#include "Menu.h"

struct namerec
{
    char name[15];
    int rec;
};

extern namerec NR[10], NRnew;
extern int m;

void print_recordlist(void);
void resaverecordlist(void);

#endif // RECORD_H
