#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

struct borda{
    int num[8];
    char ltr[8];
};

void estrutura_borda(struct borda *pb);
void printa_tabuleiro(char m[8][8], struct borda *pb);
void move_peca(char m[8][8]);
int opcoes();
int converte(int *pn, char l);

#endif // FUNCOES_H_INCLUDED
