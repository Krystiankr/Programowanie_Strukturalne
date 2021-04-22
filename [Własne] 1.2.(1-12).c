#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int main() {
	printf("Zadanie 1.2.1\n");
	printf("Hello World!\n");
	
	printf("Zadanie 1.2.2\n");
	char napis[] = "Bardzo dlugi napis";
	for (int i = 0; napis[i] != '\0'; i++)
		napis[i] == ' ' ? printf("\n") : printf("%c", napis[i]);
	
	printf("Zadanie 1.2.3\n");
	printf("\"Napis zawierajacy rozne dziwne znaczki //\\ \\ $ % & %%\"");
	
	printf("Zadanie 1.2.4\n");
	int zad_1_2_4;
	scanf("%d", &zad_1_2_4);
	printf("Twoja liczba to: %d", zad_1_2_4);

	printf("Zadanie 1.2.5\n");
	float zad_1_2_5;
	scanf("%f", &zad_1_2_5);
	printf("Twoja liczba to: %f", zad_1_2_5);
	
	printf("Zadanie 1.2.6\n");
	int zad_1_2_6a, zad_1_2_6b, zad_1_2_6c;
	scanf("%d %d %d", &zad_1_2_6a, &zad_1_2_6b, &zad_1_2_6c);
	printf("%d\n%d\n%d\n", zad_1_2_6a, zad_1_2_6b, zad_1_2_6c);
	
	printf("Zadanie 1.2.7\n");
	int zad_1_2_7;
	scanf("%d", &zad_1_2_7);
	printf("Liczba o jeden wieksza: %d", zad_1_2_7+1);
	
	printf("Zadanie 1.2.8\n");
	int zad_1_2_8[3];
	scanf("%d %d %d", &zad_1_2_8[0], &zad_1_2_8[1], &zad_1_2_8[2]);
	printf("Srednia arytmetyczna liczb: %f", float(zad_1_2_8[0] + zad_1_2_8[1] + zad_1_2_8[2]) / 3);
	
	printf("Zadanie 1.2.9\n");
	int zad_1_2_9;
	scanf("%d", &zad_1_2_9);
	if (zad_1_2_9 > 0)
		printf("Pierwiastek z %d to: %f", zad_1_2_9, sqrt(zad_1_2_9));
	else
		printf("Liczba ujemna.");
	
	printf("Zadanie 1.2.10\n");
	float zad_1_2_10;
	scanf("%f", &zad_1_2_10);
	if (zad_1_2_10 < 0)
		zad_1_2_10 *= -1;
	printf("Wartosc bezwzgledna twojej liczby to: %f", zad_1_2_10);
	
	printf("Zadanie 1.2.11\n");
	float zad_1_2_11;
	scanf("%f", &zad_1_2_11);
	printf("Twoja liczba wymierna zaokraglona do dwoch miejsc po przecinku: %.2f", zad_1_2_11);
	
	printf("Zadanie 1.2.12\n");
	float zad_1_2_12;
	scanf("%f", &zad_1_2_12);
	printf("%.e", zad_1_2_12);
}
