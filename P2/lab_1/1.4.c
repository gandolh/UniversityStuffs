//4. 2 4 6
//5. In ciclu Dupa ciclu


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,d,nr=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&d);
        int prod=1;
        
        do{
        prod*=d%10;
            d/=10;
        }while(d);
        if(prod==0)
            nr++;
    }
    printf("%d",nr);
}




