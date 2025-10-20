#ifndef BANCO_PERGUNTAS_H
#define BANCO_PERGUNTAS_H
// não altere
struct pergunta{
    char* enunciado;
    int qtdAlternativas;
    char** alternativa;
    int resposta;
    char* dica;
};

struct nivel{
    int nivel;
    int qtdPerguntas;
    struct pergunta* pergunta;
};

struct bancoPerguntas{
    int qtdNiveis;
    struct nivel* nivel;
};

typedef struct bancoPerguntas BANCO_PERGUNTAS;

void lerAquivoJson(char** json, char** caminhoArquivo);
void carregarBancoPerguntas(BANCO_PERGUNTAS* bancoPerguntas,  char* caminhoArquivo);
void liberarBancoPerguntas(BANCO_PERGUNTAS* banco);

#endif