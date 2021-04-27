#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int abss(int a) {
	return a > 0 ? a : -a;
}

int main() {
	printf("Zadanie 1.3.1\n");
	int zad_1_3_1;
	scanf("%d", &zad_1_3_1);
	printf("Wartosc bezwzgledna z liczby: %d", zad_1_3_1>0?zad_1_3_1:-zad_1_3_1);

	printf("Zadanie 1.3.2\n");
	int zad_1_3_2a, zad_1_3_2b;
	scanf("%d%d", &zad_1_3_2a, &zad_1_3_2b);
	printf("Wieksza liczba to: %d", zad_1_3_2a > zad_1_3_2b ? zad_1_3_2a : zad_1_3_2b);
		
	printf("Zadanie 1.3.3\n");
	int zad_1_3_3a, zad_1_3_3b, zad_1_3_3c;
	scanf("%d%d%d", &zad_1_3_3a, &zad_1_3_3b, &zad_1_3_3c);//1
	printf("Wieksza liczba to: %d", (zad_1_3_3a>= zad_1_3_3b and zad_1_3_3a>= zad_1_3_3c)?zad_1_3_3a:(zad_1_3_3b>zad_1_3_3c?zad_1_3_3b:zad_1_3_3c));
	
	printf("Zadanie 1.3.4\n");
	int zad_1_3_4a, zad_1_3_4b;
	scanf("%d%d", &zad_1_3_4a, &zad_1_3_4b);
	int a = abss(zad_1_3_4a);
	int b = abss(zad_1_3_4b);
	printf("Liczba o wiekszej wartosci bezwzglednej to: %d", a > b ? zad_1_3_4a : zad_1_3_4b);
	
	printf("Zadanie 1.3.5\n");
	printf("Program oblicza pola trojkata na podstawie wymiarow\n");
	printf("Jesli chcesz podac tylko podstawe i wysokosc napisz znak h\n");
	printf("Jesli chcesz podac wszystkie boki napisz w\n");
	char z_1_3_5;
	int zad_1_3_5[3];
	scanf("%c", &z_1_3_5);
	switch (z_1_3_5) {
	case 'h':{
		scanf("%d%d", &zad_1_3_5[0], &zad_1_3_5[1]);
		printf("Pole to: %f", float(zad_1_3_5[0] * zad_1_3_5[1]) / 2);
		break;
	}
	case 'w': {
		double p;
		scanf("%d%d%d", &zad_1_3_5[0], &zad_1_3_5[1], &zad_1_3_5[2]);
		p = (zad_1_3_5[0] + zad_1_3_5[1] + zad_1_3_5[2]) / 2;
		printf("Pole to: %f",sqrt(p*(p- zad_1_3_5[0])*(p- zad_1_3_5[1])*(p- zad_1_3_5[2])));

		break;
	}
	default:
		printf("Zla wartosc");
	}
	
	printf("Zadanie 1.3.6\n");

	//[0]a1x + [1]b1y = [2]c1, det(Glowny) = a1 * b2 - a2 * b1, det(X) = c1*b2 - a2*c2 
	//[3]a2x + [4]b2y = [5]c2  det(Y) = a1*c2-a2*c1
	int zad_1_3_6[6];
	for (int i = 0; i < 6; i++)
		scanf("%d", &zad_1_3_6[i]);
	double det_g, det_x, det_y;
	det_g = zad_1_3_6[0] * zad_1_3_6[4] - zad_1_3_6[3] * zad_1_3_6[1];

	det_x = zad_1_3_6[2] * zad_1_3_6[4] - zad_1_3_6[5] * zad_1_3_6[1];
	det_y = zad_1_3_6[0] * zad_1_3_6[5] - zad_1_3_6[3] * zad_1_3_6[2];
	if (det_g == 0)
		if (det_x == 0 and det_y == 0)
			printf("Nieskonczenie wiele rozwiazan");
		else
			printf("Uklad sprzeczny");
	else
		printf("x: %f, y: %f", det_x / det_g, det_y / det_g);

	printf("Zadanie 1.3.7\n");// a[0] b[1] c[2] 
	printf("Podaj wspolczynniki rownania kwadratowego\n");
	int zad_1_3_7[3];
	for (int i = 0; i < 3; i++)
		scanf("%d", &zad_1_3_7[i]);

	double delta = zad_1_3_7[1] * zad_1_3_7[1] - 4 * zad_1_3_7[0] * zad_1_3_7[2];
	if (delta < 0)
		printf("Brak rozwiazan");
	else {
		delta = sqrt(delta);
		double x1, x2;
		x1 = (-zad_1_3_7[1] + delta) / (2 * zad_1_3_7[0]);
		x2 = (-zad_1_3_7[1] - delta) / (2 * zad_1_3_7[0]);
		printf("x1: %f, x2: %f", x1, x2);
	}

	printf("Zadanie 1.3.8\n");
	printf("Podaj znak ktorej figury chcesz obliczyc pole:\n");
	printf("Kwadrat: (k)\n");
	printf("Prostokat: (p)\n");
	printf("Trojkat: (t)\n");
	char z_1_3_8;
	scanf("%c", &z_1_3_8);
	int zad_1_3_8[3];
	switch (z_1_3_8) {
	case 'k':
		printf("Podaj bok kwadratu: ");
		scanf("%d", &zad_1_3_8[0]);
		printf("Pole kwadratu: %d", zad_1_3_8[0] * zad_1_3_8[0]);
		break;
	case 'p':
		printf("Podaj dwa boki prostokatu: ");
		scanf("%d%d", &zad_1_3_8[0], &zad_1_3_8[1]);
		printf("Pole kwadratu: %d", zad_1_3_8[0] * zad_1_3_8[1]);

		break;
	case 't': {

		printf("Podaj trzy boki trojkata: ");
		scanf("%d%d%d", &zad_1_3_8[0], &zad_1_3_8[1], &zad_1_3_8[2]);
		double p = (zad_1_3_8[0] + zad_1_3_8[1] + zad_1_3_8[2]) / 2;
		printf("Pole to: %f", sqrt(p * (p - zad_1_3_8[0]) * (p - zad_1_3_8[1]) * (p - zad_1_3_8[2])));
		break;
	}
	default:
		printf("Zle dane");
	}
		
	printf("Zadanie 1.3.9\n");
	printf("Kalkulator wykonujacy proste operacje arytmetyczne: +, -, *, /\n");
	printf("Wpisz odpowiednia liczbe w zaleznosci od dzialania\n");
	printf("1) Dodawanie\n");
	printf("2) Odejmowanie\n");
	printf("3) Mnozenie\n");
	printf("4) Dzielenie\n");
	int z_1_3_9;
	scanf("%d", &z_1_3_9);
	printf("Nastepnie wczytaj dwie liczby: ");
	int aa, bb;
	scanf("%d%d", &aa, &bb);
	switch (z_1_3_9) {
	case 1:
		printf("Wynik dodawania to: %d", aa + bb);
		break;
	case 2:
		printf("Wynik odejmowania to: %d", aa - bb);
		break;
	case 3:
		printf("Wynik mnozenia to: %d", aa * bb);
		break;
	case 4:
		printf("Wynik dzielenia to: %.2f", float(aa / bb));
		break;
	}
}
