#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.142857
int main()
{
    int optiune;
    printf("Alegeti o forma geometrica:\n1.Cerc\n2.Dreptunghi\n3.Trapez\n");
    scanf("%d", &optiune);
    if (optiune == 1)
    {
        int raza;
        printf("Introduceti raza:\n");
        scanf("%d", &raza);
        printf("Aria: %d", raza * raza * 1.0 * PI);
    }
    else if (optiune == 2)
    {
        int lungime, latime;
        printf("Introduceti Lungimea si latimea, in aceasta ordine:\n");
        scanf("%d %d", &lungime, &latime);
        printf("Aria: %d", lungime * latime);
    }
    else
    {
        int bazaMare, bazaMica, inaltimea;
        printf("Introduceti baza mare, baza mica si inaltimea, in aceasta ordine:\n");
        scanf("%d %d %d", &bazaMare, &bazaMica, &inaltimea);
        printf("Aria: %d", (bazaMare + bazaMica) * inaltimea / 2);
    }

    return 0;
}