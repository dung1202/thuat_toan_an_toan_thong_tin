#include <stdio.h>
#include <math.h>

int n;

void nhap()
{
    printf("nhap n = ");
    scanf("%d", &n);
}

int tim_ucln(a, b)
{
    int r;
    if (a < b)
    {
        r = a;
        a = b;
        b = r;
    }
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void thua_so_khong_tam_thuong()
{
    int a = 2, b = 2, i = 1;
    int d, bp_a, bp_b;
    while (1)
    {
        bp_a = pow(a, 2);
        a = (bp_a + i) % n;

        bp_b = pow(b, 2);
        b = (bp_b + i) % n;
        // lan 2
        bp_b = pow(b, 2);
        b = (bp_b + i) % n;

        d = tim_ucln(a - b, n);
        if (d > 1 && d < n)
        {
            printf("d = %d", d);
            break;
        }
        else if (d == n)
        {
            // that bai thay doi c != 0, != -2
            i++;
        }
    }
}

int main()
{
    nhap();
    thua_so_khong_tam_thuong();
    return 0;
}