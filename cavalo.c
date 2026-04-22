#include <stdio.h>

int main() {

    // Quantidade de movimentos do cavalo
    int passosBaixo = 2;
    int passosEsquerda = 1;

    printf("Movimento do Cavalo:\n\n");

    // Loop externo (FOR) -> movimento vertical (para baixo)
    for(int i = 0; i < passosBaixo; i++) {
        printf("Baixo\n");
    }

    // Loop interno (WHILE) -> movimento horizontal (para esquerda)
    int j = 0;
    while(j < passosEsquerda) {
        printf("Esquerda\n");
        j++;
    }

    return 0;
}