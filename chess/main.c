#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "funcoes.h"

int main() {
    int x=-1;
    int vez=0;
    struct borda b;
    struct jogador j[2];
    char tab[8][8] = {
        { 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T', },
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', },
        { 't', 'c', 'b', 'q', 'k', 'b', 'c', 't', }
    };


    estrutura_borda(&b);
    j[0].movimentos = 0;
    j[0].capturas = 0;
    j[1].movimentos = 0;
    j[1].capturas = 0;

    printf("Nome do jogador que utilizara as pecas ");
    SetColor(12);
    printf("VERMELHAS   ");
    SetColor(7);
    scanf("%s", j[0].name);
    printf("Nome do jogador que utilizara as pecas ");
    SetColor(3);
    printf("AZUIS       ");
    SetColor(7);
    scanf("%*c%s", j[1].name);
    printf("Pecas");
    SetColor(12);
    printf(" VERMELHAS ");
    SetColor(7);
    printf("movem primeiro!\nPressione qualquer tecla para continuar  \n");
    getch();

    while(1) {
        printa_tabuleiro(tab, &b);
        if(x == 3) {
            muda_vez(&vez, x);
            printf("\nO Rei foi capturado, temos um vencedor\nqualquer tecla para acessar os dados da partida...\n");
            getch();
            dados_jogadores(vez, x, j);
            break;
        }
        printf("jogam as ");
        if(vez == 0) {
            SetColor(12);
            printf("VERMELHAS ");
            SetColor(7);
        }
        if(vez == 1) {
            SetColor(3);
            printf("AZUIS ");
            SetColor(7);
        }
        printf("(%s)\n", j[vez].name);
        x = move_peca(tab, j, vez);
        if(x == 0) {
            printf("movimento invalido, pressione alguma tecla para continuar\n");
            getch();
        }
        muda_vez(&vez, x); //recebe um int que indentifica a vez, e um outro int que indentifica se o movimento anterior foi valido
    }


    return 0;
}

