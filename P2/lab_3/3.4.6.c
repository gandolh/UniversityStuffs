#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int n,m;
    char** cuv;
    int* poz;
    scanf("%d",&n);
    printf("%d",n);
    cuv= malloc((n) * sizeof(char *));
    for(int i=0;i<n;i++){
        scanf("%s",&cuv[i][0]);
        printf("111\n");
        printf("%s\n",cuv[i]);
    }

}