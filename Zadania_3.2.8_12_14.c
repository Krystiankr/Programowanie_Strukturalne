#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include<stdlib.h>

//Autor Krystian Kręcik 3_2_8, 3_2_12, 3_2_14

void zad3_2_8(int &a, int *b) {
    int temp = *b;
    *b = a;
    a = temp;
}

int fun1(int a) {
    if (a == 3)
        return false;
    return a;
}
int fun2(int a) {
    return a;
}

bool zad_3_2_14(int (* fun1)(int arg1), int (* fun2)(int arg2), unsigned n) {
    for(int i = 0;i<n;i++)
        if (fun1(i) != fun2(i))
            return false;
    return  true;
}

double* zad_3_2_12(int n) {
    double *tab = (double *)malloc(n*sizeof(double));
    return tab;
}

int main() {
    printf("Zadanie 3.2.8\n");
    int*b=(int*)malloc(sizeof(int)), a=100;
    *b = 3;
    printf("Przed zmiana: a: %d, b: %d\n", a, *b);
    zad3_2_8(a, b);
    printf("Po zmianie: a: %d, b: %d", a, *b);

    printf("Zadanie 3.2.12\n");
    double *tab = zad_3_2_12(3);
    tab[0] = 3.3;
    tab[1] = 3.5;
    tab[2] = 3.12;
    for (int i = 0; i < 3; i++)
        printf("%f ", tab[i]);

    printf("\nZadanie 3.2.14\n");
    int (*fun1_ptr)(int) = &fun1;
    int (*fun2_ptr)(int) = &fun2;

    bool result = zad_3_2_14(fun1_ptr, fun2_ptr,4);
    if (result)
        printf("Zwracam true");
    else
        printf("Zwracam false");


}
