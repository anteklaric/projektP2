#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"										

#define OPCIJA1 1
#define OPCIJA2 2
#define OPCIJA3 3
#define OPCIJA4 4
#define OPCIJA5 5
#define OPCIJA6 6
#define OPCIJA7 7
#define OPCIJA8 8
#define OPCIJA9 9
#define OPCIJA10 10
#define OPCIJA11 11
#define OPCIJA12 12
#define OPCIJA13 13


extern int brojIgraca = 0;
static int i, j, br = 0;



int izbornik() {

	int opcija = 0;              //1
	static IGRAC* polje = NULL;             //5,12
	int provjeraOpcije = 0;

	printf("Postovani, nalazite se u bazi podataka nogometnog kluba. \nOvdje uz pomoc odredenih opcija mozete pohraniti igrace i osnovne podatke o njima uz par opcija,\nkao naprimjer dodavanje, uredivanje, trazenje itd.\n");
	printf("Pod svakim brojem nalazi se opcija\n"); //8
	printf("%d Dodavanje igraca\n", OPCIJA1);
	printf("%d Uredivanje (postojeceg) igraca\n", OPCIJA2);
	printf("%d Ispisivanje igraca\n", OPCIJA3);
	printf("%d Sortiranje igraca po odredenim parametrima\n", OPCIJA4);
	printf("%d Trazenje igraca\n", OPCIJA5);
	printf("%d Brisanje igraca\n", OPCIJA6);
	printf("%d Izlaz iz programa\n", OPCIJA7);


	do {
		provjeraOpcije = scanf("%d", &opcija);

		if (provjeraOpcije != 1) {
			printf("Unijeli ste pogresan znak, molimo unesite broj!\n");
			while (getchar() != '\n');
		}
	} while (provjeraOpcije != 1);


	system("cls");

	switch (opcija) {
	case 1:
		ucitavanjeIgraca();    //4
		if (brojIgraca == 0) {
			kreiranjeDat();
		}
		dodavanjeIgraca();
		break;
	case 2:
		azuriranje();
		break;
	case 3:
		if (polje != NULL) {
			free(polje);        //15
			polje = NULL;
		}
		polje = (IGRAC*)ucitavanjeIgraca();
		ispisivanje(polje);
		break;
	case 4:
		while (opcija != 89) {
			opcija = izbornikSortiranje();
		}
		break;
	case 5:
		while (opcija != 90)
			opcija = izbornikTrazenje();
		break;
	case 6:
		if (polje == NULL)
			printf("Baza podataka prazna.");
		else
			brisanjeIgraca(polje);
		break;
	case 7:
		brisanjeBaze(polje);
		return 99;
		break;
	default:
		printf("\nOdabrali ste pogresan broj!\nMolim probajte ponovno.\n");
	}
	return opcija;

}



