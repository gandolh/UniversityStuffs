#include <stdio.h>

double putere(int n, int x)
{
    double res = 1;
    int i;
    if (n > 0)
    {
        for (i = 0; i < n; i++)
            res *= x;
    }
    else
    {
        for (i = n; i < 0; i++)
            res /= x;
    }
    return res;
}
int main()
{
    int x, n;
    scanf("%d %d", &x, &n);

    printf("%lf", putere(n, x));
    return 0;
}