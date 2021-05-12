#include <stdio.h>
#include <math.h>

int a, b;

void nhap()
{
    printf("nhap a = ");
    scanf("%d", &a);
    printf("nhap b = ");
    scanf("%d", &b);
}

void tim_ucln()
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    printf("\nUCLN = %d", a);
}

int main()
{
    nhap();
    tim_ucln();
    return 0;
}