#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int **a, n, m, i, j, *freq;
    scanf("%d %d", &n, &m);
    a = malloc(m * sizeof(char *));
    for (i = 0; i < n; i++)
    {
    freq= (int*)calloc(100, sizeof(int));
        a[i] = malloc( sizeof(char));
        for (j = 0; j < m; j++){
            if(freq[j]==0){
                freq[j]=1;
                realloc(a[i],sizeof(a[i]) + sizeof(int));
            scanf("%d", &a[i][j]);
            }
        
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
    return 0;
}