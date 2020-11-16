#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


int main() {
    int n, l, c;
    struct borda b;
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

    while(1) {
        printa_tabuleiro(tab, &b);
        n = opcoes();
        if(n == 2) break;
        else if(n == 1) {
            move_peca(tab);
        }
    }

    return 0;
}
