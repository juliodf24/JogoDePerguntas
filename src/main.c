#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bancoPerguntas.h"
#include "main.h"
#include "ui.h"

BANCO_PERGUNTAS bancoPerguntas;
JOGADOR jogador;

int main() {
    srand((unsigned) time(NULL));

    carregarBancoPerguntas(&bancoPerguntas, "assets/perguntasTeste.json");

    
    imprimirBola();
    if (!imprimirNomeJogo()) {
        liberarBancoPerguntas(&bancoPerguntas);
        return 0;
    }

    // Inicializar jogador
    jogador.nVida = 1;  // Apenas 1 vida conforme regras
    jogador.nNivel = 0;
    jogador.nPergunta = 0;

    jogar();

    liberarBancoPerguntas(&bancoPerguntas);
    return 0;
}

void limparEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int alternativaInvalida(int escolha, int qtdAlternativas){ 
    if(escolha < 0 || escolha > qtdAlternativas){
        return 1;
    } else {
        return 0;
    }
}

void jogar() {
    int disponivelDica = 1, disponivelTroca = 1, disponivelPular = 1;
    int totalNiveis = bancoPerguntas.qtdNiveis;
    int sair = 0;

    while (jogador.nNivel < totalNiveis && jogador.nVida > 0 && !sair) {
        struct nivel* nivelAtual = &bancoPerguntas.nivel[jogador.nNivel];
        int idxPergunta = rand() % nivelAtual->qtdPerguntas;
        jogador.nPergunta = idxPergunta;
        struct pergunta* p = &nivelAtual->pergunta[idxPergunta];

        while (1) {
            imprimirPergunta(p, nivelAtual->nivel, jogador.nVida);
            char entrada[64];
            if (!fgets(entrada, sizeof(entrada), stdin)) continue;
            entrada[strcspn(entrada, "\n")] = '\0';
            if (strlen(entrada) == 0) continue;

            int opcao = atoi(entrada);

            switch (opcao) {
                case 1: {
                    int escolha;
                    printf("\nDigite o número da alternativa: ");
                    scanf(" %d", &escolha);

                    // char respBuf[32];
                    // if (!fgets(respBuf, sizeof(respBuf), stdin)) continue;
                    // respBuf[strcspn(respBuf, "\n")] = '\0';
                    
                    // int escolha = atoi(respBuf);
                    
                    do{
                        if(alternativaInvalida(escolha, p->qtdAlternativas)){
                            // Limpa 2 linhas
                            printf("\033[2A"); 
                            printf("\033[2K"); 
                            printf("\033[1B"); 
                            printf("\033[2K"); 
                            printf("\033[1A"); 
                            fflush(stdout);
                            printf("Opção inválida! Tente novamente.\n");
                        }
                        printf("Digite o número da alternativa: ");
                        limparEntrada();
                        scanf(" %d", &escolha);   
                        escolha -= 1;
                    } while(alternativaInvalida(escolha, p->qtdAlternativas));

                    if (escolha == p->resposta) {
                        imprimirAcerto();
                        jogador.nNivel++;
                    } else {
                        jogador.nVida--;
                        imprimirErro();
                    }
                    break;
                }

                case 2: {
                    printf("\nEscolha ação especial: (1) Pular  (2) Trocar  (3) Dica  (0) Voltar\nEscolha: ");
                    char acaoBuf[16];
                    if (!fgets(acaoBuf, sizeof(acaoBuf), stdin)) continue;
                    int a = atoi(acaoBuf);

                    if (a == 1 && disponivelPular) {
                        disponivelPular = 0;
                        jogador.nNivel++;
                        printf("\nVocê pulou a questão e avançou!\n");
                        printf("Pressione ENTER...\n");
                        limparEntrada();
                        break;
                    } else if (a == 2 && disponivelTroca) {
                        disponivelTroca = 0;
                        if (nivelAtual->qtdPerguntas > 1) {
                            int novo;
                            do { novo = rand() % nivelAtual->qtdPerguntas; } while (novo == idxPergunta);
                            p = &nivelAtual->pergunta[novo];
                            printf("\nQuestão trocada!\nPressione ENTER...\n");
                            limparEntrada();
                            continue;
                        } else {
                            printf("\nNão há outra pergunta neste nível.\n");
                            limparEntrada();
                            continue;
                        }
                    } else if (a == 3 && disponivelDica) {
                        disponivelDica = 0;
                        imprimirDica(p->dica);
                        printf("\nPressione ENTER...\n");
                        limparEntrada();
                        continue;
                    } else if (a != 0) {
                        printf("\nAção não disponível ou já usada.\n");
                        limparEntrada();
                        continue;
                    }
                    break;
                }

                case 3:
                    mostrarEstado(jogador.nNivel + 1, totalNiveis, jogador.nVida, disponivelDica, disponivelTroca, disponivelPular);
                    printf("Pressione ENTER...\n");
                    limparEntrada();
                    continue;

                case 4:
                    printf("\nReexibindo pergunta...\n");
                    limparEntrada();
                    continue;

                case 0:
                    printf("\nVocê escolheu sair.\n");
                    sair = 1;
                    break;

                opcao_invalida:
                default:
                    printf("\nOpção inválida!\n");
                    limparEntrada();
                    continue;
            }

            break; // sair do loop da pergunta
        }
    }

    if (jogador.nVida <= 0) imprimirDerrota();
    else if (jogador.nNivel >= totalNiveis) imprimirVitoria();
    else printf("\nJogo encerrado.\n");
}