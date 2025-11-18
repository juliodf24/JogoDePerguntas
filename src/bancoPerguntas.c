#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bancoPerguntas.h"
#include "nixJson.h"
#include "cJSON.h"
// Não altere 


void carregarBancoPerguntas(BANCO_PERGUNTAS* bancoPerguntas, char* caminhoArquivo){
    memset(bancoPerguntas, 0, sizeof(BANCO_PERGUNTAS)); // limpa o bancoPerguntas
    
    NIXJSON* arquivo = NixJson_create();
    NixJson_readJson(arquivo, caminhoArquivo);
    
    NIXJSON* json = NixJson_parseJson(arquivo);
    NixJson_free(arquivo);



    char* Char_niveis = NixJson_GetObjectItem(json, "niveis");
    int qtdNiveis = NixJson_GetArraySize(Char_niveis);
    bancoPerguntas->qtdNiveis = qtdNiveis;

    bancoPerguntas->nivel = malloc(sizeof(struct nivel) * qtdNiveis);

    for(int i = 0; i < qtdNiveis; i++){
        NIXJSON* nivel = NixJson_GetArrayItem(Char_niveis, 1);
        bancoPerguntas->nivel[i].nivel = atoi(NixJson_GetObjectItem(nivel, "nivel"));


        char* perguntasDoNivel = NixJson_GetObjectItem(nivel, "perguntas");
        int qtdPerguntasDoNivel = NixJson_GetArraySize(perguntasDoNivel);
        bancoPerguntas->nivel[i].qtdPerguntas = qtdPerguntasDoNivel;

        bancoPerguntas->nivel[i].pergunta = malloc(sizeof(struct pergunta) * (qtdPerguntasDoNivel));

        for(int j = 0; j < qtdPerguntasDoNivel; j++){
            NIXJSON* pergunta = NixJson_GetArrayItem(perguntasDoNivel, j);
            char* enunciado = NixJson_GetObjectItem(pergunta, "enunciado");
            bancoPerguntas->nivel[i].pergunta[j].enunciado = strdup(enunciado);

            bancoPerguntas->nivel[i].pergunta[j].dica = strdup(NixJson_GetObjectItem(pergunta, "dica"));

            char* resposta = NixJson_GetObjectItem(pergunta, "resposta");
            bancoPerguntas->nivel[i].pergunta[j].resposta = atoi(resposta);

            char* alternativas = NixJson_GetObjectItem(pergunta, "alternativa");
            int qtdAlternativas = NixJson_GetArraySize(alternativas);
            bancoPerguntas->nivel[i].pergunta[j].qtdAlternativas = qtdAlternativas;

            bancoPerguntas->nivel[i].pergunta[j].alternativa = malloc(sizeof(char*) * qtdAlternativas);

            for(int k = 0; k < qtdAlternativas; k++){
                NIXJSON* alternativa = NixJson_GetArrayItem(alternativas, k);
                bancoPerguntas->nivel[i].pergunta[j].alternativa[k] = strdup(alternativa->stringJson);
                
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
