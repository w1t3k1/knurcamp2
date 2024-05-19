#include <stdio.h>

int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        return fib(n - 2) + fib(n - 1);
    }
}

int main(int argc, char **argv) {
    int num;

    printf("Enter an integer number: ");
    scanf("%d", &num);

    printf("Fibonacci sequence up to %d:\n", num);
    for (int i = 0; i < num; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}