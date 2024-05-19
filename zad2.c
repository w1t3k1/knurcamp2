#include <stdio.h>

void resultOf(int n1, int n2, char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        if (ch == '+')
            printf("Result: %d\n", n1 + n2);
        else if (ch == '-')
            printf("Result: %d\n", n1 - n2);
        else if (ch == '*')
            printf("Result: %d\n", n1 * n2);
        else if (ch == '/')
            printf("Result: %d\n", n1 / n2);
    } else {
        printf("You entered wrong character\n");
    }
}

int main(int argc, char** argv) {
    int num1, num2;
    char character;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    while (getchar() != '\n'); // wyczysc bufor inputa

    printf("Enter a character (+, -, *, /): ");
    scanf("%c", &character);

    resultOf(num1, num2, character);
}