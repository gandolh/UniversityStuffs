#include <stdio.h>

int calcSum(int n, int stop){
    if(n==stop)return n;
    return n*calcSum(n-1,stop);

}

int main()
{
    int a,b,r;
    scanf("%d %d",&a,&b);
    printf("A(%d,%d)=%d",a,b,calcSum(a,a-b+1));

   return 0; 
}