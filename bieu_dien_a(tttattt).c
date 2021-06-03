#include <stdio.h>
#include <math.h>

long long p, w, a;

void nhap()
{
    printf("nhap p = ");
    scanf("%lld", &p);
    printf("nhap w = ");
    scanf("%lld", &w);
    printf("nhap a = ");
    scanf("%lld", &a);
}

void bieu_dien_a()
{
    int m, t, uoc;
    int c[50];
    m = ceil(log(p) / log(2));
    t = ceil(m / w);
    int j = t - 1;
    // printf("m = %d, t = %d", m, t);
    printf("cac he so la");
    for (int i = t - 1; i >= 0; i--)
    {
        uoc = a / pow(2, i * w);
        a = a - (pow(2, i * w) * uoc);
        c[j] = uoc;
        printf("\na[%d] = %d", j, uoc);
        j--;
    }
}

int main()
{
    nhap();
    bieu_dien_a();
    return 0;
}