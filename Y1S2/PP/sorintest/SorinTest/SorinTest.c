#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

const char* restaurantroom_path = "restaurantrooms.txt";;
const char* reserved_path = "reserved.txt";
//nume, capacitate, pretTotal, dataInceput, dataSfarsit, facilitatiAlese
const char* reserved_format = "%s;%d;%d;%s;%s;%s\n";
char ignoreEndl;
typedef struct SalaRestaurant {
    int id;
    char* nume;
    int capacitate;
    char* facilitati;
    int pretTotal;

}SalaRestaurant;


typedef struct Rezervare {
    int salaRestaurantId;
    char* dataInceput;
    char* dataSfarsit;
    char* facilitatiAlese;

}Rezervare;
SalaRestaurant** sali;
Rezervare** rezervari;
int saliCount = -1;
int RezervariCount = -1;
void view_all(const char * file_path) {
    FILE* filePointer;
    char buffer[255];
    filePointer = fopen(file_path, "r");
    if (filePointer) {
        int ok = 0;
        while (fgets(buffer, 255, filePointer)) {
            if (buffer[0] != '\n') {
                buffer[strlen(buffer)-1] = '\0';
                for (int i = 0; i < strlen(buffer); i++) {
                    if (buffer[i] == ';') {
                        char temp[255];
                        strcpy(temp,buffer+i+1);
                        strcpy(buffer+i+2, temp);
                        buffer[i] = ',';
                        buffer[i + 1] = ' ';
                       // int x = 1;
                    }
                    }
                printf("%s\n", buffer);
                ok = 1;
            }
        }
        if (!ok)printf("nu exista inregistrari.\n");
        fclose(filePointer);
    }
    else {
        printf("fisierul %s nu a putut fi accesat\n", file_path);
    }
}
void readSaliRestaurant(const char* file_path) {
    FILE* filePointer;
    char buffer[255];
    filePointer = fopen(file_path, "r");
    for (int i = 0; i <= saliCount; i++) {
        free(sali[i]->facilitati);
        free(sali[i]->nume);
        free(sali[i]);
    }
    saliCount = -1;
    if (filePointer) {
        while (fgets(buffer, 255, filePointer)) {
            if (buffer[0] != '\n') {
                sali[++saliCount] = malloc(sizeof(SalaRestaurant));
                sali[saliCount]->nume= malloc(sizeof(char)*255);
                sali[saliCount]->facilitati = malloc(sizeof(char)*255);
                char* p = strtok(buffer,";");
                sali[saliCount]->id = atoi(p);
                p = strtok(NULL,";");
                strcpy(sali[saliCount]->nume, p);
                p = strtok(NULL,";");
                sali[saliCount]->capacitate = atoi(p);
                p = strtok(NULL,";");
                strcpy(sali[saliCount]->facilitati, p);
                p = strtok(NULL, ";");
                sali[saliCount]->pretTotal = atoi(p);
            }
        }
        fclose(filePointer);
    }
    else {
        printf("fisierul %s nu a putut fi accesat\n", file_path);
    }
}

