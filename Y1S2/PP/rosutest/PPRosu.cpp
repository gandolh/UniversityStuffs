#include "Headers.h"
void list_univ(char path_universities[]) {
	system("cls");
	view_old(path_universities);
}



int stringCount(char * path, char* str) {
	FILE* filePointer;
	char linie[256];
	filePointer = fopen(path, "r");
	int nr = 0;
	if (filePointer == NULL)
	{
		printf("Fisierul nu poate fi accesat.");
	}
	else
	{
			fseek(filePointer, 0, SEEK_SET);
			while (fgets(linie, 256, filePointer)) {
				if (linie[0] != '\n') {
					if (strstr(linie, str))
						nr++;
				}
			}
		}
		fclose(filePointer);
	return nr;
	}
void universitati_side_menu(char* path,char* uni, int first, int last) {
	FILE* filePointer;
	char* result = new char[255];
	filePointer = fopen(path, "r");
	int keyPressed = 0, key;
	system("cls");
	char linie[256];
	if (filePointer == NULL)
	{
		printf("Fisierul nu poate fi accesat.");
	}
	else
	{
		int position = 1;
		int keyPressed = 0;
		while (keyPressed != 13) {
			int i = 0;
			system("cls");
			fseek(filePointer,0,SEEK_SET);
			while (fgets(linie, 256, filePointer)) {
				if (linie[0] != '\n') {
					//linie[strcspn(linie, "\n")] = '\0';
					arrow(++i, position);  printf("%s",linie);
					if (i == position)strcpy(result,linie);
				}
			}
			keyPressed = getch();
			if (keyPressed == 80 && position != last)
				position++;
			else if (keyPressed == 72 && position != first)
				position--;
			else position = position;
		}
		fclose(filePointer);
		linie[strcspn(result, "\n")] = '\0';
		strcpy(uni,result);
	}


	//printf("--------------\n");
	//printf("Pentru a va intoarce la meniul principal apasati tasta escape");
	//do {
	//	keyPressed = getch();
	//} while (keyPressed != 27);
	//main_menu();

}
void facultati_side_menu(char* path, char* fac) {
	universitati_side_menu(path, fac,1,8);
}
void specializari_side_menu(char* path, char* spec) {
	universitati_side_menu(path, spec,1,11);
}