izbornikTrazenje() {                    //21
	int opcija = 0;
	IGRAC* polje = NULL;                //9

	int provjeraOpcije1 = 0;

	polje = (IGRAC*)ucitavanjeIgraca();
	printf("Pretraga po:\n");
	printf("\t%d Imenu\n", OPCIJA1);
	printf("\t%d Prezimenu\n", OPCIJA2);
	printf("\t%d Poziciji\n", OPCIJA3);
	printf("\t%d Broju dresa\n", OPCIJA4);
	printf("\t%d Broju nastupa\n", OPCIJA5);
	printf("\t%d Broju golova\n", OPCIJA6);
	printf("\t%d Broju asistencija\n", OPCIJA7);
	printf("\t%d Natrag\n", OPCIJA8);

	do {
		provjeraOpcije1 = scanf("%d", &opcija);

		if (provjeraOpcije1 != 1) {
			printf("Unijeli ste pogresan znak, molimo unesite broj!\n");
			while (getchar() != '\n');
		}
	} while (provjeraOpcije1 != 1);                 //9

	//scanf("%d", &opcija);
	system("cls");

	switch (opcija) {
	case 1:
		TraziIme(polje);
		break;
	case 2:
		TraziPrezime(polje);
		break;
	case 3:
		TraziPozicija(polje);
		break;
	case 4:
		TraziBrDresa(polje);
		break;
	case 5:
		TraziBrNastupa(polje);
		break;
	case 6:
		TraziBrGolova(polje);
		break;
	case 7:
		TraziBrAsistencija(polje);
		break;
	case 8:
		return 90;
	default: printf("Odabrali ste pogresan broj!\nMolim probajte ponovno.\n");
	}
	return opcija;
}
int izbornikSortiranje() {              //20
	int opcija = 0;
	IGRAC* polje = NULL;
	polje = (IGRAC*)ucitavanjeIgraca();

	int provjeraOpcije2 = 0;


	printf("Sortiraj prema:\n");
	printf("\t%d Imena igraca A-Z\n", OPCIJA1);
	printf("\t%d Imena igraca Z-A\n", OPCIJA2);
	printf("\t%d Prezimena igraca A-Z\n", OPCIJA3);
	printf("\t%d Prezimena igraca Z-A\n", OPCIJA4);
	printf("\t%d Brojevi dresova igraca uzlazno\n", OPCIJA5);
	printf("\t%d Brojevi dresova igraca silazno\n", OPCIJA6);
	printf("\t%d Broj nastupa igraca uzlazno\n", OPCIJA7);
	printf("\t%d Broj nastupa igraca silazno\n", OPCIJA8);
	printf("\t%d Broj golova igraca uzlazno\n", OPCIJA9);
	printf("\t%d Broj golova igraca silazno\n", OPCIJA10);
	printf("\t%d Broj asistencija igraca uzlazno\n", OPCIJA11);
	printf("\t%d Broj asistencija igraca silazno\n", OPCIJA12);
	printf("\t%d Natrag\n", OPCIJA13);

	do {
		provjeraOpcije2 = scanf("%d", &opcija);

		if (provjeraOpcije2 != 1) {
			printf("Unijeli ste pogresan znak, molimo unesite broj!\n");
			while (getchar() != '\n');
		}
	} while (provjeraOpcije2 != 1);

	//scanf("%d", &opcija);
	system("cls");

	switch (opcija) {
	case 1:
		sortImeUzlazno(polje);
		break;
	case 2:
		sortImeSilazno(polje);
		break;
	case 3:
		sortPrezimeUzlazno(polje);
		break;
	case 4:
		sortPrezimeSilazno(polje);
		break;
	case 5:
		sortBrDresaUzlazno(polje);
		break;
	case 6:
		sortBrDresaSilazno(polje);
		break;
	case 7:
		sortBrNastupaUzlazno(polje);
		break;
	case 8:
		sortBrNastupaSilazno(polje);
		break;
	case 9:
		sortBrGolovaUzlazno(polje);
		break;
	case 10:
		sortBrGolovaSilazno(polje);
		break;
	case 11:
		sortBrAsistencijaUzlazno(polje);
		break;
	case 12:
		sortBrAsistencijaSilazno(polje);
		break;
	case 13:
		return 89;
	default: printf("Odabrali ste pogresan broj!\nMolim probajte ponovno.\n");
	}
	return opcija;
}

void kreiranjeDat() {
	FILE* fp = NULL;            //10
	fp = fopen("igraci.bin", "wb");
	if (fp == NULL) {
		perror("Kreiranje");            //19
	}
	fwrite(&brojIgraca, sizeof(int), 1, fp);
	fclose(fp);
}

void dodavanjeIgraca() {
	FILE* fp = NULL;
	fp = fopen("igraci.bin", "rb+");
	if (fp == NULL)
		perror("Dodavanje");

	fread(&brojIgraca, sizeof(int), 1, fp);
	printf("Trenutni broj igraca: %d", brojIgraca);

	IGRAC igraci;
	igraci.id = brojIgraca;
	br++;
	getchar();
	printf("\nUnesite ime igraca: ");
	scanf("%29[^\n]", igraci.ime);
	getchar();
	printf("\nUnesite prezime igraca: ");
	scanf("%29[^\n]", igraci.prezime);
	getchar();
	printf("\nUnesite poziciju igraca: ");
	scanf("%14[^\n]", igraci.pozicija);
	getchar();
	printf("\nUnesite broj dresa igraca: ");
	scanf("%d", &igraci.brIgDresa);
	printf("\nUnesite broj nastupa igraca: ");
	scanf("%d", &igraci.brNastupa);
	printf("\nUnesite broj golova igraca: ");
	scanf("%d", &igraci.brGolova);
	printf("\nUnesite broj asistencija igraca: ");
	scanf("%d", &igraci.brAsis);
	fseek(fp, sizeof(IGRAC) * brojIgraca, SEEK_CUR);
	fwrite(&igraci, sizeof(IGRAC), 1, fp);
	rewind(fp);
	brojIgraca++;
	fwrite(&brojIgraca, sizeof(int), 1, fp);
	fclose(fp);
}

