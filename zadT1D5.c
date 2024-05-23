#include <stdio.h>
#include <stdlib.h>

/*
 T1D5 - Pamiętaj bo pamięć to rzecz święta xD (pzdr bonusrpk)
 Zarządzanie pamięcią - utrwalenie
 22.05.2025


 Postępuj zgodnie z instrukcjami w komentarzach, i dopisz brakujący kod.
 Zwróć uwagę na użycie funkcji calloc i free.
 Zastanów się, dlaczego używamy calloc zamiast malloc.
 */

int main(void) {
    int num;

    // Zadanie 1: Poproś użytkownika o podanie liczby elementów
    printf("Insert number of elements: ");
    scanf("%d", &num);

    // Zadanie 2: Przydziel pamięć dynamicznie dla 'n' elementów używając calloc

    // Różnica pomiędzy malloc a calloc jest taka że calloc ustawia przydzieloną pamięć na zera a malloc nie
    int *heapMem = calloc(num, sizeof(int));

    // Zadanie 3: Sprawdź, czy pamięć została pomyślnie przydzielona
    printf("Return value of calloc (first element): %d\n", *heapMem);

    for (int i = 0; i < num; i++) {
        printf("Element %d: %d\n", i, *(heapMem + i));
    }

    puts("\n");

    // Zadanie 4: Wprowadź elementy do przydzielonej pamięci
    for (int i = 0; i < num; i++) {
        *(heapMem + i) = i;
    }

    // Zadanie 5: Wyświetl te elementy
    printf("Display inserted elements: \n");

    for (int i = 0; i < num; i++) {
        printf("Element %d: %d\n", i, *(heapMem + i));
    }

    // Zadanie 6: Zwolnij przydzieloną pamięć
    free(heapMem);

    return 0;
}
