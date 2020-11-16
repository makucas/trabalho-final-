#include "funcoes.h"
#include <stdio.h>

void estrutura_borda(struct borda *pb) {
    int i;
    char c=97;
    for(i=0; i<8; i++) {
        pb->num[i] = i+1;
    }
    for(i=0; i<8; i++) {
        pb->ltr[i] = c;
        c++;
    }
}



void printa_tabuleiro(char m[8][8], struct borda *pb) {
    int l, c, a, i=7, j=0;

    for(l=0; l<9; l++) {
        for(a=0; a<3; a++){
            for(c=0; c<9; c++) {
                if(l<8 && c<8) {
                     if((l+c) % 2 == 0) {
                        if( (a == 1 && m[l][c] != ' ') || (a == 1 && m[l][c] != ' ') ) printf("\xB2\xB2\%c\xB2\xB2", m[l][c]);
                        else printf("\xB2\xB2\xB2\xB2\xB2");
                    }else {
                        if( (a == 1 && m[l][c] != ' ') || (a == 1 && m[l][c] != ' ') ) printf("  %c  ", m[l][c]);
                        else printf("     ");
                    }
                }
                else if(c == 8 && a == 1) {
                    if (l != 8)printf("  %d  ", pb->num[i]);
                    i--;
                }
                else if(l == 8 && a == 1){
                    printf("  %c  ", pb->ltr[j]);
                    j++;
                }
            }
            printf("\n");
        }
    }

}

int opcoes() {
    int n;
    printf("Digite um numero de acordo com a opcao escolhida\n");
    printf("1 - mover peca\n");
    printf("2 - sair do jogo\n");
    scanf("%d", &n);
    return n;
}

int converte(int *pn, char *pl) {

}

void move_peca(char m[8][8]) {
    int num;
    char ltr;
    printf("Numero e Letra aonde a peca se encontra\n");
    scanf("%d%c", &num, &ltr);
    converte(&num, &ltr);



}