void azuriranje() {
	FILE* fp = NULL;
	int reload;
	int brojIgraca;

	fp = fopen("igraci.bin", "rb+");
	if (fp == NULL) {
		printf("Nije unesen ni jedan igrac.\n");
		return;
	}


	fread(&brojIgraca, sizeof(int), 1, fp);

	printf("Unesite ID igraca kojeg zelite ispraviti:\n");
	scanf("%d", &reload);


	if (reload < 0 || reload >= brojIgraca) {
		printf("Neispravan ID igraca.\n");
		fclose(fp);
		return;
	}


	fseek(fp, sizeof(int) + sizeof(IGRAC) * reload, SEEK_SET);

	IGRAC ispravljenIgrac;
	ispravljenIgrac.id = reload;
	getchar();

	printf("Unesite ispravljeno ime igraca: ");
	scanf("%29[^\n]", ispravljenIgrac.ime);
	getchar();

	printf("Unesite ispravljeno prezime igraca: ");
	scanf("%29[^\n]", ispravljenIgrac.prezime);
	getchar();

	printf("Unesite ispravljenu poziciju igraca: ");
	scanf("%14[^\n]", ispravljenIgrac.pozicija);
	getchar();

	printf("Unesite ispravljen broj dresa igraca: ");
	scanf("%d", &ispravljenIgrac.brIgDresa);
	getchar();

	printf("Unesite ispravljen broj nastupa igraca: ");
	scanf("%d", &ispravljenIgrac.brNastupa);
	getchar();

	printf("Unesite ispravljen broj golova igraca: ");
	scanf("%d", &ispravljenIgrac.brGolova);
	getchar();

	printf("Unesite ispravljen broj asistencija igraca: ");
	scanf("%d", &ispravljenIgrac.brAsis);
	getchar();


	fwrite(&ispravljenIgrac, sizeof(IGRAC), 1, fp);


	fclose(fp);
}



void* ucitavanjeIgraca() {
	FILE* fp = fopen("igraci.bin", "rb");
	if (fp == NULL) {
		printf("Nije unesen ni jedan igrac.\n");
		return NULL;
	}

	fread(&brojIgraca, sizeof(int), 1, fp);
	IGRAC* polje = (IGRAC*)calloc(brojIgraca, sizeof(IGRAC));       //13

	if (polje == NULL) {
		perror("Zauzimanje memorije");
		fclose(fp);
		return NULL;
	}

	fread(polje, sizeof(IGRAC), brojIgraca, fp);
	fclose(fp);
	return polje;
}

