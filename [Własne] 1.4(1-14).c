#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int aabs(int a) {
	return a > 0 ? a : -a;
}

int silnia(int n) {
	if (n == 1 or n == 0)
		return 1;
	else return n * silnia(n - 1);
}

double square(double n) {
	int sqr = n / 2;
	int temp = 0;
	while (temp != sqr) {
		temp = sqr;
		sqr = (n / temp + temp) / 2;
	}
	return sqr;
}

int fib(int n) {
	if (n == 0 or n == 1)
		return n;
	else
		return fib(n-2) + fib(n - 1);
}

int NWD(int a, int b) {
	for (int i = a; i > 0; i--)
		if (b % i == 0 and a % i == 0)
			return i;
	return 1;
}

int main() {

	printf("Zadanie 1.4.1\n");
	printf("Podaj dwie dodatnie liczby calkowite: ");
	int zad_1_4_1a, zad_1_4_1b;
	scanf("%d%d", &zad_1_4_1a, &zad_1_4_1b);

	for (int i = 0; i * zad_1_4_1a < zad_1_4_1b; i++)
		printf("%d) Wielokrotnosc: %d\n", i+1,zad_1_4_1a * i);
	
	printf("Zadanie 1.4.2\n");
	printf("Podaj dwie dodatnie liczby calkowite: ");
	int zad_1_4_2a, zad_1_4_2b;
	scanf("%d%d", &zad_1_4_2a, &zad_1_4_2b);

	for (int i = 0; i < zad_1_4_2b; i++)
		printf("%d) Wielokrotnosc: %d\n", i + 1, zad_1_4_2a * i);
	

	printf("Zadanie 1.4.3\n");
	//m[0] < krotnos(n)[1] < k[2]
	
	int zad_1_4_2[3]; 
	for (int i = 0; i < 3; i++)
		scanf("%d", &zad_1_4_2[i]);
	for (int i = zad_1_4_2[0] / zad_1_4_2[1]; i * zad_1_4_2[1] < zad_1_4_2[2]; i++)
		if (zad_1_4_2[0] < zad_1_4_2[1] * i)
			printf("%d) Wielokrotnosc: %d\n", i,i * zad_1_4_2[1]);
	
	printf("Zadanie 1.4.4\n");
	printf("Podaj liczbe do obliczenia silni: ");
	int zad_1_4_4, zad_1_4_4b=1;
	scanf("%d", &zad_1_4_4);
	if (zad_1_4_4 > 0)
		for (int i = 1; i <= zad_1_4_4; i++)
			zad_1_4_4b *= i;
	printf("\nWynik silni to: %d", zad_1_4_4b);
	
	printf("Zadanie 1.4.5\n");// n=1, 1, n=2, 5, n=3, 14, n=4 30
	printf("Podaj liczbe n do obliczenia wartosci 0^2+1^2+2^2+...n^2: ");
	int zad_1_4_5, zad_1_4_5a = 0;
	scanf("%d", &zad_1_4_5);
	if (zad_1_4_5 > 0)
		for (int i = 1; i <= zad_1_4_5; i++)
			zad_1_4_5a += i*i;
	printf("\nWynik wyrazenia to: %d\n", zad_1_4_5a);
	
	printf("Zadanie 1.4.6\n");// n=6: 2*4*6=48, n=7=48
	int zad_1_4_6, zad_1_4_6_s=1;
	scanf("%d", &zad_1_4_6);
	for (int i = 2; i <= zad_1_4_6; i += 2)
		if (zad_1_4_6 % 2 == 0)
			zad_1_4_6_s *= i;
		else
			zad_1_4_6_s *= i;
	printf("Wynik wyrazenia to: %d", zad_1_4_6_s);
	
	printf("Zadanie 1.4.7\n");//(1,5)
	int zad_1_4_7a, zad_1_4_7b, zad_1_4_7s=1;
	scanf("%d%d", &zad_1_4_7a, &zad_1_4_7b);
	for (int i = zad_1_4_7a; i <= zad_1_4_7b; i++)
		zad_1_4_7s *= i;
	printf("Wynik wyrazenia to: %d", zad_1_4_7s);
	
	printf("Zadanie 1.4.8\n");
	int zad_1_4_8;
	scanf("%d", &zad_1_4_8);
	printf("Fib index (%d) wynosi: %d", zad_1_4_8,fib(zad_1_4_8));
	
	printf("Zadanie 1.4.9\n");
	int zad_1_4_9a, zad_1_4_9b;
	scanf("%d%d", &zad_1_4_9a, &zad_1_4_9b);
	printf("NWD liczb %d i %d to: %d",zad_1_4_9a, zad_1_4_9b, NWD(zad_1_4_9a, zad_1_4_9b));
	
	printf("Zadanie 1.4.10\n");
	float zad_1_4_10;
	scanf("%f", &zad_1_4_10);
	printf("Pierwiastek z %g to : %d", zad_1_4_10, int(sqrt(zad_1_4_10)));
	
	printf("Zadanie 1.4.11\n");
	int zad_1_4_11[4];//a[0] b[1] c[2] d[3]
	for (int i = 0; i < 4; i++)
		scanf("%d", &zad_1_4_11[i]);
	printf("\nPodpunkt a)\n");
	int i = 0;
	while (aabs(zad_1_4_11[0]) * (i * i) + zad_1_4_11[1] * i + zad_1_4_11[2] <= zad_1_4_11[3]) {
		//printf("|%d| * (%d * %d) + %d * %d + %d > %d\n", zad_1_4_11[0], i, i, zad_1_4_11[1], i, zad_1_4_11[2], zad_1_4_11[3]);
		//printf("%d > %d\n", zad_1_4_11[0]* (i * i) + zad_1_4_11[1] * i + zad_1_4_11[2], zad_1_4_11[3]);
		i++;
	}
	printf("Ostatecznie: \n");
	printf("|%d| * (%d * %d) + %d * %d + %d > %d\n", zad_1_4_11[0], i, i, zad_1_4_11[1], i, zad_1_4_11[2], zad_1_4_11[3]);
	printf("%d > %d\n", zad_1_4_11[0] * (i * i) + zad_1_4_11[1] * i + zad_1_4_11[2], zad_1_4_11[3]);
	printf("Najmniejsza liczba calkowita spelniajaca warunek a) to: %d\n", i);

	printf("\nPodpunkt b)\n");
	i = 0;
	while (5 * (i * i) + zad_1_4_11[0] * i + zad_1_4_11[2] < zad_1_4_11[3])i++;
	printf("Ostatecznie: \n");
	printf("5 * (%d * %d) + %d * %d + %d < %d \n", i,i,zad_1_4_11[0],i, zad_1_4_11[1], zad_1_4_11[2]);
	printf("%d > %d\n", 5 * (i * i) + zad_1_4_11[0] * i + zad_1_4_11[2], zad_1_4_11[3]);
	printf("Najmniejsza liczba calkowita spelniajaca warunek b) to: %d\n", i);

	printf("\nPodpunkt c)\n");
	i = 0;
	while (5 * (i * i) + zad_1_4_11[0] * i + zad_1_4_11[2] <= zad_1_4_11[3])i++;
	printf("Ostatecznie: \n");
	printf("5 * (%d * %d) + %d * %d + %d < %d \n", i,i,zad_1_4_11[0],i, zad_1_4_11[1], zad_1_4_11[2]);
	printf("%d > %d\n", 5 * (i * i) + zad_1_4_11[0] * i + zad_1_4_11[2], zad_1_4_11[3]);
	printf("Najmniejsza liczba calkowita spelniajaca warunek b) to: %d", i);

	printf("Zadanie 1.4.12\n");
	int zad_1_4_12, zad_1_4_12_s = 0;
	scanf("%d", &zad_1_4_12);
	for (int i = 2; i < zad_1_4_12; i++)
		if (NWD(i, zad_1_4_12) == 1) {
			zad_1_4_12_s += i;
			printf("Liczba wzglednie pierwsza z %d: %d\n", zad_1_4_12, i);
		}
	printf("Suma liczb mniejszych od %d, wzglednie pierwszych z %d wynosi: %d", zad_1_4_12, zad_1_4_12, zad_1_4_12_s);
	
	printf("Zadanie 1.4.13\n");
	int zad_1_4_13, zad_1_4_13_s=0;
	scanf("%d", &zad_1_4_13);
	for (int i = 0; i <= zad_1_4_13; i++) {
		zad_1_4_13_s += silnia(i);
		printf("Silnia od %d wynosi: %d\n", i, silnia(i));
	}
	printf("Suma silni od %d wynosi: %d", zad_1_4_13, zad_1_4_13_s);

	printf("Zadanie 1.4.14\n");
	int zad_1_4_14;
	scanf("%d", &zad_1_4_14);
	for (int i = 1; i < zad_1_4_14; i++)
		for (int j = 1; j < zad_1_4_14; j++)
			for (int k = 1; k < zad_1_4_14; k++)
				if ((i * i + j * j == k * k) and i < j)
					printf("Trojka pitagorejska: %d^2 +%d^2 = %d^2\n", i, j, k);


}
