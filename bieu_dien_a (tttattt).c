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
    int b[50];
    int m, t, uoc, bieudien, j = 0;
    m = (log(p) / log(2)) + 1;
    t = (m / w) + 1;
    bieudien = a;
    printf("cac he so la");
    for (int i = t - 1; i >= 0; i--)
    {
        uoc = bieudien / pow(2, i * w);
        b[j] = uoc;
        bieudien = bieudien - (pow(2, i * w) * b[j]);
        printf("\nhe so thu %d = %d", j + 1, b[j]);
        j++;
    }
}

int main()
{
    nhap();
    bieu_dien_a(p, w, a);
    getchar();
    return 0;
}