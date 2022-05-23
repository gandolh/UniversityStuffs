#define APP_MESSAGE_COLOR CYAN
#define USER_MESSAGE_COLOR YELLOW
#define DATABASE_PATH "Database/autovehicles.csv"
#define MAX_LEN 256
#define FILTERS_COUNT 10
#define MAX_SIZE_MARCA 50
const char* TipAuto[] = {
	"S","A","B","C","D","\0"
};

typedef enum ConsoleColors {
    BLACK = 0,
    DARKBLUE = FOREGROUND_BLUE,
    DARKGREEN = FOREGROUND_GREEN,
    DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKRED = FOREGROUND_RED,
    DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
    DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
    DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY = FOREGROUND_INTENSITY,
    BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
}ConsoleColors;





void init();
void createAutovehicle(Autovehicul* autov, HANDLE hConsole);
char* trimString(char* str);
int ValidTipAuto(char* tip);
int ValidOptiuneSelectata(char* optiuneSelectata);
int  AddToDatabase(Autovehicul autov);
void PrintAllAutovehicles(HANDLE hConsole);
int getAutovehiclesCount();
char* getSearchingFilters();
int ValidTipAuto(char* tip);
char* trimString(char* str);
int ValidOptiuneSelectata(char* optiuneSelectata);
void SearchInDatabase(char* chosenFilter, char* keyword, char* result);
void initDatabase();