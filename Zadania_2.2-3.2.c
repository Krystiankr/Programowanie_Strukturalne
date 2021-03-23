#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>

// Autor Krystian Kręcik
int dwaen(int n) {
    int suma = 1;
    for (int i = 0; i < n; i++)
        suma *= 2;
    return suma;
}

int drugie(int n, int m) {
    int suma = 1;
    for (int i = 0; i < m; i++) {
        suma *= n;
    }
    return suma;
}

int rekurencja(int n) {
    int a = 1;
    if (n == 0)
        return a;
    for (int i = 0; i < n; i++) {
        a += 2 * a + 5;
    }
    return a;
}

int suma(unsigned int a1=0, unsigned int a2=0, unsigned int a3=0, unsigned int a4=0, unsigned a5=0) {
    return a1 + a2 + a3 + a4 + a5;
}

int wsk(int *a, int *b) {
    return *a + *b;
}

void wskazywana(int *a, int *b) {
    int tmp;
    tmp = *b;
    if (*b < *a) {
        *b = *a;
        *a = tmp;
    }
}

void przypis(int n, int *wsk) {
    *wsk = n;
}

double * zwrot() {
    double* nowa = (double *)malloc(sizeof(double));
    return nowa;
}

int main() {

    printf("Zadanie 2.2.5\n");
    printf("%d\n",dwaen(3));

    printf("Zadanie 2.2.6\n");
    printf("%d\n", drugie(3,4));
    
    printf("Zadanie 2.2.21\n");
    printf("%d\n", rekurencja(2));
   
    printf("Zadanie 2.2.33\n");
    printf("%d", suma(1, 1,3,4,5));
   
    printf("Zadanie 3.2.4\n");
    int a = 10, b = 1;
    wskazywana(&a, &b);
    printf("a: %d, b: %d", a, b);

    printf("Zadanie 3.2.5\n");
    int a = 5, b = 2;
    printf("%d", wsk(&a, &b));
   
    printf("Zadanie 3.2.6\n");
    int n = 10;
    int wsk_ee;
    przypis(n, &wsk_ee);
    printf("n: %d, wsk_ee: %d", n, wsk_ee);

    printf("Zadanie 3.2.10\n");
    printf("%d", zwrot());
}
