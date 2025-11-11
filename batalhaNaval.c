#include <stdio.h>

#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// NÍVEL NOVATO - POSICIONANDO NAVIOS NO TABULEIRO
// Autor: Leandro Costa
// Objetivo: Representar um tabuleiro 10x10 e posicionar dois navios — um horizontal e outro vertical.

int main() {
    // === Nível Novato - Posicionamento dos Navios ===
    // O tabuleiro será uma matriz 10x10 de inteiros, onde:
    // 0 = água
    // 3 = navio

    int tabuleiro[10][10]; // Criação do tabuleiro 10x10
    int i, j;

    // Passo 1: Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Cada navio tem tamanho fixo igual a 3
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Passo 2: Definir coordenadas iniciais (dentro dos limites 0–9)
    int linha_horizontal = 2; // linha onde o navio horizontal começa
    int coluna_horizontal = 1; // coluna inicial do navio horizontal
    int linha_vertical = 5;   // linha inicial do navio vertical
    int coluna_vertical = 7;  // coluna onde o navio vertical será posicionado

    // Passo 3: Posicionar o navio horizontal
    // Verifica se cabe no tabuleiro (não ultrapassa as colunas)
    if (coluna_horizontal + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro!\n");
        return 1;
    }

    // Passo 4: Posicionar o navio vertical
    // Verifica se cabe no tabuleiro (não ultrapassa as linhas)
    if (linha_vertical + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            // Verifica se já existe um navio nessa posição (evita sobreposição)
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
                printf("Erro: sobreposição de navios detectada!\n");
                return 1;
            }
            tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro!\n");
        return 1;
    }

    // Passo 5: Exibir as coordenadas dos navios
    printf("Coordenadas do Navio Horizontal (linha %d): ", linha_horizontal);
    for (i = 0; i < 3; i++) {
        printf("(%d,%d) ", linha_horizontal, coluna_horizontal + i);
    }

    printf("\nCoordenadas do Navio Vertical (coluna %d): ", coluna_vertical);
    for (i = 0; i < 3; i++) {
        printf("(%d,%d) ", linha_vertical + i, coluna_vertical);
    }

    // Passo 6: Exibir o tabuleiro completo
    printf("\n\n=== TABULEIRO FINAL ===\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
