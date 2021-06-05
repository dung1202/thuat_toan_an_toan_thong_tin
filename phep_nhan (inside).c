#include <stdio.h>
#include <math.h>

int w;
long long p, d, e, a[100], b[100], mang[221];

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
            phep_nhan(k);
            break;
        }
        else if (k == 2)
        {
            int t;
            t = tinh_t();
            printf("\nnhap mang cua a\n");
            for (int i = t - 1; i >= 0; i--)
            {
                printf("a[%d] = ", i);
                scanf("%lld", &a[i]);
            }
            printf("\nnhap mang cua b\n");
            for (int i = t - 1; i >= 0; i--)
            {
                printf("b[%d] = ", i);
                scanf("%lld", &b[i]);
            }
            phep_nhan(k);
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

void phep_nhan(k)
{
    long long c[100], uv, luythua;
    luythua = pow(2, w);
    int t, u, v;
    t = tinh_t();
    if (k == 1)
    {
        long long *f, *g;
        f = bieu_dien_a(d);
        for (int i = 0; i <= t - 1; i++)
        {
            a[i] = *(f + i);
            // printf("\na[%d] = %d", i, a[i]);
        }
        g = bieu_dien_a(e);
        for (int i = 0; i <= t - 1; i++)
        {
            b[i] = *(g + i);
        }
    }
    for (int i = 0; i <= (2 * t) - 1; i++)
    {
        c[i] = 0;
    }
    // ==========================================

    for (int i = 0; i <= t - 1; i++)
    {
        u = 0;
        for (int j = 0; j <= t - 1; j++)
        {
            uv = c[i + j] + a[i] * b[j] + u;
            chuyen_co_so_nhi_phan(uv);
            u = mang[0];
            v = mang[1];
            c[i + j] = v;
            // printf("\nc[%d] = %d, u = %d, v=%d", i+j, c[i+j], u, v);
        }
        c[i + t] = u;
    }
    for (int i = 0; i < w; i++)
    {
        printf("\nc[%d] = %lld", i, c[i]);
    }
}

void chuyen_co_so_nhi_phan(long long x)
{
    int u[50], v[50];
    int j = 0;
    for (int i = 0; i < w; i++)
    {
        v[i] = 0;
        u[i] = 0;
        if (i < 2)
        {
            mang[i] = 0;
        }
    }
    int i = (2 * w) - 1;
    while (x != 0)
    {
        if ((x % 2) == 1)
        {
            if (i > w - 1)
            {
                v[i - w] = 1;
            }
            else
            {
                u[i] = 1;
            }
        }
        x = x / 2;
        i--;
    }
    for (int i = w - 1; i >= 0; i--)
    {
        mang[0] = mang[0] + u[i] * pow(2, j);
        mang[1] = mang[1] + v[i] * pow(2, j);
        // printf("\n u = %d,  v = %d", u[i], v[i]);
        j++;
    }
    // printf("\n u = %d,  v = %d", mang[0], mang[1]);
}

int main()
{
    nhap();
    return 0;
}