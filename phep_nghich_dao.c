#include <stdio.h>
#include <math.h>

int a, p;

void nhap()
{
    while (1)
    {
        printf("nhap so nguyen to cho p");
        printf("\nnhap p = ");
        scanf("%d", &p);
        int k = 0;
        for (int i = 2; i <= sqrt(ceil(p)); i++)
        {
            if (p % i == 0)
            {
                k = 1;
            }
        }
        if (k == 0)
            break;
    }

    printf("nhap a = ");
    scanf("%d", &a);
    nghich_dao();
}

void nghich_dao()
{
    int u, v, r, x1, x2, x, q;
    u = a;
    v = p;
    x1 = 1;
    x2 = 0;
    while (u != 1)
    {
        q = v / u;
        r = v - q * u;
        x = x2 - q * x1;

        v = u;
        u = r;
        x2 = x1;
        x1 = x;
        printf("\n q = %d, r = %d, x = %d, v = %d, u = %d, x2 = %d, x1 = %d", q, r, x, v, u, x2, x1);
    }
    printf("\n%d mod %d", x1, p);
    printf("\nx1 = %d", x1);
}

int main()
{
    nhap();
    return 0;
}