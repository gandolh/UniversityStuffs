#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)
#define MAX_LENGTH 256


const char* format_out = "%d, %d, %s, %lf, %d, %d, %d, %s\n"; //pt citire
typedef struct date {
    int tip;
    char* dest_surs;
    double suma;            //structura datelor introduse
    struct data {
        int year;
        int month;
        int day;
    }data;

    char* categorie;
}date;
struct date Date[MAX_LENGTH];
int k = 0, l = 0;
void add_date(FILE* fp) {

    int d;
    struct date entry;
    printf("Please chose an option:\n1-continue with adding an entry\n2-back to main menu\n");
    scanf("%d", &d);
    printf("\n");       //option to go back


    switch (d) {
    case 2:
        break;
    case 1: {
        char buffer[256];
        while (fgets(buffer, MAX_LENGTH, fp))
            k++;
        printf("type(1 for payment received/ 0 for sum paid)=");
        scanf("%d", &entry.tip);
        entry.dest_surs = malloc(50 * sizeof(char));
        printf("destination/source=");                                  //citire intrare
        scanf("%s", entry.dest_surs);
        printf("sum=");
        scanf("%lf", &entry.suma);
        printf("data(dd mm yy)=");
        scanf("%d%d%d", &entry.data.day, &entry.data.month, &entry.data.year);
        entry.categorie = malloc(50 * sizeof(char));
        printf("category=");
        scanf("%s", entry.categorie);
        printf("\n");

        fprintf(fp, format_out, k, entry.tip, entry.dest_surs, entry.suma, entry.data.day, entry.data.month,
            entry.data.year, entry.categorie);           ////adaugare in fisier

        Date[k - 1] = entry;
    }
    }
}


struct date* get_date(FILE* fp,int* size) {
    char* buffer = malloc(sizeof(char) * MAX_LENGTH);
    *size = 0;
    struct date* Date = malloc(sizeof(date) * 255);
    int k = 0;
    fseek(fp,0,SEEK_SET);
    while (fgets(buffer, MAX_LENGTH, fp)) {
        //printf(buffer);
        char* p = strtok(buffer, ", ");
        p = strtok(NULL,", ");
        Date[*size].tip = p[0]-'0';
        p = strtok(NULL,", ");
        Date[*size].dest_surs = malloc(sizeof(char) * 255);
        strcpy(Date[*size].dest_surs ,p);
        p = strtok(NULL,", ");
        Date[*size].suma = atof(p);
        p = strtok(NULL,", ");
        Date[*size].data.day= atoi(p);
        p = strtok(NULL, ", ");
        Date[*size].data.month = atoi(p);
        p = strtok(NULL, ", ");
        Date[*size].data.year = atoi(p);
        p = strtok(NULL,", ");
        Date[*size].categorie = malloc(sizeof(char) * 255);
        strcpy(Date[*size].categorie, p);
        Date[*size].categorie[strlen(Date[*size].categorie) - 1] = 0;
        (*size)++;
    }
    free(buffer);
    return Date;
}
void search_date(FILE* fp){
    date* Date = get_date(fp,&k);
    int h, opt1, t, d, m, y, ok = 0;
    char* cat;
    printf("Please chose an option:\n1-continue with the search\n2-back to main menu\n");
    scanf("%d", &h);
    printf("\n");
    switch (h) {
    case 2:
        break;
    case 1:
        printf("You are searching based on:\n1-type\n2-date\n3-category\n");
        scanf("%d", &opt1);
        printf("\n");
        switch (opt1) {
        case 1:
            printf("Searching for type:");
            scanf("%d", &t);
            printf("\n");
            printf("ENTRIES OF THIS TYPE:\n");
            for (int i = 0; i < k; i++) {
                if (Date[i].tip == t) {
                    printf("Entry number %d\ntip=%d\ndestination/source=%s\nsum=%lf\ndata=%d.%d.%d\ncategory=%s\n", i + 1,
                        Date[i].tip, Date[i].dest_surs, Date[i].suma,
                        Date[i].data.day, Date[i].data.month, Date[i].data.year, Date[i].categorie);
                    ok = 1;
                    printf("\n");
                }
            }
            if (!ok) printf("Entries of this type do not exist\n");
            break;

        case 2:
            printf("Searching for date(dd mm yy):");
            scanf("%d%d%d", &d, &m, &y);
            printf("\n");
            printf("ENTRIES FROM THIS DATE:\n");
            for (int i = 0; i < k; i++) {
                if (Date[i].data.day == d && Date[i].data.month == m && Date[i].data.year == y)
                    printf("Entry number %d\ntip=%d\ndestination/source=%s\nsum=%lf\ndata=%d.%d.%d\ncategory=%s\n", i + 1,
                        Date[i].tip, Date[i].dest_surs, Date[i].suma, Date[i].data.day,
                        Date[i].data.month, Date[i].data.year, Date[i].categorie);
                ok = 1; printf("\n");
            }
            if (!ok) printf("There are no entries with this date\n");
            break;
        case 3:
            printf("Searching for category:");
            printf("\n");
             cat = (char*)malloc(255 * sizeof(char));
            scanf("%s", cat);
            printf("ENTRIES OF THIS CATEGORY:\n");
            for (int i = 0; i < k; i++) {
                if (strcmp(Date[i].categorie, cat) == 0)
                    printf("Entry number %d\ntip=%d\ndestination/source=%s\nsum=%lf\ndata=%d.%d.%d\ncategory=%s\n", i + 1,
                        Date[i].tip, Date[i].dest_surs, Date[i].suma, Date[i].data.day, Date[i].data.month,
                        Date[i].data.year, Date[i].categorie);
                ok = 1; printf("\n");
            }
            if (!ok) printf("Entries of this category do not exist:\n");
            break;

        }
    }
}
void view_date(FILE* fp) {
    int g, i, ok = 0;
    struct date entry;
    char* buffer = malloc(sizeof(char) * MAX_LENGTH);
    printf("Please chose an option:\n1-continue with viewing all entries\n2-back to main menu\n");
    scanf("%d", &g);
    printf("\n");
    switch (g) {
    case 2:
        break;
    case 1:
        fseek(fp, 0, SEEK_SET);
        while (fgets(buffer, MAX_LENGTH, fp)) {
            printf(buffer);
            // printf("tip=%d destination/source=%s sum=%lf data=%d.%d.%d category=%s\n",entry.tip,
            //        entry.dest_surs,entry.suma,entry.data.day,entry.data.month,entry.data.year,entry.categorie);
            // printf("\n");
            ok = 1;
        }
        if (!ok) printf("There are no entries\n");
    }
    free(buffer);
}

int main(int argc, char* argv[]) {
    int n = 1, opt;
    FILE* fp;
    while (n) {
        printf("Please select an option:\n1-add entry\n2-search\n3-view all\n4-exit\n");

        scanf("%d", &opt);
        switch (opt) {
        case 1:
            fp = fopen("entries.txt", "a+");
            if (fp == NULL) printf("fisierul pentru intrari nu exista.");
            else {
                add_date(fp);
                fclose(fp);
            }
            break;
        case 2:
            fp = fopen("entries.txt", "r");
            if (fp == NULL) printf("fisierul pentru intrari nu exista.");
            else {
                search_date(fp);
                fclose(fp);
            }
            break;
        case 3:
            fp = fopen("entries.txt", "r");
            if (fp == NULL) printf("fisierul pentru intrari nu exista.");
            else {
                view_date(fp);
                fclose(fp);
            }
                break;
        case 4:
            n = 0;
            system("cls");
            printf("La revedere!");
            break;
        }
    }

    return 0;
}