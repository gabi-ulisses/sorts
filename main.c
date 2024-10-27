#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/sort.h"
#include "lib/casos.h"
#include "lib/utils.h"

#define MAX 1000000

void Sort(int vetor[], int size, int opcaoOrdenacao);

int main() {
    int *vetor;  
    int tamanho[] = {1000, 100000, 1000000};
    int opcaoTamanho = 0, size;

    printf("Vamos testar alguns métodos de classificação!\n");
    printf("Escolha o tamanho do vetor desejado: \n\n");
    printf("1 - Vetor com 1.000 elementos\n");
    printf("2 - Vetor com 100.000 elementos\n");
    printf("3 - Vetor com 1.000.000 elementos\n");

    printf("\nOpção escolhida: ");
    scanf("%d", &opcaoTamanho);

    if (opcaoTamanho < 1 || opcaoTamanho > 3) {
        printf("Opção inválida!\n");
        return 1;
    }

    size = tamanho[opcaoTamanho - 1];
    vetor = (int *)malloc(size * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Executar todos os métodos de ordenação
    printf("\nMelhor caso:\n\n");
    preencherMelhorCaso(vetor, size);
    for (int metodo = 1; metodo <= 5; metodo++) {
        Sort(vetor, size, metodo);
    }

    printf("\nCaso médio:\n\n");
    preencherCasoMedio(vetor, size);
    for (int metodo = 1; metodo <= 5; metodo++) {
        Sort(vetor, size, metodo);
    }

    printf("\nPior caso:\n\n");
    preencherPiorCaso(vetor, size);
    for (int metodo = 1; metodo <= 5; metodo++) {
        Sort(vetor, size, metodo);
    }

    free(vetor);  // Liberar a memória
    return 0;
}


void Sort(int vetor[], int size, int opcaoOrdenacao) {
    int *vetorCopia = (int *)malloc(size * sizeof(int));
    Contagem resultado = {0, 0};  // Inicializa contagens
    clock_t inicio, fim;
    double tempo_gasto;

    if (vetorCopia == NULL) {
        printf("Erro ao alocar memória para vetorCopia!\n");
        return;
    }

    copiaVetor(vetor, vetorCopia, size);

    switch(opcaoOrdenacao) {
        case 1:
            printf("Executando BubbleSort...\n\n");
            inicio = clock();
            resultado = BubbleSort(vetorCopia, size);
            fim = clock();
            break;
        case 2:
            printf("Executando InsertionSort...\n\n");
            inicio = clock();
            resultado = InsertionSort(vetorCopia, size);
            fim = clock();
            break;
        case 3:
            printf("Executando SelectionSort...\n\n");
            inicio = clock();
            resultado = SelectionSort(vetorCopia, size);
            fim = clock();
            break;
        case 4:
            printf("Executando MergeSort...\n\n");
            inicio = clock();
            resultado = MergeSort(vetorCopia, 0, size - 1);
            fim = clock();
            break;
        case 5:
            printf("Executando QuickSort...\n\n");
            inicio = clock();
            resultado = QuickSort(vetorCopia, size);  
            fim = clock();
            break;
        default:
            printf("Opção de algoritmo inválida!\n");
            free(vetorCopia);
            return;
    }

    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Comparações: %lld | Trocas: %lld | Tempo de execução: %.5f segundos\n\n", 
           resultado.comparacoes, resultado.trocas, tempo_gasto);

    free(vetorCopia);
}
