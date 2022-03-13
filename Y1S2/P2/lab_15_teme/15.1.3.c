#include<stdio.h>

void rezolv(int n)
{//n e 3
    int i,j,k,primul=n,st=n,dr=n,ok=0  ;
    for(i=1;i<=n;i++)
    {
        ok=0;
        for(j=1;j<st;j++)//pana la primul #
                    printf(" ");
                    if(st==dr)
                    {
                        printf("*\n");
                        st--;
                        dr++;
                        continue;
                    }
                    else
                        printf("*");

            for(k=st+1;k<dr&&st!=dr;k++)//intre primul# si ultimul
                {
                    printf(" ");
                    ok=1;
                    }
                    if(ok==1)
            printf("*\n");
            st--;
            dr++;
    }
    st+=2;//ca sa ajunga pe cea mai din stanga pozitie+1
    dr-=2;//ca sa ajunga pe cea mai din dreapta pozitie-1
    //asta e prima jumatate
    for(i=1;i<n;i++)
    {
        for(j=1;j<st;j++)//pana la primul #
                    printf(" ");
                    if(st==dr)
                    {
                        printf("*\n");
                        st++;
                        dr--;
                        continue;
                    }
                    else
                        printf("*");

            for(k=st+1;k<dr&&st!=dr;k++)//intre primul# si ultimul
                {
                    printf(" ");
                    ok=1;
                    }
                    if(ok==1)
            printf("*\n");
            st++;
            dr--;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    rezolv(n);
}




