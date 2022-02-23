#include <stdio.h>
#include <stdlib.h>

// thats ml bro wdym
int main()
{
    int optiune;
    printf("Aveti o durere de:\n1.Torace\n2.Gat\n3.Cefalee\n");
    scanf("%d", &optiune);
    if (optiune == 1)
    { // torace
        printf("Aveti o tuse:\n1.uscata\n2.expect.\n");
        scanf("%d", &optiune);
        if (optiune == 1)
        { // tuse uscata
            printf("Aveti temperatura sub 38 de grade? \n1.Da\n2.Nu\n");
            scanf("%d", &optiune);
            if (optiune == 1)
                printf("Traheita\n");
            else
                printf("Bronsita\n");
        }
        else
        { // tuse expect.
            printf("Dispnee?\n1.Medie\n2.Grava\n");
            scanf("%d", &optiune);
            if (optiune == 1)
                printf("Pneumonie\n");
            else
                printf("Enfizem pulmonar\n");
        }
    }
    else if (optiune == 2)
    { // gat
        printf("Temperatura sub 35 de grade?\n1.Da\n2.Nu\n");
        scanf("%d", &optiune);
        if (optiune == 1)
            printf("Irinita\n");
        else
            printf("Amigdalita\n");
    }
    else
    { // cefalee
        printf("Temperatura sub 35 de grade?\n1.Da\n2.Nu\n");
        scanf("%d", &optiune);
        if (optiune == 1)
            printf("Migrena\n");
        else
            printf("Gripa\n");
    }

    return 0;
}