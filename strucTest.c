#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

void cadastrar(Funcionario funcionarios[], int *total);
void listar(Funcionario funcionarios[], int total);

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int total = 0;
    int opcao;
    
    do {
        printf("\n=== SISTEMA DE FUNCIONARIOS ===\n");
        printf("1 - Cadastrar funcionario\n");
        printf("2 - Listar funcionarios\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 
        switch(opcao) {
            case 1:
                cadastrar(funcionarios, &total);
                break;
            case 2:
                listar(funcionarios, total);
                break;
            case 0:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

void cadastrar(Funcionario funcionarios[], int *total) {

    if (*total >= MAX_FUNCIONARIOS) {
        printf("Limite de funcionarios atingido!\n");
        return;
    }
    printf("\nNome: ");
    fgets(funcionarios[*total].nome, sizeof(funcionarios[*total].nome), stdin);
    funcionarios[*total].nome[
        strcspn(funcionarios[*total].nome, "\n")
    ] = '\0';

    printf("Idade: ");
    scanf("%d", &funcionarios[*total].idade);
    printf("Salario: ");
    scanf("%f", &funcionarios[*total].salario);

    getchar();

    (*total)++;

    printf("Funcionario cadastrado com sucesso!\n");
}

void listar(Funcionario funcionarios[], int total) {

    if (total == 0) {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }
    printf("\n=== FUNCIONARIOS CADASTRADOS ===\n");

    for(int i = 0; i < total; i++) {
        printf("\nFuncionario %d\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Idade: %d\n", funcionarios[i].idade);
        printf("Salario: R$ %.2f\n", funcionarios[i].salario);
    }
}