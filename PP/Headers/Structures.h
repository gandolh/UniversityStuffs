#define MAX_SIZE_MARCA 50



const char* TipAlimentare[] = {
	"Benzina",
	"Motorina",
	"Electric",
	"GPL"
};

const char* TipAuto[] = {
	"A","A1","B","B1","C","D"
};


typedef struct Autovehicul {
	char* marca,
		* tipAuto; // din tipAuto[]
	int an;
	char* nrAuto;
	double capacitateMotor;
	char* tipAlimentare; // din TipAlimentare[]
	int numarLocuri;
	struct Autovehicul* next;
}Autovehicul;

typedef struct Flota {
	char* denumire;
	char* numeReprezentant;
	int nrAutovehicule;
	Autovehicul* autos_head; //lista

} Flota;