void readAllReserved(const char* file_path) {
    FILE* filePointer;
    char buffer[255];
    filePointer = fopen(file_path, "r");
    for (int i = 0; i <= RezervariCount; i++) {
        free(rezervari[i]->dataInceput);
        free(rezervari[i]->dataSfarsit);
        free(rezervari[i]->facilitatiAlese);
        free(rezervari[i]);
    }
    RezervariCount = -1;
    if (filePointer) {
        while (fgets(buffer, 255, filePointer)) {
            if (buffer[0] != '\n') {
                rezervari[++RezervariCount] = malloc(sizeof(Rezervare));
                rezervari[RezervariCount]->dataInceput = malloc(sizeof(char) * 255);
                rezervari[RezervariCount]->dataSfarsit= malloc(sizeof(char) * 255);
                rezervari[RezervariCount]->facilitatiAlese= malloc(sizeof(char) * 255);
                char numeSala[255];
                char* p = strtok(buffer, ";");
                strcpy(numeSala,p);
                p = strtok(NULL, ";");
                p = strtok(NULL, ";");
                p = strtok(NULL, ";");
                strcpy(rezervari[RezervariCount]->dataInceput, p);
                p = strtok(NULL, ";");
                strcpy(rezervari[RezervariCount]->dataSfarsit, p);
                p = strtok(NULL, ";");
                p[strlen(p) - 1] = 0;
                strcpy(rezervari[RezervariCount]->facilitatiAlese, p);

                rezervari[RezervariCount]->salaRestaurantId = -1;
                for (int i = 0; i <= saliCount; i++)
                    if (strcmp(sali[i]->nume, numeSala) == 0)
                        rezervari[RezervariCount]->salaRestaurantId = i;
                //int x = 1;
            }
        }
        fclose(filePointer);
    }
    else {
        printf("fisierul %s nu a putut fi accesat\n", file_path);
    }
}
void reserve(char* entries_path) {
    readSaliRestaurant(restaurantroom_path);
    FILE* filePointer;
    char buffer[255];
    filePointer = fopen(entries_path, "a+");
    if (filePointer) {
        //nume, capacitate, pretTotal, dataInceput, dataSfarsit, facilitatiAlese
        //const char* reserved_format = "%s %d %d %s %s %s";
        //fprintf(filePointer, entries_format,);
        int idSala;
        rezervari[++RezervariCount] = malloc(sizeof(Rezervare*));
        rezervari[RezervariCount]->dataInceput = malloc(sizeof(char)*255);
        rezervari[RezervariCount]->dataSfarsit = malloc(sizeof(char)*255);
        rezervari[RezervariCount]->facilitatiAlese = malloc(sizeof(char)*255);
        printf("Salile disponibile sunt:\n");
        for (int i = 0; i <= saliCount; i++)
            printf("nr: %d, nume: %s, capacitate: %d, facilitati: %s, pret total: %d\n",
                sali[i]->id, sali[i]->nume,sali[i]->capacitate, sali[i]->facilitati, sali[i]->pretTotal);
        printf("Introduceti numarul sali pe care doriti sa o rezervati:\n");
        scanf("%d",&rezervari[RezervariCount]->salaRestaurantId);
        SalaRestaurant sr = *sali[0];
        for (int i = 0; i <= saliCount; i++) {
            if (sali[i]->id == rezervari[RezervariCount]->salaRestaurantId)
                sr = *sali[i];
        }
        printf("Introduceti data de inceput: (dd mm yyyy)\n");
        scanf("%c", &ignoreEndl);
        scanf("%[^\n]", rezervari[RezervariCount]->dataInceput);
        printf("Introduceti data de sfarsit: (dd mm yyyy)\n");
        scanf("%c", &ignoreEndl);
        scanf("%[^\n]", rezervari[RezervariCount]->dataSfarsit);
        printf("Introduceti facilitatile alese, separate prin \", \":\n");
        printf("Facilitati disponibile sunt: %s\n", sr.facilitati);
        scanf("%c", &ignoreEndl);
        scanf("%[^\n]", rezervari[RezervariCount]->facilitatiAlese);
        fprintf(filePointer, reserved_format, sr.nume, sr.capacitate, sr.pretTotal, rezervari[RezervariCount]->dataInceput,
            rezervari[RezervariCount]->dataSfarsit, rezervari[RezervariCount]->facilitatiAlese);
        fclose(filePointer);
    }
    else {
        printf("fisierul %s nu a putut fi accesat\n", entries_path);
    }
}

