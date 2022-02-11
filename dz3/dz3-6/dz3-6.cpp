// Управляя стрелками сожрать цель
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
int main()
{
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD c = {6, 4};

//Рисуем границы игрового поля
   COORD c1 = {5, 3};
   SetConsoleCursorPosition (h, c1);

   printf("*");

   for (int i=1; i != 50; ++i)
       printf ("-");
   printf("*");

   COORD c2 = {5, 4};
   SetConsoleCursorPosition (h, c2);

   for (int i=1; i!= 30; ++i)
       {
       printf("|");
       c2.Y=c2.Y+1;
       SetConsoleCursorPosition (h, c2);
       }
    printf("*");

    for (int i=1; i != 50; ++i)
        printf ("-");
    printf("*");

    COORD c3 = {55, 4};
    SetConsoleCursorPosition (h, c3);
    for (int i=1; i!= 30; ++i)
        {
        printf("|");
        c3.Y=c3.Y+1;
        SetConsoleCursorPosition (h, c3);
        }
//задаем координаты цели
    //int X1, Y1;
    c1.X = rand() % 48 +6;
    c1.Y = rand() % 25 +4;
    //COORD c4 = (X1, Y1);
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

