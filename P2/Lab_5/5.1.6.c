#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct persoana {
	char* nume, * prenume;
	int varsta;
}Persoana;



Persoana** citire(int n) {
	int i = 0;
	Persoana** p = malloc(n * sizeof(Persoana*));
	Persoana** current = p;
	for (i = 0; i < n; i++) {
		*current = (Persoana*)malloc(sizeof(Persoana));
		*current++;
	}
	current = p;
	for (i = 0; i < n; i++) {
		(*current)->nume = malloc(100 * sizeof(char));
		(*current)->prenume = malloc(100 * sizeof(char));
		(*current)->varsta = malloc(sizeof(int));
		scanf("%s %s %d", ((*current)->nume), ((*current)->prenume), &((*current)->varsta));
		current++;
	}
	return p;
}


void afisare(struct persoana** p, int n, int a, int b) {
	int i = 0, ok = 0;
	Persoana** current = p;
	for (i = 0; i < n; i++) {
		if ((*current)->varsta >= a && (*current)->varsta <= b) {
			printf("%s %s %d\n", (*current)->prenume, (*current)->nume, (*current)->varsta);
			ok = 1;
		}
		current++;
	}
	if (!ok) {
		printf("Nu am gasit nicio persoana");
	}
}


int main() {
	int n, a, b;
	scanf("%d", &n);
	Persoana** p = citire(n);
	scanf("%d %d", &a, &b);

	afisare(p, n, a, b);

}