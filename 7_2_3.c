#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//Krystian Kręcik
struct zespolone {
	double re, im;
};

typedef struct zespolone zespolone;

zespolone foo5(zespolone tab1, zespolone tab2) {
	zespolone temp;
	temp.re = tab1.re + tab2.re;
	temp.im = tab1.im + tab2.im;
	return temp;
}

struct Student {
	char imie[30];
	char nazwisko[30];
	char adres[30];
	char pesel[30];
	char kierunek[30];
	char nr_leg[30];
};

typedef struct Student Student;

void foo6(Student& s) {
	scanf("%s", s.imie);
	scanf("%s", s.nazwisko);
	scanf("%s", s.adres);
	scanf("%s", s.pesel);
	scanf("%s", s.kierunek);
	scanf("%s", s.nr_leg);
}

union Liczba {
	int int_v;
	double double_v;
};

typedef union Liczba Liczba;

struct Dane {
	int tp;
	Liczba zaw;
};

typedef struct Dane Dane;

Dane foo6() {
	int a;
	Dane tmp;
	printf("Jesli chcesz wczytac liczbe calkowita wpisz 1, jesli liczbe wymiarna wpisz 0\n");
	scanf("%d", &tmp.tp);
	if (tmp.tp == 1) {
		printf("Wpisz liczbe calkowita: ");
		scanf("%d", &tmp.zaw.int_v);
	}
	else if (tmp.tp == 0) {
		printf("Wpisz liczbe wymierna: ");
		scanf("%lf", &tmp.zaw.double_v);
	}
	return tmp;
}

struct zespolone1 {
	Liczba im;
	Liczba re;
	int tp;
};
typedef struct zespolone1 zespolone1;

zespolone dodaj(zespolone1 a, zespolone1 b) {
	zespolone tmp = { 0,0 };
	if (a.tp == 1) {
		tmp.re = a.re.int_v + b.re.int_v;
		tmp.im = a.im.int_v + b.im.int_v;
		return tmp;

	}
	else if (a.tp == 0) {
		tmp.re = a.re.double_v + b.re.double_v;
		tmp.im = a.im.double_v + b.im.double_v;
		return tmp;

	}
	printf("rr");

}

enum stan {
	polaczenie_nazwiazane, polaczenie_nienazwiazane, polaczenie_w_trakcie
};

struct komputer {
	stan st;
	char ip[20];
	char nazwa[20];
};

