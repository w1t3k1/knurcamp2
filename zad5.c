#include <stdio.h>
#include <string.h>

void writeStructToFile(char *type, char *nameOfFile, void *structure, size_t sizeOfSturcture) {
    if (strlen(type) == 2 && *type == 'w' && *(type + 1) == 'b') {
        printf("You entered a correct type to write to a binary file\n");

        FILE *file = fopen(nameOfFile, type);

        if (file == NULL) {
            printf("Error: opening the file\n");
            return;
        }

        size_t writeStructure = fwrite(structure, sizeOfSturcture, 1, file);

        if (writeStructure != 1) {
            printf("Error: writing to a file\n");
            fclose(file);;
            return;
        }

        fclose(file);
        printf("Success: writing to a file\n");
    }
    else
        printf("You entered a wrong type to write to a binary file\n");
}

void readStructFromFile(char *nameOfFile, void *structure, size_t sizeOfStructure) {
    FILE *file = fopen(nameOfFile, "rb");

    if (file == NULL) {
        printf("Error: opening the file\n");
        return;
    }

    size_t readStructure = fread(structure, sizeOfStructure, 1, file);

    if (readStructure != 1) {
        printf("Error: reading from the file\n");
        fclose(file);
        return;
    }

    fclose(file);
}

int main(int argc, char** argv) {
    const char* fileName = "strukturka.bin";

    struct czlowiek {
        char imie[50];
        int wiek;
        char zawod[50];
    };

    struct czlowiek ziomo = {"toniezlyziomek", 69, "zawod dla rodzicow"};

    writeStructToFile("wb", fileName, &ziomo, sizeof(ziomo));

    struct czlowiek odczytany;

    readStructFromFile(fileName, &odczytany, sizeof(ziomo));

    printf("Read from a file:\n");
    printf("Imię: %s\n", odczytany.imie);
    printf("Wiek: %d\n", odczytany.wiek);
    printf("Zawód: %s\n", odczytany.zawod);

    return 0;
}
