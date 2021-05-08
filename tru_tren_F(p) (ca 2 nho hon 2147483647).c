#include <stdio.h>
#include <math.h>

int p, w, e, d;

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
int *bieu_dien_a(a)
{
    static int mang[50];
    int t, uoc, bieudien, j = 0;
    bieudien = a;
    t = tinh_t();
    // printf("cac he so la");
    for (int i = t - 1; i >= 0; i--)
    {
        uoc = bieudien / pow(2, i * w);
        bieudien = bieudien - (pow(2, i * w) * uoc);
        mang[j] = uoc;
        // printf("\nhe so thu %d = %d,  %d", j + 1, uoc, mang[j]);
        j++;
    }
    return mang;
}

int *tru_chinh_xac_boi(d, e)
{
    int *f, *g;
    int a[50], b[50];
    static int c[50];
    int t, hieu, luythua, ep = 0;
    t = tinh_t();
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
    // printf("\ncac he so va 'e' la");
    for (int i = t - 1; i >= 0; i--)
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
        // printf("\nc[%d] = %d, e = %d", (t - 1) - i, c[i], ep);
    }
    c[t] = ep;
    return c;
}
void tru_tren_f(d, e)
{
    int *f;
    int t;
    int c[50];
    t = tinh_t();
    f = tru_chinh_xac_boi(d, e);
    for (int i = 0; i <= t; i++)
    {
        c[i] = *(f + (t - i - 1));
        // printf("\nc[%d] = %d", i, c[i]);
        if (i == t)
        {
            c[i] = *(f + t);
        }
    }
    if (c[t] == 0)
    {
        for (int i = 0; i <= t-1; i++)
        {
            printf("\nc[%d] = %d", i, c[i]);
        }
        printf("'e' = %d", c[t]);
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
    static c[50];
    int t, tong, luythua, ep = 0;
    t = tinh_t();
    g = bieu_dien_a(p);
    for (int i = 0; i < t; i++)
    {
        b[i] = *(g + i);
    }
    // printf("\ncac he so va 'e' la");
    for (int i = t - 1; i >= 0; i--)
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
        printf("\nc[%d] = %d, e = %d", (t-1)-i, c[i], ep);
    }
}

int main()
{
    nhap();
    tru_tren_f(d, e);
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("\n*(p + %d) : %d", i, *(q + i)); // lấy giá trị q[i] = *(q + i)
    // }
    return 0;
}