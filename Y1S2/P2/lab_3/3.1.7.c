#include <stdio.h>

int main(){
    int n,v[101],d,i,aparitie=-1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
    scanf("%d",&d);
    for( i=1;i<=n;i++)
        if(v[i]==d){
            aparitie=i;
        }
          printf("%d",aparitie);
    return 0;
}