#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.c"


int main() {
    struct tipoPergunta *perguntaAtual;
    struct tipoListaPerguntas *bancoPerguntas;

    perguntaAtual[0].nivel = 1;
    strcpy(perguntaAtual[0].enunciado, "Qual é o país conhecido como o berço do futebol? 💂🏻");
    strcpy(perguntaAtual[0].alternativas[0], "Brasil");
    strcpy(perguntaAtual[0].alternativas[1], "Inglaterra");
    strcpy(perguntaAtual[0].alternativas[2], "Alemanha");
    strcpy(perguntaAtual[0].alternativas[3], "Espanha");
    perguntaAtual[0].respostaCorreta = 1;
    strcpy(perguntaAtual[0].dica, "O esporte surgiu no século XIX em uma ilha europeia.");

    printf("Nível %d\n", perguntaAtual[0].nivel);
    printf("%s\n", perguntaAtual[0].enunciado);
    for (int i = 0; i < 4; i++) {
        printf("%d) %s\n", i + 1, perguntaAtual[0].alternativas[i]);
    }
    printf("Dica: %s\n", perguntaAtual[0].dica);
    printf("Resposta correta: %s\n", perguntaAtual[0].alternativas[perguntaAtual[0].respostaCorreta]);

    return 0;
}