void aplic(char path[], char path_univ[], char path_fac[], char path_spec[]) {

	FILE* filePointer;
	filePointer = fopen(path, "a");

	int keypressed = 0;
	char nume[20], prenume[20];
	int varsta;
	float medie_bac;
	char descriere[20], liceu[20];
	char uni[255], fac[255], specializare[255];

	//aici submenu
	  universitati_side_menu(path_univ, uni,1,5);
	  facultati_side_menu(path_fac, fac);
	  specializari_side_menu(path_spec, specializare);
	  uni[strlen(uni)-1] = 0;
	  fac[strlen(fac)-1] = 0;
	  specializare[strlen(specializare)-1] = 0;
	//facultati_side_menu();
	//specializari_side_menu();
	system("cls");
	printf("--------------\n");
	printf("Adaugare\n");
	printf("--------------\n");
	  printf("\n");
	printf("Introduceti numele\n");

	scanf("%[^\n]", nume);
	printf("Introduceti prenumele\n");
	getchar();
	scanf("%[^\n]", prenume);
	getchar();
	printf("Introduceti varsta\n");
	scanf("%d", &varsta);
	getchar();
	printf("Introduceti liceul absolvit\n");
	scanf("%[^\n]", liceu);
	getchar();
	printf("Introduceti media obtinuta la Examenul de Bacalaureat\n");
	scanf("%f", &medie_bac);
	getchar();
	if (filePointer == NULL)
	{
		printf("Dosarul de inscriere nu exista sau nu poate fi accesat");
	}
	else
	{
		fprintf(filePointer, "%s, %s, %s, %s, %s, %d, %s, %.2f\n",uni, fac, specializare, nume, prenume, varsta, liceu, medie_bac);
		fclose(filePointer);
	}

	printf("Persoana %s cu vartsa %d a fost adaugata in fisier\n", nume, varsta);
	printf("--------------\n");
	printf("Pentru a va intoarce la meniul principal apasati tasta escape");
	do {
		keypressed = getch();
	} while (keypressed != 27);
	main_menu();
}
void view_old(char path[]) {
	FILE* filePointer;
	filePointer = fopen(path, "r");
	int keyPressed = 0, key;
	system("cls");
	char linie[150];

	printf("--------------\n");
	printf("Afisare\n");
	printf("--------------\n");

	if (filePointer == NULL)
	{
		printf("Fisierul nu poate fi accesat.");
	}
	else
	{
		while (fgets(linie, 100, filePointer)) {
			if (linie[0] != '\n') {
				linie[strcspn(linie, "\n")] = '\0';
				printf("%s\n", linie);
			}
		}
		fclose(filePointer);
	}

	printf("--------------\n");
	printf("Pentru a va intoarce la meniul principal apasati tasta escape");
	do {
		keyPressed = getch();
	} while (keyPressed != 27);
	main_menu();

}
void statistics_menu(char* path_univ,char* path_fac, char* path_spec, char* path_aplication) {
	printf(">>> Date si statistici: (Selectati optiunea dorita): >>\n\n");
	system("cls");
	int position = 1;
	int keyPressed = 0;

	int first = 1;
	int last = 5;

	while (keyPressed != 13) {
		system("cls");

		arrow(1, position);  printf(" 1) Vedeti numarul de aplicatii pentru o anumita universitate \n");
		arrow(2, position);  printf(" 2) Vedeti numarul de aplicatii pentru o anumita facultate\n");
		arrow(3, position);  printf(" 3) Vedeti numarul de aplicatii pentru o anumita specializare\n");
		arrow(4, position);  printf(" 4) Vedeti media minima de admitere din anul precendent pentru o anumita specializare\n");
		arrow(5, position);  printf(" 5) Exit\n");
		keyPressed = getch();

		if (keyPressed == 80 && position != last)
			position++;
		else if (keyPressed == 72 && position != first)
			position--;
		else position = position;

	}
	printf("\n Ati selectat optiunea %d", position);
	if (position == 5)
	{
		main_menu();
		print_line();
	}
	else {
		switch (position) {
		case 1: {
			system("cls");
			 char* input= new char[255];
			 universitati_side_menu(path_univ,input,1,5);
			 input[strlen(input) - 1] = 0;;
			int count = stringCount(path_aplication, input);
			system("cls");
			printf("%d au aplicat la universitatea %s", count, input);
			printf("\n--------------\n");
			printf("Pentru a va intoarce la meniul principal apasati tasta escape");
			do {
				keyPressed = getch();
			} while (keyPressed != 27);
			main_menu();
			//view_old(stat_specializare);
			break;
		}
		case 2: {
			system("cls");
			char* input = new char[255];
			facultati_side_menu(path_fac, input);
			input[strlen(input) - 1] = 0;;
			int count = stringCount(path_aplication, input);
			system("cls");
			printf("%d au aplicat la facultatea %s", count, input);
			printf("\n--------------\n");
			printf("Pentru a va intoarce la meniul principal apasati tasta escape");
			do {
				keyPressed = getch();
			} while (keyPressed != 27);
			main_menu();
			//view_old(stat_facultate);
			break;
		}
		case 3: {
			system("cls");
			char* input = new char[255];
			specializari_side_menu(path_spec, input);
			input[strlen(input) - 1] = 0;;
			int count = stringCount(path_aplication, input);
			system("cls");
			printf("%d au aplicat la specializarea %s", count, input);
			printf("\n--------------\n");
			printf("Pentru a va intoarce la meniul principal apasati tasta escape");
			do {
				keyPressed = getch();
			} while (keyPressed != 27);
			main_menu();
			//view_old(stat_universitate);
			break;
		}
		case 4: {
			system("cls");
			//view_old(stat_specializare);
			break;
		}


		}
	}
}


void main_menu() {

	system("cls");
	int position = 1;
	int keyPressed = 0;

	const int first = 1;
	const int last = 5;

	char path_application[] = "fisier_dosar.txt";
	char path_universities[] = "fisier_universitati.txt";
	char path_faculties[] = "fisier_facultati.txt";
	char path_specialities[] = "fisier_specializari.txt";
	char stat_universitate[] = "aplicatii_universitate.txt";
	char stat_facultate[] = "aplicatii_facultate.txt";
	char stat_specializare[] = "aplicatii_specializare.txt";
	char stat_medie[] = "medie.txt";
	while (keyPressed != 13) {
		system("cls");

		arrow(1, position);  printf(" 1) Vizualizati lista universitatilor / facultatilor / specializarilor\n");
		arrow(2, position);  printf(" 2) Aplicati la o facultate\n");
		arrow(3, position);  printf(" 3) Vizualizati formularele de aplicatie depuse\n");
		arrow(4, position);  printf(" 4) Vizualizati date si statistici\n");
		arrow(5, position);  printf(" 5) Exit\n");
		keyPressed = getch();

		if (keyPressed == 80 && position != last)
			position++;
		else if (keyPressed == 72 && position != first)
			position--;
		else position = position;

	}
	printf("\n Ati selectat optiunea %d", position);
	print_line();
	switch (position) {
	case 1: {
		list_univ(path_universities);
		break;
	}
	case 2: {
		aplic(path_application, path_universities, path_faculties, path_specialities);
		break;
	}
	case 3: {
		view_old(path_application);
		break;
	}
	case 4: {
		statistics_menu(path_universities,path_faculties,path_specialities, path_application);
		break;
	}
	case 5: {
		system("cls");
		printf("La revedere!");
		break;
	}

	}
}

void arrow(int realPosition, int desiredPosition) {

	if (realPosition == desiredPosition)
		printf(" ==>> - -");
	else printf("             ");
}
void print_line() {
	printf("\n");
	int i;
	for (i = 0; i < 100; i++)
		printf("_");
	printf("\n\n");
}

int main()
{
	main_menu();
	return 0;
}
