#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int foo(int n, int m) {
	if (n == 0 and m == 0)
		return 0;
	else if (n == 1 and m == 1)
		return 1;
	else if (n == m)
		return foo(n - 1, m - 1) + foo(n - 2, m - 2);
	else if (n > m)
		return foo(n - 1, m);
	else if (n < m) {
		return foo(n, m - 1);
	}
	else 
		printf("Zle\n");
}

int suma(int **tab, int n) {
	int p = 0;
	int q = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				p += tab[i][j];
			else if (n - 1-i == j)
				q += tab[i][j];
	if (p > q)
		return p;
	else return q;
}

void wczytaj(int **tab, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tab[i][j] = i * j-3;
}

struct car {
	char model[30];
	char marka[30];
	int cena;
};

void wczytaj_s(struct car &s) {
	printf("Wczyaj dane do struktury\n");
	printf("Podaj model: ");
	scanf("%s", &s.model);
	printf("Podaj marke: ");
	scanf("%s", &s.marka);
	printf("Podaj cene: ");
	scanf("%d", &s.cena);
}

int rozmiar(char* tab) {
	int i = 0;
	for (i = 0; tab[i] != '\0'; i++) {
	}
	return i;
}

void wyszukaj_auto(struct car *s,char *marka, int n) {
	bool flag;
	for (int i = 0; i < n; i++) {
		flag = true;
		for (int j = 0; j < rozmiar(marka); j++) {
			if (s->marka[i] != marka[i])
				flag = false;
		}
		if (flag == true) {
			printf("Model: %s Marka: %s Cena: %d\n", s->model,s->marka,s->cena);
		}
	}
}



void cena_low(struct car* s, int cena, int n) {
	printf("Auta o cenie nizszej niz %d\n", cena);
	for (int i = 0; i < n; i++) {
		if (s[i].cena < cena)
			printf("Model: %s Marka: %s Cena: %d\n", s[i].model, s[i].marka, s[i].cena);
	}
}

void wypisz_auto(struct car &s) {
	printf("Model: %s Marka: %s Cena: %d\n", s.model, s.marka, s.cena);

}

struct element {
	int value;
	element* next;
};

struct element* utworz() {
	return NULL;
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

struct element* usun(struct element* Lista) {
	struct element* wsk, * wsk2;
	if (Lista == NULL)
		return Lista;
	wsk = Lista;

	if (wsk->next != NULL) {
		wsk2 = wsk->next;
		wsk->next = wsk2->next;
		free(wsk2);
	}
	
	return Lista;
}

void wypisz_x2(struct element* Lista) {
	struct element* tmp = Lista;
	int rozmiar = 0;
	while (Lista != NULL) {
		rozmiar++;
		Lista = Lista->next;
	}
	Lista = tmp;
	for (int i = 0; Lista != NULL; Lista = Lista->next, i++) {
		if (rozmiar%2 == 0 and i == rozmiar/2-2) {
				usun(Lista);
				usun(Lista);
				break;
		}
		else {
			if (i == rozmiar / 2-1) {
				usun(Lista);
				break;
			}
		}
	}

	printf("\nWypisuje elementy listy\n");
	while (tmp != NULL) {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int main(){

	printf("Zadanie 1\n");
	int f1 = foo(7, 12);
	int f2 = foo(11, 9);
	if (f1 > f2) 
		printf("Wartosc foo(7, 12)[%d] > foo(11, 9)[%d]", f1, f2);
	else
		printf("Wartosc foo(7, 12)[%d] < foo(11, 9)[%d]", f1, f2);


	printf("Zadanie 2\n");

	int n;
	do {
		printf("Podaj liczbe mniejsza od 10\n");
		scanf("%d", &n);
	} while (n>10);
	int** tab = (int**)malloc(n*sizeof(int*));
	for (int i = 0; i < n; i++)
		tab[i] = (int*)malloc(n*sizeof(int));

	wczytaj(tab, n);
	printf("%d",suma(tab, n));
		
	printf("Zadanie 3\n");
	struct car s[5];
	for (int i = 0; i < 5; i++) {
		printf("Auto nr: %d\n",i + 1);
		wczytaj_s(s[i]);
	}
	cena_low(s, 300,5);

	printf("Zadanie 4\n");
	printf("Lista bez glowy\n");
	struct element* Lista_bez = utworz();
	Lista_bez = dodajk(Lista_bez, 1);
	Lista_bez = dodajk(Lista_bez, 5);
	Lista_bez = dodajk(Lista_bez, 8);
	Lista_bez = dodajk(Lista_bez, 7);
	Lista_bez = dodajk(Lista_bez, 2);

	wypisz_x2(Lista_bez);
	wypisz_x2(Lista_bez);
}
