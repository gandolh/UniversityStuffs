#define N 100

/**
* :param t: tabloul în care se vor citi valori
* :param n: numărul de elemente care se va citi în tablou
*/
void citireTablou(int t[], int n){
   int i;
   for(i = 0; i < n; i++){
      //printf("t[%d]=", i);
      scanf("%d", &t[i]);
   }
}
/**
* :param cof: tabloul care conține coeficienti polinomului
* :param n: gradul polinomului
* :param x: valoarea (punctul) in care se evalueaza polinomul
* :return: functia returneaza valoarea obținută în urma evaluări polinomului
*/
int evaluarePolinom(int coef[], int n, int x){
   int i;
   int rez = 0;
   int vx = 1; //variabila in care se va calcula x la puterea i
   for(i = 0; i <= n; i++){
      rez += coef[i]*vx;
      vx *= x;
   }
   return rez;
}
/**
* :param coef: tabloul care conține coeficienti polinomului
* :param n: gradul polinomului
*/
void afisarePolinom(int coef[], int n){
    for(int i = 0; i <= n; i++){
        printf(" %d*x^%d +", coef[i], i);
    }
    printf("\b\n");
}
/**
* :param coef: tabloul care conține coeficienti polinomului
* :param n: gradul polinomului
*/
void evaluare(int coef[], int n){
   int x = 0;
   //printf("Introduceti valorile punctelor în care va fi evaluat polinomul.");
   do{
     //printf("x="); 
     scanf("%d", &x);
     //printf("val polinom = %d\n", evaluarePolinom(coef, n, x));
     printf("%d\n", evaluarePolinom(coef, n, x));
   }while(x!=0);
}
int main(){
  int n, coef[N];
  //printf("grad pol=");
  scanf("%d", &n);
  if (n > N){
    printf("Gradul polinomului trebuie să fie mai mic de %d\n", N);
    return 1; //se termină execuția programului cu un cod de eroare
  }
  citireTablou(coef, n+1);
  //afisarePolinom(coef, n);
  evaluare(coef, n);
}