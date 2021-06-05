#include <stdio.h>
#include <math.h>

long long p, a;
int w;

void nhap()
{
    printf("nhap p = ");
    scanf("%lld", &p);
    printf("nhap w = ");
    scanf("%d", &w);
    printf("nhap a = ");
    scanf("%lld", &a);
}

void bieu_dien_a()
{
    int m, t, luythua;
    long long uoc;
    long long c[100];
    m = ceil(log(p) / log(2));
    t = ceil((float)m / w);
    int j = t - 1;
    // printf("m = %d, t = %d", m, t);
    printf("cac he so la");
    for (int i = t - 1; i >= 0; i--)
    {
        luythua = pow(2, i * w);
        uoc = a / luythua;
        a = a % luythua;
        c[j] = uoc;
        printf("\nc[%d] = %lld", j, c[j]);
        j--;
    }
}

int main()
{
    nhap();
    bieu_dien_a();
    return 0;
}