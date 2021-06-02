#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct element {
	float x;
	struct element* next;
};

struct element* utworz() {
	return NULL;
}

struct element* dodaj(struct element* Lista, float a) {
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
	wsk->x = a;
	wsk->next = NULL;
	return Lista;
}

int wypisz(struct element *s, float a) {
	int liczba = 0;
	while (s != NULL) {
		if (s->x == a)
			liczba++;
		s = s->next;
	}
	return liczba;
}

int main(){

	printf("Zadanie 5\n");
	printf("Lista bez glowy\n");
	struct element* Lista_bez = utworz();
	Lista_bez = dodaj(Lista_bez, 3.2);
	Lista_bez = dodaj(Lista_bez, 5.3);
	Lista_bez = dodaj(Lista_bez, 8);
	Lista_bez = dodaj(Lista_bez, 3.2);
	Lista_bez = dodaj(Lista_bez, 3.2);
	Lista_bez = dodaj(Lista_bez, 2);
	printf("Liczba elementow rownych %g w liscie to %d", 3.2, wypisz(Lista_bez, 3.2));
}
