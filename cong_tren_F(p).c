#include <stdio.h>
#include <math.h>

int p, w, e, d, a[50], b[50];

void nhap()
{
    int k;
    printf("nhap p = ");
    scanf("%d", &p);
    printf("nhap w = ");
    scanf("%d", &w);

    while (1)
    {
        printf("\n\nban muon nhap nhu the nao??");
        printf("\nchon 1 hoac 2");
        printf("\n1. nhap so");
        printf("\n2. nhap mang");
        printf("\nban chon = ");
        scanf("%d", &k);

        if (k == 1)
        {
            printf("nhap a = ");
            scanf("%d", &d);
            printf("nhap b = ");
            scanf("%d", &e);
            cong_tren_F(k);
            break;
        }
        else if (k == 2)
        {
            int t;
            t = tinh_t();
            for (int i = t - 1; i >= 0; i--)
            {
                printf("\na[%d] = ", i);
                scanf("%d", &a[i]);
            }
            for (int i = t - 1; i >= 0; i--)
            {
                printf("\nb[%d] = ", i);
                scanf("%d", &b[i]);
            }
            cong_tren_F(k);
            break;
        }
    }
}

int tinh_t()
{
    int t, m;
    m = (log(p) / log(2)) + 1;
    t = (m / w) + 1;
    return t;
}
int *bieu_dien_a(long long a)
{
    static int mang[50];
    int t;
    t = tinh_t();
    int j = t - 1;
    long long uoc, bieudien;
    bieudien = a;
    // printf("cac he so la");
    for (int i = t - 1; i >= 0; i--)
    {
        uoc = bieudien / pow(2, i * w);
        bieudien = bieudien - (pow(2, i * w) * uoc);
        mang[j] = uoc;
        // printf("\nhe so thu %d = %d,  %d", j + 1, uoc, mang[j]);
        j--;
    }
    return mang;
}

int *cong_chinh_xac_boi(k)
{
    static int c[50];
    int t, tong, luythua, ep = 0;
    t = tinh_t();
    if (k == 1)
    {
        int *f, *g;
        f = bieu_dien_a(d);
        for (int i = 0; i < t; i++)
        {
            a[i] = *(f + i);
        }
        g = bieu_dien_a(e);
        for (int i = 0; i < t; i++)
        {
            b[i] = *(g + i);
        }
    }
    // printf("\ncac he so va 'e' la");
    for (int i = 0; i <= t - 1; i++)
    {
        tong = a[i] + b[i] + ep;
        luythua = pow(2, w);
        if (tong > pow(2, w))
        {
            c[i] = tong % luythua;
            ep = 1;
        }
        else
        {
            ep = 0;
            c[i] = tong;
        }
        // printf("\nc[%d] = %d, e = %d", i, c[i], ep);
    }
    c[t] = ep;
    return c;
}

void tru_chinh_xac_boi(long long so_c, int p)
{
    int *f, *g;
    int c[50];
    int t, hieu, luythua, ep = 0;
    t = tinh_t();
    f = bieu_dien_a(so_c);
    for (int i = 0; i < t; i++)
    {
        a[i] = *(f + i);
    }
    g = bieu_dien_a(p);
    for (int i = 0; i < t; i++)
    {
        b[i] = *(g + i);
    }
    printf("\ncac he so va 'e' la");
    for (int i = 0; i <= t - 1; i++)
    {
        hieu = a[i] - b[i] - ep;
        luythua = pow(2, w);
        if (hieu < 0)
        {
            c[i] = luythua + hieu;
            ep = 1;
        }
        else
        {
            ep = 0;
            c[i] = hieu;
        }
        printf("\nc[%d] = %d, e = %d", i, c[i], ep);
    }
}

long long so_chinh_xac(int c[])
{
    int t;
    long long tong = 0;
    t = tinh_t();
    // printf("\nt =%d", t);
    for (int i = 0; i <= t - 1; i++)
    {
        tong = tong + c[i] * pow(2, i * w);
        // printf("\nc[%d] = %d", i, c[i]);
    }
    printf("\n so_c = %lld", tong);
    return tong;
}

void cong_tren_F(k)
{
    int *f;
    int t;
    long long so_c;
    int c[50];
    t = tinh_t();
    f = cong_chinh_xac_boi(k);
    for (int i = 0; i <= t; i++)
    {
        c[i] = *(f + i);
        // printf("\nc[%d] = %d", i, c[i]);
    }
    // printf("c[%d] = %d", t, c[t]);
    so_c = so_chinh_xac(c);
    // printf("\n so_c = %lld", p - so_c);
    if (c[t] == 0)
    {
        if (so_c < p)
        {
            for (int i = 0; i <= t - 1; i++)
            {
                printf("\nc[%d] = %d", i, c[i]);
            }
            printf("\nso 'e' = %d", c[t]);
        }
        else
        {
            tru_chinh_xac_boi(so_c, p);
        }
    }
    else if (c[t] == 1)
    {
        tru_chinh_xac_boi(so_c, p);
    }
}

int main()
{
    nhap();
    return 0;
}