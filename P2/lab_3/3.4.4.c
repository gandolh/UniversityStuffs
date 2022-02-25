#include <stdio.h>
#include <string.h>
#define NL 80
#define NC 80
//hai ca nici nu a durat mult
//mama lui de c
void citeste(int n, int m, int a[NL][NC])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

void printare(int n, int m, int a[NL][NC])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int addMatrix(int n,int m,int a[NL][NC],int b[NL][NC],int c[NL][NC]){
    int i,j;
 for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        c[i][j]=a[i][j]+b[i][j];
}
int main()
{
    int n1, m1,n2,m2, a[NL][NC], b[NL][NC],c[NL][NC];
    scanf("%d %d", &n1, &m1);
    citeste(n1, m1, a);
      scanf("%d %d", &n2, &m2);
    citeste(n2, m2, b);
    if(n1!=n2 && m1!=m2){
        printf("matricile nu se pot aduna");
    }else{
        addMatrix(n1,m1,a,b,c);
        printare(n1,m1,c);
        
    }

}