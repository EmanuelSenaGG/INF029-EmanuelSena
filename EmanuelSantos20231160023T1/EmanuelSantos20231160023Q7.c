#include <stdio.h>

void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("  A B C\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf(" --+-+--\n");
    }
}

int verificarVitoria(char tabuleiro[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) return 1; // Linhas
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) return 1; // Colunas
    }
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) return 1; // Diagonal principal
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) return 1; // Diagonal secundária
    return 0;
}

int verificarEmpate(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0; // Ainda há espaços em branco, o jogo não está empatado
            }
        }
    }
    return 1; // Todos os espaços estão preenchidos, o jogo está empatado
}

int main() {
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int jogador = 1;
    int linha, coluna;
    char jogada[3];

    printf("Bem-vindo ao Jogo da Velha!\n");

    while (1) {
        imprimirTabuleiro(tabuleiro);
        printf("\nJogador %d, faça a sua jogada (exemplo: B3): ", jogador);
        scanf("%s", jogada);

        coluna = jogada[0] - 'A';
        linha = jogada[1] - '1';

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
            if (jogador == 1) {
                tabuleiro[linha][coluna] = 'X';
                if (verificarVitoria(tabuleiro, 'X')) {
                    imprimirTabuleiro(tabuleiro);
                    printf("Jogador 1 venceu! Parabéns!\n");
                    break;
                }
                jogador = 2;
            } else {
                tabuleiro[linha][coluna] = 'O';
                if (verificarVitoria(tabuleiro, 'O')) {
                    imprimirTabuleiro(tabuleiro);
                    printf("Jogador 2 venceu! Parabéns!\n");
                    break;
                }
                jogador = 1;
            }

            if (verificarEmpate(tabuleiro)) {
                imprimirTabuleiro(tabuleiro);
                printf("O jogo empatou!\n");
                break;
            }
        } else {
            printf("Jogada inválida. Tente novamente.\n");
        }
    }

    return 0;
}
