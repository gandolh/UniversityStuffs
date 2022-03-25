

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

void PrintAllAutovehicles(HANDLE hConsole) {
	FILE* fptr;
	char buffer[MAX_LEN];
	fopen_s(&fptr, DATABASE_PATH, "a+");
	if (fptr) {
		fseek(fptr, 0, SEEK_SET);
		////ignoram prima linie pentru ca e header-ul
		//fgets(buffer, MAX_LEN, fptr);

		while(fgets(buffer, MAX_LEN, fptr))
		{
			// Remove trailing newline
			buffer[strcspn(buffer, "\n")] = 0;
			changeConsoleColor(hConsole,GREEN);
			for (int i = 0; buffer[i]; i++)if (buffer[i] == ';')buffer[i] = ' ';
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
	char* temp_str=calloc( sizeof(CSVHeader) / sizeof(char),sizeof(char));
	char* FilterTypes[FILTERS_COUNT];
	int index_temp_str = -1;
	for (int i = 0; CSVHeader[i]!=NULL; i++) {
		if (CSVHeader[i] == ';' || CSVHeader[i] == '\n') {
		temp_str[++index_temp_str] = '\0';
		FilterTypes[k] = malloc((strlen(temp_str))* sizeof(char));
		FilterTypes[k][strlen(FilterTypes[k])-1] = '\0';
		strcpy_s(FilterTypes[k],strlen(temp_str)+1, temp_str);
		temp_str[0] = '\0';
		index_temp_str = -1;
		k++;
		}
		else {
			//strcat_s(temp_str, 1, CSVHeader[i]);
			//strcpy_s(temp_str+ strlen(temp_str),1, CSVHeader[i]);
			temp_str[++index_temp_str] = CSVHeader[i];
		}
	}
	for (int i = 0; i<k; i++)
		if (result != NULL) {
			strcpy_s(result + strlen(result), strlen(FilterTypes[i]) +1, FilterTypes[i]);
			if (i<k-1)
				strcpy_s(result + strlen(result), 3, ",");
		}
	return result;

}

int CharacterCount(char* str, char c) {
	int i = 0,count=0;
	for (i = 0; str[i]; i++)
		if (str[i] == c)count++;
	return count;
}

void SearchInDatabase(char *chosenFilter, char* keyword,char *result) {
	FILE* fptr;
	char buffer[MAX_LEN];
	int lineCount = 0;
	fopen_s(&fptr, DATABASE_PATH, "r");
	if (fptr) {
		fseek(fptr, 0, SEEK_SET);
		char* CSV_header = malloc(MAX_LEN);
		fgets(CSV_header, MAX_LEN, fptr);
		char* beautifull_formated_csv_header = malloc(sizeof(char) * 255);
		strcpy(beautifull_formated_csv_header,CSV_header);
		for (int i = 0; beautifull_formated_csv_header[i]; i++)if(beautifull_formated_csv_header[i]==';')beautifull_formated_csv_header[i] = ' ';
		printf(beautifull_formated_csv_header);
		CSV_header[strstr(CSV_header, chosenFilter) - CSV_header + strlen(chosenFilter)] = '\0';
		int position_filter = CharacterCount(CSV_header,';');
		while (fgets(buffer, MAX_LEN, fptr))
		{
			char* found = strstr(buffer, keyword);
			if (found != 0) {
				char* foo_string = malloc(MAX_LEN * sizeof(char));
				strcpy(foo_string, buffer );
				foo_string[found - buffer + strlen(keyword)] = '\0';
				int position_result = CharacterCount(foo_string, ';');
				if (position_result == position_filter)strcpy(result,buffer);
			free(foo_string);
			}
		}
		free(CSV_header);
		fclose(fptr);
	}
	return lineCount;
}


void deleteRow(char* deletingId) {
	FILE* fptr;
	char** content = calloc(1024,sizeof(char));
	char buffer[MAX_LEN];
	char id[MAX_LEN];
	int k = 0,i,j;
	fopen_s(&fptr, DATABASE_PATH, "r");
	if (fptr) {
		while (fgets(buffer, MAX_LEN, fptr)) {
			strcpy(id, buffer);
			id[strstr(id, ";") - id] = '\0';
			if (strstr(id, deletingId) == 0) {
				content[k] = malloc(MAX_LEN * sizeof(char));
				strcpy(content[k], buffer);
				k++;
			}
		}
		fclose(fptr);
	}
	fopen_s(&fptr, DATABASE_PATH, "w");
	if (fptr) {
	for (i = 0; content[i]; i++) {
		content[i][strlen(content[i])] = '\0';
		fprintf(fptr, content[i]);
	}
	fclose(fptr);
	}
	free(content);
}

void replaceAutov(Autovehicul autov) {
	FILE* fptr;
	char buffer[MAX_LEN];
	fopen_s(&fptr, DATABASE_PATH, "r");
	char databaseCSV[MAX_LEN][MAX_LEN];
	int i = -1, updatingRowIndex=-1;
	if (fptr) {
		fseek(fptr, 0, SEEK_SET);
		while (fgets(buffer, MAX_LEN, fptr))
		{
			strcpy(databaseCSV[++i], buffer);
			if (buffer[0] == autov.id + '0')
				updatingRowIndex = i;
		}
		int rows = i;
		fclose(fptr);
		fopen_s(&fptr, DATABASE_PATH, "w+");
		fseek(fptr, 0, SEEK_SET);
		for (i = 0; i <= rows; i++) {
			if(updatingRowIndex!= i)
			fprintf(fptr, databaseCSV[i]);
			else 
			fprintf(fptr, "%d;%s;%s;%d;%.2lf;%d;%s\n", autov.id, autov.marca, autov.tipAuto, autov.an, autov.capacitateMotor, autov.numarLocuri, autov.nrAuto);
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
			fprintf(fptr,"id;marca;tipAuto;an;capacitateMotor;numarLocuri;numarDeInmatriculare");
		}

		fclose(fptr);
	}
}