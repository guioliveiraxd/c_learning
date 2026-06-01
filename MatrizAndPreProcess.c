#include <stdio.h>
#include <stdlib.h>

#define DIM 5

int main() {
    int matriz[DIM][DIM];
    int soma_acima = 0;
    int maior_primeira_linha;

    printf("Digite os valores da matriz:\n");

    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Soma dos elementos acima da diagonal principal
    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            if(j > i) {
                soma_acima += matriz[i][j];
            }
        }
    }

    // Maior elemento da primeira linha
    maior_primeira_linha = matriz[0][0];

    for(int j = 1; j < DIM; j++) {
        if(matriz[0][j] > maior_primeira_linha) {
            maior_primeira_linha = matriz[0][j];
        }
    }

    // Multiplicar diagonal secundária
    for(int i = 0; i < DIM; i++) {
        matriz[i][DIM - 1 - i] *= maior_primeira_linha;
    }

    printf("\nSoma acima da diagonal principal: %d\n", soma_acima);

    printf("\nMatriz modificada:\n");

    for(int i = 0; i < DIM; i++) {
        for(int j = 0; j < DIM; j++) {
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
