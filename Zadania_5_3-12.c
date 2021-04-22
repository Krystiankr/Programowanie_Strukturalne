#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string>
#include<stdlib.h>
//Autor: Krystian Kręcik
//5.2.3, 5.2.5, 5.2.6, 5.2.12
bool porownaj(char* tab1, char * tab2) {
    for (int i = 0; tab1[i] != '\0' or tab2[i] != '\0'; i++)
        if (tab1[i] != tab2[i])
            return false;
    return true;
}

bool porownaj_w(wchar_t* tab1, wchar_t* tab2) {
    for (int i = 0; tab1[i] != '\0' or tab2[i] != '\0'; i++)
        if (tab1[i] != tab2[i])
            return false;
    return true;
}

void przepisz(char* tab1, char* tab2) {
    for (int i = 0; tab1[i] != '\0'; i++)
        tab2[i] = tab1[i];
}

void przepisz_w(wchar_t* tab1, wchar_t* tab2) {
    for (int i = 0; tab1[i] != '\0'; i++)
        tab2[i] = tab1[i];
}

void kopiujn(char* nap1, char* nap2, int n) {
    int i;
    for (i = 0; nap1[i] != '\0' and i<n; i++)
        nap2[i] = nap1[i];
    nap2[i] = '\0';
}

void kopiujn_w(wchar_t* nap1, wchar_t* nap2, int n) {
    int i;
    for (i = 0; nap1[i] != '\0' and i<n; i++)
        nap2[i] = nap1[i];
    nap2[i] = '\0';
}

bool jest_w(char c, char* tab) {
    for (int i = 0; tab[i] != '\0'; i++)
        if (tab[i] == c)
            return true;
    return false;
}

void wytnijzn(char* nap1, char* nap2) {
    char temp[20];
    int licznik = 0;
    for (int i = 0; nap2[i] != '\0'; i++) 
        if (not(jest_w(nap2[i], temp)) and ((nap2[i] <= 'z' and nap2[i] >= 'a') or (nap2[i] <= 'Z' and nap2[i] >= 'A')))
            temp[licznik++] = nap2[i];
    for (int i = 0; nap1[i] != '\0'; i++) 
        if (jest_w(nap1[i], temp))
            nap1[i] = ' ';
}

void wytnijzn_w(wchar_t* nap1, wchar_t* nap2) {
    char temp[20];
    int licznik = 0;
    for (int i = 0; nap2[i] != '\0'; i++)
        if (not(jest_w(nap2[i], temp)) and ((nap2[i] <= 'z' and nap2[i] >= 'a') or (nap2[i] <= 'Z' and nap2[i] >= 'A')))
            temp[licznik++] = nap2[i];
    for (int i = 0; nap1[i] != '\0'; i++) 
        if (jest_w(nap1[i], temp))
            nap1[i] = ' ';
}
int main() {
    
    printf("Zadanie 5.2.3\n");
    char znak_1[] = "Napis_true", znak_2[] = "Napis_true";
    wchar_t znak_w1[] = L"Napis_true3", znak_w2[] = L"Napis_true";

    bool result1 = porownaj(znak_1, znak_2);
    bool result2 = porownaj_w(znak_w1, znak_w2);

    result1?printf("Podane napisy sa rowne\n"): printf("Napisy nie sa rowne\n");
    result2?printf("Podane napisy sa rowne") : printf("Napisy nie sa rowne");
   
    printf("\nZadanie 5.2.5\n");
    char z_5_2_5_a[] = "(char) Ala ma kota\n", z_5_2_5_b[100];
    przepisz(z_5_2_5_a, z_5_2_5_b);
    for (int i = 0; z_5_2_5_a[i] != '\0'; i++)
        printf("%c", z_5_2_5_b[i]);

    wchar_t z_5_2_5_w1[] = L"(wchar_t) Ala ma kota\n", z_5_2_5_w2[100];
    przepisz_w(z_5_2_5_w1, z_5_2_5_w2);
    for (int i = 0; z_5_2_5_w1[i] != '\0'; i++)
        printf("%c", z_5_2_5_w2[i]);

    printf("\nZadanie 5.2.6\n");
    char nap1[] = "(char) Ala ma kota 5.2.6\n", nap2[100];

    kopiujn(nap1, nap2, 35);
    for (int i = 0; nap2[i] != '\0'; i++)
        printf("%c", nap2[i]);
    
    wchar_t nap1_w[] = L"(wchar_t) Ala ma kota 5.2.6\n", nap2_w[100];
    kopiujn_w(nap1_w, nap2_w, 36);
    for (int i = 0; nap2_w[i] != '\0'; i++)
        printf("%c", nap2_w[i]);

    printf("\nZadanie 5.2.12\n");
    char zad_12_a[] = "Ewa na psaa", zad_12_b[] = "Ala ma kota";
    wytnijzn(zad_12_a, zad_12_b);
    for (int i = 0; zad_12_a[i] != '\0'; i++)
        printf("%c", zad_12_a[i]);
    printf("\n");

    wchar_t zad_12_wa[] = L"Ewa na psaa", zad_12_wb[] = L"Ala ma kota";
    wytnijzn_w(zad_12_wa, zad_12_wb);
    for (int i = 0; zad_12_wa[i] != '\0'; i++)
        printf("%c", zad_12_wa[i]);
    printf("\n");

}
