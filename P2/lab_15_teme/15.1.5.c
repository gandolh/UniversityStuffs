#include<stdio.h>
void rezolv(int n,int sumacif,int a,int b)
{
    int ok=0,nrdiv=0;
    if(b%2==0)
    {
        ok++;
        nrdiv=2;
    }
    if(ok==1&&nrdiv==2)
    printf("divizibil cu: 2,");


    if(sumacif%3==0)
    {
        ok++;
        nrdiv=3;
    }
    if(ok==1&&nrdiv==3)
        printf("divizibil cu: 3,");
    else
        if(ok>1&&nrdiv==3)
        printf(" 3,");


    if((a*10+b)%4==0)
    {
        ok++;
        nrdiv=4;
    }
    if(ok==1&&nrdiv==4)
        printf("divizibil cu: 4,");
    else
        if(ok>1&&nrdiv==4)
        printf(" 4,");


    if(b%5==0)
    {
        ok++;
        nrdiv=5;
    }
    if(ok==1&&nrdiv==5)
        printf("divizibil cu: 5,");
    else
        if(ok>1&&nrdiv==5)
        printf(" 5,");


        if(sumacif%9==0)
    {
        ok++;
        nrdiv=9;
    }
    if(ok==1&&nrdiv==9)
        printf("divizibil cu: 9,");
    else
        if(ok>1&&nrdiv==9)
        printf(" 9,");
    if(ok==0)
        printf("nu satisface criteriile de divizibilitate");
}

int main()
{
    int n,a,b,sumacif=0,aa,bb;
    char c;
    scanf("%d",&a);
    scanf("%d",&b);
    aa=a;
    bb=b;
    //fflush(stdin);
    scanf("%s",&c);
    sumacif=sumacif+aa;
    sumacif=sumacif+bb;

    //sumacif=sumacif+c;
    while(c!='x')
    {
        aa=bb;
        bb=(int)(c)-(int)('0');
        sumacif=sumacif+bb;
        scanf("%s",&c);
    }
    rezolv(n,sumacif,aa,bb);
}