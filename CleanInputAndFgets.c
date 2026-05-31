#include <stdio.h>
#include <string.h>

// Função criada para limpar o buffer do teclado.
// Remove caracteres restantes até encontrar '\n' ou EOF.
void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main()
{
    int idade1, idade2;
    char nome1[50], nome2[50];

    printf("Digite o valor da idade 1: ");
    scanf("%d", &idade1);

    printf("Digite o nome da pessoa 1: ");
    limpar_entrada(); // Limpa o ENTER deixado pelo scanf

    // Lê uma linha inteira de texto, incluindo espaços
    fgets(nome1, 50, stdin);

    // Remove o '\n' que o fgets normalmente armazena no final
    strtok(nome1, "\n");

    printf("Digite o valor da idade 2: ");
    scanf("%d", &idade2);

    printf("Digite o nome da pessoa 2: ");
    limpar_entrada();

    // Lê uma linha inteira de texto
    fgets(nome2, 50, stdin);

    // Remove o '\n' do final da string
    strtok(nome2, "\n");

    printf("idade 1: %d\n", idade1);
    printf("Nome 1: %s\n", nome1);
    printf("idade 2: %d\n", idade2);
    printf("Nome 2: %s\n", nome2);

    return 0;
}
