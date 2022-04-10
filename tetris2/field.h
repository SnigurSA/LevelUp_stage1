#ifndef FIELD_H
#define FIELD_H

extern int Start_Field[22][12], Curent_Field[22][12], check[4];
extern int H, W;
extern int Xfo, Yfo;

void print_field(int *mass);
bool intercept(int *field, int *figure, int number_figure, int number_position, int X, int Y);
void summ_field(int *field, int *figure, int number_figure, int number_position, int X, int Y);
int check_field(int *field, int check[]);
void crash_lines(int *field, int *check, int K);

#endif // FIELD_H
