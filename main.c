/**
 * PROJETO E ANALISE DE ALGORITMOS II
 * TURMA 04P
 * PROJETO BOMBEIROS
 * ALAN MENIUK GLEIZER - 10416804
 * CAIO VINICIUS CORSINI FILHO - 10342005
 * GILBERTO DE MELO JÚNIOR - 10419275
 * **/

/**
 * REFERENCIAS
 * Algoritmo de Dijkstra Geeks for Geeks: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
 * Manipulacao de arquivos em C: https://www.geeksforgeeks.org/basics-file-handling-c/
 *
 *  
 *
 * **/

//gcc -o main.exe *.c *.h & main.exe 

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "arquivos.h"

int main(){
    char* nomeArquivoEntrada = "entrada.txt";
    printf("%d\n", EsquinaComIncendio_ou_numeroEsquinas(nomeArquivoEntrada,'i'));
    printf("%d", EsquinaComIncendio_ou_numeroEsquinas(nomeArquivoEntrada,'n'));



    //int** matrix = (int**)malloc(20 * sizeof(int*)); for (int i = 0; i < 20; i++) {matrix[i] = (int*)malloc(20 * sizeof(int));}
    //imprimirMatriz(matrix,20);

    return 0;
}