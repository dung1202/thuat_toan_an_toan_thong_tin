#include <stdio.h>
#include <math.h>

char t[1000], p[1000];

void nhap()
{
    printf("nhap chuoi T = ");
    scanf("%s", &t);

    printf("nhap chuoi P = ");
    scanf("%s", &p);
}

int kiem_tra_p()
{
    int d = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        d = 0;
        for (int j = 0; j < strlen(p); j++)
        {
            if (t[i + j] == p[j])
            {
                d++;
            }
        }
        if (d == (int)(strlen(p)))
        {
            printf("bat dau tu vi tri %d", i + 1);
            break;
        }
        else if (i == (int)(strlen(t) - 1) && d < (int)(strlen(p)))
        {
            printf("P ko co trong T");
        }
    }
}
int main()
{
    nhap();
    kiem_tra_p();
    return 0;
}