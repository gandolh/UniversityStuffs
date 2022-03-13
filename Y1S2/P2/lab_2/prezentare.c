//exercitiul 4.



#include <stdio.h>
#include <stdlib.h>


int main(){
    char c;
    do{
        scanf("%c",&c);

        if(c>='a' && c<='z')
            printf("Caracterul ca litera mare: %c\n",c + 'A'-'a');
        else printf("Caracterul ca litera mare: %c\n",c);

        if(c>='1' && c<='9')
            printf("%c este cifra\n",c);
        else printf("%c nu este cifra\n",c);
        fflush(stdin);
    }while(c != 'Q');


}