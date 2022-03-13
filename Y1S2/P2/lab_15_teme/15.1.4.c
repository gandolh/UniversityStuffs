

#include<stdio.h>

int inversare(int a)
{
    int invers=0;
    while(a!=0)
    {
        invers=invers*10+a%10;
        a=a/10;
    }
    return invers;
}
int cif(int a)
{ //din stanga in dreapta
    int nou=0,p=1,nrcif=0,aa,nr=0;
    aa=a;//poate pun aa=0
    while(aa!=0)
    {
        nr++;
        aa=aa/10;
    }
    while(a!=0)
    {
        if(nr%2==1)
            {nou=nou+a%10*p;
        p=p*10;
        }
        nr--;
        a=a/10;
    }
    return nou;
}
void rezolv(int n)
{
    int i,a,invers,elimcif;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a);
        invers=inversare(a);
        elimcif=cif(a);
        printf("%d %d\n",invers,elimcif);
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    rezolv(n);
}