void search_all(char* file_path) {
    int capacitate;
    char facilitati[255], facilitati_copy[255];
    int opt;
    printf("Introduceti:\n");
    printf("1: pentru cautarea dupa capacitate\n");
    printf("2: pentru cautarea dupa facilitati\n");

    scanf("%d", &opt);
    if (opt == 1) {
        printf("Introduceti capacitate:\n");
        scanf("%d", &capacitate);
        for (int i = 0; i <= saliCount; i++)
            if (sali[i]->capacitate == capacitate)
                printf("%d, %s, %d, %s, %d lei\n",i,sali[i]->nume,sali[i]->capacitate,sali[i]->facilitati,sali[i]->pretTotal);
    }
    else {
    printf("Introduceti facilitatile dorite  separate prin \",\":\n");
    scanf("%c", &ignoreEndl);
    scanf("%[^\n]", facilitati);
    strcpy(facilitati_copy,facilitati);
    for (int i = 0; i <= saliCount; i++) {
        char* p = strtok(facilitati,",");
        while (p) {
            if (p[strlen(p) - 1] == '\n')p[strlen(p) - 1] = 0;
            if (strstr(p, sali[i]->facilitati) != 0)
                continue;

            p = strtok(NULL, ",");
         }

        printf("%d, %s, %d, %s, %d lei\n", i, sali[i]->nume, sali[i]->capacitate, sali[i]->facilitati, sali[i]->pretTotal);
        strcpy(facilitati,facilitati_copy);
    }
    }
}


void write_only(const char* path, const char nume[], char dataInceput[], char dataSfarsit[]) {
    FILE* filePointer;
    char buffer[255][255];
    filePointer = fopen(path, "r");
    int k = -1;
    if (filePointer) {
        while (fgets(buffer[++k], 255, filePointer)) {}
        fclose(filePointer);
    }
    else {
        printf("fisierul %s nu a putut fi accesat\n", path);
    }


    filePointer = fopen(path, "w+");
    if (filePointer) {
        //nume, capacitate, pretTotal, dataInceput, dataSfarsit, facilitatiAlese
        //const char* reserved_format = "%s %d %d %s %s %s";
        //fprintf(filePointer, entries_format,);
        while (k>0 && buffer[--k]) {
            if (strstr(buffer[k], nume) == NULL || strstr(buffer[k], dataInceput) == NULL || strstr(buffer[k], dataSfarsit) == NULL)
                fprintf(filePointer,buffer[k]);
        }
        fclose(filePointer);
    }
    else {
        printf("fisierul %s nu a putut fi accesat\n", path);
    }
}


void cancel(char *path) {
    char nume[255], dataInceput[255], dataSfarsit[255];
    printf("Introduceti numele salii:\n");
    scanf("%c", &ignoreEndl);
    scanf("%[^\n]", nume);
    printf("Introduceti data de inceput:\n");
    scanf("%c", &ignoreEndl);
    scanf("%[^\n]", dataInceput);
    printf("Introduceti data de sfarsit:\n");
    scanf("%c", &ignoreEndl);
    scanf("%[^\n]", dataSfarsit);

        write_only(path,nume,dataInceput,dataSfarsit);
}
int main() {
    char ch='0';
    sali= malloc(sizeof(SalaRestaurant*) * 255);
    rezervari = malloc(sizeof(Rezervare*) * 255);
    readSaliRestaurant(restaurantroom_path);
    readAllReserved(reserved_path);
    do {
    /*system("cls");*/
    printf("Introduceti: \n");
    printf("1: Vizualizeaza toate salile de restaurant\n");
    printf("2: Creaza o rezervare\n");
    printf("3: Cauta o rezervare\n");
    printf("4: Anuleaza o rezervare\n");
    printf("5: Vizualizeaza toate rezervarile\n");
    printf("6: exit\n");
    do {
        scanf("%c", &ch);
    } while (ch == '\n');
    
    switch (ch) {
    case '1':
        view_all(restaurantroom_path);
        break;
    case '2':
        reserve(reserved_path);
        break;
    case '3':
        search_all(restaurantroom_path);
        break;
    case '4':
        cancel(reserved_path);
        break;
    case '5':
        view_all(reserved_path);
        break;
    case '6':
        printf("La revedere!");
        break;
    }


        
    } while (ch != '6');

   /* for (int i = 0; i <= saliCount; i++) {
        free(sali[i]->facilitati);
        free(sali[i]->nume);
        free(sali[i]);
    }
    for (int i = 0; i <= RezervariCount; i++) {
        free(rezervari[i]->dataInceput);
        free(rezervari[i]->dataSfarsit);
        free(rezervari[i]->facilitatiAlese);
        free(rezervari[i]);
    }*/
    }
