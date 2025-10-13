#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/cJSON.h"
#include "bibliotecas/cJSON.c"
#include "tipos.c"

// Função para ler o conteúdo do jason e retornar uma string
char *lerArquivo(const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (!arquivo)
    {
        perror("Erro ao abrir arquivo");
        return NULL;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    char *conteudo = malloc(tamanho + 1);
    if (!conteudo)
    {
        fclose(arquivo);
        perror("Erro ao alocar memória para o conteúdo do arquivo");
        return NULL;
    }

    fread(conteudo, 1, tamanho, arquivo);
    conteudo[tamanho] = '\0';

    fclose(arquivo);
    return conteudo;
}

// Função para criar o banco de questões a partir do json
int CriarBancoQuestoes(struct tipoBancoPerguntas *bancoPerguntas)
{
    char *jsonTexto= lerArquivo("perguntasTeste.json");
    if (!jsonTexto)
    {
        printf("Erro: texto JSON nulo!\n");
        return 1;
    }

    cJSON *json = cJSON_Parse(jsonTexto);
    if (!json)
    {
        printf("Erro ao fazer parse do JSON!\n");
        return 1;
    }

    // camada 1
    cJSON *questoes = cJSON_GetObjectItem(json, "questoes");

    int quantidade = cJSON_GetArraySize(questoes);
    bancoPerguntas->qtdNiveis = quantidade;

    for (int i = 0; i < quantidade; i++)
    {
        cJSON *perguntas = cJSON_GetArrayItem(questoes, i);
        cJSON *nivel = cJSON_GetObjectItem(perguntas, "nivel");
        bancoPerguntas->niveis[nivel->valueint].nivel = nivel->valueint;

        cJSON *perguntasDoNivel = cJSON_GetObjectItem(perguntas, "perguntas");
        int quantidadePerguntasDoNivel = cJSON_GetArraySize(perguntasDoNivel);
        bancoPerguntas->niveis[i].qtdPerguntas = quantidadePerguntasDoNivel;

        for (int j = 0; j < quantidadePerguntasDoNivel; j++)
        {
            cJSON *perguntaNivel = cJSON_GetArrayItem(perguntasDoNivel, j);
            cJSON *enunciado = cJSON_GetObjectItem(perguntaNivel, "enunciado");
            cJSON *dica = cJSON_GetObjectItem(perguntaNivel, "dica");
            strcpy(bancoPerguntas->niveis[i].perguntas[j].enunciado, enunciado->valuestring);
            strcpy(bancoPerguntas->niveis[i].perguntas[j].dica, dica->valuestring);
            cJSON *alternativas = cJSON_GetObjectItem(perguntaNivel, "alternativas");
            int quantidadeAlternativas = cJSON_GetArraySize(alternativas);
            bancoPerguntas->niveis[i].perguntas[j].qtdAlternativas = quantidadeAlternativas;
            for (int k = 0; k < quantidadeAlternativas; k++)
            {
                cJSON *alternativa = cJSON_GetArrayItem(alternativas, k);
                strcpy(bancoPerguntas->niveis[i].perguntas[j].alternativas[k], alternativa->valuestring);
            }
        }
    }
    cJSON_Delete(json);
    return 0;
}


