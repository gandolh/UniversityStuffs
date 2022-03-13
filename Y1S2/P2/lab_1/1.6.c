//1
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,d;
    char c[10];
    scanf("%s",&c);
    if(c[1]!=NULL){
       printf("%s","nu este cifra");
        return  0;
    }
    switch (c[0])
    {
        case '0':
        printf("%s\n%s\n","zero","zero");
        break;
    case '1':
        printf("%s\n%s\n","unu","one");
        break;
    case '2':
    printf("%s\n%s\n","doi","two");
    break;
        case '3':
    printf("%s\n%s\n","trei","three");
    break;
        case '4':
    printf("%s\n%s\n","patru","four");
    break;
        case '5':
    printf("%s\n%s\n","cinci","five");
    break;
        case '6':
    printf("%s\n%s\n","sase","six");
    break;
        case '7':
    printf("%s\n%s\n","sapte","seven");
    break;
        case '8':
    printf("%s\n%s\n","opt","eight");
    break;
        case '9':
    printf("%s\n%s\n","noua","nine");
    break;
    default:
       printf("%s","nu este cifra");
    }
}


//2
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char c;
  scanf("%c",&c);
    int char_code= c;
    printf("%d",char_code);
}


//3
#include <stdio.h>
int Maxim(int a, int b, int c, int d) {
    int maxim = a;
    if (b > maxim) maxim = b;
    if (c > maxim) maxim = c;
    if (d > maxim) maxim = d;
    return maxim;
}
int Minim(int a, int b, int c, int d) {
    int minim = a;
    if (b < minim) minim = b;
    if (c < minim) minim = c;
    if (d < minim) minim = d;
    return minim;
}
int Unique(int a, int b, int c, int d) {
    
    return !( a==b || a==c || a==d || b==c || b==d || c==d);
}
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int maxx = Maxim(a,b,c,d);
    int minn = Minim(a,b,c,d);
    int ok = Unique(a,b,c,d);
  
    printf("%d\nToate numerele sunt diferite? %s",minn+maxx, ok?"da":"nu");


}
//4
#include <stdio.h>

int main(){
    int r,g,b;
    scanf("%d%d%d",&r,&g,&b);
    if(r<0 || g<0 || b<0 || r>255 || g>255 || b>255){
        printf("intrari invalide");
        return 0;
    }
    
    printf("%d %d %d",255- r,255 - g,255 - b);
        
        
    return 0;

}




