#include <stdio.h>
#include <math.h>

int n;

void nhap()
{
    printf("nhap n = ");
    scanf("%d", &n);
}

void tim_so_nguyen_to_phan_doan()
{
    int a[1000];
    int phan_tu, so_phan_doan;
    phan_tu = sqrt(n) - 1;
    if ((n - 1) % phan_tu == 0)
    {
        so_phan_doan = (n / phan_tu);
    }
    else
    {
        so_phan_doan = (n / phan_tu) + 1;
    }
    for (int i = 2; i <= n; i++)
    {
        a[i] = 1;
    }

    for (int k = 0; k < so_phan_doan; k++)
    {
        printf("\n");
        for (int i = (k * phan_tu) + 2; i < ((k + 1) * phan_tu) + 2; i++)
        {
            if (i <= n)
            {
                for (int j = 2; j < ((k + 1) * phan_tu) + 2; j++)
                {
                    if (a[j] == 1 && i != j)
                    {
                        if (i % j == 0)
                        {
                            a[i] = 0;
                            break;
                        }
                    }
                }
            }
            else
            {
                break;
            }
        }
        for (int i = (k * phan_tu) + 2; i < ((k + 1) * phan_tu) + 2; i++)
        {
            if (a[i] == 1)
            {
                printf("%d ", i);
            }
            else if (a[i] == 0)
            {
                printf("_ ");
            }
        }
    }

    // printf("cac so nguyen to la ");
    // for (int i = 2; i <= n; i++)
    // {
    //     if (a[i] == 1)
    //     {
    //         printf("%d ", i);
    //     }
    // }
}

int main()
{
    nhap();
    tim_so_nguyen_to_phan_doan();
    return 0;
}