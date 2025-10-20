#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bancoPerguntas.h"
#include "../bibliotecas/cJSON.h"

void lerAquivoJson(char** json, char** caminhoArquivo){
    FILE* f; 
    f = fopen(*caminhoArquivo, "r");
    if(f == 0){
        printf("! Erro ao ler o Json. !\n\n");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long tamanhoJson = ftell(f);
    fseek(f,0, SEEK_SET);

    *json = malloc(tamanhoJson+1);
    if(!*json){
        printf("! Erro ao alocar memória para o JSON. !\n\n");
        fclose(f);
        exit(1);
    }

    fread(*json, sizeof(char), tamanhoJson, f);

    (*json)[tamanhoJson] = '\0';
    fclose(f);
}

void carregarBancoPerguntas(BANCO_PERGUNTAS* bancoPerguntas, char* caminhoArquivo){
    memset(bancoPerguntas, 0, sizeof(BANCO_PERGUNTAS)); // limpa o bancoPerguntas
    
    char* TextoJson;
    lerAquivoJson(&TextoJson, &caminhoArquivo);
    if(TextoJson == NULL){
        printf("! Erro ao ler o Json. !\n\n");
        exit(1);
    }
    cJSON *json = cJSON_Parse(TextoJson);
    if (!json){
        printf("Erro ao fazer parse do JSON!\n");
        free(json);
        exit(1);
    }

    cJSON* niveis = cJSON_GetObjectItem(json, "niveis");
    int qtdNiveis = cJSON_GetArraySize(niveis);
    bancoPerguntas->qtdNiveis = qtdNiveis;

    bancoPerguntas->nivel = malloc(sizeof(struct nivel) * qtdNiveis);

    for(int i = 0; i < qtdNiveis; i++){

        cJSON* nivel = cJSON_GetArrayItem(niveis, i);
        bancoPerguntas->nivel[i].nivel = cJSON_GetObjectItem(nivel, "nivel")->valueint;

        cJSON* perguntasDoNivel = cJSON_GetObjectItem(nivel, "perguntas");
        int qtdPerguntasDoNivel = cJSON_GetArraySize(perguntasDoNivel);
        bancoPerguntas->nivel[i].qtdPerguntas = qtdPerguntasDoNivel;

        bancoPerguntas->nivel[i].pergunta = malloc(sizeof(struct pergunta) * (qtdPerguntasDoNivel));

        for(int j = 0; j < qtdPerguntasDoNivel; j++){
            cJSON* pergunta = cJSON_GetArrayItem(perguntasDoNivel, j);
            char* enunciado = cJSON_GetObjectItem(pergunta, "enunciado")->valuestring;
            bancoPerguntas->nivel[i].pergunta[j].enunciado = strdup(enunciado);

            bancoPerguntas->nivel[i].pergunta[j].dica = strdup(cJSON_GetObjectItem(pergunta, "dica")->valuestring);

            cJSON* resposta = cJSON_GetObjectItem(pergunta, "resposta");
            bancoPerguntas->nivel[i].pergunta[j].resposta = resposta->valueint;

            cJSON* alternativas = cJSON_GetObjectItem(pergunta, "alternativa");
            int qtdAlternativas = cJSON_GetArraySize(alternativas);
            bancoPerguntas->nivel[i].pergunta[j].qtdAlternativas = qtdAlternativas;

            bancoPerguntas->nivel[i].pergunta[j].alternativa = malloc(sizeof(char*) * qtdAlternativas);

            for(int k = 0; k < qtdAlternativas; k++){
                cJSON* alternativa = cJSON_GetArrayItem(alternativas, k);
                bancoPerguntas->nivel[i].pergunta[j].alternativa[k] = strdup(alternativa->valuestring);
                
            }

        }



    }
    free(json);
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
