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
            cong_chinh_xac_boi(k);
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
            cong_chinh_xac_boi(k);
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

void cong_chinh_xac_boi(int k)
{
    int c[50], t;
    t = tinh_t();
    int tong, luythua, ep = 0;
    if (k == 1)
    {
        int *f, *g;
        f = bieu_dien_a(d);
        printf("\n");
        for (int i = 0; i < t; i++)
        {
            a[i] = *(f + i);
            // printf("%d, ", a[i]);
        }
        g = bieu_dien_a(e);
        for (int i = 0; i < t; i++)
        {
            b[i] = *(g + i);
        }
    }
    printf("\ncac he so va 'e' la");
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