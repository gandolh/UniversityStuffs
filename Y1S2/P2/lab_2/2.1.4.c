int suma_cifre(int nr){
}

/**
* Citeste n numere si determina cea mai mare valoare a sumei cifrelor numerelor citite
* param n: numarul de numere care vor fi citite
* retrurn: cea mai mare valoare a sumei cifrelor numerelor citite
*/
int prelucrare_numere(int n){
    int i,d,sum,maxx=0;

    for( i=0;i<n;i++){
        scanf("%d",&d);
        if(d<0)d=-d;
        sum=0;
        while(d){
            sum+=d%10;
            d/=10;
        }
        if(sum>maxx)maxx=sum;

    }
    return maxx;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d", prelucrare_numere(n));
    return 0;

}