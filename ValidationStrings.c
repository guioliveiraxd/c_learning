#include <stdio.h>
#include <string.h>

void gerar_versao_seguranca(char *frase) {

    int inicio = 0;
    int fim;
    int tamanho = strlen(frase);

    if(frase[tamanho - 1] == '\n') {
        frase[tamanho - 1] = '\0';
        tamanho--;
    }

    for(int i = 0; i <= tamanho; i++) {

        if(frase[i] == ' ' || frase[i] == '\0') {

            fim = i - 1;

            while(inicio < fim) {
                char temp = frase[inicio];
                frase[inicio] = frase[fim];
                frase[fim] = temp;

                inicio++;
                fim--;
            }

            if(frase[i] == ' ')
                frase[i] = '_';

            inicio = i + 1;
        }
    }

    printf("\nVersao de seguranca:\n%s\n", frase);
}

int main() {

    char buffer[100];

    printf("Digite a frase: ");
    fgets(buffer, sizeof(buffer), stdin);

    gerar_versao_seguranca(buffer);

    return 0;
}
