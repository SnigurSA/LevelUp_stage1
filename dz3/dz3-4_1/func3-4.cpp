#include <stdio.h>
void func3_4(long long int n)
{
bool flag1 = 0;
long long int i;

for (int r = 63; r > 0; r--)
{
    i = 1;
    i <<= r;
    if (n & i)        // битовое И - в данном случае вернет 2^i - если i-ый бит 1
    {
        printf("1");
        flag1 = 1;

    }
    else
        if (flag1) // чтобы не печатать лишние нули слева
            printf("0");

}
}
