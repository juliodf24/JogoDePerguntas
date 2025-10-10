#include <stdio.h>
#include <string.h>
#include "tipos.c"

int main() {
    struct tipoPergunta perguntaAtual;

    perguntaAtual.nivel = 1;
    strcpy(perguntaAtual.enunciado, "Qual é o país conhecido como o berço do futebol? 💂🏻");
    strcpy(perguntaAtual.alternativas[0], "Brasil");
    strcpy(perguntaAtual.alternativas[1], "Inglaterra");
    strcpy(perguntaAtual.alternativas[2], "Alemanha");
    strcpy(perguntaAtual.alternativas[3], "Espanha");
    perguntaAtual.qtdAlternativas = 4;
    perguntaAtual.respostaCorreta = 1;
    strcpy(perguntaAtual.dica, "O esporte surgiu no século XIX em uma ilha europeia.");

    printf("Nível %d\n", perguntaAtual.nivel);
    printf("%s\n", perguntaAtual.enunciado);
    for (int i = 0; i < perguntaAtual.qtdAlternativas; i++) {
        printf("%d) %s\n", i + 1, perguntaAtual.alternativas[i]);
    }
    printf("Dica: %s\n", perguntaAtual.dica);
    printf("Resposta correta: %s\n", perguntaAtual.alternativas[perguntaAtual.respostaCorreta]);

    return 0;
}
