#ifndef VEICULO_H
#define VEICULO_H

#define MAX_VEICULOS 10

typedef struct {
    char placa[10];
    char modelo[50];
    char motorista[50];
    double capacidade_carga;
    int status; /* 1 = Disponível, 0 = Em Rota */
} Veiculo;

#endif
