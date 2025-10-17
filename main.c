#include <stdio.h>
#include <string.h>
#include "bancoPerguntas.h"

int main() {
    BANCO_PERGUNTAS bancoPerguntas;
    carregarBancoPerguntas(&bancoPerguntas);

    for(int i = 0; i< bancoPerguntas.qtdNiveis; i++){
        printf(" %s\n\n", bancoPerguntas.nivel[i].pergunta[0].enunciado);
    }
    return 0;
}
