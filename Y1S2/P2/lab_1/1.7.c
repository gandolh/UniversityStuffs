//1


#include <stdio.h>

int isPrime(int n){
    for(int i=2;i<=n-1;i++)
    if(n%i==0)return 0;
    return 1;

}
int main()
{
    int n;
    scanf("%d",&n);
    int prim = isPrime(n);
    printf("Numarul %d %s",n,prim?"este prim":"nu este prim");
}



//2
#include<stdio.h>
#include<math.h>
//0.001
int main()
{
    int i=3;
    double precizie,s0,s1,aux;
    scanf("%lf",&precizie);
    s0=2;
    s1=2.25;//default e int
    while(s1-s0>precizie)
    {
        s0=s1;
        s1=pow(1+(double)1/i,i);
        i++;
    }
    printf("limita=%lf",s1);
    return 0;
}

//3


#include<stdio.h>
#include<math.h>

int main()
{
    double precizie,s0,s1,a;
    scanf("%lf%lf",&a,&precizie);
    s0=a;
    s1=(s0+a/s0)/2;
    while(fabs(s0-s1)>precizie)
        {
            s0=s1;
            s1=(s0+a/s0)/2;
        }
        printf("limita=%lf",s1);
    return 0;
}


//4 
#include <stdio.h>


int main()
{
    int n,nr=0;
    scanf("%d",&n);
    while(n){
        if(n%2==1)nr++;
        n/=2;
    }
    printf("%d",nr);
}

//5
#include <stdio.h>
#include <stdlib.h>
int reverse(int x)
{
    int q = 0;
    while(x)
    {
        q *= 10;
        q += x%10;
        x /= 10;
    }
    return q;
}
void intToString(int x,char* str)
{   
    int k=-1;
    if(x<0){str[++k]= '-';x=-x;}
    x = reverse(x);
    while(x)
    {
        str[++k]= '0' + (x % 10);
        // printf("%d\n",x%10);
        x /= 10;
    }
    str[++k]=0;

}
int main()
{
    int n,d,i,maxx=-1,minn=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&d);
        if(d>maxx)maxx=d;
        if(d<minn)minn=d;
    }
    char smax[20],smin[20];
    intToString(maxx,smax);
    intToString(minn,smin);
    printf("%s\n%s",(maxx<0?"nu exista":smax), (minn>0?"nu exista":smin));
}

//6 


    #include <stdio.h>
    #include <stdlib.h>
  
    int main()
    {
        int n,first=1;

        scanf("%d",&n);
        int d=2;
        while(n>1){
            int p=0;
            while(n%d==0){
                p++;n/=d;
            }
            if(p>0){
                if(!first)printf("*");
                first=0;
                printf("%d",d);
                if(p>1)printf("^%d",p);
            }
            d++;
            //if(d*d>=n)d=n;
        }
    }



