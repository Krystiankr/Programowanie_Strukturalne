#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
//Autor Krystian Kręcik
//6.2.5, 6.2.6, 6.2.11, 6.2.12

int *** zad_6_2_1(int n, int m, int wymiar) { // zad_6_2_1 zrobione
	int*** tab = (int***)malloc(wymiar*sizeof(int**));
	for (int j = 0; j < wymiar; j++) {
		tab[j] = (int**)malloc((n) * sizeof(int*));
		for (int i = 0; i < n; i++)
			tab[j][i] = (int*)malloc(m * sizeof(int*));
	}

	return tab;
}

void zad_6_2_3(int*** tab, int n, int wymiar){ // zad_6_2_3 zrobione
	for (int j = 0; j < wymiar; j++) {
		for (int i = 0; i < n; i++)
				free(tab[j][i]);
		free(tab[j]);
	}
}

int * zad_6_2_2(int row, int col, int d3) { //zad_6_2_2 zrobione
	return (int *)malloc(row*col*d3*sizeof(int)); 
}

void zad_6_2_4(int **tab4) {
	printf("Adress tab4:%d (c)\n", *tab4);  // zad_6_2_4 zrobione
	free(*tab4);
}


int zad_6_2_11(int tab[][100], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 100; j++)
			suma += tab[i][j];
	return suma;
}

int zad_6_2_12(int** tab, int n, int m) {
	int suma = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			suma += tab[i][j];
	return suma;
}


int main() {
	
	printf("Zadanie 1\n");
	int a_row = 2, a_col = 4, a_wymiar = 2;
	int*** tab1 = zad_6_2_1(a_row, a_col, a_wymiar);
	for(int i = 0;i<a_wymiar;i++)
		for(int j =0 ;j<a_row;j++)
			for (int k = 0; k < a_col; k++) {
				tab1[i][j][k] = i + j + k;
				printf("[%d][%d][%d]=%d", i, j, k, tab1[i][j][k]);
			}
	zad_6_2_3(tab1, a_row, a_wymiar);

	int n = 2, m = 2;
	
	int*** tab = (int***)malloc(sizeof(int**));
	tab[0] = (int**)malloc((n)*sizeof(int*));
	for (int j = 0; j < n; j++)
		tab[0][j] = (int*)malloc(m*sizeof(int));
	tab[0][0][0] = 23;
	
	printf("\n\nZadanie 2\n");
	int row = 2, col = 3, wymiar = 2;
	int* tab4 = zad_6_2_2(row,col,wymiar);
	
	for (int i = 0; i < wymiar; i++) {
		for(int j = 0;j<row;j++)
			for (int k = 0; k < col; k++) {
				*(tab4 + (i * col) + j) = i * j+i+j+1;
				printf("[%d %d, %d]=%d", i, j, k, *(tab4 + (i * col) + j));
			}
		printf("\n");
	}
	printf("Adress tab4:%d\n", tab4);
	zad_6_2_4(&tab4);
	for (int i = 0; i < wymiar; i++) {
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				printf("[%d %d, %d]=%d", i, j, k, *(tab4 + (i * col) + j));
		printf("\n");
	}
	printf("\nZadanie 6_2_11\n");
	int tab10[4][100];
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 100; i++)
			tab10[j][i] = j + i + 2;
	}
	printf("Suma wszystkich elementow wynosi: %d\n", zad_6_2_11(tab10, 4));
	printf("\nZadanie 6_2_12\n");
	int** tab11 = (int**)malloc(30 * sizeof(int*));
		for (int i = 0; i < 30; i++)
			tab11[i] = (int*)malloc(50 * sizeof(int));
	for (int j = 0; j < 30; j++) 
		for (int i = 0; i < 50; i++)
			tab11[j][i] = j + i + 2;

	printf("Suma wszystkich elementow wynosi: %d", zad_6_2_12(tab11, 5, 30));

}
