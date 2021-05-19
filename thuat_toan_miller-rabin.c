#include <stdio.h>
#include <math.h>

int n = 0, o, t = 0, lan_lap = 0;

void nhap()
{
    while (n < 3)
    {
        printf("nhap n (>=3) = ");
        scanf("%d", &n);
    }

    while (lan_lap < 1)
    {
        printf("nhap t (>=1) = ");
        scanf("%d", &lan_lap);
    }
}

int tim_so_le_r(int x)
{
    int r;
    while (r % 2 == 0)
    {
        r = (x - 1) / 2;
    }
    return r;
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

int binh_phuong_co_lap(int a)
{
    int *f;
    int w, bp, b = 1;
    int k[50];
    f = chuyen_nhi_phan(n - 1);
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
        }
        else if (k[i] == 0)
        {
            b = w;
        }
    }
    return b;
}

int random(int min, int max)
{
    int tg;
    if (min > max)
    {
        tg = min;
        min = max;
        max = tg;
    }
    return min + rand() % (max + 1 - min);
}

int kt_so_nguyen_to()
{
    int r, s, a, y, bp;
    r = tim_so_le_r(n);
    s = log((n - 1) / r) / log(2);
    for (int i = 0; i <= lan_lap; i++)
    {
        a = random(2, n - 2);
        y = binh_phuong_co_lap(a);
        if (y != 1 && y != (n - 1))
        {
            int j = 1;
            while (j <= (s - 1) && y != (n - 1))
            {
                bp = pow(y, 2);
                y = bp % n;
                if (y == 1)
                {
                    printf("la hop so");
                    return 0;
                }
                j = j + 1;
            }
            if (y != n - 1)
            {
                printf("la hop so");
                return 0;
            }
        }
        if (i == lan_lap)
        {
            printf("la so nguyen to");
        }
    }
}

int main()
{
    nhap();
    o = kt_so_nguyen_to();
    return 0;
}