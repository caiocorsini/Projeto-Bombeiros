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

// gcc -o main.exe *.c *.h & main.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "arquivos.h"
#include "dijkstra.h"

int main()
{
    char *nomeArquivoEntrada = "entrada.txt";
    int esquinaComIncendio;
    int numeroEsquinas;
    int **mapa;
    int opcao = -1;
    bool arquivoLido = false;

    int *tempos;
    int *rota;

    // Menu de interacao com o usuario
    while (opcao)
    {
        menu();
        printf("Selecione opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1)
        {
            esquinaComIncendio = EsquinaComIncendio_ou_numeroEsquinas(nomeArquivoEntrada, 'i');
            numeroEsquinas = EsquinaComIncendio_ou_numeroEsquinas(nomeArquivoEntrada, 'n');
            mapa = arquivoParaMapa(nomeArquivoEntrada, numeroEsquinas);
            arquivoLido = true;
        }

        if (opcao == 2)
        {
            if (arquivoLido)
            {
                printf("Esquina com incendio: %d\n", esquinaComIncendio);
                printf("Numero esquinas com incendio: %d\n", numeroEsquinas);
                imprimirMatriz(mapa, numeroEsquinas);
                printf("\n");
            }
            else
                printf("Nenhum mapa carregado.\nPor favor selecionar opcao 1 primeiro.\n");
        }

        if (opcao == 3)
        {
            if (arquivoLido) {
                tempos = (int *)malloc(numeroEsquinas * sizeof(int));
                rota = (int *)malloc(numeroEsquinas * sizeof(int));

                dijkstra(mapa, numeroEsquinas, tempos, rota);

                // para testes APENAS
                // printArray(tempos, numeroEsquinas);
                // printArray(rota, numeroEsquinas);

                printf("Tempo para a esquina %d: %d minutos\n", esquinaComIncendio, tempos[esquinaComIncendio - 1]);
                printf("Rota para a esquina %d: ", esquinaComIncendio);
                imprimirRota(esquinaComIncendio - 1, rota);
            } else {
                printf("Nenhum mapa carregado. Selecione a opção 1 primeiro.\n");
            }
        } 

        if (opcao == 4)
        {
            if (arquivoLido) {
                gerarArquivoSaida("saida.txt", esquinaComIncendio - 1, rota, tempos[esquinaComIncendio- 1]);
            } else {
                printf("Nenhum mapa carregado. Selecione a opção 1 primeiro.\n");
            }
        }
    }

    // Liberar mem
    for (int i = 0; i < numeroEsquinas; i++)
    {
        free(mapa[i]);
    }
    free(mapa);
    free(tempos);
    free(rota);

    return 0;
}