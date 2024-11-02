/**
 * PROJETO E ANALISE DE ALGORITMOS II
 * TURMA 04P
 * PROJETO BOMBEIROS
 * ALAN MENIUK GLEIZER - 10416804
 * CAIO VINICIUS CORSINI FILHO - 10342005
 * GILBERTO DE MELO JÚNIOR - 10419275
 * **/

#include <stdio.h>
#include <stdlib.h>


// Retorna o numero da esquina com incendio OU o numero de esquinas. Baseado na opcao escolhida
// 'i' para retornar esquina com incendio. 'n' para retornar numero de esquinas
// Fiz isso pois separar isso em duas funcoes iria gerar duas funcoes identicas tirando por uma linha de diferenca
int EsquinaComIncendio_ou_numeroEsquinas(char* nomeArquivo, char opcao){
    if(opcao != 'i' && opcao != 'n') return -1;  // Verificacao de opcao valida

    FILE* arquivo;  // Variavel para armazenar o arquivo em si
    arquivo = fopen(nomeArquivo, "r");
    char linha[10];  // Buffer para armazenar cada linha do arquivo

    if (arquivo == NULL) {  // Verificacao se o arquivo carregou corretamente
        printf("Arquivo nao encontrado!");
        return -1;
    }

    fgets(linha, sizeof(linha), arquivo);  // Pega a primeira linha do arquivo (esquina com incendo)
    if(opcao == 'n') fgets(linha, sizeof(linha), arquivo);  // Pega a segunda linha do arquivo (numero de esquinas)
    return linha[0] - '0';  // Retorna fazendo a conversao de char para int
}

/*
int** arquivoParaMapa(char* nomeArquivo, int n){
    FILE* arquivo;  // Variavel para armazenar o arquivo em si
    arquivo = fopen(nomeArquivo, "r");
    char linha[10];  // Buffer para armazenar cada linha do arquivo

    if (arquivo == NULL) {  // Verificacao se o arquivo carregou corretamente
        printf("Arquivo nao encontrado!");
        //return NULL;
    }


    int** mapa = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mapa[i] = (int*)malloc(n * sizeof(int));
    }

}
*/