#include <stdio.h>

int main(){
    int n,v[101],d,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
    scanf("%d",&d);
    for( i=1;i<=n;i++)
        if(v[i]==d){
            printf("%d",i);
            return 0;
        }
          printf("%d",-1);
    return 0;
}