# JogoDePerguntas - Guia de Contribuição  

## Preparando o Ambiente  

1. Abra o **VS Code** em uma pasta vazia.  
2. Clone o repositório com o comando:  
   ```bash
   git clone https://github.com/juliodf24/JogoDePerguntas.git
   ```
3. Pressione `Ctrl + K + O` e selecione a pasta **JogoDePerguntas**.  
4. Atualize o código com:  
   ```bash
   git pull
   ```
   > Esse comando garante que você está com a versão mais recente do projeto.  

 **Ambiente preparado!**

---

## Compilando o Código 

1. execute:  
   ```bash
   gcc src/bancoPerguntas.c src/main.c src/ui.c  bibliotecas/cJSON.c -o main.out
   ```

4