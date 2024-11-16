#ifndef PEGAR_NUMERO_DE_ESQUINAS_H
#define PEGAR_NUMERO_DE_ESQUINAS_H


int EsquinaComIncendio_ou_numeroEsquinas(char* nomeArquivo, char opcao);

int** arquivoParaMapa(char* nomeArquivo, int n);

void gerarArquivoSaida(char* nomeArquivoSaida, int destino, int* rota, int tempoTotal);


#endif
