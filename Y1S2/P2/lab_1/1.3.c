//2
int main()
{
    int i, d, nr = 0;
    double sum = 0;
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &d);
        if (d >0)
        {
            sum += d;
            nr++;
        }
    }
    printf("%.2f", sum / (nr ? nr : 1));
    return 0;
}


//3
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    while(n){
        sum+= n%10;
        n/=10;
    }
    printf("%d",sum);
}

// 4. cazul implicit executat