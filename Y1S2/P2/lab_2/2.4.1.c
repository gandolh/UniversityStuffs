#include <stdio.h>

int cmmdc(int a, int b)
{
    int r;
    do
    {
        r = a % b;
        a = b;
        b = r;
    } while (r > 1);
    return a;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (b == 0 || d == 0)
    {
        printf("numitorul nu poate fi 0 !!!");
    }
    else
    {
        int sum_a = a * d + b * c;
        int sum_b = b * d;
        int prod_a = a * c;
        int prod_b = b * d;
        // printf("%d %d %d \n" ,sum_a,sum_b, cmmdc(sum_a, sum_b));
        // printf("%d %d %d \n" ,prod_a,prod_b, cmmdc(prod_a, prod_b));
        int sum_cmmdc=cmmdc(sum_a, sum_b);
        int prod_cmmdc=cmmdc(prod_a, prod_b);
        sum_a = sum_a / sum_cmmdc;
        sum_b = sum_b / sum_cmmdc;
        printf("%d %d %d",prod_a,prod_b,prod_cmmdc);
        prod_a = prod_a / prod_cmmdc;
        prod_b = prod_b / prod_cmmdc;
        printf("suma=%d/%d\nprodusul=%d/%d", sum_a, sum_b, prod_a, prod_b);
    }
    return 0;
}