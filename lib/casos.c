#include "casos.h"
#include <stdlib.h>
#include <time.h>

void preencherMelhorCaso(int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        vetor[i] = i; 
    }
}

void preencherCasoMedio(int vetor[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        vetor[i] = rand() % size; 
    }
}

void preencherPiorCaso(int vetor[], int size) {
    for (int i = 0; i < size; i++) {
        vetor[i] = size - i - 1;
    }
}
