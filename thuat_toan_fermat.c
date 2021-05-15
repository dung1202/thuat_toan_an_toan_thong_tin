#include <stdio.h>
#include <math.h>

int n = 0, t = 0, lan_lap = 0;

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

void kiem_tra_nguyen_to()
{
    int a, r;
    for (int i = 1; i <= lan_lap; i++)
    {
        a = random(2, n - 2);
        printf("\na = %d", a);
        r = binh_phuong_co_lap(a);
        printf("\nr = %d", r);
        if (r == 1)
        {
            printf("\nla so nguyen to");
            break;
        }
        if (r != 1 && i == lan_lap)
        {
            printf("\nla hop so");
        }
    }
}

int main()
{
    nhap();
    kiem_tra_nguyen_to();
    return 0;
}