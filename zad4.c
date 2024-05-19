#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    char *buffer = malloc(1024);
    char string1[100], string2[100];
    const char* fileToWrite = "dupa.txt";

    printf("Enter first string: ");
    scanf("%s", string1);
    printf("Enter second string: ");
    scanf("%s", string2);

    sprintf(buffer, "%s%s", string1, string2);

    printf("%s\n", buffer);

    FILE* uchwyt = fopen(fileToWrite, "w");
    if(uchwyt == NULL)
    {
        printf("Nie udało się otworzyć pliku do zapisu\n");
        return -1;
    }

    size_t ret = fwrite(buffer, 1, strlen(buffer), uchwyt);
    if(ret == strlen(buffer))
    {
        printf("Operacja się powiodła\n");
    }

    fclose(uchwyt);

    free(buffer);

    return 0;
}