#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX 256
typedef struct {
	char nume[20];
	float precipitatii;
	char zona;
	char regiune[10];
}Oras;

char* getRegiune(char zona) {
	char regiune[10];
	if (zona == 'N')strcpy(regiune, "Nord");
	if (zona == 'S')strcpy(regiune, "Sud");
	if (zona == 'E')strcpy(regiune, "Est");
	if (zona == 'V')strcpy(regiune, "Vest");
	return regiune;
}

Oras Citire_Oras() {
	Oras oras;
	scanf("%s %f %s", &oras.nume, &oras.precipitatii, &oras.zona);
	strcpy(oras.regiune, getRegiune(oras.zona));
	return oras;
}




int main() {
	int n, i, j, nr_cons;
	char zona;
	Oras oras[MAX];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		oras[i] = Citire_Oras();
	scanf("%d %c", &nr_cons, &zona);

	for (i = 0; i < n; i++) {
		int act_nr_cons = 0;
		for (j = 0; oras[i].nume[j]; j++) {
			if (!strchr("aeiouAEIOU", oras[i].nume[j]))
				act_nr_cons++;
		}
		if (act_nr_cons >= nr_cons) {
			printf("%s precipitatii=%.2f l %s\n", oras[i].nume, oras[i].precipitatii, oras[i].regiune);
		}
	}

	char regiune[10];
	char stele[MAX];
	strcpy(regiune, getRegiune(zona));
	printf("In %s\n", regiune);
	for (i = 0; i < n; i++) {
		if (zona == oras[i].zona) {
			strcpy(stele, "");
			for (j = 0; j < (int)(oras[i].precipitatii); j++)
				strcat(stele, "*");
			printf("%-9s: %s\n", oras[i].nume, stele);
		}
	}

}
