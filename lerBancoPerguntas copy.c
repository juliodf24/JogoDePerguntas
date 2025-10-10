#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/cJSON.h"
#include "bibliotecas/cJSON.c"

char *lerArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (!arquivo) return NULL;

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    char *conteudo = malloc(tamanho + 1);
    fread(conteudo, 1, tamanho, arquivo);
    conteudo[tamanho] = '\0';

    fclose(arquivo);
    return conteudo;
}

int main() {
    char *jsonTexto = lerArquivo("perguntasTeste.json");
    if (!jsonTexto) {
        printf("Erro ao abrir o JSON!\n");
        return 1;
    }

    cJSON *json = cJSON_Parse(jsonTexto);
    if (!json) {
        printf("Erro ao fazer parse do JSON\n");
        free(jsonTexto);
        return 1;
    }

    cJSON *perguntas = cJSON_GetObjectItem(json, "perguntas");
    int quantidade = cJSON_GetArraySize(perguntas);

    for (int i = 0; i < quantidade; i++) {
        cJSON *pergunta = cJSON_GetArrayItem(perguntas, i);
        printf("Pergunta %d: %d\n", i + 1, cJSON_GetObjectItem(pergunta, "nivel")->valueint);
    }

    cJSON_Delete(json);
    free(jsonTexto);
    return 0;
}