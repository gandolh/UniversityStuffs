


#include<stdio.h>
void rezolv(int n,float v[1000])
{
    int i,j,k,nr=1,ok;
    for(i=1; i<=n; i++)
    {
        nr=1;
        if((float)n/i==n/i)
        {
            printf("%dx%d\n",i,n/i);
            for(j=1; j<=i; j++)
            {
                ok=0;
                for(k=1; k<=n/i; k++)
                {
                    if(ok==1)
                        printf(" ");
                    printf("%.2f",v[nr]);
                    ok=1;
                    nr++;
                }
                printf("\n");
            }
        }
    }
  //  printf("\n");
}

int main()
{
    int n,i;
    float v[1000];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%f",&v[i]);
    }
    rezolv(n,v);
    return 0;
}

