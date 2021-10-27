#include <stdio.h>

#define PAGINE_LIBRO    376
#define NUMERO_ALUNNI   20

int sommaCifre(int);

int main() {

    int alunni[NUMERO_ALUNNI] = { 0 };
    
    for (int i = 1; i <= PAGINE_LIBRO; ++i) {

        int somma = sommaCifre(i);

        while (somma > NUMERO_ALUNNI) {
            somma = sommaCifre(somma);
        }

        ++alunni[somma - 1]; // aumenta il numero di ricorrenze del numero cotenuto dalla somma di uno

    }

    for (int i = 1; i <= NUMERO_ALUNNI; ++i) {

        printf("%d\t-->\t%d\t-->\t%.20lf%%\n", i, alunni[i - 1], (double)(alunni[i - 1] * 100 / (double)PAGINE_LIBRO));

    }

}

int sommaCifre(int numero) {

    int somma = 0;

    while(numero > 0) {
        somma += numero % 10;
        numero /= 10;
    }

    return somma;

}
