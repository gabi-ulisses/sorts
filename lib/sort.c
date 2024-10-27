#include "sort.h"
#include <stdlib.h>

Contagem BubbleSort(int vetor[], int size) {
    Contagem contagem = {0, 0};  
    int i;

    for (int j = 0; j < size - 1; j++) {
        int continua = 0;

        for (i = 0; i < size - 1 - j; i++) {
            contagem.comparacoes++; 

            if (vetor[i] > vetor[i + 1]) {
                troca(&vetor[i], &vetor[i + 1]);
                contagem.trocas++;
                continua = 1;
            }
        }

        if (!continua) break;
    }

    return contagem;
}

Contagem InsertionSort(int vetor[], int size) {
    Contagem contagem = {0, 0};  

    for (int i = 1; i < size; i++) {
        int chave = vetor[i];
        int j = i - 1;

        contagem.comparacoes++;  
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];  
            contagem.trocas++;  
            j--;
            contagem.comparacoes++; // Conta a comparação no while
        }
        vetor[j + 1] = chave;
    }

    return contagem;
}

Contagem SelectionSort(int vetor[], int size) {
    Contagem contagem = {0, 0};  

    for (int i = 0; i < size - 1; i++) {
        int inicio = i;

        for (int j = i + 1; j < size; j++) {
            contagem.comparacoes++;  
            if (vetor[j] < vetor[inicio]) {
                inicio = j;
            }
        }

        if (inicio != i) {
            troca(&vetor[inicio], &vetor[i]);
            contagem.trocas++;  
        }
    }

    return contagem;  
}

Contagem intercala(int v[], int left, int right) {
    Contagem contagem = {0, 0}; // Inicializa as contagens de comparações e trocas
    int meio = (left + right) / 2;
    int i = left;
    int j = meio + 1;
    int k = 0;
    int temp[right - left + 1];

    // Comparando e copiando elementos das duas metades
    while (i <= meio && j <= right) {
        contagem.comparacoes++; // Conta a comparação entre v[i] e v[j]
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
            contagem.trocas++; // Conta os elementos restantes da metade esquerda
        }
    }

    // Copia os elementos restantes da metade esquerda
    while (i <= meio) {
        temp[k++] = v[i++];
    }

    // Copia os elementos restantes da metade direita
    while (j <= right) {
        temp[k++] = v[j++];
    }

    // Copia de volta para o vetor original
    for (i = left, k = 0; i <= right; i++, k++) {
        v[i] = temp[k];
         contagem.trocas++; // Conta os elementos restantes da metade esquerda

    }

    return contagem;
}

Contagem MergeSort(int v[], int left, int right) {
    Contagem contagem = {0, 0};

    if (left < right) {
        int meio = (left + right) / 2;
        Contagem contagem_esq = MergeSort(v, left, meio); 
        Contagem contagem_dir = MergeSort(v, meio + 1, right);
        Contagem contagem_merge = intercala(v, left, right);

        // Soma as contagens de comparações e trocas
        contagem.comparacoes = contagem_esq.comparacoes + contagem_dir.comparacoes + contagem_merge.comparacoes;
        contagem.trocas = contagem_esq.trocas + contagem_dir.trocas + contagem_merge.trocas;
    }

    return contagem;
}

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int vetor[], int inicio, int fim, Contagem* contagem) {
    int pivo = vetor[fim];
    int i = inicio;

    for (int j = inicio; j < fim; j++) {
        contagem->comparacoes++; 
        if (vetor[j] < pivo) {
            if (i != j) {
                troca(&vetor[i], &vetor[j]);
                contagem->trocas++;
            }
            i++;
        }
    }

    if (i != fim) {
        troca(&vetor[i], &vetor[fim]);
        contagem->trocas++;
    }
    return i; // Retorna a nova posição do pivô
}


Contagem QuickSort(int vetor[], int size) {
    int inicio = 0, fim = size - 1;
    int* pilha = (int*)malloc(size * sizeof(int) * 2);
    int topo = -1;
    Contagem contagem = {0, 0}; // Inicializar a contagem

    pilha[++topo] = inicio;
    pilha[++topo] = fim;

    while (topo >= 0) {
        fim = pilha[topo--];
        inicio = pilha[topo--];

        int pivo = particiona(vetor, inicio, fim, &contagem);

        if (pivo - 1 > inicio) {
            pilha[++topo] = inicio;
            pilha[++topo] = pivo - 1;
        }

        if (pivo + 1 < fim) {
            pilha[++topo] = pivo + 1;
            pilha[++topo] = fim;
        }
    }

    free(pilha); // Liberar a memória da pilha
    return contagem; // Retornar a estrutura Contagem
}
