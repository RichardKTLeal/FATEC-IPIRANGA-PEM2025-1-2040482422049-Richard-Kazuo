/*---------------------------------------------------------------------*
*                         FATEC Ipiranga                               *
*               Disciplina: Programaçao Estruturada e Modular          *
*                        Prof. Veríssimo                               *
*----------------------------------------------------------------------*
* Objetivo do Programa: Seleção para residências acadêmica             *
* Data - 28/02/2025                                                    * 
* Autor: Richard Kazuo Takada Leal                                     *
*----------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define RUAS 3
#define GONDOLAS 10

char *ruas[RUAS] = {"A", "B", "C"};


char armazem[RUAS][GONDOLAS][10]; 

void inicializarArmazem() {
    
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            strcpy(armazem[i][j], "");
        }
    }
}

int estocarProduto(char produto[10]) {
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
           
            if (strcmp(armazem[i][j], "") == 0) {
                strcpy(armazem[i][j], produto);
                printf("Produto %s estocado na Rua %s, Gôndola %d\n", produto, ruas[i], j + 1);
                return 1;
            }
        }
    }
    printf("Não há espaço disponível para estocar o produto %s.\n", produto);
    return 0;
}

int retirarProduto(char produto[10]) {
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            if (strcmp(armazem[i][j], produto) == 0) {
                printf("Produto %s retirado da Rua %s, Gôndola %d\n", produto, ruas[i], j + 1);
                strcpy(armazem[i][j], "");  
                return 1;
            }
        }
    }
    printf("Produto %s não encontrado no armazém.\n", produto);
    return 0;
}

int main() {
    inicializarArmazem();

    int opcao;
    char produto[10];
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Estocar Produto\n");
        printf("2. Retirar Produto\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o código do produto para estocar (exemplo: S123): ");
                scanf("%s", produto);
                estocarProduto(produto);
                break;
            case 2:
                printf("Digite o código do produto para retirar (exemplo: S123): ");
                scanf("%s", produto);
                retirarProduto(produto);
                break;
            case 3:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
