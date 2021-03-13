#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
// Autor Krystian Kręcik
using namespace std;
int main() {

    printf("Zadanie 1.3.3\n");
    printf("Podaj trzy liczby calkowite\n");
    int a, b, c, max;
    scanf("%d %d %d", &a, &b, &c);
    if (a >= b and a >= c) max = a;
    else if (b >= a and b >= c) max = b;
    else max = c;
    printf("Najwieksza wartosc to %d\n", max);
    printf("Zadanie 1.3.7\n");

    printf("Prosze podac wspolczynnik rownania kwadratowego w kolejnosci a, b, c\n");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a != 0) {
        float delta = (b * b) - (4 * a * c);
        if ((delta) < 0) {
            printf("Delta ujemna brak rozwiazan");
        }
        else if (delta == 0) { printf("%f", -b / (2. * a)); }
        else { printf("%lf", (-b - sqrt(delta)) / (2. * a)); printf(" %lf", (-b + sqrt(delta)) / (2. * a)); }
    }
    else {
        if (b == 0) {
            if (c == 0) {
                printf("Nieskonczenie wiele");
            }
            else printf("Brak rozwiazan1");
        }
        else {
            printf("%lf", (-c) / b);
        }
    }
        
    printf("Zadanie 1.3.9\n");
    printf("Witaj w programie kalkulator, podaj dwie dowolne liczby\n");
    int input;
    float wynik=0, a1, b1;
    scanf("%f %f", &a1, &b1);
    printf("Wybierz operacje arytmetyczna\n");
    printf("1) Dodawanie\n");
    printf("2) Odejmowanie\n");
    printf("3) Mnozenie\n");
    printf("4) Dzielenie\n");
    scanf("%d", &input);
    switch (input) {
    case 1:
        wynik = a1 + b1;
        break;
    case 2:
        wynik = a1 - b1;
        break;
    case 3:
        wynik = a1 * b1;
        break;
    case 4:
        wynik = a1 / b1;
        break;
    }
    printf("\nTwoj wynik to: %f", wynik);
  
    printf("Zadanie 1.4.5\n");
    int a3, suma=0;
    do {
        printf("Podaj nieujemna liczbe calkowita\n");
        scanf("%d", &a3);
    }     while (a3 < 0);
    for (int i = 0; i < a3; i++) {
        suma += i * i;
    }
    printf("Twoja suma wynosi: %d", suma);
}
