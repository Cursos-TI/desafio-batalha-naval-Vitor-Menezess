#include <stdio.h>

                int main() {
                    // Matrizes para as guias visuais do tabuleiro no terminal
                    // letras no topo e números na lateral
                    char Cabecalho[10] = {'A','B','C','D','E','F','G','H','I','J'};
                    int NumeroLinha[10] = {1,2,3,4,5,6,7,8,9,10};

                    // Tabuleiro principal do jogo de tamanho 10x10
                    int Tabuleiro[10][10] = {0}; 


    
                //  CONSTRUÇÃO DOS NAVIOS 
                // ========================

            // Construção do navio linha horizontal para a exibição
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i == 4) {
                        if (j > 3) {
                            if (j < 7) {
                                Tabuleiro[i][j] = 3;
                            }
                        }
                    }
                }
            }

            // Construção do navio linha vertical para a exibição
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (j == 2) {
                        if (i > 2) {
                            if (i < 6) {
                                Tabuleiro[i][j] = 3;
                            }
                        }
                    }
                }
            }

            // Construção do navio na diagonal da direita para a esquerda para a exibição
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i + j == 15) {
                        if (i >= 7) {
                            if (i <= 9) {
                                Tabuleiro[i][j] = 3;
                            }
                        }
                    }                    
                }
            }

            // Construção do navio Descendo na diagonal da esquerda para a direita para a exibição 
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (j - i == 4) { 
                        if (i >= 0) {
                            if(i <= 2) {
                                Tabuleiro[i][j] = 3;
                            }
                        }
                    }
                }
            }


    
                    // DECLARAÇÃO DOS ARRAYS DE HABILIDADE (Submatrizes fixas de tamanho 5x5)
                    // Onde tiver 1 representa a área atingida pelo poder. Onde tiver 0 é ignorado
                    // =============================================================================
                    
                    //Cone: Desenho de uma pirâmide que começa estreita no topo central e se espalha para baixo
                    int Cone[5][5] = {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 0}
                    };

                    //Cruz: Uma linha central cheia na horizontal cruzando com uma coluna na vertical (5x3)
                    int Cruz[5][5] = {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {1, 1, 1, 1, 1},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    };

                    // Octaedro: Formato geométrico compacto de um "+" de tamanho 3x3 posicionado no centro da submatriz
                    int Octaedro[5][5] = {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 1, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    };


    
                //  SOBREPOSIÇÃO DAS HABILIDADES UTILIZANDO REPETIÇÕES ANINHADAS E CONDICIONAIS
                // O codigo calcula o deslocamento em relação ao centro (indice 2) da submatriz
                // O if de validação impede que o programa tente gavar fora dos limites (0 a 9)
                // ==========================================
                
                // Variáveis para guardar as posições de origem (centralizadas no tabuleiro)
                int LinhaAlvo, ColunaAlvo;

                // ### Inserindo o CONE ###
                LinhaAlvo = 7; // O jogador escolheu mirar na Linha 7
                ColunaAlvo = 2; // O jogador escolheu mirar na Coluna 2
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (Cone[i][j] == 1) {
                            int LinhaFinal = LinhaAlvo + (i - 2); // Calcula a linha correspondente no tabuleiro 10x10
                            int ColunaFinal = ColunaAlvo + (j - 2); // Calcula a coluna correspondente no tabuleiro 10x10
                            // Essa validação garante que a coordenada calculada existe no tabuleiro principal
                            if (LinhaFinal >= 0 && LinhaFinal < 10 && ColunaFinal >= 0 && ColunaFinal < 10) {
                                Tabuleiro[LinhaFinal][ColunaFinal] = 5; //o efeito do poder será o numero 5
                            }
                        }
                    }
                }

                // ### Inserindo a CRUZ ###
                LinhaAlvo = 2; // O jogador escolheu mirar na Linha 2
                ColunaAlvo = 3; // O jogador escolheu mirar na Coluna 3
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (Cruz[i][j] == 1) {
                            int LinhaFinal = LinhaAlvo + (i - 2);
                            int ColunaFinal = ColunaAlvo + (j - 2);
                            if (LinhaFinal >= 0 && LinhaFinal < 10 && ColunaFinal >= 0 && ColunaFinal < 10) {
                                Tabuleiro[LinhaFinal][ColunaFinal] = 5;
                            }
                        }
                    }
                }

                // ### Inserindo o OCTAEDRO ###
                LinhaAlvo = 5; // O jogador escolheu mirar na Linha 5
                ColunaAlvo = 7; // O jogador escolheu mirar na Coluna 7
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (Octaedro[i][j] == 1) {
                            int LinhaFinal = LinhaAlvo + (i - 2);
                            int ColunaFinal = ColunaAlvo + (j - 2);
                            if (LinhaFinal >= 0 && LinhaFinal < 10 && ColunaFinal >= 0 && ColunaFinal < 10) {
                                Tabuleiro[LinhaFinal][ColunaFinal] = 5;
                            }
                        }
                    }
                }


    
                    // ### EXIBIÇÃO DO TABULEIRO NO TERMINAL ###
                    // ==========================================
                    printf("|  TABULEIRO DE BATALHA NAVAL  |\n\n");

                    // Cabeçalho de letras guias DE A até J
                    printf("   "); // Espaçamento inicial para alinhar perfeitamente com os números laterais
                    for (int i = 0; i < 10; i++) {
                        printf("%c ", Cabecalho[i]);
                    }
                    printf("\n");

                    // Imprime as linhas numeradas e os elementos do Tabuleiro
                    for (int i = 0; i < 10; i++) {
                        if (NumeroLinha[i] < 10) {
                            printf("%d  ", NumeroLinha[i]);
                        } else {
                            printf("%d ", NumeroLinha[i]);
                        }

                        for (int j = 0; j < 10; j++) {
                            printf("%d ", Tabuleiro[i][j]);  // Exibe o valor da célula (0 para água, 3 para navio, 5 para poder)
                        }
                        printf("\n"); // Salta para a próxima linha após imprimir as 10 colunas
                    }

return 0;
}
