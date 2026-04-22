#include <stdio.h>

#define TAM 8

// desenho do tabuleiro
void desenharTabuleiro(int linha, int coluna, char peca) {

    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {

            if(i == linha && j == coluna) {
                printf("%c ", peca);
            } else {
                printf(". ");
            }

        }
        printf("\n");
    }
}

int main() {

    int opcao;
    int linha = 0, coluna = 0; // posição inicial
    char peca = 'P';

    do {
        printf("\n=== MINI XADREZ 8x8 ===\n");
        printf("1 - Torre\n");
        printf("2 - Bispo\n");
        printf("3 - Rainha\n");
        printf("4 - Cavalo\n");
        printf("5 - Sair\n");

        printf("Escolha a peça: ");
        scanf("%d", &opcao);

        printf("\n");

        switch(opcao) {

            // ================= TORRE =================
            case 1:
                peca = 'T';
                printf("Movendo Torre...\n");

                for(int i = 0; i < 3; i++) {
                    if(coluna < TAM - 1) {
                        coluna++;
                        printf("Direita\n");
                        desenharTabuleiro(linha, coluna, peca);
                        printf("\n");
                    }
                }
                break;

            // ================= BISPO =================
            case 2:
                peca = 'B';
                printf("Movendo Bispo...\n");

                int i = 0;
                while(i < 3) {
                    if(linha > 0 && coluna < TAM - 1) {
                        linha--;
                        coluna++;
                        printf("Diagonal (Cima + Direita)\n");
                        desenharTabuleiro(linha, coluna, peca);
                        printf("\n");
                    }
                    i++;
                }
                break;

            // ================= RAINHA =================
            case 3:
                peca = 'R';
                printf("Movendo Rainha...\n");

                for(int k = 0; k < 3; k++) {
                    if(coluna > 0) {
                        coluna--;
                        printf("Esquerda\n");
                        desenharTabuleiro(linha, coluna, peca);
                        printf("\n");
                    }
                }
                break;

            // ================= CAVALO =================
            case 4:
                peca = 'C';
                printf("Movendo Cavalo...\n");

                int passosBaixo = 2;
                int passosEsquerda = 1;

                for(int x = 0; x < passosBaixo; x++) {

                    if(linha < TAM - 1) {
                        linha++;
                        printf("Baixo\n");
                        desenharTabuleiro(linha, coluna, peca);
                        printf("\n");
                    }

                    // loop aninhado
                    if(x == passosBaixo - 1) {
                        int y = 0;

                        while(y < passosEsquerda) {
                            if(coluna > 0) {
                                coluna--;
                                printf("Esquerda\n");
                                desenharTabuleiro(linha, coluna, peca);
                                printf("\n");
                            }
                            y++;
                        }
                    }
                }
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 5);

    return 0;
}