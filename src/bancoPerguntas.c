#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bancoPerguntas.h"
#include "cJSON.h"

void carregarBancoPerguntas(BANCO_PERGUNTAS* banco, const char* caminhoArquivo) {
    FILE* f = fopen(caminhoArquivo, "r");
    if (!f) {
        printf("Erro: não foi possível abrir o arquivo %s\n", caminhoArquivo);
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long tamanho = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* conteudo = malloc(tamanho + 1);
    fread(conteudo, 1, tamanho, f);
    conteudo[tamanho] = '\0';
    fclose(f);

    cJSON* raiz = cJSON_Parse(conteudo);
    if (!raiz) {
        printf("Erro ao interpretar o JSON.\n");
        free(conteudo);
        exit(1);
    }

    cJSON* niveis = cJSON_GetObjectItem(raiz, "niveis");
    banco->qtdNiveis = cJSON_GetArraySize(niveis);
    banco->nivel = malloc(sizeof(struct nivel) * banco->qtdNiveis);

    for (int i = 0; i < banco->qtdNiveis; i++) {
        cJSON* nivelJSON = cJSON_GetArrayItem(niveis, i);
        struct nivel* n = &banco->nivel[i];
        n->nivel = cJSON_GetObjectItem(nivelJSON, "nivel")->valueint;

        cJSON* perguntas = cJSON_GetObjectItem(nivelJSON, "perguntas");
        n->qtdPerguntas = cJSON_GetArraySize(perguntas);
        n->pergunta = malloc(sizeof(struct pergunta) * n->qtdPerguntas);

        for (int j = 0; j < n->qtdPerguntas; j++) {
            cJSON* perguntaJSON = cJSON_GetArrayItem(perguntas, j);
            struct pergunta* p = &n->pergunta[j];
            p->enunciado = strdup(cJSON_GetObjectItem(perguntaJSON, "enunciado")->valuestring);
            p->resposta = cJSON_GetObjectItem(perguntaJSON, "resposta")->valueint;
            p->dica = strdup(cJSON_GetObjectItem(perguntaJSON, "dica")->valuestring);

            cJSON* alternativas = cJSON_GetObjectItem(perguntaJSON, "alternativas");
            p->qtdAlternativas = cJSON_GetArraySize(alternativas);
            p->alternativa = malloc(sizeof(char*) * p->qtdAlternativas);

            for (int k = 0; k < p->qtdAlternativas; k++) {
                cJSON* alt = cJSON_GetArrayItem(alternativas, k);
                p->alternativa[k] = strdup(alt->valuestring);
            }
        }
    }

    cJSON_Delete(raiz);
    free(conteudo);
}

void liberarBancoPerguntas(BANCO_PERGUNTAS* banco) {
    for (int i = 0; i < banco->qtdNiveis; i++) {
        struct nivel* n = &banco->nivel[i];
        for (int j = 0; j < n->qtdPerguntas; j++) {
            struct pergunta* p = &n->pergunta[j];
            free(p->enunciado);
            free(p->dica);
            for (int k = 0; k < p->qtdAlternativas; k++) free(p->alternativa[k]);
            free(p->alternativa);
        }
        free(n->pergunta);
    }
    free(banco->nivel);
}
