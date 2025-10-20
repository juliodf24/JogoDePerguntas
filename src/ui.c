#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "bancoPerguntas.h"

// === Cores ANSI ===
#define RESET     "\033[0m"
#define NEGRITO   "\033[1m"
#define AZUL      "\033[1;34m"
#define VERDE     "\033[1;32m"
#define VERMELHO  "\033[1;31m"
#define AMARELO   "\033[1;33m"
#define BRANCO    "\033[1;37m"

void imprimirBola() {
    printf("\033[1;32m");
    printf("                                   _,aaadP\"\"\"\"\"\"Ybaaaa,,_\n");
    printf("                                ,adP,__,,,aaaadP\"\"\"\"\"Y888888a,_\n");
    printf("                             ,a8888888P''             \"Y8888888b,\n");
    printf("                          _a888888888\"                   `Y88888888b,\n");
    printf("                        ,d888888888P'                       \"888888888b,\n");
    printf("                      ,88888888P\"Y8,                       ,P'   `\"\"Y888b,\n");
    printf("                    ,d8888P\"'     \"Ya,                    ,P'         `Ya`b,\n");
    printf("                   ,P88\"'           `Ya,                 ,P'            `b`Yi\n");
    printf("                  d\",P                `\"Y,              ,P'              `Y \"i\n");
    printf("                ,P' P'                   \"888888888888888b                `b \"i\n");
    printf("               ,P' d'                    d8888888888888888b                `b `b\n");
    printf("               d' d'                    ,888888888888888888b                I, Y,\n");
    printf("              ,f ,f                    ,88888888888888888888b               `b, b\n");
    printf("              d' d'                    d888888888888888888888b              ,88,I\n");
    printf("\033[1;33m");
    printf("             ,P  8                    ,88888888888888888888888b,_          ,d8888\n");
    printf("             d'  8,                   d8888888888888888888888P'`\"Ya,_     ,d88888\n");
    printf("             8  d88b,             ,adP\"\"Y888888888888888888P'      `\"\"Ya, d88888P\n");
    printf("             8 ,88888b,       ,adP\"'     `\"Y8888888888888\"'             `\"888888I\n");
    printf("             Y,88888888b, ,adP\"'             \"\"Y888888P\"                  888888'\n");
    printf("             `888888888888P'                     \"\"YP\"                    888888\n");
    printf("              I88888888888                          8                     88888I\n");
    printf("              `Y8888888888                          8                     88888'\n");
    printf("               `Y888888888                          8                     8888I\n");
    printf("                `Y88888888                          8                     8P\"8'\n");
    printf("\033[1;34m");
    printf("                 `Y8888888,                         8                   ,d',d'\n");
    printf("                  `b\"\"\"\"Y8b                         8                 ,d\" ,d'\n");
    printf("                    \"b,   \"Y,                       8               ,P\" ,d\"\n");
    printf("                      \"b,   \"Ya,_                 ,d88ba,,___   _,aP\" ,P\"\n");
    printf("                        \"Ya_   \"\"Ya,_       _,,ad88888888888888P\"' _,d\"\n");
    printf("                          `\"Ya_    \"\"Yaaad88888888888888888888P _,d\"'\n");
    printf("                              `\"Ya,_     \"Y888888888888888888P\",d\"'\n");
    printf("                                 `\"\"Ya,__`Y888888888888888P\"\"\"\n");
    printf("                                      ``\"\"\"\"\"\"\"\"\"\"\"\"\"''\n");
    printf("\033[0m\n\n");
}

