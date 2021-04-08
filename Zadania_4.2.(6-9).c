#include <stdio.h>
// Autor: Krystian Kręcik
void zad6a(int n, int *tab1, int *tab2) {
	for (int i = 0; i < n; i++)
		tab2[i] = tab1[i];
}

void zad6b(int n, int* tab1, int* tab3) {
	for (int i = 1; i <= n; i++)
		tab3[7 - i] = tab1[i-1];
}

void zad7a(int n, int* tab1, int* tab2, int* tab3) {
	for (int i = 0; i < n; i++) 
		tab3[i] = tab1[i] + tab2[i];
}

void zad7b(int n, int* tab1, int* tab2, int* tab3) {
	for (int i = 0; i < n; i++)
		tab1[i] > tab2[i] ? tab3[i] = tab1[i] : tab3[i] = tab2[i];
}

void zad7c(int n, int* tab1, int* tab2, int* tab3) {
	int temp[7];
	for (int i = 0; i < n; i++) {
		temp[i] = tab1[i];
		tab1[i] = tab3[i];
		tab3[i] = tab2[i];
		tab2[i] = temp[i];
	}
}

void zad8a(int n, int* tab1, int*tab2, double *tab3) {
	for (int i = 0; i < n; i++)
		tab3[i] = tab1[i];	
	for (int i = 0; i < n; i++)
		tab3[n+i] = tab2[i];
}
void zad8b(int n, int* tab1, int* tab2, double* tab3) {
	for (int i = 0; i < n; i++) {
		tab3[i * 2] = tab2[i];
		tab3[i * 2 + 1] = tab1[i];
	}
	
}

int max_v(int a, int b, int c) {
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}

int min_v(int a, int b, int c) {
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}

int sred_v(int a, int b, int c) {
	if (a >= b and b >= c)
		return b;
	if (a >= c and c >= b)
		return c;
	if (b >= a and a >= c)
		return a;
	if (b >= c and c >= a)
		return c;
	if (c >= a and a >= b)
		return a;
	return b;
}

void zad9a(int n, int *tab1, int *tab2, int *tab3) {
	for (int i = 0; i < n; i++)
		tab1[i] = max_v(tab1[i], tab2[i], tab3[i]);
}

void zad9b(int n, int *tab1, int *tab2, int *tab3) {
	for (int i = 0; i < n; i++)
		tab2[i] = sred_v(tab1[i], tab2[i], tab3[i]);
}

void zad9c(int n, int *tab1, int *tab2, int *tab3) {
	for (int i = 0; i < n; i++)
		tab3[i] = min_v(tab1[i], tab2[i], tab3[i]);
}

int main() {

	int tab1[7] = { 9,8,7,6,3,21,4 };
	int tab2[7];
	int tab3[7];
	zad6a(7, tab1, tab2);
	printf("Zadanie 4.2.6 (a): \n");
	for (int i = 0; i < 7; i++)
		printf("Element nr(%d): %d\n", i, tab2[i]);
	printf("Zadanie 4.2.6 (b): \n");
	zad6b(7, tab1, tab3);
	for (int i = 0; i < 7; i++)
		printf("Element nr(%d): %d\n", i, tab3[i]);
	
	printf("Zadanie 4.2.7 (a): \n");
	int tab71[7] = { 542,123,42,1,0,421,5 };
	int tab72[7] = { 98,71,0,32,7,123,2 };
	int tab73[7];
	zad7a(7, tab71, tab72, tab73);
	for (int i = 0; i < 7; i++)
		printf("Element nr(%d): %d\n", i, tab73[i]);
	printf("Zadanie 4.2.7 (b): \n");
	zad7b(7, tab71, tab72, tab73);
	for (int i = 0; i < 7; i++)
		printf("Element nr(%d): %d\n", i, tab73[i]);
	zad7c(7, tab71, tab72, tab73);
	for (int i = 0; i < 7; i++)
		printf("%d| Tab1:(%d) Tab2:(%d) Tab3:(%d)\n", i, tab71[i], tab72[i], tab73[i]);

	printf("Zadanie 4.2.8 (a): \n");
	int tab81[7] = { 12,32,11,0,4,2,5 };
	int tab82[7] = { 824,123,1254,923,4,2,0};
	double tab83[14];
	zad8a(7, tab81, tab82, tab83);
	for (int i = 0; i < 14; i++)
		printf("%d %.0f\n",i, tab83[i]);
	printf("Zadanie 4.2.8 (b): \n");
	zad8b(7, tab81, tab82, tab83);
	for (int i = 0; i < 14; i++)
		printf("%d %.0f\n", i, tab83[i]);

	printf("Zadanie 4.2.9 (a): \n");
	int tab91[5] = { 0,1,2,3,4 };
	int tab92[5] = { 3,4,7,9,10 };
	int tab93[5] = { 10,39,41,52,0 };

	zad9a(5, tab91, tab92, tab93);
	for (int i = 0; i < 5; i++)
		printf("%d: %d\n",i, tab91[i]);
	
	printf("Zadanie 4.2.9 (b): \n");
	zad9b(5, tab91, tab92, tab93);
	for (int i = 0; i < 5; i++)
		printf("%d: %d\n", i, tab92[i]);
	
	printf("Zadanie 4.2.9 (c): \n");
	zad9c(5, tab91, tab92, tab93);
	for (int i = 0; i < 5; i++)
		printf("%d: %d\n", i, tab93[i]);
}
