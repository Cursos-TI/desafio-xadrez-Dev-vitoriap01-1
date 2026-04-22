#include <stdio.h>

int main() {

    // Quantidade de movimentos do cavalo
    int passosCima = 2;
    int passosEsquerda = 1;

    printf("Movimento do Cavalo:\n\n");

   for(int i = 0; i < passosCima; i++) {
        printf("Acima\n");

        if(i == passosCima - 1) {

            int j = 0;

            // Loop WHILE (interno)
            while(j < passosEsquerda) {
                printf("Esquerda\n");
                j++;
            }
        }
    }

    return 0;
}