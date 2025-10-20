#ifndef UI_H
#define UI_H

#include "bancoPerguntas.h"

void imprimirBola();
int imprimirNomeJogo();
void limparTela();
void imprimirPergunta(struct pergunta* p, int nivel, int vidas);
void imprimirDica(const char* dica);
void imprimirAcerto();
void imprimirErro();
void imprimirVitoria();
void imprimirDerrota();
void mostrarMenu();
void mostrarEstado(int nivelAtual, int totalNiveis, int vidas, int disponivelDica, int disponivelTroca, int disponivelPular);

#endif