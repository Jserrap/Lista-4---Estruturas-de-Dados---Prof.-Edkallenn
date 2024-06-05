/*
** Função : Criar um programa para Implementar uma pilha de números reais. Apresentar um menu
para inserir (push), retirar(pop) elementos na pilha (exibir a pilha a cada operação). Criar
também uma função para verificar se a pilha está vazia
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    float items[MAX_SIZE];
    int top;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->top = -1;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->top == -1;
}

int pilhaCheia(Pilha *pilha) {
    return pilha->top == MAX_SIZE - 1;
}

void push(Pilha *pilha, float valor) {
    if (pilhaCheia(pilha)) {
        printf("Erro: pilha cheia\n");
    } else {
        pilha->top++;
        pilha->items[pilha->top] = valor;
    }
}

float pop(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: pilha vazia\n");
        return -1;
    } else {
        float valor = pilha->items[pilha->top];
        pilha->top--;
        return valor;
    }
}

void exibirPilha(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
    } else {
        printf("Elementos da pilha:\n");
        for (int i = pilha->top; i >= 0; i--) {
            printf("%.2f\n", pilha->items[i]);
        }
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);
    int opcao;
    float valor;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Inserir elemento (push)\n");
        printf("2. Retirar elemento (pop)\n");
        printf("3. Exibir pilha\n");
        printf("4. Verificar se a pilha esta vazia\n");
        printf("5. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido na pilha: ");
                scanf("%f", &valor);
                push(&pilha, valor);
                exibirPilha(&pilha);
                break;
            case 2:
                valor = pop(&pilha);
                if (valor != -1) {
                    printf("Elemento retirado da pilha: %.2f\n", valor);
                    exibirPilha(&pilha);
                }
                break;
            case 3:
                exibirPilha(&pilha);
                break;
            case 4:
                if (pilhaVazia(&pilha)) {
                    printf("A pilha esta vazia\n");
                } else {
                    printf("A pilha nao esta vazia\n");
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (opcao != 5);

    return 0;
}