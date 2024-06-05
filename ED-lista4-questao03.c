/*
** Função : Criar um programa para Implementar uma pilha de números reais. Apresentar um menu
para inserir (push), retirar(pop) elementos na pilha (exibir a pilha a cada operação). Criar
também uma função para verificar se a pilha está vazia
** Autor : João Victor de Almeida Quintans Urbano Serra Pinto
** Data : 05/06/2024
** Observações: 
*/

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nomeCompleto[81];
    char sexo;
    Data dataNascimento;
    float altura;
    float peso;
} PerfilSaude;

int main() {
    PerfilSaude perfil;

    printf("Nome Completo: ");
    fgets(perfil.nomeCompleto, sizeof(perfil.nomeCompleto), stdin);

    printf("Sexo (M/F): ");
    scanf(" %c", &perfil.sexo);

    printf("Data de Nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &perfil.dataNascimento.dia, &perfil.dataNascimento.mes, &perfil.dataNascimento.ano);

    printf("Altura (m): ");
    scanf("%f", &perfil.altura);

    printf("Peso (kg): ");
    scanf("%f", &perfil.peso);

    printf("\nPerfil de Saude:\n");
    printf("Nome Completo: %s", perfil.nomeCompleto);
    printf("Sexo: %c\n", perfil.sexo);
    printf("Data de Nascimento: %02d/%02d/%d\n", perfil.dataNascimento.dia, perfil.dataNascimento.mes, perfil.dataNascimento.ano);
    printf("Altura: %.2f m\n", perfil.altura);
    printf("Peso: %.2f kg\n", perfil.peso);

    return 0;
}