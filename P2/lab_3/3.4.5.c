#include <stdio.h>
#include <string.h>
#define NL 80
#define NC 80
void citeste(int n, int m, int a[NL][NC])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

int check(int n, int m, int a[NL][NC]){
    int i,j;
    if(n!=m)
        return 0;
    for( i=0;i<=n;i++)
    for(j=i+1;j<=m;j++)
        if(a[i][j]!=0)return 1;

return 2;
}

int main()
{
    int n1, m1,n2,m2, a[NL][NC];
    scanf("%d %d", &n1, &m1);
    citeste(n1, m1, a);
    int result = check(n1,m1,a);
    if(result==0){
        printf("proprietatea nu poate fi verificata");
    }else if(result ==1){
        printf("proprietatea nu este verificata");
    }else{
printf("proprietatea este verificata");
    }
}