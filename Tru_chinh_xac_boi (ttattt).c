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
        printf("\nban muon nhap nhu the nao??");
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
            tru_chinh_xac_boi(k);
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
            tru_chinh_xac_boi(k);
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
    static long long mang[50];
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

void tru_chinh_xac_boi(int k)
{
    long long c[100], luythua;
    int t, hieu, ep = 0;
    t = tinh_t();

    if (k == 1)
    {
        long long *f, *g;
        f = bieu_dien_a(d);
        for (int i = 0; i < t; i++)
        {
            a[i] = *(f + i);
            // printf("%d, ", a[i]);
        }
        g = bieu_dien_a(e);
        for (int i = 0; i < t; i++)
        {
            b[i] = *(g + i);
            // printf("%d, ", b[i]);
        }
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

int main()
{
    nhap();
    return 0;
}