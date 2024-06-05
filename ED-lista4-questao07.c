/*
** Função :  Você foi contratado para desenvolver um sistema de gerenciamento de atendimento para
uma clínica médica. O sistema deve permitir que os pacientes sejam atendidos por ordem
de chegada, utilizando uma estrutura de fila.
Implemente uma struct (registro/classe) chamada Atendimento que possui os seguintes
métodos:
1. adicionar_paciente(paciente) : Recebe como parâmetro o nome de um paciente e o
adiciona à fila de atendimento.
2. proximo_paciente() : Retorna o próximo paciente a ser atendido e o remove da fila.
Caso a fila esteja vazia, retorna a mensagem "Não há pacientes na fila".
3. quantidade_pacientes() : Retorna a quantidade de pacientes na fila de atendimento.
Instruções:
Utilize uma estrutura de fila para gerenciar os pacientes. Você pode implementar a fila
do zero ou utilizar uma biblioteca existente.
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[50];
    struct Node *prox;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
    int tamanho;
} FilaAtendimento;

void inicializarFila(FilaAtendimento *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int filaVazia(FilaAtendimento *fila) {
    return (fila->inicio == NULL);
}

void adicionarPaciente(FilaAtendimento *fila, char nome[]) {
    Node *novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("Erro: impossível alocar memória\n");
        exit(1);
    }

    strcpy(novoNode->nome, nome);
    novoNode->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNode;
    } else {
        fila->fim->prox = novoNode;
    }

    fila->fim = novoNode;
    fila->tamanho++;
}

char* proximoPaciente(FilaAtendimento *fila) {
    if (filaVazia(fila)) {
        return "Não há pacientes na fila";
    }

    Node *temp = fila->inicio;
    char *nomePaciente = (char*)malloc(sizeof(char) * 50);
    if (nomePaciente == NULL) {
        printf("Erro: impossível alocar memória\n");
        exit(1);
    }

    strcpy(nomePaciente, temp->nome);

    fila->inicio = fila->inicio->prox;
    free(temp);
    fila->tamanho--;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    return nomePaciente;
}

int quantidadePacientes(FilaAtendimento *fila) {
    return fila->tamanho;
}

int main() {
    FilaAtendimento fila;
    inicializarFila(&fila);
    int opcao;
    char nomePaciente[50];

    do {
        printf("\n----- MENU -----\n");
        printf("1. Adicionar paciente\n");
        printf("2. Próximo paciente\n");
        printf("3. Quantidade de pacientes\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome do paciente: ");
                scanf(" %[^\n]s", nomePaciente);
                adicionarPaciente(&fila, nomePaciente);
                printf("Paciente \"%s\" adicionado à fila de atendimento\n", nomePaciente);
                break;
            case 2:
                printf("Próximo paciente: %s\n", proximoPaciente(&fila));
                break;
            case 3:
                printf("Quantidade de pacientes na fila: %d\n", quantidadePacientes(&fila));
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (opcao != 4);

    return 0;
}