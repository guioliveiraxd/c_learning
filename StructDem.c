#include <stdio.h>

struct Livro {
    char titulo[50];
    char autor[50];
    int ano;
    float preco;
};

void aplicar_desconto(struct Livro *l) {

    l->preco = l->preco * 0.90;
}

int main() {

    struct Livro livro = {
        "Linguagem C",
        "Dennis Ritchie",
        1978,
        100.0
    };

    printf("Preco antes: %.2f\n", livro.preco);

    aplicar_desconto(&livro);

    printf("Preco depois: %.2f\n", livro.preco);

    return 0;
}
