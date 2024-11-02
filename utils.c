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

// Funcao apenas para imprimir matrizes. Para testes
void imprimirMatriz(int** matriz, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

// Apenas imprime as opcoes de menu para o usuario escolher
void menu(){
    printf("\n---SISTEMA BOMBEIROS---\n");
    printf("[1] Gerar mapa\n");
    printf("[2] Imprimir mapa\n");
    printf("[3] Resolver\n");
    printf("[4] Gerar arquivo de saida\n");
    printf("[0] Sair do programa\n");
}