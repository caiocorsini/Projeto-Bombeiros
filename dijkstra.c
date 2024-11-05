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
#include <limits.h> // INT_MAX definido aqui, será o nosso infinito
#include <stdbool.h>
#include "utils.h"

// FUNCOES AUXILIARES

// retorna true se o vetor E[] esta "vazio" (nenhum elemento > 0)
bool eEstaVazio(int e[], int qtdEsquinas)
{
    for (int i = 0; i < qtdEsquinas; i++)
    {
        if (e[i] > 0)
            return false;
    }
    return true;
}

// retorna o indice do menor elemento do vetor T[] QUE AINDA ESTA EM E[]
int indiceMenorValorEmT(int *tempos, int *esquinas, int qtdEsquinas)
{
    int menorIndice = -1; // nao pode comecar em 0 pois não sabemos de esquinas[0] ainda "existe" no vetor!!
    int menor = INT_MAX;  // comecar com infinito pois qqr valor sera menor e atualizara corretamente

    for (int i = 0; i < qtdEsquinas; i++)
    {
        if (tempos[i] < menor && esquinas[i]) // && esquinas[i] é necessário pois só devemos considerar esquinas que ainda estão em E! isso é representado por esquinas[i] = 1 = está, esquinas[i] = 0 = não está!
        {
            menor = tempos[i];
            menorIndice = i;
        }
    }
    return menorIndice;
}

// funcao principal dijkstra
// funcao recebe um **mapa (matriz adjacente) com as informacoes sobre as esquinas e a qtd de esquinas
// retorna dois vetores. tempos[i] = tempo da esquina 1 até a esquina i E rota[i] = esquina antecessora de i
void dijkstra(int **mapa, int qtdEsquinas, int *tempos, int *rota)
{
    // inicializar E com as esquinas de M
    int esquinas[qtdEsquinas];

    // preencher E com 1s.. quer dizer que esquina i está sim no vetor
    for (int i = 0; i < qtdEsquinas; i++)
    {
        esquinas[i] = 1;
    }

    // para cada esquina e em E faça T[e] ← ∞
    for (int i = 0; i < qtdEsquinas; i++)
    {
        tempos[i] = INT_MAX;
    }

    // preencher rotas com -1! POSSO JUNTAR TUDO ISSO EM UM UNICO FOR LOOP DEPOIS
    for (int i = 0; i < qtdEsquinas; i++)
    {
        rota[i] = -1;
    }

    // T[1] ← 0 # tempo gasto para ir da esquina 1 até a esquina 1
    tempos[0] = 0;

    // enquanto E não estiver vazio faça
    while (!eEstaVazio(esquinas, qtdEsquinas))
    {

        // v ← é uma esquina em E com menor custo no vetor T[]
        int v = indiceMenorValorEmT(tempos, esquinas, qtdEsquinas);

        if (v == -1)
            break; // indiceMenorValor retorna -1 se não existem mais indices acessíveis E EM E[]! isso que estava gerando o SegFault

        // E ← E – {v} # remove a esquina v de E
        esquinas[v] = 0;

        // para cada esquina e que seja acessada a partir da esquina v no Mapa M

        // vars para armazenar indice da rota atual
        int inRota = 1;
        int ultimoV = 0;

        // vamos percorrer a linha v do mapa (representa um "passo" saindo de v)
        for (int e = 0; e < qtdEsquinas; e++)
        {

            // se a coluna e na linha v tem valor > 0, pode ser acessada a partir de v com o valor == custo!
            // tal que a esquina e esteja presente em E // ou seja, precisamos verificar se essa esquina que pode ser acessada ainda está em E!
            if (mapa[v][e] > 0 && esquinas[e])
            {

                // se T[e] > T[v] + tempo par ir de v até e
                if (tempos[e] > tempos[v] + mapa[v][e])
                {
                    // então T[e] ← T[v] + tempo par ir de v até e
                    tempos[e] = tempos[v] + mapa[v][e];

                    // PARTE QUE FALTAVA NO CODIGO
                    // também precisamos incluir a esquina "v" na rota!
                    // OU SEJA, ROTA VAI ARMAZENAR, PARA CADA ESQUINA i, A ESQUINA ANTERIOR NO CAMINHO MAIS CURTO
                    rota[e] = v;

                    // printf("esquina v atual = %d\n", v + 1);
                }
            }
        }
    }
}

// FUNCOES DE IMPRESSAO
/*
Como funciona o vetor rota[]:

rota[i] armazena a esquina anterior a i no caminho mais curto

om output do caso teste é: [-1, 5, 1, 0, 3, 4]

como o incendio é na esquina 3, queremos chegar na esquina 2 (0-index)

enttão comecamos por rota[2] !!!

0-index      |   1-index
rota[2] = 1  |    3 <- 2
rota[1] = 5  |    2 <- 6
rota[5] = 4  |    6 <- 5
rota[4] = 3  |    5 <- 4
rota[3] = 0  |    4 <- 1
rota[0] = -1  |   1 <- 0

logo, de trás para frente

0-index
0 -> 3 -> 4 -> 5 -> 1 -> 2

1-index
1 -> 4 -> 5 -> 6 -> 2 -> 3

*/

void imprimirRota(int destino, int *rota)
{
    int caminho[6]; // armazenar o caminho "final"
    int indice = 0;

    // fazer o caminho em ordem reversa do destino ateh a origem
    while (destino != -1)
    {
        caminho[indice] = destino + 1; // Ajuste para index-1 na impressao
        destino = rota[destino];       // Vai para a esquina anterior no caminho mais curto
        indice++;
    }

    // imprimir o caminho na ordem correta (tras p frente)
    for (int i = indice - 1; i >= 0; i--)
    {
        printf("%d", caminho[i]);
        if (i > 0)
            printf(" -> ");
    }
    printf("\n");
}