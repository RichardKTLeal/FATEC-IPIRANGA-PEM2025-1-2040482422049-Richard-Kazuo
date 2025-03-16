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
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATOS 50
#define PE_NOTAS 4
#define AC_NOTAS 5
#define PP_NOTAS 10
#define EB_NOTAS 3

typedef struct {
    char nome[100];
    float notaFinal;
} Candidato;

float calcularMediaCentral(float notas[], int numNotas) {
    float maior = notas[0], menor = notas[0], soma = 0;
    
    for (int i = 0; i < numNotas; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }

    for (int i = 0; i < numNotas; i++) {
        if (notas[i] != maior && notas[i] != menor) {
            soma += notas[i];
        }
    }

    return soma / (numNotas - 2);
}

float calcularNotaFinal(float pe, float ac, float pp, float eb) {
    return (pe * 0.3) + (ac * 0.1) + (pp * 0.4) + (eb * 0.2);
}

int compararCandidatos(const void* a, const void* b) {
    Candidato* c1 = (Candidato*)a;
    Candidato* c2 = (Candidato*)b;
    if (c1->notaFinal < c2->notaFinal) return 1;
    if (c1->notaFinal > c2->notaFinal) return -1;
    return 0;
}

int main() {
    Candidato candidatos[MAX_CANDIDATOS];
    int numCandidatos = 0;

    while (numCandidatos < MAX_CANDIDATOS) {
        printf("Digite o nome do candidato #%d: ", numCandidatos + 1);
        fgets(candidatos[numCandidatos].nome, 100, stdin);
        candidatos[numCandidatos].nome[strcspn(candidatos[numCandidatos].nome, "\n")] = 0; // Remove o '\n'

        float peNotas[PE_NOTAS], acNotas[AC_NOTAS], ppNotas[PP_NOTAS], ebNotas[EB_NOTAS];
        
        printf("Digite as 4 notas da Prova Escrita (PE): ");
        for (int i = 0; i < PE_NOTAS; i++) {
            do {
                scanf("%f", &peNotas[i]);
                if (peNotas[i] > 10) {
                    printf("Nota inválida! A nota deve ser menor ou igual a 10. Digite novamente: ");
                }
            } while (peNotas[i] > 10);
        }

        printf("Digite as 5 notas da Análise Curricular (AC): ");
        for (int i = 0; i < AC_NOTAS; i++) {
            do {
                scanf("%f", &acNotas[i]);
                if (acNotas[i] > 10) {
                    printf("Nota inválida! A nota deve ser menor ou igual a 10. Digite novamente: ");
                }
            } while (acNotas[i] > 10);
        }

        printf("Digite as 10 notas da Prova Prática (PP): ");
        for (int i = 0; i < PP_NOTAS; i++) {
            do {
                scanf("%f", &ppNotas[i]);
                if (ppNotas[i] > 10) {
                    printf("Nota inválida! A nota deve ser menor ou igual a 10. Digite novamente: ");
                }
            } while (ppNotas[i] > 10);
        }

        printf("Digite as 3 notas da Entrevista em Banca Avaliadora (EB): ");
        for (int i = 0; i < EB_NOTAS; i++) {
            do {
                scanf("%f", &ebNotas[i]);
                if (ebNotas[i] > 10) {
                    printf("Nota inválida! A nota deve ser menor ou igual a 10. Digite novamente: ");
                }
            } while (ebNotas[i] > 10);
        }

        // Calcula a média central de cada fase
        float peMedia = calcularMediaCentral(peNotas, PE_NOTAS);
        float acMedia = calcularMediaCentral(acNotas, AC_NOTAS);
        float ppMedia = calcularMediaCentral(ppNotas, PP_NOTAS);
        float ebMedia = calcularMediaCentral(ebNotas, EB_NOTAS);

        // Calcula a nota final
        candidatos[numCandidatos].notaFinal = calcularNotaFinal(peMedia, acMedia, ppMedia, ebMedia);

        numCandidatos++;

        printf("Deseja cadastrar mais um candidato? (1 - Sim, 0 - Não): ");
        int resposta;
        scanf("%d", &resposta);
        getchar(); 
        if (resposta == 0) break;
    }

    qsort(candidatos, numCandidatos, sizeof(Candidato), compararCandidatos);

    printf("\nRanking dos 15 primeiros candidatos:\n");
    for (int i = 0; i < 15 && i < numCandidatos; i++) {
        printf("%d. %s - Nota Final: %.2f\n", i + 1, candidatos[i].nome, candidatos[i].nf);
    }

    return 0;
}
