
#include<stdio.h>
void rezolv(int n)
{
    int i,j,aux,ok=0,nrapmaxi=1,nrapmini=1;
    float suma=0,mini=11,maxi=-1,a,b,v[1000]={0};
    scanf("%f",&a);
    scanf("%f",&b);
    v[1]=a;
    v[2]=b;
    if(a>=b)
    {
        maxi=a;
        mini=b;
    }
    else
    {
        maxi=b;
        mini=a;
    }
    for(i=1; i<=n-2; i++)
    {
        scanf("%f",&a);
        v[i+2]=a;
        if(mini>a)
        {
          //  if(ok==1)
          //      printf(" ");
         //   printf("%.2f",mini);
            suma=suma+mini;
            mini=a;
          //  ok=1;
            continue;
        }
        if(maxi<a)
        {
           // if(ok==1)
           //     printf(" ");
           // printf("%.2f",maxi);
            suma=suma+maxi;
            maxi=a;
           // ok=1;
            continue;
        }
        if(mini<=a&&a<=maxi)
        {
           // if(ok==1)
            //    printf(" ");
           // printf("%.2f",a);
            suma=suma+a;
           // ok=1;
            continue;
        }
    }
   // printf("%.0f\n",mini); pana aici am cel m-ai mare si cel m-ai mic numar pe care nu le pun in calcul
    //printf("%.0f\n",maxi);
    //printf("\n");
    suma=suma/(n-2);
    for(i=1;i<=n;i++)
    {
        if((v[i]==mini&&nrapmini==1)||(v[i]==maxi&&nrapmaxi==1))
           {

           if(v[i]==mini)
            nrapmini=0;
            if(v[i]==maxi)
            nrapmaxi=0;
             }
             else
             {
                 if(ok==1)
                 printf(" ");
                 printf("%.2f",v[i]);
                 ok=1;
             }
    }
    printf("\n");
    printf("%.2f",suma);

}

int main()
{
    int n,i;
    float v[1000];
    scanf("%d",&n);
    rezolv(n);
    return 0;
}



