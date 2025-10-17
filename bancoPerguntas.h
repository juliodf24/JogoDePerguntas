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

void lerAquivoJson(char** json);
void carregarBancoPerguntas(BANCO_PERGUNTAS* bancoPerguntas);
