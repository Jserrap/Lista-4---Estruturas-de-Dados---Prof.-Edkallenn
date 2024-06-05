/*
** Função : Crie um programa para gerenciar uma pilha de processos em C. Cada processo possui um
identificador(número) e uma descrição(string). Você deverá pedir ao usuário para escolher
se deseja encerrar, incluir ou retirarum processo da pilha. Se a operação for uma inclusão,
colocar o processo na pilha e imprimir o novo estado dessa; se for uma exclusão, caso a
pilha não esteja vazia, imprimir "removido o processo #identificador – descrição da
pilha" e mostrar o conteúdo atual dela; se a pilha estiver vazia, mostrar "pilha vazia". Se o
usuário escolher encerrar, esvazie a pilha (caso ainda existam elementos nela) e encerre o
programa
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char descricao[100];
} Processo;

typedef struct {
    Processo itens[MAX_SIZE];
    int topo;
} PilhaProcessos;

void inicializarPilha(PilhaProcessos *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(PilhaProcessos *pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(PilhaProcessos *pilha) {
    return pilha->topo == MAX_SIZE - 1;
}

void incluirProcesso(PilhaProcessos *pilha, Processo processo) {
    if (pilhaCheia(pilha)) {
        printf("Erro: pilha cheia\n");
    } else {
        pilha->topo++;
        pilha->itens[pilha->topo] = processo;
        printf("Processo #%d - %s incluído na pilha\n", processo.id, processo.descricao);
    }
}

void retirarProcesso(PilhaProcessos *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia\n");
    } else {
        Processo processo = pilha->itens[pilha->topo];
        pilha->topo--;
        printf("Removido o processo #%d - %s da pilha\n", processo.id, processo.descricao);
    }
}

int main() {
    PilhaProcessos pilha;
    Processo processo;
    int opcao;

    inicializarPilha(&pilha);

    do {
        printf("\n----- MENU -----\n");
        printf("1. Incluir processo\n");
        printf("2. Retirar processo\n");
        printf("3. Encerrar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o ID do processo: ");
                scanf("%d", &processo.id);
                printf("Digite a descrição do processo: ");
                scanf(" %[^\n]s", processo.descricao);
                incluirProcesso(&pilha, processo);
                break;
            case 2:
                retirarProcesso(&pilha);
                break;
            case 3:
                while (!pilhaVazia(&pilha)) {
                    retirarProcesso(&pilha);
                }
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (opcao != 3);

    return 0;
}