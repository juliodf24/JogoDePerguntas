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

## Executando um Card  

1. Atualize o repositório para garantir a versão mais recente:  
   ```bash
   git pull
   ```

2. Escolha um **card da coluna “A Executar”** no board do GitHub.
   <img width="1889" height="913" alt="image" src="https://github.com/user-attachments/assets/83fcf36e-d847-4308-ae51-6a178007fb24" />  

3. **Atribua o card a você mesmo.**
   <img width="1254" height="855" alt="image" src="https://github.com/user-attachments/assets/b75be4fd-4808-4ec2-9495-b843e30cc0d8" />

4. **Mova o card para a coluna “EM EXECUÇÃO”.**
   <img width="1894" height="941" alt="image" src="https://github.com/user-attachments/assets/151521b4-004a-4cc1-b589-6dbc64aae1c6" />

5. **Crie uma branch para esse card.**
   <img width="1256" height="842" alt="image" src="https://github.com/user-attachments/assets/d5a6e9a9-c83b-4707-a270-7c4f026f483e" />
   <img width="1900" height="929" alt="image" src="https://github.com/user-attachments/assets/41d25b82-f1d1-4cba-9caa-926bbe2884bb" />

6. Copie o comando exibido no GitHub e execute no VS Code.
   <img width="1896" height="919" alt="image" src="https://github.com/user-attachments/assets/ff4b58c1-6325-437e-b334-621dd116b037" />
   
   Exemplo:  
   
   ```bash
   git fetch origin
   git checkout <<nome-da-branch>>
   ```
   > ⚠️ Substitua `<<nome-da-branch>>` pelo nome gerado para o card (ex: `1-criar-o-arquivo-main`).

7. **Implemente a tarefa solicitada no card.**

8. Quando finalizar, execute os seguintes comandos:  
   ```bash
   git pull
   ```
   ```bash
   git add .
   git commit -m "mensagem clara sobre sua modificação"
   ```
   ```bash
   git push
   ```

   >  Caso o push peça login, faça a autenticação e repita o comando.
   
4. **Mova o card para a coluna “EM Homologação”.**
   <img width="1892" height="925" alt="image" src="https://github.com/user-attachments/assets/677e8547-6a92-4b1c-a552-fab051e1dc30" />
   
**Card Finalizado!**
