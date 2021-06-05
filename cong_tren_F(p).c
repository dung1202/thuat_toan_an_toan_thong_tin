#include <stdio.h>
#include <math.h>

int w;
long long p, d, e, a[100], b[100];

void nhap()
{
    int k;
    printf("nhap p = ");
    scanf("%lld", &p);
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
            scanf("%lld", &d);
            printf("nhap b = ");
            scanf("%lld", &e);
            cong_tren_F(k);
            break;
        }
        else if (k == 2)
        {
            int t;
            t = tinh_t();
            printf("\nnhap mang cua a\n");
            for (int i = t - 1; i >= 0; i--)
            {
                printf("\na[%d] = ", i);
                scanf("%lld", &a[i]);
            }
            printf("\nnhap mang cua b\n");
            for (int i = t - 1; i >= 0; i--)
            {
                printf("\nb[%d] = ", i);
                scanf("%lld", &b[i]);
            }
            cong_tren_F(k);
            break;
        }
    }
}

int tinh_t()
{
    int t, m;
    m = ceil(log(p) / log(2));
    t = ceil((float)m / w);
    return t;
}
long long *bieu_dien_a(long long a)
{
    static long long mang[100];
    int t;
    t = tinh_t();
    long long uoc, luythua;
    int j = t - 1;
    // printf("cac he so la");
    for (int i = t - 1; i >= 0; i--)
    {
        luythua = pow(2, i * w);
        uoc = a / luythua;
        a = a % luythua;
        mang[j] = uoc;
        // printf("\nhe so thu %d = %d,  %d", j + 1, uoc, mang[j]);
        j--;
    }
    return mang;
}

long long *cong_chinh_xac_boi(int k)
{
    static long long c[50];
    int t, ep = 0;
    long long luythua, tong;
    t = tinh_t();
    if (k == 1)
    {
        long long *f, *g;
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
        if (tong >= pow(2, w))
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

void tru_chinh_xac_boi(long long a[], long long p)
{
    long long *f, hieu, luythua;
    long long c[100];
    int t, ep = 0;
    t = tinh_t();
    f = bieu_dien_a(p);
    for (int i = 0; i < t; i++)
    {
        b[i] = *(f + i);
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
        printf("\nc[%d] = %lld, e = %d", i, c[i], ep);
    }
}

long long so_chinh_xac(long long c[])
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
    long long *f, c[100];
    int t;
    long long so_c;
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
                printf("\nc[%d] = %lld", i, c[i]);
            }
            printf("\nso 'e' = %lld", c[t]);
        }
        else
        {
            tru_chinh_xac_boi(c, p);
        }
    }
    else if (c[t] == 1)
    {
        tru_chinh_xac_boi(c, p);
    }
}

int main()
{
    nhap();
    return 0;
}