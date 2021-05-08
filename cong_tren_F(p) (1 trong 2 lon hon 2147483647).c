#include <stdio.h>
#include <math.h>

int p, w, x[50], y[50];

void nhap()
{
    printf("nhap p = ");
    scanf("%d", &p);
    printf("nhap w = ");
    scanf("%d", &w);
    int t;
    t = tinh_t();
    for (int i = t - 1; i >= 0; i--)
    {
        printf("\na[%d] = ", i);
        scanf("%d", &x[i]);
    }
    for (int i = t - 1; i >= 0; i--)
    {
        printf("\nb[%d] = ", i);
        scanf("%d", &y[i]);
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

void cong_tren_f_so_to(int x[], int y[])
{
    int tong, luythua, ep = 0;
    int t, so_c;
    int c[50];
    t = tinh_t();
    for (int i = 0; i <= t - 1; i++)
    {
        tong = x[i] + y[i] + ep;
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
        printf("\nc[%d] = %d, e = %d", i, c[i], ep);
    }
    c[t] = ep;

    //vi d > p va e > p => (d+e) > p
    tru_chinh_xac_boi_so_lon(c);
}

void tru_chinh_xac_boi_so_lon(int mangc[])
{
    int *f;
    int mangp[50], c[50];
    int t, hieu, luythua, ep = 0;
    t = tinh_t();
    f = bieu_dien_a(p);
    for (int i = 0; i < t; i++)
    {
        mangp[i] = *(f + i);
    }

    printf("\ncac he so va 'e' la");
    for (int i = t - 1; i >= 0; i--)
    {
        hieu = mangc[t - 1 - i] - mangp[i] - ep;
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
        printf("\nc[%d] = %d, e = %d", (t - 1) - i, c[i], ep);
    }
}

int main()
{
    nhap();
    cong_tren_f_so_to(x, y);
    return 0;
}