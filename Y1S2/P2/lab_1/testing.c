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
            if(d*d>=n)d=n;
        }
    }
