#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.000001
int a,b,c,d;

double eval_expresie(double x){
   // printf("=====%lf %lf====\n",x,x*x*x*a+ x*x*b+ x*c+ d);
    return x*x*x*a+ x*x*b+ x*c+ d;
}

double cautare_solutie(double st,double dr){
    // printf("%lf %lf\n",st,dr);
    double m = (st+dr)/2.0;
    double rezultat_st= eval_expresie(st);
    double rezultat_dr= eval_expresie(dr);
    double rezultat_m= eval_expresie(m);
    if(fabs(rezultat_m)<=eps){
    return m;
    }
    if(rezultat_st * rezultat_m >0 )
    return cautare_solutie(m,dr);
    else return cautare_solutie(st,m);
    
}

int main(){
    double n,m;
    scanf("%lf %lf",&n,&m);
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%lf",cautare_solutie(n,m));

}