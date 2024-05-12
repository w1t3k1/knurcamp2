/* NIE DOTYKAJ */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void weryfikacja1(void *ss, int sz) {
    char *st = (char *) ss;
    int wiek = *st;
    if (wiek != 105) {
        printf("BĹ‚Ä™dne rozwiÄ…zanie\n");
        return;
    }
    st += sz / 3;
    uint64_t imiePtr = (*(uint64_t *) st);
    char *imie = (char *) imiePtr;
    st += sz / 3;

    if (strcmp(imie, "Jan") != 0) {
        printf("BĹ‚Ä™dne rozwiÄ…zanie\n");
        return;
    }
    float wzrost = *(float *) st;
    if (wzrost < 2.138 && wzrost > 2.136) {
        printf("Brawo poprawne rozwiÄ…zanie\n");
    } else {
        printf("Ups, bĹ‚Ä™dne rozwiÄ…zanie\n");
    }
}
/* KONIEC SEKCJI NIE DOTYKAJ */

/*
 TreĹ›Ä‡ zadania:

 StwĂłrz strukturÄ™ o nazwie `czlowiek`.
 ZrĂłb ĹĽeby zawieraĹ‚a nastÄ™pujÄ…ce pola:
 - `wiek` <- liczba caĹ‚kowita (rozmiar standardowy)
 - `imie` <- no jego imie a co xD (ptr do stringa)
 - `wzrost` <- liczba zmiennoprzecinkowa w metrach amerykaĹ„skich np 1.234

 StwĂłrz czĹ‚owieka o imieniu `Jan`, wieku 105 lat, wzroĹ›cie 2 m 137 cm (w metrach amerykaĹ„skich - 1 metr = 1000 cm - 2m 137cm = 2.137)
 Pola wiek, imie, i wzrost muszÄ… mieÄ‡ takÄ… samÄ… kolenoĹ›Ä‡.

 Uruchom funckje `weryfikacja1` ze swojej funkcji main podajÄ…c wskaĹşnik do czĹ‚owieka oraz rozmiar struktury czĹ‚owiek jako drugi parametr.

 ***** Zadanie na 6 albo gwiazdke jak zwaĹ‚ tak zwaĹ‚ *****
 Opisz co robi po kolei funckja `void weryfikacja1(void* ss, int sz)`
*/

/*
 * Opis działania funkcji weryfikacja1:
 *
 * Nie wiem czy dobrze, ucze się dopiero. Bardzo prosze o wytłumaczenie nieścisłości jeżeli można.
 * W celu przeprowadzenia analizy i opisu funkcji pożytkowałem się tym co usłyszałem na wykładzie + dokumentacja + artykuły.
 *
 *
 * Parametry: (void *ss) -> "wskazuje na adres przekazany w argumencie podczas wywołania funkcji."
 *            (int sz) -> "przyjumuje wartość która zwracana jest przez sizeof(Jan) przekazana w argumencie podczas wywołania funkcji."
 * Ciało:
 *            char *st = (char *) ss; -> "Tworzony jest wskaźnik do przekazanej w argumencie zmiennej ss gdzie następuje type cast na typ char
 *                                       ze względu na to że nie możemy zdereferować typu void."
 *            int wiek = *st -> "Tworzona jest zmienna wiek która przyjmuje wartość pod adresem na który wskazuje st."
 *                              (Nie rozumiem dlaczego *st wskazuje akurat na wiek naszego Jana, ale tak to wynika z kodu o ile dobrze rozumuje (pewnie nie XD))
 *            st += sz / 3 -> "sizeof(Jan) zwraca liczbe 24 co oznacza że st przyjmuje teraz wartość 16."
 *
 *            uint64_t imiePtr = (*(uint64_t *) st) -> "Tworzona jest zmienna imiePtr o wielkości 8 bajtów (obstawiam że to z powodu tego że string zajmuje 8 bajtów pamięci), której wartość to dereferencja wskaźnika st,
 *                                                      który na dodatek jest type castowany na unit64_t (z tego co wynika rozumiem że jeśli zmienna jest np. typu int,
 *                                                      a nasz wskaźnik np. typu char to żeby przypisać wartość z pod adresu na która wskazuje wskaźnik typu char musimy
 *                                                      zrobić type cast wskaźnika na int)."
 *            char *imie = (char *) imiePtr -> "Tworzony jest zmienna wskaźnikowa imie do której przypisana jest zmienna imiePtr z type castem na char."
 *
 *            st += sz / 3 -> "st przyjumuje teraz wartość 24 (Obstawiam że to wszystko powiązane jest z dostawaniem się do poszczególnych miejsc w pamięci naszych pól struktury Jana)."
 *                            (Tylko dlaczego sizeof(Jan) zwraca 24 skoro int i float zajmują po 4 bajty co daje nam 8 ,a char będąć w tym przypadku stringiem zajmuje 8 bajtów.
 *                            Matematyka podpowiada że sizeof(Jan) powinno zwracać 16, ale myśle że jest coś czego nie rozumiem)
 *            float wzrost = *(float *) st -> "Tworzona jest zmienna wzrost która przyjmuje wartość z pod adresu na którą wskazuje st, a st jest type castowane na float."
 *
 *            Przypuszczam że pola Jana miały być deklarowane w takiej a nie innej kolejności którą zakłada polecenie zadania właśnie dlatego aby działanie st += sz / 3 miało sens,
 *            ale nie jestem co do tego pewny na 100%.
 */

int main(void) {
    // Miejce na twĂłj kod

    struct czlowiek {
        int wiek;
        char *imie;
        float wzrost;
    };

    struct czlowiek Jan;
    Jan.wiek = 105;
    Jan.imie = "Jan";
    Jan.wzrost = 2.137;

    weryfikacja1(&Jan, sizeof(Jan));
}
