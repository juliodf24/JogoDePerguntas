#ifndef MAIN_H
#define MAIN_H

typedef struct {
    int nVida;
    int nNivel;
    int nPergunta;
    char** habilidades;
} JOGADOR;

void jogar();
void limparEntrada();
int alternativaInvalida(int escolha, int qtdAlternativas);

#endif