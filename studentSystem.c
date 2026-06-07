#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float media;
} Aluno;

void cadastrarAluno(Aluno *aluno);
void exibirAluno(Aluno aluno);

int main() {

    Aluno aluno;

    cadastrarAluno(&aluno);

    printf("\nRESULTADO\n");
    exibirAluno(aluno);

    return 0;
}

void cadastrarAluno(Aluno *aluno) {

    printf("Digite o nome do aluno: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);

    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';

    printf("Digite a primeira nota: ");
    scanf("%f", &aluno->nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &aluno->nota2);

    aluno->media = (aluno->nota1 + aluno->nota2) / 2;
}

void exibirAluno(Aluno aluno) {

    printf("Nome: %s\n", aluno.nome);
    printf("Nota 1: %.1f\n", aluno.nota1);
    printf("Nota 2: %.1f\n", aluno.nota2);
    printf("Media: %.1f\n", aluno.media);

    if(aluno.media >= 7.0) {
        printf("Situacao: APROVADO\n");
    } else {
        printf("Situacao: REPROVADO\n");
    }
}