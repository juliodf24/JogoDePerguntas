#include <stdio.h>
#include "tipos.c"


int main() {
    struct tipoPergunta pergunta;

    pergunta.nivel = 1;
    strcpy(pergunta.enunciado, "Qual é o país conhecido como o berço do futebol? 💂🏻");
    strcpy(pergunta.alternativas[0], "Brasil");
    strcpy(pergunta.alternativas[1], "Inglaterra");
    strcpy(pergunta.alternativas[2], "Alemanha");
    strcpy(pergunta.alternativas[3], "Espanha");
    pergunta.respostaCorreta = 1;
    strcpy(pergunta.dica, "O esporte surgiu no século XIX em uma ilha europeia.");

    printf("Nível %d\n", pergunta.nivel);
    printf("%s\n", pergunta.enunciado);
    for (int i = 0; i < 4; i++) {
        printf("%d) %s\n", i + 1, pergunta.alternativas[i]);
    }
    printf("Dica: %s\n", pergunta.dica);
    printf("Resposta correta: %s\n", pergunta.alternativas[pergunta.respostaCorreta]);

    return 0;
}
