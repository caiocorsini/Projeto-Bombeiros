#ifndef DIJKSTRA_AUX
#define DIJKSTRA_AUX

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "utils.h"

bool eEstaVazio(int e[], int qtdEsquinas);
int indiceMenorValorEmT(int *tempos, int *esquinas, int qtdEsquinas);
void dijkstra(int **mapa, int qtdEsquinas, int *tempos, int *rota);
void imprimirRota(int destino, int *rota);

#endif