int imprimirNomeJogo() {
    char simounao;
    printf("%s       _                           _                                              %s\n", BRANCO, RESET);
    printf("%s      | |                         (_)                                             %s\n", BRANCO, RESET);
    printf("%s   ___| |__   __ _ _ __ ___  _ __  _  ___  _ __  ___    __ _  __ _ _ __ ___   ___ %s\n", BRANCO, RESET);
    printf("%s  / __| '_ \\ / _` | '_ ` _ \\| '_ \\| |/ _ \\| '_ \\/ __|  / _` |/ _` | '_ ` _ \\ / _ \\%s\n", BRANCO, RESET);
    printf("%s | (__| | | | (_| | | | | | | |_) | | (_) | | | \\__ \\ | (_| | (_| | | | | | |  __/%s\n", BRANCO, RESET);
    printf("%s  \\___|_| |_|\\__,_|_| |_| |_| .__/|_|\\___/|_| |_|___/  \\__, |\\__,_|_| |_| |_|\\___|%s\n", BRANCO, RESET);
    printf("%s                            | |                         __/ |                     %s\n", BRANCO, RESET);
    printf("%s                            |_|                        |___/                      %s\n", BRANCO, RESET);
    printf("%s⚽🏆 Bem-vindo ao Champions Game — o quiz de futebol definitivo! ⚽🏆%s\n", AMARELO, RESET);
    printf("\nVocê tem %s1 vida%s. Uma resposta errada e o jogo acaba!\n", VERMELHO, RESET);
    printf("Use sabiamente suas ações especiais (Dica, Troca e Pular — %suma vez cada%s).\n\n", AMARELO, RESET);
    printf("Está pronto para começar sua jornada rumo ao título de campeão? (s/n): ");

    if (scanf(" %c", &simounao) != 1) return 0;
    while (getchar() != '\n');
    return (simounao == 's' || simounao == 'S');
}

void limparTela() {
    if (system("clear") != 0) {
        // Se falhar, tenta o comando do Windows
        system("cls");
    }
}

void imprimirPergunta(struct pergunta* p, int nivel, int vidas) {
    limparTela();
    printf("%s=============================================%s\n", AZUL, RESET);
    printf("%s⚽ NÍVEL %d ⚽%s\n", NEGRITO, nivel, RESET);
    printf("%s=============================================%s\n", AZUL, RESET);
    printf("\n%s%s%s\n\n", NEGRITO, p->enunciado, RESET);

    for (int i = 0; i < p->qtdAlternativas; i++) {
        printf("[%d] %s\n", i + 1, p->alternativa[i]);
    }

    printf("---------------------------------------------\n");
    printf("❤️ Vidas: %d\n", vidas);
    printf("Escolha: (1) Responder  (2) Ações especiais  (3) Estado  (4) Repetir  (0) Sair\n");
}

void imprimirDica(const char* dica) {
    printf("\n%s💡 DICA:%s %s\n", AMARELO, RESET, dica);
}

void imprimirAcerto() {
    printf("\n%s✅ Resposta certa! Avançando para o próximo nível! ⚽%s\n", VERDE, RESET);
    printf("Pressione ENTER para continuar...\n");
    getchar();
}

void imprimirErro() {
    printf("\n%s❌ Resposta errada! Você perdeu uma vida!%s\n", VERMELHO, RESET);
    printf("Pressione ENTER para continuar...\n");
    getchar();
}

void imprimirVitoria() {
    limparTela();
    printf("\n%s🏆 PARABÉNS! VOCÊ É O CAMPEÃO DO CHAMPIONS GAME! 🏆%s\n", AMARELO, RESET);
    printf("%sVocê respondeu todas as perguntas corretamente!%s\n\n", VERDE, RESET);
}

void imprimirDerrota() {
    limparTela();
    printf("\n%s💀 FIM DE JOGO! Suas vidas acabaram.%s\n", VERMELHO, RESET);
    printf("%sTente novamente e mostre que é um verdadeiro campeão!%s\n", AMARELO, RESET);
}

void mostrarMenu() {
    printf("\n%s--------- MENU ---------%s\n", AZUL, RESET);
    printf("1 - Responder pergunta\n");
    printf("2 - Usar ação especial\n");
    printf("3 - Mostrar estado do jogo\n");
    printf("4 - Exibir pergunta novamente\n");
    printf("0 - Sair\n");
    printf("-------------------------\n");
    printf("Escolha: ");
}

void mostrarEstado(int nivelAtual, int totalNiveis, int vidas, int disponivelDica, int disponivelTroca, int disponivelPular) {
    printf("\n%s=== ESTADO DO JOGO ===%s\n", BRANCO, RESET);
    printf("Nível atual: %d/%d\n", nivelAtual, totalNiveis);
    printf("Vidas: %d\n", vidas);
    printf("Dica disponível: %s\n", disponivelDica ? "✅" : "❌");
    printf("Troca disponível: %s\n", disponivelTroca ? "✅" : "❌");
    printf("Pular disponível: %s\n", disponivelPular ? "✅" : "❌");
    printf("=======================\n");
}