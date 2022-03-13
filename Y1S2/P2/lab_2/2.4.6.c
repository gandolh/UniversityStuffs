#include <stdio.h>




int prim(n){
    if(n<2)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    for(int d=3;d*d<=n;d+=2)
        if(n%d==0)return 0;
    return 1;
}

int main()
{
    int a,b,i;
    int nr=0;
    scanf("%d %d",&a,&b);
    for( i=a;i<=b;i++)
        if(prim(i))
            nr++;
    printf("%d\n",nr);
    for( i=a;i<=b;i++)
        if(prim(i))
        printf("%d ",i);


   return 0; 
}