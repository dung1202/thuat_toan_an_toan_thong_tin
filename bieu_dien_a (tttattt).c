#include <stdio.h>
#include <math.h>

int p, w, a;

void nhap()
{
    printf("nhap p = ");
    scanf("%d", &p);
    printf("nhap w = ");
    scanf("%d", &w);
    printf("nhap a = ");
    scanf("%d", &a);
}

void bieu_dien_a(p, w, a)
{
    int m, t, uoc;
    int j = 0;
    m = (log(p) / log(2)) + 1;
    t = (m / w) + 1;
    // printf("m = %d, t = %d", m, t);
    printf("cac he so la");
    for (int i = t - 1; i >= 0; i--)
    {
        uoc = a / pow(2, i * w);
        a = a - (pow(2, i * w) * uoc);
        printf("\nhe so thu %d = %d", j + 1, uoc);
        j++;
    }
}

int main()
{
    nhap();
    bieu_dien_a(p, w, a);
    return 0;
}
