#include <stdio.h>

/*
 T1D6
 BOMBELKOWE SORTOWANIE NA WSKAZNIKACH HEHE
 Powodzenia bombelku, napisz ciało funkcji sortujPrzezWskazniki.
 Aby spełniała swoje zadanie i posortowała liczby rosnąco.
 */

void sortujPrzezWskazniki(int *tab, int rozmiar) {
    // miejsce na rozwiązanie
    int temp;

    for (int i = 0; i < rozmiar; i++)
        for (int j = i + 1; j < rozmiar; j++)
            if (*(tab + i) > *(tab + j)) {
                temp = *(tab + i);
                *(tab + i) = *(tab + j);
                *(tab + j) = temp;
            }
}

int main() {
    int liczby[] = {34, 67, 23, 28, 98, 15};
    int rozmiar = sizeof(liczby) / sizeof(liczby[0]);

    printf("Tablica przed sortowaniem: \n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", liczby[i]);
    }
    printf("\n");

    sortujPrzezWskazniki(liczby, rozmiar);

    printf("Tablica po sortowaniu: \n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", liczby[i]);
    }
    printf("\n");

    return 0;
}
