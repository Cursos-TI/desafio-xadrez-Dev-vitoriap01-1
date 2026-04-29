#include <stdio.h>

#define TAM 8

// tabuleiro 
void desenharTabuleiro(int linha, int coluna, char peca) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {

            if(i == linha && j == coluna)
                printf("%c ", peca);
            else
                printf(". ");
        }
        printf("\n");
    }
}

// torre
// Move para a direita
void moverTorre(int casas, int *linha, int *coluna) {
    if(casas <= 0) return;

    if(*coluna < TAM - 1) {
        (*coluna)++;
        printf("Direita\n");
        desenharTabuleiro(*linha, *coluna, 'T');
        printf("\n");
    }

    moverTorre(casas - 1, linha, coluna);
}

// rainha // Move para a esquerda
void moverRainha(int casas, int *linha, int *coluna) {
    if(casas <= 0) return;

    if(*coluna > 0) {
        (*coluna)--;
        printf("Esquerda\n");
        desenharTabuleiro(*linha, *coluna, 'R');
        printf("\n");
    }

    moverRainha(casas - 1, linha, coluna);
}

// bispo // Diagonal: cima + direita
void moverBispo(int casas, int *linha, int *coluna) {
    if(casas <= 0) return;

    // loop externo (vertical)
    for(int i = 0; i < 1; i++) {

        if(*linha > 0) {
            (*linha)--;
            printf("Cima\n");
        }

        // loop interno (horizontal)
        for(int j = 0; j < 1; j++) {
            if(*coluna < TAM - 1) {
                (*coluna)++;
                printf("Direita\n");
            }
        }

        desenharTabuleiro(*linha, *coluna, 'B');
        printf("\n");
    }

    moverBispo(casas - 1, linha, coluna);
}

// cavalo // Movimento: 2 cima + 1 direita
void moverCavalo(int *linha, int *coluna) {

    int movVertical = 2;
    int movHorizontal = 1;

    for(int i = 0; i < movVertical; i++) {

        if(i < 0) continue; 

        if(*linha > 0) {
            (*linha)--;
            printf("Cima\n");
            desenharTabuleiro(*linha, *coluna, 'C');
            printf("\n");
        }

        // último passo vertical → faz o horizontal
        if(i == movVertical - 1) {

            for(int j = 0; j < movHorizontal; j++) {

                if(j > 1) break; // exemplo de uso

                if(*coluna < TAM - 1) {
                    (*coluna)++;
                    printf("Direita\n");
                    desenharTabuleiro(*linha, *coluna, 'C');
                    printf("\n");
                }
            }
        }
    }
}

// main
int main() {

    int casas = 3;

    // posição inicial (centro do tabuleiro)
    int linha = 4;
    int coluna = 4;

    // TORRE
    printf("Movimento da Torre:\n\n");
    desenharTabuleiro(linha, coluna, 'T');
    printf("\n");

    moverTorre(casas, &linha, &coluna);

    printf("\n");

    // reset posição
    linha = 4;
    coluna = 4;

    // BISPO
    printf("Movimento do Bispo:\n\n");
    desenharTabuleiro(linha, coluna, 'B');
    printf("\n");

    moverBispo(casas, &linha, &coluna);

    printf("\n");

    // reset posição
    linha = 4;
    coluna = 4;

    // RAINHA
    printf("Movimento da Rainha:\n\n");
    desenharTabuleiro(linha, coluna, 'R');
    printf("\n");

    moverRainha(casas, &linha, &coluna);

    printf("\n");

    // reset posição
    linha = 4;
    coluna = 4;

    // CAVALO
    printf("Movimento do Cavalo:\n\n");
    desenharTabuleiro(linha, coluna, 'C');      
    printf("\n");

    moverCavalo(&linha, &coluna);

    return 0;
}