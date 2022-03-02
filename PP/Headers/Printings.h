typedef enum ConsoleColors{
    BLACK             = 0,
    DARKBLUE          = FOREGROUND_BLUE,
    DARKGREEN         = FOREGROUND_GREEN,
    DARKCYAN          = FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKRED           = FOREGROUND_RED,
    DARKMAGENTA       = FOREGROUND_RED | FOREGROUND_BLUE,
    DARKYELLOW        = FOREGROUND_RED | FOREGROUND_GREEN,
    DARKGRAY          = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY              = FOREGROUND_INTENSITY,
    BLUE              = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN             = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN              = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED               = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA           = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW            = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE             = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
}ConsoleColors;

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

