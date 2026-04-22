#include <stdio.h>

int main() {

    
    // torre - 5 casas para a direita
    printf("Movimento da Torre:\n\n");

    int i = 0;
    while(i < 5) {
        printf("Direita\n");
        i++;
    }

    printf("\n");

    // bispo - 5 casas para cima e direita
    
    printf("Movimento do Bispo:\n\n");

    int j = 0;
    do {
        printf("Cima\n");
        printf("Direita\n");
        j++;
    } while(j < 5);

    printf("\n");

    
    // rainha - 5 casas para a esquerda
    
    printf("Movimento da Rainha:\n\n");

    for(int k = 0; k < 5; k++) {
        printf("Esquerda\n");
    }

    printf("\n");

    // cavalo - 2 casas para baixo e 1 casa para a esquerda
    
    printf("Movimento do Cavalo:\n\n");

    int passosBaixo = 2;
    int passosEsquerda = 1;

    for(int x = 0; x < passosBaixo; x++) {
        printf("Baixo\n");

        if(x == passosBaixo - 1) {
            int y = 0;
            while(y < passosEsquerda) {
                printf("Esquerda\n");
                y++;
            }
        }
    }

    return 0;
}