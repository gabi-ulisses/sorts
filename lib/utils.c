#include "utils.h"

void copiaVetor(int origem[], int destino[], int size) {
    for (int i = 0; i < size; i++) {
        destino[i] = origem[i];
    }
}