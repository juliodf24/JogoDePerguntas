struct tipoPergunta {
    int nivel;
    char *enunciado;
    char **alternativas;
    int qtdAlternativas;
    int respostaCorreta;
    char *dica;
};

struct tipoListaPerguntas{
    int nivel;
    struct tipoPergunta *pergunta;
    int qtdPerguntas;
};

// struct tipoListaPerguntas bancoPerguntas[]
// bancoPerguntas[nivel da pergunta].pergunta[numero da perguta].enunciado
