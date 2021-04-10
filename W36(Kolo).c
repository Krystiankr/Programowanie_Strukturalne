#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int min(int *tab) {
	int min = INFINITY, index=0;
	for (int i = 0; i < 10; i++)
		if (tab[i] < min)
			min = tab[i],
			index = i;
			
			
	printf("Wartosc min: %d\n", min);
	return index;
}

void przesun(int* tab4) {
	int tmp[2];
	for (int i = 0; i < 8; i++)
		i < 2 ? tmp[1 - i] = tab4[9 - i], tab4[9 - i] = tab4[9 - i - 2] : tab4[9 - i] = tab4[9 - i - 2];
	tab4[0] = tmp[0];
	tab4[1] = tmp[1];

}

int main() {
	
	printf("Zadanie 1\n");
	int a, b;
	printf("Podaj a i b");
	scanf("%d %d", &a, &b);
	int c = 4 * b;
	float delta = (((-2) * (-2)) - 4 * a * c),x1,x2;
	if (delta < 0)
		printf("Brak rozwiazan");
	else {
		delta = sqrt(delta);
		x1 = (2 + delta) / (2 * a);
		x2 = (2 - delta) / (2 * a);
		printf("x1: %f, x2: %f", x1, x2);
	}

	printf("Zadanie 3\n");
	int tab3[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &tab3[i]);
	printf("Index min elementu to: %d\n", min(tab3));
	
	printf("Zadanie 4\n");
	int tab4[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &tab4[i]);
	przesun(tab4);
	for (int i = 0; i < 10; i++)
		printf("%d ",tab4[i]);
}
