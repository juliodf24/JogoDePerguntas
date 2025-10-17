#include <stdio.h>
#include <string.h>
#include "bancoPerguntas.h"
#include "main.h"
#include "ui.h"

BANCO_PERGUNTAS bancoPerguntas;
JOGADOR jogador;

int main() {
    carregarBancoPerguntas(&bancoPerguntas);

    imprimirBola();
    imprimirNomeJogo();

    for(int i = 0; i< bancoPerguntas.qtdNiveis; i++){
        printf(" %s\n\n", bancoPerguntas.nivel[i].pergunta[0].enunciado);
    }
    return 0;
}