void ispisivanje(IGRAC* polje) {
	for (i = 0; i < brojIgraca; i++) {
		printf("ID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
	}
}

void* TraziIme(IGRAC* polje) {
	char trazenoIme[30];
	int br = 0;

	printf("Upisite ime trazenog igraca:\n");
	getchar();
	scanf("%29[^\n]", trazenoIme);

	for (i = 0; i < brojIgraca; i++) {
		if (!strcmp(trazenoIme, (polje + i)->ime)) {
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
			br++;
		}
	}
	if (br == 0)
		printf("\nIgrac pod ovim imenom nije pronaden.\n");
	return NULL;
}

void* TraziPrezime(IGRAC* polje) {
	char trazenoPrez[30];
	int br = 0;

	printf("Upisite prezime trazenog igraca:\n");
	getchar();
	scanf("%29[^\n]", trazenoPrez);

	for (i = 0; i < brojIgraca; i++) {
		if (!strcmp(trazenoPrez, (polje + i)->prezime)) {
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
			br++;
		}
	}
	if (br == 0)
		printf("\nIgrac pod ovim prezimenom nije pronaden.\n");
	return NULL;
}

void* TraziPozicija(IGRAC* polje) {         //10
	char trazenaPoz[15];
	int br = 0;

	printf("Upisite poziciju koju trazite:\n");
	getchar();
	scanf("%14[^\n]", trazenaPoz);

	for (i = 0; i < brojIgraca; i++) {
		if (!strcmp(trazenaPoz, (polje + i)->pozicija)) {
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
			br++;
		}
	}
	if (br == 0)
		printf("\nNije unesen niti jedan igrac na ovoj poziciji.\n");  //11
	return NULL;
}

void* TraziBrDresa(IGRAC* polje) {
	int trazeniBrD, br = 0;

	printf("Unesite broj dresa igraca kojeg trazite:\n");
	scanf("%d", &trazeniBrD);

	for (i = 0; i < brojIgraca; i++) {
		if (trazeniBrD == (polje + i)->brIgDresa) {
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
			br++;
		}
	}
	if (br == 0)
		printf("\nTrazeni broj dresa nije pronadjen.\n");       //11
	return NULL;
}

void* TraziBrNastupa(IGRAC* polje) {
	int trazeniBrN, br = 0;

	printf("Unesite broj nastupa igraca kojeg trazite:\n");
	scanf("%d", &trazeniBrN);

	for (i = 0; i < brojIgraca; i++) {
		if (trazeniBrN == (polje + i)->brNastupa) {
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
			br++;
		}
	}
	if (br == 0)
		printf("\nIgrac s trazenim brojem nastupa nije pronadjen.\n");
	return NULL;
}

void* TraziBrGolova(IGRAC* polje) {
	int trazeniBrGol, br = 0;

	printf("Unesite broj golova igraca kojeg trazite:\n");
	scanf("%d", &trazeniBrGol);

	for (i = 0; i < brojIgraca; i++) {
		if (trazeniBrGol == (polje + i)->brGolova) {
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
			br++;
		}
	}
	if (br == 0)
		printf("\nIgrac s trazenim brojem nastupa nije pronadjen.\n");
	return NULL;
}

void* TraziBrAsistencija(IGRAC* polje) {
	int trazeniBrA, br = 0;

	printf("Unesite broj asistencija igraca kojeg trazite:\n");
	scanf("%d", &trazeniBrA);

	for (i = 0; i < brojIgraca; i++) {
		if (trazeniBrA == (polje + i)->brAsis) {
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
			br++;
		}
	}
	if (br == 0)
		printf("\nIgrac s trazenim brojem nastupna nije pronadjen.\n");
	return NULL;
}

void zamjena(IGRAC* veci, IGRAC* manji) {
	IGRAC temp = { 0 };
	temp = *veci;
	*veci = *manji;
	*manji = temp;
}

void zamjena2(IGRAC* manji, IGRAC* veci) {
	IGRAC temp = { 0 };
	temp = *manji;
	*manji = *veci;
	*veci = temp;
}

void sortImeUzlazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (strcmp(polje[i].ime, polje[i + 1].ime) > 0) {
				zamjena2(&polje[i], &polje[i + 1]);
			}
		}
	}
	for (int i = 0; i < brojIgraca; i++) {
		printf("\nID: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
	}
	printf("\n");
}

void sortImeSilazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (strcmp(polje[i].ime, polje[i + 1].ime) < 0) {
				zamjena(&polje[i], &polje[i + 1]);
			}
		}
	}
	for (int i = 0; i < brojIgraca; i++) {
		printf("\nID: %d Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
	}
	printf("\n");
}

void sortPrezimeUzlazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (strcmp(polje[i].prezime, polje[i + 1].prezime) > 0) {
				zamjena2(&polje[i], &polje[i + 1]);
			}
		}
	}
	for (int i = 0; i < brojIgraca; i++) {
		printf("\nID: %d Prezime:%s Ime:%s Pozicija:%s  Broj dresa: %d  Broj nastupa: %d Broj golova: %d Broj asistencija: %d\n", (polje + i)->id, (polje + i)->prezime, (polje + i)->ime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
	}
	printf("\n");
}

void sortPrezimeSilazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (strcmp(polje[i].prezime, polje[i + 1].prezime) < 0) {
				zamjena(&polje[i], &polje[i + 1]);
			}
		}
	}
	for (int i = 0; i < brojIgraca; i++) {
		printf("\nID: %d Prezime:%s  Ime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d  Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->prezime, (polje + i)->ime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
	}
	printf("\n");
}

void sortBrDresaUzlazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (polje[i].brIgDresa > polje[i + 1].brIgDresa) {
				zamjena2((polje + i), (polje + i + 1));
			}
		}
	}
	for (i = 0; i < brojIgraca; i++) {
		printf("\nID: %d  Broj dresa: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj nastupa: %d  Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->brIgDresa, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
	}
	printf("\n");
}

void sortBrDresaSilazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (polje[i].brIgDresa < polje[i + 1].brIgDresa) {
				zamjena((polje + i), (polje + i + 1));
			}
		}
	}
	for (i = 0; i < brojIgraca; i++) {
		printf("\nID: %d  Broj dresa: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj nastupa: %d Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->brIgDresa, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brNastupa, (polje + i)->brGolova, (polje + i)->brAsis);
	}
	printf("\n");
}

void sortBrNastupaUzlazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (polje[i].brNastupa > polje[i + 1].brNastupa) {
				zamjena2((polje + i), (polje + i + 1));
			}
		}
	}
	for (i = 0; i < brojIgraca; i++) {
		printf("\nID: %d  Broj nastupa: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->brNastupa, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brGolova, (polje + i)->brAsis);
	}
	printf("\n");
}

void sortBrNastupaSilazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (polje[i].brNastupa < polje[i + 1].brNastupa) {
				zamjena((polje + i), (polje + i + 1));
			}
		}
	}
	for (i = 0; i < brojIgraca; i++) {
		printf("\nID: %d  Broj nastupa: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj golova: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->brNastupa, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brGolova, (polje + i)->brAsis);
	}
	printf("\n");
}
void sortBrGolovaUzlazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (polje[i].brGolova > polje[i + 1].brGolova) {
				zamjena2((polje + i), (polje + i + 1));
			}
		}
	}
	for (i = 0; i < brojIgraca; i++) {
		printf("\nID: %d  Broj golova: %d Broj nastupa: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->brGolova, (polje + i)->brNastupa, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brAsis);
	}
	printf("\n");
}

void sortBrGolovaSilazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (polje[i].brGolova < polje[i + 1].brGolova) {
				zamjena((polje + i), (polje + i + 1));
			}
		}
	}
	for (i = 0; i < brojIgraca; i++) {
		printf("\nID: %d  Broj golova: %d Broj nastupa: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj asistencija: %d\n", (polje + i)->id, (polje + i)->brGolova, (polje + i)->brNastupa, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brAsis);
	}
	printf("\n");
}

void sortBrAsistencijaUzlazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (polje[i].brAsis > polje[i + 1].brAsis) {
				zamjena2((polje + i), (polje + i + 1));
			}
		}
	}
	for (i = 0; i < brojIgraca; i++) {
		printf("\nID: %d  Broj asistencija: %d Broj nastupa: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj golova: %d\n", (polje + i)->id, (polje + i)->brAsis, (polje + i)->brNastupa, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brGolova);
	}
	printf("\n");
}

void sortBrAsistencijaSilazno(IGRAC* polje) {
	for (int j = 0; j < brojIgraca; j++) {
		for (int i = 0; i < brojIgraca - 1; i++) {
			if (polje[i].brAsis < polje[i + 1].brAsis) {
				zamjena((polje + i), (polje + i + 1));
			}
		}
	}
	for (i = 0; i < brojIgraca; i++) {
		printf("\nID: %d  Broj asistencija: %d Broj nastupa: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj golova: %d\n", (polje + i)->id, (polje + i)->brAsis, (polje + i)->brNastupa, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brGolova);
	}
	printf("\n");
}

void brisanjeIgraca(IGRAC* polje) {
	FILE* fp = NULL;
	fp = fopen("igraci.bin", "wb");         //16
	if (fp == NULL) {
		perror("Brisanje igraca");
	}
	rewind(fp);
	fseek(fp, sizeof(int), SEEK_CUR);       //17

	int br = 0, trazeniIgrac;

	printf("Unesite ID igraca kojeg zelite obrisati:");
	scanf("%d", &trazeniIgrac);

	for (i = 0; i < brojIgraca; i++) {
		if (trazeniIgrac != (polje + i)->id) {
			fwrite((polje + i), sizeof(IGRAC), 1, fp);
			br++;
		}
	}
	rewind(fp);
	fwrite(&br, sizeof(int), 1, fp);
	fclose(fp);
}

void brisanjeBaze(IGRAC* polje) {
	printf("Izbrisati datoteku pri izlasku iz programa ili je zadrzati?\n");
	printf("Ako zelite izbrisati datoteku napisite da, ako ne zelite napisite ne\n");

	char uvjet[3] = { '\0' };
	scanf("%2s", uvjet);
	if (!strcmp("da", uvjet)) {
		remove("igraci.bin") == 0 ? printf("Izbrisali ste datoteku igraci.bin.\n") : printf("Datoteka neuspjesno izbrisani ili ona ne postoji.\n");
		printf("\nIzlaz iz programa.\n");
		free(polje);    //14,15
	}
	else printf("\nZadrzali ste datoteku.\nIzlaz iz programa\n");
}
