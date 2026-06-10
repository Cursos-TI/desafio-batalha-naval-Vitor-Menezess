#include <stdio.h>

int main() {
            char Cabecalho[10] = {'A','B','C','D','E','F','G','H','I','J'};
            int NumeroLinha[10] = {1,2,3,4,5,6,7,8,9,10};

            int Tabuleiro[10][10] = {0}; // inicializa tudo com 0

                        //contrução do navio linha vertical para a exibição
            // 3 números 3 em uma coluna (coluna 5, linhas 4,5,6)
            for (int i = 0; i < 3; i++) {
                Tabuleiro[4 + i][5] = 3;
            }

                        //contrução do navio linha horizontal para a exibição
            // 3 números 3 em uma linha (linha 2, colunas 3,4,5)
            for (int j = 0; j < 3; j++) {
                Tabuleiro[2][3 + j] = 3;
            }

                        //contrução do navio na DIAGONAL DESCENDO PARA A ESQUERDA para a exibição
            // 3 números 3 em uma linha (linha 3,4,5 colunas 0,1,2)
            for (int i = 0, j = 0; i < 3, j < 3; i++, j++)
            {
                Tabuleiro[3 + i][2 - j] = 3;
            }

                        //contrução do navio na DIAGONAL SUBINDO PARA A DIREITA para a exibição
            // 3 números 3 em uma linha (linha 0,1,2 colunas 7,8,9)
            for (int i = 0, j = 0; i < 3, j < 3; i++, j++)
            {
                Tabuleiro[2 - i][7 + j] = 3;
            }


                printf("|  TABULEIRO DE BATALHA NAVAL  |\n\n");

            // cabeçalho
                printf("- ");
            for (int i = 0; i < 10; i++) { // imprime o cabeçalho de letras guias do tabuleiro
                printf("%c ", Cabecalho[i]);
            }
                printf("\n");

            // imprime o tabuleiro
            for (int i = 0; i < 10; i++) { // percorre as linhas
                printf("%d ", NumeroLinha[i]); // imprime o número da linha

                for (int j = 0; j < 10; j++) { // percorre as colunas
                    printf("%d ", Tabuleiro[i][j]); // i fixa linha, j imprime cada célula da linha de i
                }

                printf("\n"); // quebra de linha
            }

return 0;
}