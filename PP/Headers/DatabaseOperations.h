#define DATABASE_PATH "Database/autovehicles.csv"
#define MAX_LEN 256
#define FILTERS_COUNT 10

int AddToDatabase(Autovehicul autov) {
	FILE* fptr;
	char buffer[MAX_LEN];
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		fseek(fptr,0, SEEK_END);
		fprintf(fptr, "\n%d;%s;%s;%d;%.2lf;%d;%s",autov.id, autov.marca,autov.tipAuto,autov.an,autov.capacitateMotor,autov.numarLocuri,autov.nrAuto);
		fclose(fptr);
	}
	return 1;
}

void PrintAllAutovehicles() {
	FILE* fptr;
	char buffer[MAX_LEN];
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		fseek(fptr, 0, SEEK_SET);
		//ignoram prima linie pentru ca e header-ul
		fgets(buffer, MAX_LEN, fptr);

		while(fgets(buffer, MAX_LEN, fptr))
		{
			// Remove trailing newline
			buffer[strcspn(buffer, "\n")] = 0;
			printf("%s\n", buffer);
		}

		fclose(fptr);
	}
}


int getAutovehiclesCount() {
	FILE* fptr;
	char buffer[MAX_LEN];
	int lineCount=0;
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		fseek(fptr, 0, SEEK_SET);
		while (fgets(buffer, MAX_LEN, fptr))
		{
			lineCount++;
		}

		fclose(fptr);
	}
	return lineCount;
}


char* getSearchingFilters() {
	char* result = calloc(250, sizeof(char));
	FILE* fptr;
	char CSVHeader[MAX_LEN];
	rsize_t strmax = sizeof CSVHeader;
	const char* delim = ";";
	char* next_token;

	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		fseek(fptr, 0, SEEK_SET);
		fgets(CSVHeader, MAX_LEN, fptr);
		fclose(fptr);
	}

	int k = 0;
	char* temp_str;
	char* FilterTypes[FILTERS_COUNT];

	for (int i = 0; strlen(CSVHeader); i++) {
		if (CSVHeader[i] == ';') {

		temp_str[strlen(temp_str)] = '\0';
		strcpy_s(FilterTypes[k++], temp_str);
		temp_str[0] = '\0';
		}
		else {
			temp_str[strlen(temp_str)] = CSVHeader[i];
		}
	}
	for (int i = 0; FilterTypes[i] != NULL; i++)
		if (result != NULL) {
			strcpy_s(result + strlen(result), 3, FilterTypes[i]);
			if (FilterTypes[i + 1] != NULL)
				strcpy_s(result + strlen(result), 3, ",");
		}
	return result;

}


void initDatabase() {
	FILE* fptr;
	char buffer[MAX_LEN];
	buffer[0] = 0;
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		//ignoram prima linie pentru ca e header-ul
		fgets(buffer, MAX_LEN, fptr);
		if (buffer[0] == 0) { //lipseste header
			fprintf(fptr,"id;marca;tipAuto;an;capacitateMotor;numarLocuri;numarDeInmatriculare");
		}

		fclose(fptr);
	}
}