/*
** Função : Faça um programa, em C, que simule uma lista de compras. As compras podem ter itens e
esses itens devem ter quantidade e o nome do produto. O programa permite inserir,
remover, consultar e mostrar todos os itens da lista de compras. (Usar obrigatoriamente
uma lista encadeada)
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Item {
    char nome[50];
    int quantidade;
    struct Item *prox;
} Item;

Item* inicializarLista() {
    return NULL;
}

Item* inserirItem(Item *lista, char nome[], int quantidade) {
    Item *novoItem = (Item*)malloc(sizeof(Item));
    if (novoItem == NULL) {
        printf("Erro: impossível alocar memória\n");
        exit(1);
    }

    strcpy(novoItem->nome, nome);
    novoItem->quantidade = quantidade;
    novoItem->prox = lista;
    return novoItem;
}

Item* removerItem(Item *lista, char nome[]) {
    if (lista == NULL) {
        printf("Lista de compras vazia\n");
        return NULL;
    }

    Item *atual = lista;
    Item *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Item não encontrado na lista de compras\n");
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Item \"%s\" removido da lista de compras\n", nome);
    return lista;
}

void consultarItem(Item *lista, char nome[]) {
    Item *atual = lista;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Item não encontrado na lista de compras\n");
    } else {
        printf("Item \"%s\" encontrado na lista de compras. Quantidade: %d\n", nome, atual->quantidade);
    }
}

void mostrarLista(Item *lista) {
    if (lista == NULL) {
        printf("Lista de compras vazia\n");
    } else {
        printf("Lista de compras:\n");
        Item *atual = lista;
        while (atual != NULL) {
            printf("%s - Quantidade: %d\n", atual->nome, atual->quantidade);
            atual = atual->prox;
        }
    }
}

void liberarLista(Item *lista) {
    Item *atual = lista;
    while (atual != NULL) {
        Item *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Item *lista = inicializarLista();
    int opcao;
    char nomeItem[50];
    int quantidade;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Inserir item na lista de compras\n");
        printf("2. Remover item da lista de compras\n");
        printf("3. Consultar item na lista de compras\n");
        printf("4. Mostrar todos os itens da lista de compras\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome do item: ");
                scanf(" %[^\n]s", nomeItem);
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                lista = inserirItem(lista, nomeItem, quantidade);
                break;
            case 2:
                printf("Nome do item a ser removido: ");
                scanf(" %[^\n]s", nomeItem);
                lista = removerItem(lista, nomeItem);
                break;
            case 3:
                printf("Nome do item a ser consultado: ");
                scanf(" %[^\n]s", nomeItem);
                consultarItem(lista, nomeItem);
                break;
            case 4:
                mostrarLista(lista);
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (opcao != 5);

    liberarLista(lista);
    return 0;
}