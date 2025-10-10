struct tipoPergunta {
    int nivel;
    char enunciado[150];
    char alternativas[150][150];
    int qtdAlternativas;
    int respostaCorreta;
    char dica[150];
};

struct tipoListaPerguntas{
    int nivel;
    int qtdNiveis;
    struct tipoPergunta pergunta[150];
    int qtdPerguntas;
};

struct tipoBancoPerguntas{
    struct tipoListaPerguntas perguntasNivel[150];
    int qtdNiveis;
};
// struct tipoListaPerguntas bancoPerguntas[];
// bancoPerguntas[nivel da pergunta].pergunta[numero da pergunta].enunciado;
