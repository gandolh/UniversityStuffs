#include<stdio.h>

int verif(int a)
{
    int ok=0,proprietate=0,nrcif=0,cif=-1;
    if(a<=99)
        return 0;
    while(a!=0)
    {
        if(a%10==2||a%10==3||a%10==5||a%10==7)
            ok=1;//avem cifra prima
        if(a%10==cif)
            nrcif++;
        else
        {
            cif=a%10;
            nrcif=1;
        }
        if(nrcif>=3)
            proprietate=1;
        a=a/10;
    }
    if(ok==1&&proprietate==1)
        return 1;
    return 0;
}

void rezolv(int n)
{
    int i,a,ok=0;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a);
        if(verif(a)==1)
        {
            if(ok==1)
                printf(" ");
            printf("%d",a);
            ok=1;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    rezolv(n);
}




