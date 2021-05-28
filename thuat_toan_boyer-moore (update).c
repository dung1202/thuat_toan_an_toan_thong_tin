#include <stdio.h>
#include <math.h>
#include <string.h>

char t[1000], p[1000];
int l[127];

void nhap()
{
    printf("nhap chuoi T = ");
    fgets(t, sizeof(t), stdin);

    printf("nhap chuoi P = ");
    fgets(p, sizeof(p), stdin);

    for (int i = 0; i < 127; i++)
    {
        l[i] = -1;
    }
    for (int i = 0; i < (int)strlen(t) - 1; i++)
    {
        l[(int)t[i]] = i;
    }
    printf("\n");
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
            int min;
            if (j > 1 + l[(int)t[i]])
            {
                min = 1 + l[(int)t[i]];
            }
            else
            {
                min = j;
            }
            cong_them = (strlen(p) - 1) - min;
        }
        if (d == (int)strlen(p) - 1)
        {
            printf("\nP co trong T bau dau tai vi tri %d", i + 1);
            return 0;
        }
    }
    printf("\nP khong co trong T");
}
int main()
{
    nhap();
    kiem_tra_p();
    getchar();
    return 0;
}