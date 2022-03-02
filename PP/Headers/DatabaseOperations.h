#define DATABASE_PATH "Database/autovehicles.csv"
#define MAX_LEN 256

int AddToDatabase(Autovehicul autov) {
	FILE* fptr;
	char buffer[MAX_LEN];
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		fseek(fptr,0, SEEK_END);
		fprintf(fptr, "\n%d;%s;%s;%d;%.2lf;%d",autov.id, autov.marca,autov.tipAuto,autov.an,autov.capacitateMotor,autov.numarLocuri);
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





void initDatabase() {
	FILE* fptr;
	char buffer[MAX_LEN];
	buffer[0] = 0;
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		//ignoram prima linie pentru ca e header-ul
		fgets(buffer, MAX_LEN, fptr);
		if (buffer[0] == 0) { //lipseste header
			fprintf(fptr,"id;marca;tipAuto;an;capacitateMotor;numarLocuri");
		}

		fclose(fptr);
	}
}