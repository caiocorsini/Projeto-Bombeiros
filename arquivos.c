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

int numeroEsquinaComIncendio(char* nomeArquivo){
    FILE* arquivo;  // Variavel para armazenar o arquivo em si
    arquivo = fopen(nomeArquivo, "r");
    char linha[10];  // Buffer para armazenar cada linha do arquivo
    if (arquivo == NULL) {  // Verificacao se o arquivo carregou corretamente
        printf("Arquivo nao encontrado!");
        return -1;
    }
    fgets(linha, sizeof(linha), arquivo);  // Pega a primeira linha do arquivo
    return linha[0] - '0';  // Retorna fazendo a conversao de char para int
}

int numeroDeEsquinasTotal(char* nomeArquivo){
    FILE* arquivo;  // Variavel para armazenar o arquivo em si
    arquivo = fopen(nomeArquivo, "r");
    char linha[10];  // Buffer para armazenar cada linha do arquivo
    if (arquivo == NULL) {  // Verificacao se o arquivo carregou corretamente
        printf("Arquivo nao encontrado!");
        return -1;
    }
    fgets(linha, sizeof(linha), arquivo);  // Pega a primeira linha do arquivo
    fgets(linha, sizeof(linha), arquivo);  // Pega a segunda linha do arquivo
    return linha[0] - '0';  // Retorna fazendo a conversao de char para int

}