#include <stdio.h>
#include <string.h>
#define MAX 10
struct Livro {
    char titulo[100];
    char autor[50];
    int ano;
};
int main() {

    struct Livro livros[MAX];
    int qtd = 0;
    int opcao;
    int i;
    char busca[100];
    int achou;

    do {
        printf("\n1 - Cadastrar livro");
        printf("\n2 - Listar livros");
        printf("\n3 - Buscar livro");
        printf("\n0 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        while(getchar() != '\n');

        if(opcao == 1) {

            if(qtd < MAX) {
                printf("Titulo: ");
                fgets(livros[qtd].titulo, 100, stdin);
                livros[qtd].titulo[strcspn(livros[qtd].titulo, "\n")] = '\0';

                printf("Autor: ");
                fgets(livros[qtd].autor, 50, stdin);
                livros[qtd].autor[strcspn(livros[qtd].autor, "\n")] = '\0';

                printf("Ano: ");
                scanf("%d", &livros[qtd].ano);

                while(getchar() != '\n');

                qtd++;

                printf("Livro cadastrado.\n");
            }
            else {
                printf("Limite atingido.\n");
            }
        }

        else if(opcao == 2) {

            if(qtd == 0) {
                printf("Nenhum livro cadastrado.\n");
            }
            else {

                for(i = 0; i < qtd; i++) {

                    printf("\nLivro %d", i + 1);
                    printf("\nTitulo: %s", livros[i].titulo);
                    printf("\nAutor: %s", livros[i].autor);
                    printf("\nAno: %d\n", livros[i].ano);
                }
            }
        }

        else if(opcao == 3) {
            achou = 0;

            printf("Digite o titulo: ");
            fgets(busca, 100, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            for(i = 0; i < qtd; i++) {

                if(strcmp(busca, livros[i].titulo) == 0) {

                    printf("\nEncontrado!\n");
                    printf("Titulo: %s\n", livros[i].titulo);
                    printf("Autor: %s\n", livros[i].autor);
                    printf("Ano: %d\n", livros[i].ano);

                    achou = 1;
                    break;
                }
            }

            if(achou == 0) {
                printf("Livro nao encontrado.\n");
            }
        }

    } while(opcao != 0);

    return 0;
}