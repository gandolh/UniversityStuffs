#include <stdio.h>
#include <math.h>
//https://stepik.org/lesson/308978/step/2?unit=291103 -- problema 7
/*
primul numar este cerinta ce va fi rezolvata
in cazul cerintei 1:
    al 2lea numar introdus este lungimea drumului
    urmeaza 'lungime numere' ce reprezinta directia la fiecare pas al drumului.
in cazul cerintei 2:
    se cere un numar pentru care sa se calculeze drumul de cost
    maxim
*/

int main()
{
    int lungime, d, sum, i, c;
    scanf("%d", &c);
    if (c == 1)
    {
        /*
        Observam ca in coborare numarul ce urmeaza va fi
        indicele liniei -1 daca directia este stanga,
        -0 in caz
        */
        sum = 1;
        scanf("%d", &lungime);
        for (i = 1; i <= lungime; i++)
        {
            scanf("%d", &d);
            sum += (i + 1) - (d == 1 ? 1 : 0);
        }
        printf("%d\n", sum);
    }
    else
    {
        /*
        Cata bataie de cap mi-a dat dar:
        notam cu l linia pe care se afla elementul K si c numarul de ordine
        de pe linia respectiva.
        Costul maxim al traseului este format din suma valorilor maxime de pe liniile 1,2,...,c
        si a valorilor de pe pozitia c din liniile c+1,c+2...,l
        */
        scanf("%d", &d);
        sum = 0;
        double result = (-1 + sqrt(1 + 8 * d)) / 2 + 1;
        int l = result;
        if (result == (int)result)
            l--;
        int c = d - (l * (l - 1) / 2);
        for (i = 1; i <= c; i++)
            sum += (i * (i + 1) / 2);
         for ( i = c+1; i <= l; i++)
            sum= sum+ (i * (i -1) / 2) + c;
        printf("%d\n", sum);
    }
    //suprins,dar merge.
    return 0;
}
