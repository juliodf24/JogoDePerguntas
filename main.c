#include <stdio.h>
#include <string.h>
#include "lerBancoPerguntas.c"

int main() {
    struct tipoBancoPerguntas bancoPerguntas = {0};
    struct tipoPergunta perguntaAtual;
    CriarBancoQuestoes( &bancoPerguntas);

    // exemplo de uso
    printf("Total de niveis: %d \n", bancoPerguntas.qtdNiveis);
    for (int i = 0; i < bancoPerguntas.qtdNiveis; i++)
    {
        printf("Nivel: %d \n", bancoPerguntas.niveis[i].nivel);
        printf("quantidade de perguntas: %d \n", bancoPerguntas.niveis[i].qtdPerguntas);
        for (int j = 0; j < bancoPerguntas.niveis[i].qtdPerguntas; j++)
        {
            printf("pergunta: %s \n", bancoPerguntas.niveis[i].perguntas[j].enunciado);
            for (int k = 0; k < bancoPerguntas.niveis[i].perguntas[j].qtdAlternativas; k++)
            {
                printf("alternativa %d: %s \n", k, bancoPerguntas.niveis[i].perguntas[j].alternativas[k]);
            }
        }
    }

    return 0;
}
