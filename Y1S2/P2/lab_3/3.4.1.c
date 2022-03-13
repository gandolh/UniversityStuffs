#include <stdio.h>

void citesteArr(int n, int arr[]){
    int i=1;
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);

}

int Maxim(int n, int arr[]){
    int i,maxx=-1;
    for(i=1;i<=n;i++)
        if(arr[i]>maxx)
        maxx=arr[i];
    return maxx;
}

float Media(int n, int arr[]){
    float sum=0;
    int i;
    for(i=1;i<=n;i++)
        sum+=(float)arr[i];
    return sum/n;
}

int NumaraDiv(int n, int arr[]){
        int i,nr=0;
    for(i=1;i<=n;i++)
    if(arr[i]%100==0)
        nr++;
    return nr;
}

int verifSecventa(int k, int h,int arr[]){
    int i,ok=1;
    for(i=k;i<h;i++)
        if(arr[i]<arr[i+1])
            ok=0;
    if(ok==1){
        printf("da:");
          for(i=k;i<=h;i++)
          printf(" %d",arr[i]);
    }else{
        printf("nu");
    }
}

int main() {
    int n,d,k,h,arr[101];
    scanf("%d",&n);
    citesteArr(n,arr);
    scanf("%d %d",&k, &h);

    printf("max=%d\n",Maxim(n,arr));
    printf("media=%.2f\n",Media(n,arr));
    printf("nr. divizibile cu 4 si 100=%d\n",NumaraDiv(n,arr));
    verifSecventa(k+1,h+1,arr);
    
    return 0;
}