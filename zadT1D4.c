#include <stdio.h>

// T1D4: Dziki i wskaźniki
// Zaimplementuj funkcję void swap(int *a, int *b) aby podmienić zawartość a na b i b na a.
// Zadanie bonusowe: Napisz funkcję, która przyjmuje wskaźnik do innej funkcji.
// Wywołaj z tej funkcji ten wskaźnik.
// Spraw aby funkcja pod wskaźnikiem wypisała na ekranie "SIGMA".

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

}

void sigmaFunc() {
    printf("SIGMA");
}

void callFunctionSigma(void (*sigma)()) {
    sigma();
}

int main(void) {
    int x = 10;
    int y = 20;
    printf("Przed swapem: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Po swapie: x = %d, y = %d\n", x, y);

    callFunctionSigma(sigmaFunc); /* Działa tak samo gdyby podać &sigmaFunc dlatego, że podając samą nazwe
                                          funkcji następuje coś co nazywa się "function-to-pointer decay"*/

    return 0;
}