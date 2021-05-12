#include <stdio.h>
#include <math.h>

int c, d;

void nhap()
{
    printf("nhap a = ");
    scanf("%d", &c);
    printf("nhap b = ");
    scanf("%d", &d);
}

void euclide()
{
    int a, b, r, q, x, y, x1, x2, y1, y2;
    if (d == 0)
    {
        printf("\n(d, x, y) = (%d, %d, %d)", c, 1, 0);
    }
    if (c >= d)
    {
        x2 = 1;
        x1 = 0;
        y2 = 0;
        y1 = 1;

        a = c;
        b = d;
    }
    else 
    {
        x2 = 1;
        x1 = 0;
        y2 = 0;
        y1 = 1;

        a = d;
        b = c;
    }
    printf("a = %d, b = %d", a, b);
    while (b != 0)
    {
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    printf("\n(d, x, y) = (%d, %d, %d)", a, x2, y2);
}

int main()
{
    nhap();
    euclide();
    return 0;
}