#ifndef SORT_H
#define SORT_H

typedef struct {
    long long int comparacoes;
    long long int trocas;
} Contagem;

Contagem BubbleSort(int vetor[], int size);
Contagem InsertionSort(int vetor[], int size);
Contagem SelectionSort(int vetor[], int size);
Contagem MergeSort(int v[], int left, int right);
Contagem QuickSort(int vetor[], int size);
void troca(int* a, int* b);
int particiona(int vetor[], int inicio, int fim, Contagem* contagem);
Contagem intercala(int v[], int left, int right);

#endif // SORT_H
