#include <iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
    int b, d;
    float a, c;
    a = 5.0;
    c = 5.0;
    printf("c=%f\n",c);
    printf("a=%f\n",a);

    printf("Enter b=");
      scanf("%d", &b);
    printf("Enter d=");
      scanf("%d", &d);
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);

    a = a + b - 2;
    cout << "count a=a+b-2:";
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);

    c = c + 1;
    cout << "count c=c+1:";
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);

    d = c - a + d;
    cout << "count d=c-a+d:";
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);

    a = a * c;
    cout << "count a=a*c:";
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);

    c = c - 1;
    cout << "count c=c-1:";
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);

    a = a / 10;
    cout << "count a=a/10:";
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);

    c = c / 2;
    cout << "count c=c/2:";
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);

    b = b - 1;
    cout << "count b=b-1:";
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);

    d = d *(c + b + a);
    cout << "count d=d*(c+b+a):";
    printf(" a = %f b = %d c = %f d = %d\n ", a, b, c, d);


    return 0;
}

