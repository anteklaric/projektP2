#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct igrac {										//2,3
	int id;
	char ime[30];
	char prezime[30];
	char pozicija[15];
	int brIgDresa;
	int brNastupa;
}IGRAC;

int izbornik();
int izbornikTrazenje();
int izbornikSortiranje();
void kreiranjeDat();
void dodavanjeIgraca();
void azuriranje();
void* ucitavanjeIgraca();
void ispisivanje(IGRAC*);
void* TraziIme(IGRAC*);
void* TraziPrezime(IGRAC*);
void* TraziPozicija(IGRAC*);
void* TraziBrDresa(IGRAC*);
void* TraziBrNastupa(IGRAC*);
void zamjena(IGRAC*, IGRAC*);
void zamjena2(IGRAC*, IGRAC*);
void sortImeUzlazno(IGRAC*);
void sortImeSilazno(IGRAC*);
void sortPrezimeUzlazno(IGRAC* polje);
void sortPrezimeSilazno(IGRAC* polje);
void sortBrDresaUzlazno(IGRAC*);
void sortBrDresaSilazno(IGRAC*);
void brisanjeIgraca(IGRAC*);
void brisanjeBaze(IGRAC*);

#endif //FUNCTIONS_H