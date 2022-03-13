#include <stdio.h>
#include <stdlib.h>

int nrpare(int x)
{
    int cif=0;
    if(x==0)
        return 1;
    while(x!=0)
    {
       if(x%2==0)
            cif++;
       x=x/10;
    }
    return cif;
}
int main()
{
    int a,b,c,tnrcifrepare=0,nrcifrepare,val;
    scanf("%d%d%d",&a,&b,&c);
        nrcifrepare=nrpare(a);
        if(tnrcifrepare<=nrcifrepare)
        {
            tnrcifrepare=nrcifrepare;
            val=a;
        }
        nrcifrepare=nrpare(b);
        if(tnrcifrepare<=nrcifrepare)
        {
            tnrcifrepare=nrcifrepare;
            val=b;
        }
        nrcifrepare=nrpare(c);
        if(tnrcifrepare<=nrcifrepare)
        {
            tnrcifrepare=nrcifrepare;
            val=c;
        }
        printf("%d",val);
    return 0;
}