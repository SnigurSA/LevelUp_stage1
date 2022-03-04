// Управляя стрелками сожрать цель
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;
int main()
{
    srand(time(0));
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD c, c1;

//Рисуем границы игрового поля
   c.X = 5;
   c.Y = 3;
   SetConsoleCursorPosition (h, c);

   printf("*");

   for (int i=1; i != 50; ++i)
       printf ("-");
   printf("*");

   c.X = 5;
   c.Y = 4;
   SetConsoleCursorPosition (h, c);

   for (int i=1; i!= 30; ++i)
       {
       printf("|");
       c.Y=c.Y+1;
       SetConsoleCursorPosition (h, c);
       }
    printf("*");

    for (int i=1; i != 50; ++i)
        printf ("-");
    printf("*");

    c.X = 55;
    c.Y = 4;
    SetConsoleCursorPosition (h, c);
    for (int i=1; i!= 30; ++i)
        {
        printf("|");
        c.Y=c.Y+1;
        SetConsoleCursorPosition (h, c);
        }
//задаем координаты цели
    c1.X = rand() % 48 +6;
    c1.Y = rand() % 25 +4;

    SetConsoleCursorPosition (h, c1);
    printf("0");

    c.X = rand() % 10 +6;
    c.Y = rand() % 10 +4;
    SetConsoleCursorPosition (h, c);
    cout<<char(1);
    while (true) //((c.Y == c1.Y) && (c.X == c1.X))
       {
        SetConsoleCursorPosition (h, c);
            int k = getch();
            if (k==0||k==224)  k = getch();
                switch(k)
                {
                case 72:
                    if (c.Y > 4)
                      {
                         printf(" ");
                         c.Y=c.Y-1;
                         SetConsoleCursorPosition(h, c);
                         cout<<char(1);
                       }
                    break;
                case 75:
                    if (c.X > 6)
                       {
                          printf(" ");
                          c.X=c.X-1;
                          SetConsoleCursorPosition(h, c);
                          cout<<char(1);
                       }
                    break;
                case 77:
                    if (c.X < 54)
                        {
                            printf(" ");
                            c.X=c.X+1;
                            SetConsoleCursorPosition(h, c);
                            cout<<char(1);
                        }
                    break;
                case 80:
                    if (c.Y < 32)
                        {
                           printf(" ");
                           c.Y=c.Y+1;
                           SetConsoleCursorPosition(h, c);
                           cout<<char(1);
                        }
                    break;
                default: return 0;

                }
            if ((c.Y == c1.Y) && (c.X == c1.X))
                break;

       }
    c.X = 20;
    c.Y = 15;
    SetConsoleCursorPosition(h, c);
    printf ("YOU WIN");
  }

