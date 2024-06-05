/*
** Função : Criar uma base de dados usando a técnica de lista encadeada para gerir os livros de uma
biblioteca. A informação de cada livro é: autor, título, editora, ano de edição. A base de
dados deve ter as seguintes funcionalidades (funções): Inserção ordenada; remoção;
alteração; busca por nome do livro e busca por nome do autor. Faça um menu para
melhorar a apresentação do programa para o usuário
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    char autor[50];
    char titulo[100];
    char editora[50];
    int ano;
    struct Livro *prox;
} Livro;

Livro* criarLivro(char autor[], char titulo[], char editora[], int ano) {
    Livro* novoLivro = (Livro*)malloc(sizeof(Livro));
    if (novoLivro != NULL) {
        strcpy(novoLivro->autor, autor);
        strcpy(novoLivro->titulo, titulo);
        strcpy(novoLivro->editora, editora);
        novoLivro->ano = ano;
        novoLivro->prox = NULL;
    }
    return novoLivro;
}

void inserirLivro(Livro** lista, Livro* novoLivro) {
    if (*lista == NULL || strcmp((*lista)->titulo, novoLivro->titulo) > 0) {
        novoLivro->prox = *lista;
        *lista = novoLivro;
    } else {
        Livro* atual = *lista;
        while (atual->prox != NULL && strcmp(atual->prox->titulo, novoLivro->titulo) < 0) {
            atual = atual->prox;
        }
        novoLivro->prox = atual->prox;
        atual->prox = novoLivro;
    }
}

void removerLivro(Livro** lista, char titulo[]) {
    Livro* atual = *lista;
    Livro* anterior = NULL;

    while (atual != NULL && strcmp(atual->titulo, titulo) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            *lista = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
    } else {
        printf("Livro nao encontrado.\n");
    }
}

void alterarLivro(Livro* lista, char titulo[]) {
    Livro* atual = lista;
    while (atual != NULL && strcmp(atual->titulo, titulo) != 0) {
        atual = atual->prox;
    }

    if (atual != NULL) {
        printf("Digite o novo autor: ");
        scanf(" %[^\n]s", atual->autor);
        printf("Digite a nova editora: ");
        scanf(" %[^\n]s", atual->editora);
        printf("Digite o novo ano de edicao: ");
        scanf("%d", &atual->ano);
        printf("Livro alterado com sucesso.\n");
    } else {
        printf("Livro nao encontrado.\n");
    }
}

Livro* buscarLivroPorTitulo(Livro* lista, char titulo[]) {
    Livro* atual = lista;
    while (atual != NULL && strcmp(atual->titulo, titulo) != 0) {
        atual = atual->prox;
    }
    return atual;
}

Livro* buscarLivroPorAutor(Livro* lista, char autor[]) {
    Livro* resultado = NULL;
    Livro* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->autor, autor) == 0) {
            resultado = atual;
            break;
        }
        atual = atual->prox;
    }
    return resultado;
}

void imprimirLivro(Livro* livro) {
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Editora: %s\n", livro->editora);
    printf("Ano de edicao: %d\n", livro->ano);
}

void imprimirLista(Livro* lista) {
    Livro* atual = lista;
    while (atual != NULL) {
        imprimirLivro(atual);
        printf("\n");
        atual = atual->prox;
    }
}

void liberarLista(Livro* lista) {
    Livro* atual = lista;
    while (atual != NULL) {
        Livro* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    Livro* lista = NULL;
    int opcao;
    char titulo[100];

    do {
        printf("\n----- MENU -----\n");
        printf("1. Inserir livro\n");
        printf("2. Remover livro\n");
        printf("3. Alterar livro\n");
        printf("4. Buscar livro por titulo\n");
        printf("5. Buscar livro por autor\n");
        printf("6. Imprimir lista de livros\n");
        printf("7. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char autor[50], editora[50];
                int ano;

                printf("Digite o titulo do livro: ");
                scanf(" %[^\n]s", titulo);
                printf("Digite o autor do livro: ");
                scanf(" %[^\n]s", autor);
                printf("Digite a editora do livro: ");
                scanf(" %[^\n]s", editora);
                printf("Digite o ano de edicao do livro: ");
                scanf("%d", &ano);

                Livro* novoLivro = criarLivro(autor, titulo, editora, ano);
                if (novoLivro != NULL) {
                    inserirLivro(&lista, novoLivro);
                    printf("Livro inserido com sucesso.\n");
                } else {
                    printf("Erro ao criar o livro.\n");
                }
                break;
            }
            case 2: {
                printf("Digite o titulo do livro a ser removido: ");
                scanf(" %[^\n]s", titulo);
                removerLivro(&lista, titulo);
                break;
            }
            case 3: {
                printf("Digite o titulo do livro a ser alterado: ");
                scanf(" %[^\n]s", titulo);
                alterarLivro(lista, titulo);
                break;
            }
            case 4: {
                printf("Digite o titulo do livro a ser buscado: ");
                scanf(" %[^\n]s", titulo);
                Livro* livro = buscarLivroPorTitulo(lista, titulo);
                if (livro != NULL) {
                    printf("Livro encontrado:\n");
                    imprimirLivro(livro);
                } else {
                    printf("Livro nao encontrado.\n");
                }
                break;
            }
            case 5: {
                char autor[50];
                printf("Digite o autor do livro a ser buscado: ");
                scanf(" %[^\n]s", autor);
                Livro* livro = buscarLivroPorAutor(lista, autor);
                if (livro != NULL) {
                    printf("Livro encontrado:\n");
                    imprimirLivro(livro);
                } else {
                    printf("Livro nao encontrado.\n");
                }
                break;
            }
            case 6: {
                printf("Lista de livros:\n");
                imprimirLista(lista);
                break;
            }
            case 7:
                liberarLista(lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 7);

    return 0;
}