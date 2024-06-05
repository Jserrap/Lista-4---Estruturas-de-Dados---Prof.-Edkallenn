/*
** Função : Implemente uma função que classifica os elementos de um vetor em ordem crescente
usando o seguinte algoritmo (conhecido como "classificação por seleção"): procure pelo
menor elemento no vetor e permute esse elemento com o primeiro elemento do vetor;
repita este processo para o subvetor que se inicia no segundo elemento e, assim,
sucessivamente; o processo termina quando o subvetor contiver apenas um elemento. Teste
a função com dados gerados aleatoriamente.
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int vetor[], int tamanho) {
    int i, j, min_index, temp;
    for (i = 0; i < tamanho - 1; i++) {
        min_index = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[min_index]) {
                min_index = j;
            }
        }
        temp = vetor[min_index];
        vetor[min_index] = vetor[i];
        vetor[i] = temp;
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 10;
    int vetor[tamanho];

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    selectionSort(vetor, tamanho);

    imprimirVetor(vetor, tamanho);

    return 0;
}