# JogoDePerguntas



## Instalação
Clone o repositório e compile os arquivos `.c` normalmente:

```bash
git clone https://github.com/juliodf24/JogoDePerguntas.git
cd nixjson
mkdir build && cd build
cmake ..
make
```
para iniciar o jogo basta executar o arquivo `jogoperguntas`:

```bash
./jogoperguntas
```

## Criação do Banco de perguntas Json
O arquivo `perguntas.json` deve ser criado no seguinte formato:

```json
{
  "niveis": [
    {
      "nivel": 1,
      "perguntas": [
        {
          "enunciado": "Texto da pergunta",
          "alternativa": ["Alternativa A", "Alternativa B", "Alternativa C", "Alternativa D"],
          "resposta": 1,
          "dica": "Texto da dica"
        }
      ]
    }
  ]
}

```
> A resposta deve seguir o padrão de índice de um array, começando em 0.

## Bibliotecas
A biblioteca utilizada para leitura e manipulação de Json:

`NixJson v1.1.1`

disponível em: [Github NixJson](https://github.com/juliodf24/NixJson.git) 

