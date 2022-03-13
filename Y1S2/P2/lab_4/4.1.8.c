#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
void fct(int *tab, int n, double *sum, double *med, double *avg)
{
    int i;
    *sum = 0;
    *med = 0;
    for (i = 0; i < n; i++)
    {
        *sum = *sum + tab[i];
    }
    *avg = *sum / n;
    double numarator=0,result;
    for (i = 0; i < n; i++)
    {
        numarator =numarator + ((1.0*tab[i] - *avg) * (1.0*tab[i] - *avg));
        // printf("%.2lf==\n", numarator);
    }
        // printf("%.2lf==\n", numarator/ (n-1));
    *med = sqrt(numarator/ (n-1));
}
int main()
{
    int n, *v = malloc(255 * sizeof(int)), i;
    double sum, med, avg;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    fct(v, n, &sum, &med, &avg);
    printf("%.0lf\n%.2lf\n%.2lf", sum, avg, med);
    return 0;
}