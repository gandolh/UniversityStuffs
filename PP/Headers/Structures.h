#define MAX_SIZE_MARCA 50



const char* TipAuto[] = {
	"S","A","B","C","D","\0"
};


typedef struct Autovehicul {
	char* marca,
		* tipAuto; // din tipAuto[]
	int an;
	char* nrAuto;
	double capacitateMotor;
	int numarLocuri;
	struct Autovehicul* next;
}Autovehicul;

typedef struct Flota {
	char* denumire;
	char* numeReprezentant;
	int nrAutovehicule;
	Autovehicul* autos_head; //lista

} Flota;

