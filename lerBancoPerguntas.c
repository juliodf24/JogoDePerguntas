#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/cJSON.h"
#include "bibliotecas/cJSON.c"
#include "tipos.c"

char *lerArquivo(const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (!arquivo)
        return NULL;

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    char *conteudo = malloc(tamanho + 1);
    fread(conteudo, 1, tamanho, arquivo);
    conteudo[tamanho] = '\0';

    fclose(arquivo);
    return conteudo;
}
int preencherBancoPerguntas(struct tipoBancoPerguntas *bancoPerguntas, char *conteudo)
{
    if (!conteudo)
    {
        printf("Erro ao ler o Json!\n");
        return 1;
    }
    cJSON *json = cJSON_Parse(conteudo);
    if (!json)
    {
        printf("Erro ao fazer parse do JSON\n");
        free(conteudo);
        return 1;
    }
    // primeiro nivel
    printf("gravando na variavelan");
    cJSON *questoes = cJSON_GetObjectItem(json, "questoes");
    if (!questoes)
    {
        printf("Erro: campo 'questoes' não encontrado no JSON\\n");
        cJSON_Delete(json);
        free(conteudo);
        return 1;
    }
    int quantidadeNiveis = cJSON_GetArraySize(questoes);
    bancoPerguntas->qtdNiveis = quantidadeNiveis;

    for (int i = 0; i < quantidadeNiveis; i++)
    {
        // segundo nivel
        cJSON *perguntasDeUmNivel = cJSON_GetArrayItem(questoes, i);
        bancoPerguntas->perguntasNivel[i].nivel = cJSON_GetObjectItem(perguntasDeUmNivel, "nivel")->valueint;
        cJSON *perguntas = cJSON_GetObjectItem(perguntasDeUmNivel, "perguntas");
        int quantidadePerguntas = cJSON_GetArraySize(perguntas);
        bancoPerguntas->perguntasNivel[i].qtdPerguntas = quantidadePerguntas;
        for (int j = 0; j < quantidadePerguntas; j++)
        {
            // terceiro nivel
            cJSON *pergunta = cJSON_GetArrayItem(perguntas, j);
            bancoPerguntas->perguntasNivel[i].pergunta[j].nivel = bancoPerguntas->perguntasNivel[i].nivel;
            strcpy(bancoPerguntas->perguntasNivel[i].pergunta[j].enunciado, cJSON_GetObjectItem(pergunta, "enunciado")->valuestring);

            cJSON *alternativas = cJSON_GetObjectItem(pergunta, "alternativas");
            int qtdAlternativas = cJSON_GetArraySize(alternativas);
            bancoPerguntas->perguntasNivel[i].pergunta[j].qtdAlternativas = qtdAlternativas;
            for (int k = 0; k < qtdAlternativas; k++)
            {
                // quarto nivel
                cJSON *alternativa = cJSON_GetArrayItem(alternativas, k);
                strcpy(bancoPerguntas->perguntasNivel[i].pergunta[j].alternativas[k], alternativa->valuestring);
            }

            strcpy(bancoPerguntas->perguntasNivel[i].pergunta[j].dica, cJSON_GetObjectItem(pergunta, "dica")->valuestring);
            bancoPerguntas->perguntasNivel[i].pergunta[j].respostaCorreta = cJSON_GetObjectItem(pergunta, "resposta_correta")->valueint;
        }
    }
    cJSON_Delete(json);
    free(conteudo);
    return 0;
}

int main()
{
    struct tipoBancoPerguntas bancoPerguntas;
    char *conteudo = lerArquivo("perguntasTeste.json");
    preencherBancoPerguntas(&bancoPerguntas, conteudo);
    printf("Total de níveis: %s\n", conteudo);

    for (int i = 0; i < bancoPerguntas.qtdNiveis; i++)
    {
        printf("Nível %d\n", bancoPerguntas.perguntasNivel[i].nivel);
        for (int j = 0; j < bancoPerguntas.perguntasNivel[i].qtdPerguntas; j++)
        {
            printf("%s\n", bancoPerguntas.perguntasNivel[i].pergunta[j].enunciado);
            for (int k = 0; k < bancoPerguntas.perguntasNivel[i].pergunta[j].qtdAlternativas; k++)
            {
                printf("%d) %s\n", k + 1, bancoPerguntas.perguntasNivel[i].pergunta[j].alternativas[k]);
            }
            printf("Dica: %s\n", bancoPerguntas.perguntasNivel[i].pergunta[j].dica);
            printf("Resposta correta: %s\n", bancoPerguntas.perguntasNivel[i].pergunta[j].alternativas[bancoPerguntas.perguntasNivel[i].pergunta[j].respostaCorreta]);
        }
    }

    return 0;
}