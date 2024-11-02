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
 * Manipulacao de arquivos em C Geeks for Geeks: https://www.geeksforgeeks.org/basics-file-handling-c/
 * Representacoes de grafos Geeks for Geeks: https://www.geeksforgeeks.org/graph-and-its-representations/
 *  
 *
 * **/

//gcc -o main.exe *.c *.h & main.exe 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "arquivos.h"

int main(){
    char* nomeArquivoEntrada = "entrada.txt";
    int esquinaComIncendio;
    int numeroEsquinas;
    int** mapa;
    int opcao = -1;
    bool arquivoLido = false;

    // Menu de interacao com o usuario
    while(opcao){
        menu();
        printf("Selecione opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if(opcao == 1){
            esquinaComIncendio = EsquinaComIncendio_ou_numeroEsquinas(nomeArquivoEntrada,'i');
            numeroEsquinas = EsquinaComIncendio_ou_numeroEsquinas(nomeArquivoEntrada,'n');
            mapa = arquivoParaMapa(nomeArquivoEntrada, numeroEsquinas);
            arquivoLido = true;
        }

        if(opcao == 2){
            if(arquivoLido){
                printf("Esquina com incencio: %d\n",esquinaComIncendio);
                printf("Numero esquinas com incendio: %d\n", numeroEsquinas);
                imprimirMatriz(mapa, numeroEsquinas);
                printf("\n");
            } else printf("Nenhum mapa carregado.\nPor favor selecionar opcao 1 primeiro.\n");
        }

        if(opcao == 3){

        }

        if(opcao == 4){
            
        }
    }
    return 0;
}