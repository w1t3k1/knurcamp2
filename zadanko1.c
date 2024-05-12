/* NIE DOTYKAJ */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void weryfikacja1(void* ss, int sz)
{
    char* st = (char*)ss;
    int wiek = *st;
    if(wiek != 105)
    {
        printf("BĹ‚Ä™dne rozwiÄ…zanie\n");
        return;
    }
    st += sz / 3;
    uint64_t imiePtr = (*(uint64_t*)st);
    char* imie = (char*)imiePtr;
    st += sz / 3;

    if(strcmp(imie, "Jan") != 0)
    {
        printf("BĹ‚Ä™dne rozwiÄ…zanie\n");
        return;
    }
    float wzrost = *(float*)st;
    if(wzrost < 2.138 && wzrost > 2.136)
    {
        printf("Brawo poprawne rozwiÄ…zanie\n");
    }
    else
    {
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

int main(void)
{
    // Miejce na twĂłj kod

    struct czlowiek
    {
        int wiek;
        char* imie;
        float wzrost;
    };

    struct czlowiek Jan;
    Jan.wiek = 105;
    Jan.imie = "Jan";
    Jan.wzrost = 2.137;

    weryfikacja1(&Jan, sizeof(Jan));
}
