#define DATABASE_PATH "Database/autovehicles.csv"
#define MAX_LEN 256

int AddToDatabase(Autovehicul autov) {
	FILE* fptr;
	char buffer[MAX_LEN];
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		fseek(fptr,0, SEEK_END);
		fprintf(fptr, "\n%s;%s;%d;%lf;%d", autov.marca,autov.tipAuto,autov.an,autov.capacitateMotor,autov.numarLocuri);
		fclose(fptr);
	}
	return 1;
}

void PrintAllAutovehicles() {
	FILE* fptr;
	char buffer[MAX_LEN];
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
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

void initDatabase() {
	FILE* fptr;
	char buffer[MAX_LEN];
	buffer[0] = 0;
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		//ignoram prima linie pentru ca e header-ul
		fgets(buffer, MAX_LEN, fptr);
		if (buffer[0] == 0) { //lipseste header
			fprintf(fptr,"marca;tipAuto;an;capacitateMotor;numarLocuri");
		}

		fclose(fptr);
	}
}