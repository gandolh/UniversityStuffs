#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct persoana {
	char* nume, * prenume;
	int varsta;
}Persoana;


Persoana* citire() {
	Persoana* p = malloc(sizeof(Persoana));
	p->nume = malloc(100 * sizeof(char));
	p->prenume = malloc(100 * sizeof(char));

	scanf("%s %s %d", (p->nume), (p->prenume), &(p->varsta));
	return p;
}
void afisare(struct persoana* p) {
	printf("%s %s %d", p->prenume, p->nume, p->varsta);

}


int main() {
	Persoana* p = citire();
	afisare(p);

}