#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void kopiuj(const char napis[], char tab[]) {
	while (*napis != '\0')
		*tab++ = *napis++;
	*tab = '\0';
}

void kopiuj_wchar(const wchar_t napis[], wchar_t tab[]) {
	while (*napis != '\0')
		*tab++ = *napis++;
	*tab = '\0';
}

char* kopiuj_25(const char napis[], char** tab) {
	char* tablica = (char*)malloc(50 * sizeof(char));
	char* ptr = tablica;
	*tab = ptr;
	while (*napis != '\0')
		*tablica++ = *napis++;
	*tablica = '\0';


	return ptr;
}

wchar_t* kopiuj_25_w(const wchar_t napis[], wchar_t** tab) {
	wchar_t* tablica = (wchar_t*)malloc(50 * sizeof(wchar_t));
	wchar_t* ptr = tablica;
	*tab = ptr;
	while (*napis != '\0')
		*tablica++ = *napis++;
	*tablica = '\0';


	return ptr;
}

int zad_4_2_10_a(int n, int tab[]) {
	int max = -INFINITY;
	for (int i = 0; i < n; i++)
		if (tab[i] > max)
			max = tab[i];
	return max;
}

int zad_4_2_10_b(int n, int tab[]) {
	int min = INFINITY;
	for (int i = 0; i < n; i++)
		if (tab[i] < min)
			min = tab[i];
	return min;
}

int zad_4_2_10_c(int n, int tab[]) {
	int max = -INFINITY;
	int index = 0;
	for (int i = 0; i < n; i++)
		if (tab[i] > max)
			max = tab[i],
			index = i;
	return index;
}

int zad_4_2_10_d(int n, int tab[]) {
	int min = INFINITY;
	int index = 0;
	for (int i = 0; i < n; i++)
		if (tab[i] < min)
			min = tab[i],
			index = i;
	return index;
}

int zad_4_2_10_e(int n, int tab[]) {
	int max = -INFINITY;
	for (int i = 0; i < n; i++)
		if (abs(tab[i]) > max)
			max = abs(tab[i]);
	return max;
}

int zad_4_2_10_f(int n, int tab[]) {
	int max = -INFINITY;
	int index = 0;
	for (int i = 0; i < n; i++)
		if (abs(tab[i]) > max)
			max = abs(tab[i]),
			index = i;
	return index;
}

double zad_4_2_11(int n, double tab1[], double tab2[]) {
	double wynik = 0;
	for (int i = 0; i < n; i++)
		wynik += tab1[i] + tab2[i];
	return wynik;
}

//5.2.24, 5.2.25, 4.2.10, 4.2.11
int main() {


	printf("Zadanie 5.2.24\n");
	char tab[100];
	wchar_t tab_w[100];
	kopiuj("Ala ma kota", tab);
	kopiuj_wchar(L"Ala ma kota", tab_w);
	printf("Char:	 %s\n", tab);
	printf("Wchar_t: %ls", tab_w);

	printf("Zadanie 5.2.25\n");
	char** nap_25 = (char**)malloc(sizeof(char));
	wchar_t** nap_25_w = (wchar_t**)malloc(sizeof(wchar_t));
	*nap_25 = kopiuj_25("char: Ala ma kota\n", nap_25);
	*nap_25_w = kopiuj_25_w(L"wchar_t: Ala ma kota", nap_25_w);
	printf("%s", *nap_25);
	printf("%ls", *nap_25_w);


	printf("Zadanie 4.2.10\n");

	int tab_4_2_10[10] = { 0,1,2,3,4,5,6,7,8,-9 };
	printf("a) Max: %d\n", zad_4_2_10_a(10, tab_4_2_10));
	printf("b) Min: %d\n", zad_4_2_10_b(10, tab_4_2_10));
	printf("c) Index max: %d\n", zad_4_2_10_c(10, tab_4_2_10));
	printf("d) Index min: %d\n", zad_4_2_10_d(10, tab_4_2_10));
	printf("e) Abs(Max): %d\n", zad_4_2_10_e(10, tab_4_2_10));
	printf("f) Index Abs(Max): %d\n", zad_4_2_10_f(10, tab_4_2_10));

	printf("Zadanie 4.2.11\n");

	double tab_4_2_11_a[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double tab_4_2_11_b[5] = { 1.1,2.2,3.3,4.4,5.5 };
	printf("Iloczyn skalarny dwoch wektorow wynosi: %f", zad_4_2_11(5, tab_4_2_11_a, tab_4_2_11_b));


}
