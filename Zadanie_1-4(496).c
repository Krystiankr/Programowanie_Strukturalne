#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
// Autor Krystian Kręcik
#include "Header.h"
#define MAXTYT 40
#define MAXAUT 40
#define MAXKS 100 
struct Miesiac {
    char nazwa[12];
    char skr[4];
    int liczba_dni;
    int nr_miesiaca;
};

Miesiac ptr[12] = { {"styczen", "sty", 31, 1},{"luty", "lut", 28, 2}, {"marzec","mar", 31, 3},
    {"kwiecien","kwi", 30, 4}, {"maj","maj", 31, 5}, {"czerwiec","cze", 30, 6},
    {"lipiec", "lip",31, 7}, {"sierpien","sie", 31, 8}, {"wrzesien","wrz", 30, 9},
    {"pazdziernik", "paz", 31, 10}, {"listopad", "lis", 30, 11}, {"grudzien", "gru", 31, 12} };


struct ksiazka { 
    char tytuł[30];
    char autor[30];
    int wartość;
};
struct pes {
    int PESEL;
    struct {
        char imie[12];
        char drugie_imie[12];
        char nazwisko[12];
    };
};


void fun(pes tab[]) {
    for (int i = 0; i < 3; i++) {
        if (tab[i].drugie_imie[0] != '\0')
            printf("%c.\n", tab[i].drugie_imie[0]);
    }
}

int main() {
    printf("Zadanie 1\n");
    int suma_1 = 0;
    for (int i = 0; i < 12; i++) {
        suma_1 += (ptr + i)->liczba_dni;
        if  (!(strcmp((ptr + i)->nazwa, "maj"))) {
            printf("%s: %d", (ptr + i)->nazwa,(ptr + i)->nr_miesiaca);
            printf("\nLiczba dni w roku: %d", suma_1);
            break;
        }
    }
    
    printf("Zadanie 2\n");
    int dzien, rok;
    printf("Podaj dzien, rok: ");
    scanf("%d %d", &dzien, &rok);
    int suma_2 = 0, wybor, nr=-1;
    char nazwa_1[12], skrt[4];
    printf("Wybierz sposob wyliczenia: \n");
    printf("1) Podaj numer miesiaca:\n");
    printf("2) Podaj nazwe miesiaca:\n");
    printf("3) Podaj skrot miesiaca:\n");
    scanf("%d", &wybor);
    switch (wybor) {
    case 1:
        scanf("%d", &nr);
        break;
    case 2:
        scanf("%s", nazwa_1);
        break;
    case 3:
        scanf("%s", skrt);
        break;
    }
 
    for (int i = 0; i < 12; i++) {
        if (rok % 4 == 0 and (!(strcmp((ptr + i)->nazwa, "luty"))))
            (ptr + i)->liczba_dni = 29;
        if (((ptr + i)->nr_miesiaca == nr) or (!(strcmp((ptr + i)->nazwa, nazwa_1))) or (!(strcmp((ptr + i)->skr, skrt)))) {
        //if (!(strcmp((ptr + i)->skr, skrt))) {
            printf("%s: %d", (ptr + i)->nazwa, (ptr + i)->nr_miesiaca);
            suma_2 += dzien;

            printf("\nLiczba dni w roku: %d", suma_2);
            break;
        }
        suma_2 += (ptr + i)->liczba_dni;
    }


    printf("Zadanie 3\n");

    struct ksiazka bibl[MAXKS]; 
    int licznik = 0;
    int index;
    char temp[25];
    printf("Podaj tytuł książki.\n");
    printf("Aby zakonczyc, wciśnij [enter] na początku wiersza.\n");
    while (licznik < 3) {
        printf("Teraz podaj autora.\n");
        scanf("%s", &bibl[licznik].autor);
        printf("Teraz podaj wartość.\n");
        scanf("%d", &bibl[licznik].wartość);
        printf("Teraz podaj tytul.\n");
        scanf("%s", &bibl[licznik++].tytuł);
        if (licznik < MAXKS)
            printf("Podaj kolejny tytuł.\n");
    }
    printf("Oto lista Twoich ksiazek:\n");

    for (int i = 0; i <= licznik; i++)
        for (int j = i + 1; j <= licznik; j++) {
            if (strcmp(bibl[i].tytuł, bibl[j].tytuł) > 0) {
                strcpy(temp, bibl[i].tytuł);
                strcpy(bibl[i].tytuł, bibl[j].tytuł);
                strcpy(bibl[j].tytuł, temp);
            }
        }
    for (index = 0; index < licznik; index++)
        printf("Tytuk %s, autor: %s, cena: %d zl\n", bibl[index].tytuł,
            bibl[index].autor, bibl[index].wartość);
    return 0;
    
    printf("Zadanie 4\n");

    pes zaczynam[3] = { {6236231234, {"Marcin", "Lewo", "Komors"}},
                        {5125124362, {"Norman", "Testo", "Mocny"}},
                        {7844323412, {"Karol", "", "Ciemny"}}
    };
    for (int i = 0; i < 3; i++) {
        printf("%s, %s, %c. -- %d\n", zaczynam[i].nazwisko, zaczynam[i].imie, (zaczynam[i].nazwisko)[0], zaczynam[i].PESEL);
    }
    fun(zaczynam);
}
