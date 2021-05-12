#include <stdio.h>
#include <math.h>

int a, mu, n, t = 0;

void nhap()
{
    printf("nhap a = ");
    scanf("%d", &a);
    printf("nhap k = ");
    scanf("%d", &mu);
    printf("nhap n = ");
    scanf("%d", &n);
}

int *chuyen_nhi_phan(int x)
{
    static int mang[50];
    while (x != 0)
    {
        mang[t] = x % 2;
        x = x / 2;
        t++;
    }
    return mang;
}

void binh_phuong_co_lap()
{
    int *f;
    int w, bp, b = 1;
    int k[50];
    f = chuyen_nhi_phan(mu);
    for (int i = t - 1; i >= 0; i--)
    {
        k[t - 1 - i] = *(f + i);
    }
    for (int i = 0; i < t; i++)
    {
        bp = pow(b, 2);
        w = bp % n;
        if (k[i] == 1)
        {
            b = (a * w) % n;
            printf("\nb = %d, w = %d", b, w);
        }
        else if (k[i] == 0)
        {
            b = w;
        }
    }
    printf("\na^k mod n = %d", b);
}

int main()
{
    nhap();
    if (mu == 0)
    {
        printf("a^k mod n = %d", 1);
    }
    else if (mu != 0)
    {
        binh_phuong_co_lap();
    }
    return 0;
}