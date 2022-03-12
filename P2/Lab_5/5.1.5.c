#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct persoana {
	char* nume, * prenume;
	int varsta;
}Persoana;



Persoana** citire(int n) {
	int i = 0;
	Persoana** p = malloc(n * sizeof(Persoana));
	Persoana* current = *p;
	for (i = 0; i < n; i++) {
		current->nume = malloc(100 * sizeof(char));
		current->prenume = malloc(100 * sizeof(char));
		scanf("%s %s %d", (current->nume), (current->prenume), &(current->varsta));
		current++;
	}
	return p;
}
void afisare(struct persoana** p) {
	printf("%s %s %d", (*p)->prenume, (*p)->nume, (*p)->varsta);
}


int main() {
	int n;
	scanf("%d", &n);
	Persoana** p = citire(n);
	afisare(p);

}