#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"										

static int brojIgraca = 0;
static int i, j, br = 0;

int izbornik() {

	int opcija = 0;											//1
	static IGRAC* polje = NULL;								//5,12

	printf("Postovani, nalazite se u bazi podataka nogometnog kluba. \nOvdje uz pomoc odredenih opcija mozete pohraniti igrace i osnovne podatke o njima uz par opcija,\nkao naprimjer dodavanje, uredivanje, trazenje itd.\n");
	printf("Pod svakim brojem nalazi se opcija\n");		//8
	printf("%d Dodavanje igraca\n", 1);
	printf("%d Uredivanje (postojeceg) igraca\n", 2);
	printf("%d Ispisivanje igraca\n", 3);
	printf("%d Sortiranje igraca po odredenim parametrima\n", 4);
	printf("%d Trazenje igraca\n", 5);
	printf("%d Brisanje igraca\n", 6);
	printf("%d Izlaz iz programa\n", 7);


	scanf("%d", &opcija);
	system("cls");

	switch (opcija) {
	case 1:
		ucitavanjeIgraca();									//4
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
			free(polje);									//15
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



izbornikTrazenje() {												//21
	int opcija = 0;
	IGRAC* polje = NULL;										//9
	polje = (IGRAC*)ucitavanjeIgraca();
	printf("Pretraga po:\n");
	printf("\t%d Imenu\n", 1);
	printf("\t%d Prezimenu\n", 2);
	printf("\t%d Poziciji\n", 3);
	printf("\t%d Broju dresa\n", 4);
	printf("\t%d Broju nastupa\n", 5);
	printf("\t%d Natrag\n", 6);

	scanf("%d", &opcija);										//9
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
		return 90;
	default: printf("Odabrali ste pogresan broj!\nMolim probajte ponovno.\n");
	}
	return opcija;
}
int izbornikSortiranje() {												//20
	int opcija = 0;
	IGRAC* polje = NULL;
	polje = (IGRAC*)ucitavanjeIgraca();
	printf("Sortiraj prema:\n");
	printf("\t%d Imena igraca uzlazno\n", 1);
	printf("\t%d Imena igraca silazno\n", 2);
	printf("\t%d Prezimena igraca uzlazno\n", 3);
	printf("\t%d Prezimena igraca silazno\n", 4);
	printf("\t%d Brojevi dresova igraca uzlazno\n", 5);
	printf("\t%d Brojevi dresova igraca silazno\n", 6);
	printf("\t%d Natrag\n", 7);

	scanf("%d", &opcija);
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
		return 89;
	default: printf("Odabrali ste pogresan broj!\nMolim probajte ponovno.\n");
	}
	return opcija;
}

void kreiranjeDat() {												//10
	FILE* fp = NULL;
	fp = fopen("igraci.bin", "wb");
	if (fp == NULL) {
		perror("Kreiranje");									//19
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
	getchar();
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

	fp = fopen("igraci.bin", "rb+");
	if (fp == NULL) {
		printf("Niste unijeli niti jednog igraca.\n");
		return;
	}

	printf("Unesite ID igraca kojeg zelite ispraviti:\n");
	scanf("%d", &reload);


	if (reload <= 0 || reload > brojIgraca) {
		printf("Neispravan ID igraca.\n");
		fclose(fp);
		return;
	}

	fseek(fp, sizeof(int) + sizeof(IGRAC) * (reload - 1), SEEK_SET);
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

	fwrite(&ispravljenIgrac, sizeof(IGRAC), 1, fp);
	rewind(fp);
	fwrite(&brojIgraca, sizeof(int), 1, fp);
	fclose(fp);
}


void* ucitavanjeIgraca() {															//10
	FILE* fp = fopen("igraci.bin", "rb");
	if (fp == NULL) {
		printf("Niste unijeli niti jednog igraca.\n");
		return NULL;
	}

	fread(&brojIgraca, sizeof(int), 1, fp);
	IGRAC* polje = (IGRAC*)calloc(brojIgraca, sizeof(IGRAC));						//13

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
		printf("ID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n",(polje+i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
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
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n",(polje+i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
			br++;
		}
	}
	if (br == 0)
		printf("\nIgrac pod ovim imenom nije pronaden.\n");								//11
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
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n",(polje+i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
			br++;
		}
	}
	if (br == 0)
		printf("\nIgrac pod ovim prezimenom nije pronaden.\n");
	return NULL;
}

void* TraziPozicija(IGRAC* polje) {										//10
	char trazenaPoz[15];
	int br = 0;

	printf("Upisite poziciju koju trazite:\n");
	getchar();
	scanf("%14[^\n]", trazenaPoz);

	for (i = 0; i < brojIgraca; i++) {
		if (!strcmp(trazenaPoz, (polje + i)->pozicija)) {
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n",(polje+i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
			br++;
		}
	}
	if (br == 0)
		printf("\nNije unesen niti jedan igrac na ovoj poziciji.\n");		//11
	return NULL;
}

void* TraziBrDresa(IGRAC* polje) {
	int trazeniBrD, br = 0;

	printf("Unesite broj dresa igraca kojeg trazite:\n");
	scanf("%d", &trazeniBrD);

	for (i = 0; i < brojIgraca; i++) {
		if (trazeniBrD == (polje + i)->brIgDresa) {
			printf("\nID:%d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n",(polje+i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
			br++;
		}
	}
	if (br == 0)
		printf("\nTrazena broj dresa nije pronadjen.\n");			//11
	return NULL;
}

void* TraziBrNastupa(IGRAC* polje) {
	int trazeniBrN, br = 0;

	printf("Unesite broj nastupa igraca kojeg trazite:\n");
	scanf("%d", &trazeniBrN);

	for (i = 0; i < brojIgraca; i++) {
		if (trazeniBrN == (polje + i)->brNastupa) {
			printf("\nID: %d  Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n",(polje+i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
			br++;
		}
	}
	if (br == 0)
		printf("\nIgrac s trazenim brojem nasstupna nije pronadjena.\n");			//11
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
		printf("\nID: %d Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
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
		printf("\nID: %d Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
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
		printf("\nID: %d Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
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
		printf("\nID: %d Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
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
		printf("\nID: %d Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
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
		printf("\nID: %d Ime:%s  Prezime:%s  Pozicija:%s  Broj dresa: %d  Broj nastupa: %d\n", (polje + i)->id, (polje + i)->ime, (polje + i)->prezime, (polje + i)->pozicija, (polje + i)->brIgDresa, (polje + i)->brNastupa);
	}
	printf("\n");
}

void brisanjeIgraca(IGRAC* polje) {
	FILE* fp = NULL;
	fp = fopen("igraci.bin", "wb");				//16
	if (fp == NULL) {
		perror("Brisanje igraca");
	}
	rewind(fp);
	fseek(fp, sizeof(int), SEEK_CUR);			//17

	int br = 0, reqIgr;

	printf("Unesite ID igraca kojeg zelite obrisati:");
	scanf("%d", &reqIgr);

	for (i = 0; i < brojIgraca; i++) {
		if (reqIgr != (polje + i)->id) {
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
		remove("igraci.bin") == 0 ? printf("Izbrisali ste datoteku igraci.bin.\n") : printf("Datoteka neuspjesno izbrisani ili ona ne postoji.\n");				//18
		printf("\nIzlaz iz programa.\n");
		free(polje);							//14,15
	}
	else printf("\nZadrzali ste datoteku.\nIzlaz iz programa\n");
}