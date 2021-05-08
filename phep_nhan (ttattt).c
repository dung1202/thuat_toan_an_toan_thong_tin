#include <stdio.h>
#include <math.h>

int p, w, e, d ,mang[50];

void nhap()
{
    printf("nhap p = ");
    scanf("%d", &p);
    printf("nhap w = ");
    scanf("%d", &w);
    printf("nhap a = ");
    scanf("%d", &d);
    printf("nhap b = ");
    scanf("%d", &e);
}

int tinh_t()
{
    int t, m;
    m = (log(p) / log(2)) + 1;
    t = (m / w) + 1;
    return t;
}

void *bieu_dien_a(int a)
{
    int t, uoc;
    int j = 0;
    static int c[50];
    t = tinh_t();
    // printf("cac he so la");
    for (int i = t - 1; i >= 0; i--)
    {
        uoc = a / pow(2, i * w);
        a = a - (pow(2, i * w) * uoc);
        // printf("\nhe so thu %d = %d", j + 1, uoc);
        c[j] = uoc;
        j++;
    }
    return c;
}

void phep_nhan(d, e)
{
    int *f, *g;
    int a[50], b[50], c[100];
    int t, uv, u, v;
    t = tinh_t();
    f = bieu_dien_a(d);
    for (int i = 0; i <= t - 1; i++)
    {
        a[i] = *(f + (t - 1 - i));
        // printf("\na[%d] = %d", i, a[i]);
    }
    g = bieu_dien_a(e);
    for (int i = 0; i <= t - 1; i++)
    {
        b[i] = *(g + (t - 1 - i));
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
    for (int i = 0; i < 8; i++)
    {
        printf("\nc[%d] = %d", i, c[i]);
    }
}

void chuyen_co_so_nhi_phan(int x)
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
    phep_nhan(d, e);
    return 0;
}