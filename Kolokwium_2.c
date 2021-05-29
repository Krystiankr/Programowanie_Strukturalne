#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
// Krystian Kręcik wariant 10
void zad_1(int *a, int *b) {
	if (*b < *a) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

int ** wczytaj(int m, int n) {
	int** tab = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
		tab[i] = (int*)malloc(n * sizeof(int));
	for (int i =0;i<m;i++)
		for (int j = 0; j < n; j++) {
			//tab[i][j] = i + j * 2 - 10;
			printf("Podaj wartosc dla tab[%d][%d]: \n", i, j);// 3 2   -9 8 1 -4 4 2
			scanf("%d", &tab[i][j]);
		}
	return tab;
}

void wypisz(int m, int n, int **tab) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("\ntab[%d][%d] = %d ", i, j, tab[i][j]);
		printf("\n");
	}

}

int druga(int m, int n, int **tab) {
	int max_ujemny = 0, wiersz, kolumna;
	bool pierwszy = true;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (tab[i][j]<0) {
				if (pierwszy == true) {
					max_ujemny = tab[i][j];
					pierwszy = false;
					wiersz = i;
					kolumna = j;
				}
				else {
					if (tab[i][j] > max_ujemny)
						max_ujemny = tab[i][j];
						wiersz = i;
						kolumna = j;
				}
			}
	if (max_ujemny != 0) {
		printf("Wartosc najwiekszego ujemnego elementu tablicy wynosi: %d numer wiersza: %d, numer kolumny: %d\n", max_ujemny, wiersz, kolumna);
	}
	return max_ujemny; 
}

struct Student {
	char imie[100];
	char nazwisko[100];
	char kierunek[100];
	int numer_legitymacji;
};

void zad_3(struct Student *s) {
	printf("Prosze podac imie studenta: ");
	scanf("%s", &s->imie);
	printf("\nProsze podac nazwisko studenta: ");
	scanf("%s", &s->nazwisko);
	printf("\nProsze podac kierunek studenta: ");
	scanf("%s", &s->kierunek);
	printf("\nProsze podac numer legitymacji: ");
	scanf("%d", &s->numer_legitymacji);
}

void wypisz_stud(struct Student *s) {
	printf("Imie studenta: %s\n", s->imie);
	printf("Nazwisko studenta: %s\n", s->nazwisko);
	printf("Kierunek studenta: %s\n", s->kierunek);
	printf("Numer legitymacji studenta: %d\n", s->numer_legitymacji);
}

void zad_3_druga(struct Student *tab, int n) {
	for (int i = 0; i < n; i++) {
		printf("Dane studenta nr: %d\n", i+1);
		zad_3(&tab[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("Dane studenta nr: %d\n", i + 1);
		wypisz_stud(&tab[i]);
	}
}

struct element {
	int value;
	element* next;
};


struct element* utworz() {
	return NULL;
}

struct element* dodaj_b(struct element* Lista, int value) {
	struct element* wsk = (struct element*)malloc(sizeof(struct element));
	wsk->value = value;
	wsk->next = Lista;
	return wsk;
}

struct element* dodajk(struct element* Lista, int a) {
	struct element* wsk;
	if (Lista == NULL) {
		Lista = wsk = (struct element*)malloc(sizeof(struct element));
	}
	else {
		wsk = Lista;
		while (wsk->next != NULL) {
			wsk = wsk->next;
		}
		wsk->next = (struct element*)malloc(sizeof(struct element));
		wsk = wsk->next;
	}
	wsk->value = a;
	wsk->next = NULL;
	return Lista;
}

void wypisz_lista(struct element* Lista) {
	int licznik = 0;
	while (Lista != NULL) {
		if (licznik % 3 == 0)
			printf("Lista value:%d\n", Lista->value);
		Lista = Lista->next;
		licznik += 1;
	}
}

struct element * wczytuj_dane_lista(struct element * Lista) {
	printf("Podaj liczbe do wczytania: \n");
	int tmp;
	scanf("%d", &tmp);
	Lista = dodajk(Lista, tmp);
	return Lista;
}

int main() {

	printf("Zadanie 1\n");
	int a, b;
	printf("Prosze podac dwie liczby calkowite: ");
	scanf("%d%d", &a, &b);
	printf("Stan zmiennych: a=%d, b=%d\n", a, b);
	zad_1(&a, &b);
	printf("Po wywolaniu funkcji stan zmiennych: a=%d, b=%d", a, b);
	
	printf("Zadanie 2\n");
	int m, n;
	printf("Podaj wymiary macierzy: ");
	do {
		scanf("%d %d", &m, &n);
		if (m <= 10 and n <= 10 and m > 0 and n > 0) {
			printf("Prawidlowe dane: ");
		}
		else {
			printf("M i N musza byc liczbami dodatnimi mniejszymi niz 10\n");
			printf("Podaj ponownie liczby: ");
		}
	} 	while (not(m <= 10 and n <= 10 and m > 0 and n > 0));

	printf("m=%d, n=%d\n", m, n);
	int** tab = wczytaj(m,n);
	wypisz(m,n,tab);
	int zad_2 = druga(m, n, tab);//Funkcja druga od razu przypisuje 0 jesli brak ujemnego elementu.
	if (zad_2 == 0) {
		printf("Brak ujemnych elementow w tablicy.\n");
	}
	
	printf("Zadanie 3\n");
	struct Student stud;
	//zad_3(&stud);
	struct Student stud_tab[5];
	zad_3_druga(stud_tab,5);
	
	printf("Zadanie 4\n");

	struct element* Lista;
	Lista = utworz();
	int ile;
	printf("Ile chcesz wczytac liczb? ");
	scanf("%d", &ile);
	for (int i =0;i<ile;i++)
		Lista = wczytuj_dane_lista(Lista);
	wypisz_lista(Lista);
}




