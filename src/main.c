#include <stdio.h>
#include <string.h>
#include "bancoPerguntas.h"

BANCO_PERGUNTAS bancoPerguntas;

int main() {
    carregarBancoPerguntas(&bancoPerguntas);

    for(int i = 0; i< bancoPerguntas.qtdNiveis; i++){
        printf(" %s\n\n", bancoPerguntas.nivel[i].pergunta[0].enunciado);
    }
    return 0;
}
