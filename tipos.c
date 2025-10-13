struct tipoPergunta {
    int nivel;
    char enunciado[150];
    char alternativas[10][150]; 
    int qtdAlternativas;
    int respostaCorreta;
    char dica[150];
};

struct tipoListaPerguntas {
    int nivel;
    struct tipoPergunta perguntas[150]; 
    int qtdPerguntas;
};

struct tipoBancoPerguntas {
    struct tipoListaPerguntas niveis[10]; 
    int qtdNiveis;
};


// bancoPerguntas.niveis[indiceNivel].perguntas[indicePergunta].enunciado os niveis começa com o 0 exemplo: nivel 0, 1, 2,3...
