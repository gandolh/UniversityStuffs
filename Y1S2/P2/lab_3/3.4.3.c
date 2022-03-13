#include <stdio.h>
#include <string.h>
#define NL 80
#define NC 80
//hai ca nici nu a durat mult
//mama lui de c
void citeste(int nl, int nc, int m[NL][NC])
{
    int i, j;
    for (i = 0; i < nc; i++)
        for (j = 0; j < nl; j++)
            scanf("%d", &m[j][i]);
}

void printare(int nl, int nc, int m[NL][NC])
{
    int i, j;
    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc - 1; j++)
            printf("%d ", m[i][j]);
        printf("%d", m[i][j]);
        printf("\n");
    }
}

void det_maxim(int nl, int nc, int m[NL][NC])
{
    int i, j, maxx = -1, imaxx, jmaxx;
    for (i = 0; i < nl; i++)
        for (j = 0; j < nc; j++)
            if (maxx < m[i][j])
            {
                maxx = m[i][j];
                imaxx = i;
                jmaxx = j;
            }
    printf("max %d:", maxx);
    for (i = 0; i < nl; i++)
        for (j = 0; j < nc; j++)
            if (maxx == m[i][j])
            {
                printf(" linia %d coloana %d;", i + 1, j + 1);
            }
    printf("\n");
}

void constr_tab(int nl, int nc, int m[NL][NC])
{
    int i, j, sum;
    printf("sume:");
    for (i = 0; i < nl; i++)
    {
        sum = 0;
        for (j = 0; j < nc; j++)
            sum += m[i][j];
        printf(" %d", sum);
    }
    printf("\n");
}

void interschimbare(int nl, int nc, int c1, int c2, int a[NL][NC])
{
    int i, j;
    // int a[NL][NC];
    // for (i = 0; i < nl; i++)
    //     for (j = 0; j < nc; j++)
    //         a[i][j] = m[i][j];
    for (i = 0; i < nc; i++)
    {
        int t = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = t;
    }
    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc - 1; j++)
            printf("%d ", a[i][j]);
        printf("%d", a[i][j]);
        printf("\n");
    }
}

void cauta(int nl, int nc, int x, int m[NL][NC])
{
    int i, j;

    printf("elementul %d se gaseste pe:",x);
    for (i = 0; i < nl; i++)
        for (j = 0; j < nc; j++)
            if (m[i][j] == x)
            {
                
                printf(" linia %d coloana %d;", i + 1, j + 1);
            }
}
int main()
{
    int nl, nc, m[NL][NC], c1, c2, x;
    scanf("%d %d", &nl, &nc);
    citeste(nl, nc, m);
    scanf("%d %d", &c1, &c2);
    scanf("%d", &x);
    printare(nl, nc, m);
    det_maxim(nl, nc, m);
    constr_tab(nl, nc, m);
    interschimbare(nl, nc, c1 - 1, c2 - 1, m);
    cauta(nl, nc, x, m);
}