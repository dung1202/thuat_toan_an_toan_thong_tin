#include <stdio.h>
#include <math.h>

int n;

void nhap()
{
    printf("nhap n = ");
    scanf("%d", &n);
}

void tim_so_nguyen_to()
{
    int a[1000];

    for (int i = 2; i <= n; i++)
    {
        a[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 1)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (j % i == 0)
                {
                    a[j] = 0;
                }
            }
        }
    }
    printf("cac so nguyen to la ");
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 1)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    nhap();
    tim_so_nguyen_to();
    return 0;
}