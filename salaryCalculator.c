#include <stdio.h>
#include <string.h>

int main(void) {

    char nome[50];
    double valorHora, salario;
    int horasTrabalhadas;

    printf("Digite o nome do funcionario:\n");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("Quanto ele recebe por hora?\n");
    scanf("%lf", &valorHora);

    printf("Quantas horas ele trabalhou no mes?\n");
    scanf("%d", &horasTrabalhadas);

    salario = horasTrabalhadas * valorHora;

    printf("\nNome: %s\n", nome);
    printf("Valor por hora: R$ %.2f\n", valorHora);
    printf("O pagamento para %s deve ser de R$ %.2f\n", nome, salario);

    return 0;
}
