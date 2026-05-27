#include <stdio.h>

int main() {
    float x, y, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &x);

    printf("Digite a segunda nota: ");
    scanf("%f", &y);

    media = (x + y) / 2;

    printf("Media do aluno: %.2f\n", media);

    return 0;
}