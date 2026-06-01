#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"

Veiculo *frota[MAX_VEICULOS];

void iniciar_frota() {
    for (int i = 0; i < MAX_VEICULOS; i++) {
        frota[i] = NULL;
    }
}

void imprimir_veiculo(int pos) {
    if (frota[pos] == NULL) return;

    printf("\n------------------------\n");
    printf("Placa: %s\n", frota[pos]->placa);
    printf("Modelo: %s\n", frota[pos]->modelo);
    printf("Motorista: %s\n", frota[pos]->motorista);
    printf("Capacidade: %.2lf kg\n", frota[pos]->capacidade_carga);
    printf("Status: %s\n", frota[pos]->status ? "Disponivel" : "Em Rota");
}

void listar_frota_completa() {
    int encontrou = 0;

    for (int i = 0; i < MAX_VEICULOS; i++) {
        if (frota[i] != NULL) {
            imprimir_veiculo(i);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum veiculo cadastrado.\n");
    }
}

void cadastrar_veiculo() {
    int pos = -1;

    for (int i = 0; i < MAX_VEICULOS; i++) {
        if (frota[i] == NULL) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Frota cheia!\n");
        return;
    }

    frota[pos] = (Veiculo *)malloc(sizeof(Veiculo));

    printf("Placa: ");
    fgets(frota[pos]->placa, sizeof(frota[pos]->placa), stdin);
    frota[pos]->placa[strcspn(frota[pos]->placa, "\n")] = '\0';

    printf("Modelo: ");
    fgets(frota[pos]->modelo, sizeof(frota[pos]->modelo), stdin);
    frota[pos]->modelo[strcspn(frota[pos]->modelo, "\n")] = '\0';

    printf("Motorista: ");
    fgets(frota[pos]->motorista, sizeof(frota[pos]->motorista), stdin);
    frota[pos]->motorista[strcspn(frota[pos]->motorista, "\n")] = '\0';

    printf("Capacidade (kg): ");
    scanf("%lf", &frota[pos]->capacidade_carga);

    printf("Status (1=Disponivel / 0=Em Rota): ");
    scanf("%d", &frota[pos]->status);

    getchar();

    printf("Veiculo cadastrado com sucesso!\n");
}

void buscar_veiculo_por_placa() {
    char placa[10];

    printf("Digite a placa: ");
    fgets(placa, sizeof(placa), stdin);
    placa[strcspn(placa, "\n")] = '\0';

    for (int i = 0; i < MAX_VEICULOS; i++) {
        if (frota[i] != NULL && strcmp(frota[i]->placa, placa) == 0) {
            imprimir_veiculo(i);
            return;
        }
    }

    printf("Veiculo nao encontrado.\n");
}

void atualizar_dados_veiculo() {
    char placa[10];

    printf("Placa do veiculo: ");
    fgets(placa, sizeof(placa), stdin);
    placa[strcspn(placa, "\n")] = '\0';

    for (int i = 0; i < MAX_VEICULOS; i++) {
        if (frota[i] != NULL && strcmp(frota[i]->placa, placa) == 0) {

            char buffer[50];

            printf("Novo motorista (ENTER mantem): ");
            fgets(buffer, sizeof(buffer), stdin);

            if (strcmp(buffer, "\n") != 0) {
                buffer[strcspn(buffer, "\n")] = '\0';
                strcpy(frota[i]->motorista, buffer);
            }

            double capacidade;
            printf("Nova capacidade (-1 mantem): ");
            scanf("%lf", &capacidade);

            if (capacidade != -1)
                frota[i]->capacidade_carga = capacidade;

            int status;
            printf("Novo status (-1 mantem): ");
            scanf("%d", &status);

            if (status != -1)
                frota[i]->status = status;

            getchar();

            printf("Dados atualizados!\n");
            return;
        }
    }

    printf("Veiculo nao encontrado.\n");
}

int main() {
    int opcao;

    iniciar_frota();

    do {
        printf("\n===== CARGOTRACK =====\n");
        printf("1 - Cadastrar Veiculo\n");
        printf("2 - Listar Frota\n");
        printf("3 - Buscar por Placa\n");
        printf("4 - Atualizar Veiculo\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrar_veiculo(); break;
            case 2: listar_frota_completa(); break;
            case 3: buscar_veiculo_por_placa(); break;
            case 4: atualizar_dados_veiculo(); break;
        }

    } while (opcao != 0);

    for (int i = 0; i < MAX_VEICULOS; i++) {
        if (frota[i] != NULL)
            free(frota[i]);
    }

    return 0;
}
