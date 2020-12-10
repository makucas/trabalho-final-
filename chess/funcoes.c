#include "funcoes.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

void SetColor(int ForgC) {
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


void inicia(struct LISTA **l, struct LISTA **l_b) {
    *l = (struct LISTA*) malloc(sizeof(struct LISTA));
    if(*l == NULL) {
        printf("erro de alocacao\n");
        exit(1);
    }
    (*l)->next = NULL;
    (*l_b) = (*l);
}

void add(struct LISTA **l) {
    (*l)->next = (struct LISTA*) malloc(sizeof(struct LISTA));
     if((*l)->next == NULL) {
        printf("erro de alocacao\n");
        exit(1);
    }
    *l = (*l)->next;
    (*l)->next = NULL;
}

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

    system("CLS");
    for(l=0; l<9; l++) {
        for(a=0; a<3; a++){
            for(c=0; c<9; c++) {
                if(l<8 && c<8) {
                    if((l+c) % 2 == 0) {
                        SetColor(15);
                        if( (a == 1 && m[l][c] != ' ') ) {
                            printf("\xB2\xB2");
                            if(m[l][c] > 64 && m[l][c] < 91) {
                                SetColor(3);
                                printf("%c", m[l][c]);
                                SetColor(15);
                            }
                            else if(m[l][c] > 96 && m[l][c] < 123) {
                                SetColor(12);
                                printf("%c", m[l][c]);
                                SetColor(15);
                            }
                            printf("\xB2\xB2");
                        }else printf("\xB2\xB2\xB2\xB2\xB2");
                    }else {
                        SetColor(15);
                        if( (a == 1 && m[l][c] != ' ') ) {
                            printf("  ");
                            if(m[l][c] > 64 && m[l][c] < 91) {
                                SetColor(3); //azul
                                printf("%c", m[l][c]);
                                SetColor(15);
                            }
                            else if(m[l][c] > 96 && m[l][c] < 123) {
                                SetColor(12); //vermelhas
                                printf("%c", m[l][c]);
                                SetColor(15);
                            }
                            printf("  ");
                        }
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

/*int opcoes() {
    int n;
    printf("Digite um numero de acordo com a opcao escolhida\n");
    printf("1 - voltar ao jogo\n");
    scanf("%d", &n);
    return n;
}*/

int converte(int *pn, char l) {
    int i , j = 0;;

    i = 8;
    while(1) {
        if(*pn-(i) == j) {
            *pn = j;
            break;
        }
        j++;
        i=i-2;
    }
    j=0;
    for(i = 97; i<105; i++) {
        if(l == i) {
            return j;
        }
        j++;
    }
    return 0;
}

int checa_movimento(int l_i, int c_i, int l_f, int c_f, char m[8][8], int vez) {
    int ToF=0;
    char aux;
    int dL = abs(l_f - l_i);
    int dC = abs(c_f - c_i);

    if(l_i == l_f && c_i == c_f) ToF = 1;
    aux = m[l_i][c_i];
    if( (aux > 64 && aux < 91 && vez == 1) || ( (aux > 96 && aux < 123 && vez == 0) && (ToF!= 1) ) ) {

        if( (aux == 'T' || aux == 't') && (dL == 0 || dC == 0) ) return 1;
        if( (aux == 'B' || aux == 'b') && (dL == dC) ) return 1;
        if( (aux == 'C' || aux == 'c') && ( (dL == 2 && dC == 1 ) || (dL == 1 && dC == 2) ) ) return 1;
        if( (aux == 'Q' || aux == 'q') && ( (dL == dC) || (dL == 0 || dC == 0) ) ) return 1;
        if( (aux == 'K' || aux == 'k') && ( (dL >= 0 && dL <= 1) && (dC >= 0 && dC <=1) ) ) return 1;
        if( aux == 'P' ) {
            if( (m[l_f][c_f] != ' ') && (l_i - l_f == -1) && (c_i - c_f == -1 || c_i - c_f == 1) ) return 1;
            else if( (l_i == 1) && (l_i - l_f == -2) && (m[l_f][c_f] == ' ') ) return 1;
            else if( (l_i - l_f == -1) && (c_i - c_f == 0) && (m[l_f][c_f] == ' ') ) return 1;
        }
        if( aux == 'p' ) {
            if( (m[l_f][c_f] != ' ') && (l_i - l_f == 1) && (c_i - c_f == 1 || c_i - c_f == -1) ) return 1;
            else if( (l_i == 6) && (l_i - l_f == 2) && (m[l_f][c_f] == ' ') ) return 1;
            else if( (l_i - l_f == 1) && (c_i - c_f == 0) && (m[l_f][c_f] == ' ') ) return 1;
        }

    }
    return 0;
}

int move_peca(char m[8][8], struct jogador *pj, int vez, struct LISTA **l) {
    int num_i, ltr_i, num_f, ltr_f, ToF;
    int num_ia, num_fa;
    char ltr_ia, ltr_fa;
    char ltr;

    printf("Letra e Numero de origen  ");
    scanf("%*c%c%d", &ltr, &num_i);
    num_ia = num_i;
    ltr_ia = ltr;
    if((num_i < 1 || num_i > 8) || (ltr < 97 || ltr > 105)) return 0;
    ltr_i = converte(&num_i, ltr);
    printf("Letra e Numero de destino  ");
    scanf("%*c%c%d", &ltr, &num_f);
    num_fa = num_f;
    ltr_fa = ltr;
    printf("\n");
    if((num_f < 1 || num_f > 8) || (ltr < 97 || ltr > 105)) return 0;
    ltr_f = converte(&num_f, ltr);

    ToF = checa_movimento(num_i, ltr_i, num_f, ltr_f, m, vez);
    if(ToF == 1) {
        (*l)->reg.ni = num_ia;
        (*l)->reg.nf = num_fa;
        (*l)->reg.ci = ltr_ia;
        (*l)->reg.cf = ltr_fa;
        add(l);
        if( m[num_f][ltr_f] != ' ') pj[vez].capturas++;
        if(m[num_f][ltr_f] == 'k' || m[num_f][ltr_f] == 'K') {
            m[num_f][ltr_f] = m[num_i][ltr_i];
            m[num_i][ltr_i] = ' ';
            pj[vez].movimentos++;
            return 3;
        }
        m[num_f][ltr_f] = m[num_i][ltr_i];
        m[num_i][ltr_i] = ' ';
        pj[vez].movimentos++;
    } else {
        return 0;
    }
    return 1;
}

int muda_vez(int *vez, int x) {
    if(x == 0 || x == 2) return 0;
    if (*vez == 0) {
        *vez = 1;
        return 0;
    }
    if (*vez == 1) {
        *vez = 0;
        return 0;
    }
    return 0;
}

void dados_jogadores(int vez, int x, struct jogador *pj, struct LISTA **l) {
    int i=1;
    system("CLS");
    if(vez == 0) {
        printf("parabens ");
        SetColor(12);
        printf("%s ", pj[0].name);
        SetColor(7);
    }
    if(vez == 1) {
        printf("parabens ");
        SetColor(3);
        printf("%s ", pj[1].name);
        SetColor(7);
    }
    printf("voce foi o vencedor!!\n\n");
    printf("--DADOS DA PARTIDA--\n\n");
    printf("O jogador(a) ");
    SetColor(12);
    printf("%s:\n", pj[0].name);
    SetColor(7);
    printf("realizou %d movimentos.\n", pj[0].movimentos);
    printf("capturou %d pecas.\n", pj[0].capturas);
    printf("\n");
    printf("O jogador(a) ");
    SetColor(3);
    printf("%s:\n", pj[1].name);
    SetColor(7);
    printf("realizou %d movimentos.\n", pj[1].movimentos);
    printf("capturou %d pecas.\n\n", pj[1].capturas);

    SetColor(7);
    printf("--LANCES JOGADOS--\n\n");
    while((*l)->next != NULL) {
        SetColor(7);
        printf("%d. ", i);
        if(i%2 == 0) SetColor(3);
        else if(i%2 != 0) SetColor(12);
        printf("%c%d %c%d ", (*l)->reg.ci, (*l)->reg.ni, (*l)->reg.cf, (*l)->reg.nf);
        *l = (*l)->next;
        i++;
    }
    SetColor(7);
    printf("\n\n");
}