void foo7(struct komputer k) {
	switch (k.st) {
	case 0: {
		printf("Uzytkownik: %s o IP: %s stan polaczenia: polaczenie_nazwiazane", k.nazwa, k.ip);
		break;
	}
	case 1: {
		printf("Uzytkownik: %s o IP: %s stan polaczenia: polaczenie_nienazwiazane", k.nazwa, k.ip);
		break;
	}
	case 2: {
		printf("Uzytkownik: %s o IP: %s stan polaczenia: polaczenie_w_trakcie", k.nazwa, k.ip);
		break;
	}
	}
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

struct element* utworz_1() {
	struct element* wsk = (struct element*)malloc(sizeof(struct element));
	wsk->next = NULL;
	return wsk;
}

void dodaj_2(struct element* Lista, int a) {
	struct element* wsk = (struct element*)malloc(sizeof(struct element));
	wsk->value = a;
	wsk->next = Lista->next;
	Lista->next = wsk;
}


void bezwzgledna(struct element* Lista) {
	while (Lista != NULL) {
		Lista->value = abs(Lista->value);
		Lista = Lista->next;
	}
}

void wypisz_x(struct element* Lista) {
	Lista = Lista->next;

	while (Lista != NULL) {
		printf("%d ", Lista->value);
		Lista = Lista->next;
	}
}

void wypisz_x2(struct element* Lista) {

	while (Lista != NULL) {
		printf("%d ", Lista->value);
		Lista = Lista->next;
	}
}
//Zadanie 7.2.15
enum zwierzak {
	pies, kot, chomik, szczur, swinka_morska
};

//7.3.22


struct Trojkat {
	double a, b, c, pole;
	struct Trojkat *next;
};

void pole(struct Trojkat *Lista) {
	while (Lista != NULL) {
		double p = Lista->a + Lista->b + Lista->c;
		p = p * (1. / 2);
		double pole = sqrt(p*(p-Lista->a)*(p-Lista->b)*(p-Lista->c));
		Lista->pole = pole;
		Lista = Lista->next;
	}
}

struct Trojkat* dodaj_b(struct Trojkat *Lista, int a, int b, int c) {
	struct Trojkat* wsk = (struct Trojkat*)malloc(sizeof(struct Trojkat));
	wsk->a = a;
	wsk->b = b;
	wsk->c = c;
	wsk->next = Lista;
	return wsk;
}
void dodaj_g(struct Trojkat *Lista, int a, int b, int c) {
	struct Trojkat* wsk = (struct Trojkat*)malloc(sizeof(struct Trojkat));
	wsk->a = a;
	wsk->b = b;
	wsk->c = c;
	wsk->next = Lista->next;
	Lista->next = wsk;
}

struct Trojkat * utworz_g() {
	struct Trojkat* wsk = (struct Trojkat*)malloc(sizeof(Trojkat));
	wsk->next = NULL;
	return wsk;
}

struct Trojkat * utworz_b() {
	return NULL;
}

void wypisz_g1(struct Trojkat *Lista) {
	Lista = Lista->next;
	while (Lista != NULL) {
		printf("Lista a=%g, b=%g, c=%g, pole=%g\n", Lista->a, Lista->b, Lista->c, Lista->pole);
		Lista = Lista->next;
	}
}
void wypisz_g2(struct Trojkat *Lista) {
	while (Lista != NULL) {
		printf("Lista a=%g, b=%g, c=%g, pole=%g\n", Lista->a, Lista->b, Lista->c, Lista->pole);
		Lista = Lista->next;
	}
}

int main() {
	printf("Zadanie 7.2.7\n");

	zespolone zad7a = { 4,4}, zad7b = { 9,91 }, suma7;

	suma7 = foo5(zad7a, zad7b);
	printf("Wynikiem dodawania lizcb %g+%gj + %g+%gj = %g+%gj",zad7a.re,zad7a.im,zad7b.re,zad7b.im,suma7.re,suma7.im);

	printf("\nZadanie 7.2.8\n");///Adam Kowalski Dworcowa_23/12 99124512512 Turystyka 148239
	//= { "Adam", "Kowalski", "Dworcowa_23/12","99124512512", "Turystyka", "148239" }
	Student stud;
	foo6(stud);
	printf("Imie:%s Nazwisko:%s Adres:%s Pesel:%s Kierunek:%s Numer legitymacji:%s", stud.imie, stud.nazwisko, stud.adres, stud.pesel, stud.kierunek, stud.nr_leg);

	printf("Zadanie 7.2.16\n");
	struct komputer k1;
	k1.st = polaczenie_nazwiazane;
	char tmp[] = "Marker";
	int i=0;
	for (int i = 0; tmp[i] != '\0'; i++)
		k1.nazwa[i] = tmp[i];
	k1.nazwa[i] = '\0';

	char tmp1[] = "192.162.0.1";
	for (i = 0; tmp1[i] != '\0'; i++)
		k1.ip[i] = tmp1[i];
	k1.ip[i] = '\0';
	foo7(k1);

	printf("\nZadanie 7.3.21\n");
	printf("Lista z glowa\n");
	struct element* Lista = utworz_1();
	dodaj_2(Lista, 10);
	dodaj_2(Lista, -9);
	dodaj_2(Lista, -3);
	dodaj_2(Lista, 10);
	wypisz_x(Lista);
	printf("\n");
	bezwzgledna(Lista);
	wypisz_x(Lista);
	printf("\nLista bez glowy\n");
	struct element* Lista_bez = utworz();
	Lista_bez = dodajk(Lista_bez, 10);
	Lista_bez = dodajk(Lista_bez, -3);
	Lista_bez = dodajk(Lista_bez, -17);
	Lista_bez = dodajk(Lista_bez, 10);
	wypisz_x2(Lista_bez);
	bezwzgledna(Lista_bez);
	printf("\n");
	wypisz_x2(Lista_bez);

	printf("\nZadanie 7.3.22\n");
	struct Trojkat* tr;
	tr = utworz_g();
	dodaj_g(tr, 4, 5, 6);
	dodaj_g(tr, 87,50,76);
	pole(tr);
	printf("Lista z glowa\n");
	wypisz_g1(tr); 

	printf("\nLista z bez glowy\n");
	struct Trojkat* tr2;
	tr2 = utworz_b();
	tr2 = dodaj_b(tr2, 23, 20, 16);
	tr2 = dodaj_b(tr2, 9, 8, 5);
	tr2 = dodaj_b(tr2, 100, 150, 101);
	pole(tr2);
	wypisz_g2(tr2);
}




