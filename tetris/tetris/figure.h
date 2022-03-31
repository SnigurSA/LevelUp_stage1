#ifndef FIGURE_H
#define FIGURE_H

/*extern*/ const int Nf = 7, Fij = 4;
extern int Allfigures[Nf][Fij][Fij];

void print_figure(int *mass, int number_figure, int number_position, int X, int Y);
void erase_figure(int *mass, int number_figure, int number_position, int X, int Y);


#endif // FIGURE_H
