#include <stdio.h>
#include <windows.h>
#include "Headers/Structures.h"
#include "Headers/Gandolhs.h"
#include "Sources/Printings.c"
#include "Sources/DatabaseOperations.c"

Flota gandolhFleet;

int main() {
	init();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char optiuneSelectata[3];
	SetConsoleTitle(L"O luna max");
	PrettyPrint(hConsole, "Buna ziua,cu ce va putem ajuta astazi?", APP_MESSAGE_COLOR);


	do {
		PrettyPrint(hConsole, "\t1. Vizualizeaza toate autoturismele", APP_MESSAGE_COLOR);
		PrettyPrint(hConsole, "\t2. Cauta un autoturism", APP_MESSAGE_COLOR);
		PrettyPrint(hConsole, "\t3. Adauga autoturism", APP_MESSAGE_COLOR);
		PrettyPrint(hConsole, "\t4. Actualizeaza autoturism (Mai intai cautati id-ul)", APP_MESSAGE_COLOR);
		PrettyPrint(hConsole, "\t5. Sterge Autoturism (Mai intai cautati id-ul)", APP_MESSAGE_COLOR);
		changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
		gets(optiuneSelectata, stdin);
		fflush(stdin);
		int succeeded = 0;
		while (!ValidOptiuneSelectata(optiuneSelectata)) {
			PrettyPrint(hConsole, "Introduceti o optiune valida", RED);
			changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
			gets(optiuneSelectata, stdin);
			fflush(stdin);
		}
		switch (optiuneSelectata[0]) {
		case '1':
			PrintAllAutovehicles(hConsole);
			break;
		case '2': {
			char* Filters = getSearchingFilters();
			char* chosenFilter = malloc(255, sizeof(char));
			changeConsoleColor(hConsole, APP_MESSAGE_COLOR);
			printf("Alegeti un criteriu de cautare dintre:\n( %s )\n", Filters);
			changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
			gets(chosenFilter, stdin);
			trimString(chosenFilter);
			trimString(Filters);

			while (strstr(Filters, chosenFilter) == 0) {
				PrettyPrint(hConsole, "Introduceti un filtru valid", RED);
				changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
				gets(chosenFilter, stdin);
				trimString(chosenFilter);
			}
			PrettyPrint(hConsole, "Introduceti cuvantul cheie pentru cautare", APP_MESSAGE_COLOR);
			char* keyword = malloc(255, sizeof(char));
			changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
			gets(keyword, stdin);
			trimString(keyword);
			char* searchResult = malloc(MAX_LEN* sizeof(char));
			changeConsoleColor(hConsole,GREEN);
			SearchInDatabase(chosenFilter, keyword, searchResult);
			printf(searchResult);
			free(searchResult);
			free(keyword);
			free(chosenFilter);
			break;
		}
		case '3':
		{
			Autovehicul autov;
			createAutovehicle(&autov, hConsole);
			succeeded = AddToDatabase(autov);
			if (succeeded == 1)
				PrettyPrint(hConsole, "Elementul a fost adaugat cu succes", GREEN);
			else PrettyPrint(hConsole, "Eroare la adaugarea in baza de date", RED);
			//free(&autov);
			break;
		}
		case '4': {
			char* editingId = calloc(MAX_LEN, sizeof(char));
			Autovehicul editedAutovhechicle;

			PrettyPrint(hConsole, "Id-ul autovehiculului de modificat:",APP_MESSAGE_COLOR);
			changeConsoleColor(hConsole,USER_MESSAGE_COLOR);
			gets(editingId, stdin);
			PrettyPrint(hConsole,"Daca nu doriti sa modificati lasa-ti campul gol", APP_MESSAGE_COLOR);
			createAutovehicle(&editedAutovhechicle, hConsole);
			//EditRow();
			//EditRow();
			//ca la delete doar ca in loc de delete row ai edit row.
			//eventual str replace pe splituri.
			//custrtok?
		}
			break;
		case '5': {
			char* deletingId = calloc(MAX_LEN,sizeof(char));
			PrettyPrint(hConsole, "Id-ul autovehiculului de sters:", USER_MESSAGE_COLOR);
			gets(deletingId,stdin);
			deleteRow(deletingId);

		}
			break;
		default: {
			int x = 1;
		}
		}

		PrettyPrint(hConsole, "Altceva?", APP_MESSAGE_COLOR);
	} while (1);




	return 0;
}


void init() {
	gandolhFleet.denumire = "Flota lui gandolh";
	gandolhFleet.numeReprezentant = "gandolh";
	gandolhFleet.nrAutovehicule = getAutovehiclesCount();
	gandolhFleet.autos_head = NULL;
	initDatabase();
}

char* trimString(char* str)
{
	char* end;

	while (isspace((unsigned char)*str)) str++;

	if (*str == 0)
		return str;

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;

	end[1] = '\0';

	return str;
}

int ValidTipAuto(char* tip) {
	for (int i = 0; i < TipAuto[i] != NULL; i++) {
		if (strcmp(tip, TipAuto[i]) == 0)
			return 1;
	}
	return 0;
}

int ValidOptiuneSelectata(char* optiuneSelectata) {
	if (strlen(optiuneSelectata) != 1)return 0;
	if (optiuneSelectata[0] < '1' || optiuneSelectata[0] > '5')
		return 0;
	return 1;
}

void createAutovehicle(Autovehicul* autov, HANDLE hConsole) {
	autov->marca = malloc((MAX_SIZE_MARCA + 1) * sizeof(char));
	autov->nrAuto = malloc(11 * sizeof(char));
	char* tipAutov = malloc(11 * sizeof(char));;

	autov->id = getAutovehiclesCount();


	PrettyPrint(hConsole, "Introduceti marca autovehicului:", APP_MESSAGE_COLOR);
	changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
	gets(autov->marca, sizeof(autov->marca), stdin);

	PrettyPrint(hConsole, "Introduceti anul autovehiculului:", APP_MESSAGE_COLOR);
	changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
	scanf_s("%d", &autov->an);

	PrettyPrint(hConsole, "Introduceti tipul autovehicului:", APP_MESSAGE_COLOR);
	printf("tipurile disponibile sunt: ");
	changeConsoleColor(hConsole, BLUE);
	printf("%s\n", GetTipuriAutovehicule());
	changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
	gets(tipAutov, sizeof(tipAutov), stdin);
	gets(tipAutov, sizeof(tipAutov), stdin);
	trimString(tipAutov);
	while (!ValidTipAuto(tipAutov)) {
		PrettyPrint(hConsole, "Introduceti un tip valid", RED);
		changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
		gets(tipAutov, sizeof(tipAutov), stdin);
		trimString(tipAutov);
	}
	changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
	autov->tipAuto = tipAutov;



	PrettyPrint(hConsole, "Introduceti capacitatea cilindrica a motorului in litri", APP_MESSAGE_COLOR);
	changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
	scanf_s("%lf", &autov->capacitateMotor);
	PrettyPrint(hConsole, "Introduceti numarul de locuri", APP_MESSAGE_COLOR);
	changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
	scanf_s("%d", &autov->numarLocuri);
	PrettyPrint(hConsole, "Introduceti numarul matricol (faraspatii):", APP_MESSAGE_COLOR);
	changeConsoleColor(hConsole, USER_MESSAGE_COLOR);
	gets(autov->nrAuto, sizeof(autov->nrAuto), stdin);
	gets(autov->nrAuto, sizeof(autov->nrAuto), stdin);

	autov->next = NULL;
}