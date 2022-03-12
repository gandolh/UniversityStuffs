#include <stdio.h>
#include <stdlib.h>

int ciframax(long n) {
    int minn = 0;
    while (n) {
        if (minn < n % 10)
            minn = n % 10;
        n /= 10;
    }
    return minn;
}

int nrcif(long n) {
    int nr = 0;
    while (n) {
        nr++;
        n /= 10;
    }
    return nr;
}

void sortare(int n, int* t, int (*pf)(long)) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int opt1 = pf(t[i]);
            int opt2 = pf(t[j]);
            if (opt1 == opt2) {
                if (t[i] > t[j]) {
                    int aux = t[i];
                    t[i] = t[j];
                    t[j] = aux;
                }
            }
            if (opt1 > opt2) {
                int aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
}

void afisare(int n, int* t) {
    for (int i = 0; i < n; i++)
        printf("%d;", t[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int t[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    printf("cifra maxima: ");
    sortare(n, t, ciframax);
    afisare(n, t);
    printf("nr. cifre: ");
    sortare(n, t, nrcif);
    afisare(n, t);
    return 0;
}