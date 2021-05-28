#include <stdio.h>
#include <math.h>
#include <string.h>

char t[1000], p[1000];
int f[1000] = {-1, 0};

void nhap()
{
    printf("nhap chuoi T = ");
    fgets(t, sizeof(t), stdin);

    printf("nhap chuoi P = ");
    fgets(p, sizeof(p), stdin);
    int kt, d;

    char t_to[1000] = {'a'}, h_to[1000] = {'a'};
    for (int j = 2; j < strlen(p) - 1; j++)
    {
        d = 0;
        // printf("\n\nj = %d", j);
        for (int i = 0; i < j; i++)
        {
            // printf("\n j - 1 - i = %d", j - 1 - i);
            if (j - 1 - i >= 1)
            {
                // printf("\ni = %d", i);
                t_to[i] = p[i];
                h_to[i] = p[j - 1 - i];
                // printf("\np[%d] = %c, p[%d] = %c", i, p[i], j - 1 - i, p[j - 1 - i]);
                // printf("\nt_to = %s, h_to = %s", t_to, h_to);
                kt = 0;
                for (int k = 0; k <= i; k++)
                {
                    if (t_to[k] == h_to[i - k])
                    {
                        kt++;
                    }
                    else
                    {
                        break;
                    }
                }
                // printf("\nkt = %d", kt);
                if (kt - 1 == i)
                {
                    d = i + 1;
                }
            }
        }
        // printf("\nd = %d", d);
        f[j] = d;
    }
    printf("\nF[] = ");
    for (int i = 0; i < (int)strlen(p) - 1; i++)
    {
        printf("%d, ", f[i]);
    }
}

int thuat_toan_KMP()
{
    int d = 0;
    int i = 0, j = 0;
    while (i < strlen(t) - 1)
    {
        while (j < strlen(p) - 1)
        {
            if (t[i + j] == p[j])
            {
                d++;
                j++;
            }
            else
            {

                i = i + j - f[j];
                if (f[j] == -1 || f[j] == 0)
                {
                    j = 0;
                    d = 0;
                }
                else
                {
                    j = f[j];
                    d = f[j] - 1;
                }
                break;
            }
            if (d == strlen(p) - 1)
            {
                printf("\nP co trong T bat dau tai vi tri %d", i);
                return 0;
            }
        }
    }
    printf("\np khong co trong t");
}

int main()
{
    nhap();
    thuat_toan_KMP();
    return 0;
}