#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct persoana {
	char* nume, * prenume;
	int nota;
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
		(*current)->nota = malloc(sizeof(int));
		scanf("%s %s", ((*current)->nume), ((*current)->prenume));
		char nota_str[4];
		gets(nota_str);
		gets(nota_str);
		if (nota_str[0] == 'A')
			(*current)->nota = -1;
		else {
			if (nota_str[0] == '1' && nota_str[1] == '0')
				(*current)->nota = 10;
			else (*current)->nota = nota_str[0] - '0';
		}
		current++;
	}
	return p;
}


void afisare(struct persoana** p, int n, int x) {
	int i = 0, ok = 0, prezenti = 0, printed = 0;
	Persoana** persoane = p;

	for (i = 0; i < n; i++)
		if (persoane[i]->nota != -1)
			prezenti++;
	printf("Prezenti: %d\n", prezenti);
	printf("Statistica\n", prezenti);
	int* freqNote = calloc(11, sizeof(int));
	for (i = 0; i < n; i++) {
		freqNote[persoane[i]->nota] += 1;
	}

	for (i = 10; i >= 0; i--) {
		if (freqNote[i] != 0)printf("Nota %d - %d student(i)\n", i, freqNote[i]);
	}

	printf("Nota %d: ",x);
	ok = 0;
	for (i = 0; i < n; i++) {
		if (persoane[i]->nota == x) {
			printf("%s %s;", persoane[i]->nume, persoane[i]->prenume);
			ok = 1;
		}
		if (ok == 0)printf("niciun student");
	}
}


int main() {
	int n, x;
	scanf("%d", &n);
	Persoana** p = citire(n);
	scanf("%d", &x);

	afisare(p, n, x);

}