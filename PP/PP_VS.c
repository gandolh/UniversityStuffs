#include <stdio.h>
#include <windows.h>
#include "Headers/Structures.h"
#include "Headers/Printings.h"
#include "Headers/DatabaseOperations.h"
#define APP_MESSAGE_COLOR CYAN
#define USER_MESSAGE_COLOR YELLOW
Flota gandolhFleet;



void init();
void createAutovehicle(Autovehicul* autov);
int ValidTipAuto(char* tip);
char* trimString(char* str);
int ValidOptiuneSelectata(char* optiuneSelectata);

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
		PrettyPrint(hConsole, "\t4. Actualizeaza autoturism", APP_MESSAGE_COLOR);
		PrettyPrint(hConsole, "\t5. Sterge Autoturism", APP_MESSAGE_COLOR);
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
			PrintAllAutovehicles();
			break;
		case '2':
			break;
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
		case '4':
			break;
		case '5':
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