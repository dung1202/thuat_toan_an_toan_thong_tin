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
            tru_tren_f(k);
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
            tru_tren_f(k);
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
int *bieu_dien_a(a)
{
    static int mang[50];
    int t;
    t = tinh_t();
    int uoc, bieudien, j = t - 1;
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

int *tru_chinh_xac_boi(k)
{
    static int c[50];
    int t, hieu, luythua, ep = 0;
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
        hieu = a[i] - b[i] - ep;
        luythua = pow(2, w);
        if (hieu <= 0)
        {
            c[i] = luythua + hieu;
            ep = 1;
        }
        else
        {
            ep = 0;
            c[i] = hieu;
        }
        // printf("\nc[%d] = %d, e = %d", i, c[i], ep);
    }
    c[t] = ep;
    return c;
}
void tru_tren_f(k)
{
    int *f;
    int t;
    int c[50];
    t = tinh_t();
    f = tru_chinh_xac_boi(k);
    for (int i = 0; i <= t; i++)
    {
        c[i] = *(f + i);
        // printf("\nc[%d] = %d", i, c[i]);
        if (i == t)
        {
            c[i] = *(f + t);
        }
    }
    if (c[t] == 0)
    {
        for (int i = 0; i <= t - 1; i++)
        {
            printf("\nc[%d] = %d", i, c[i]);
        }
        printf("\n'e' = %d", c[t]);
    }
    else if (c[t] == 1)
    {
        cong_chinh_xac_boi(c);
    }
}

void cong_chinh_xac_boi(int a[])
{
    int *g;
    int b[50];
    static int c[50];
    int t, tong, luythua, ep = 0;
    t = tinh_t();
    g = bieu_dien_a(p);
    for (int i = 0; i < t; i++)
    {
        b[i] = *(g + i);
        printf("\nb[%d] = %d, a[%d] = %d", i, b[i], i, a[i]);
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
        printf("\nc[%d] = %d, e = %d", i, c[i], ep);
    }
}

int main()
{
    nhap();
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("\n*(p + %d) : %d", i, *(q + i)); // lấy giá trị q[i] = *(q + i)
    // }
    return 0;
}