

void changeConsoleColor(HANDLE hConsole, ConsoleColors color) {
    SetConsoleTextAttribute(hConsole,
        color);
}

void PrettyPrint (HANDLE hConsole,const char * msg, ConsoleColors color) {
    changeConsoleColor(hConsole, color);
    printf("%s%s",msg , "\n");
}




char * GetTipuriAutovehicule( ) {
    char * result = calloc(50 , sizeof(char));
    int k = 0;
    for (int i = 0; TipAuto[i] != NULL; i++)
        if (result != NULL) {
            strcpy_s(result + strlen(result), 3, TipAuto[i]);
            if(TipAuto[i+1]!=NULL)
                strcpy_s(result + strlen(result),3, ",");
        }
    return result;

}

