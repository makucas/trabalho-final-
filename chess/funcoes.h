#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

struct borda{
    int num[8];
    char ltr[8];
};

struct jogador{
    char name[20];
    int movimentos;
    int capturas;
};

void dados_jogadores(int vez, int x, struct jogador *pj);
int muda_vez(int *vez, int x);
void SetColor(int ForgC);
void estrutura_borda(struct borda *pb);
void printa_tabuleiro(char m[8][8], struct borda *pb);
int move_peca(char m[8][8], struct jogador *pj, int vez);
//int opcoes();
int converte(int *pn, char l);
int checa_movimento(int l_i, int c_i, int l_f, int c_f, char m[8][8], int vez);


#endif // FUNCOES_H_INCLUDED

