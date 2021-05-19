#include <stdio.h>
#include <math.h>

char t[1000], p[1000];

void nhap()
{
    printf("nhap chuoi T = ");
    fgets(t, sizeof(t), stdin);

    printf("nhap chuoi P = ");
    fgets(p, sizeof(p), stdin);
}

int kiem_tra_p()
{
    int d = 0;
    int j = strlen(p) - 2, cong_them = 0, i = strlen(p) - 2;
    // printf("%d = leng P,   %d = leng T", strlen(p), strlen(t));
    while (i < strlen(t))
    {
        if (cong_them != 0)
        {
            d = 0;
            i = i + cong_them;
            j = strlen(p) - 2;
        }
        // printf("\nt[%d] = %c    p[%d] = %c", i, t[i], j, p[j]);
        if (t[i] == p[j])
        {
            i--;
            j--;
            d++;
            cong_them = 0;
        }
        else
        {
            for (int k = j - 1; k >= 0; k--)
            {
                if (t[i] == p[k])
                {
                    cong_them = strlen(p) - (k + 1) - 1;
                    break;
                }
                else if (k == 0)
                {
                    cong_them = strlen(p) - 1;
                    break;
                }
            }
        }
        if (d == (int)strlen(p) - 1)
        {
            printf("\nP co trong T tai vi tri %d", i + 2);
            return 0;
        }
    }
    printf("\nP khong co trong T");
}
int main()
{
    nhap();
    kiem_tra_p();
    return 0;
}