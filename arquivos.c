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
        return 0;
    }

    fgets(linha, sizeof(linha), arquivo);  // Pega a primeira linha do arquivo (esquina com incendo)
    if(opcao == 'n') fgets(linha, sizeof(linha), arquivo);  // Pega a segunda linha do arquivo (numero de esquinas)
    int resultado;
    sscanf(linha, "%d", &resultado);  // Usa sscanf para permitir valores com multiplos digitos
    fclose(arquivo);
    return resultado;
}

// Le o arquivo e o converte para uma matriz para representar o grafo de esquinas. O mapa.
// Vale lembrar que no txt a matriz comeca pelo indice 1 enquanto no C comeca pelo indice 0
int** arquivoParaMapa(char* nomeArquivo, int n){
    FILE* arquivo;  // Variavel para armazenar o arquivo em si
    arquivo = fopen(nomeArquivo, "r");
    char linha[10];  // Buffer para armazenar cada linha do arquivo

    if (arquivo == NULL) {  // Verificacao se o arquivo carregou corretamente
        printf("Arquivo nao encontrado!");
        //return NULL;
    }

    // Gerando a matriz que vai representar o mapa/grafo de esquinas
    int** mapa = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        mapa[i] = (int*)malloc(n * sizeof(int));
    
    // Inicializa todo o mapa com zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) mapa[i][j] = 0;
    }
    
    fgets(linha, sizeof(linha), arquivo);  // Primeira linha
    fgets(linha, sizeof(linha), arquivo);  // Segunda linha
    fgets(linha, sizeof(linha), arquivo);  // Terceira linha (aqui as esquinas comecam)
    int nEsquinaAtual, conexaoAtual, custoAtual = -1;

    // Vai verificar cada esquina/linha indicada no arquivo enquanto nao chegar no valor 0
    while(linha[0] != '0'){
        sscanf(linha, "%d %d %d", &nEsquinaAtual, &conexaoAtual, &custoAtual);  // Mapeando os valores
        mapa[nEsquinaAtual - 1][conexaoAtual - 1] = custoAtual;  // Atualiza elemento no mapa
        fgets(linha, sizeof(linha), arquivo);
    }
    fclose(arquivo);
    return mapa;
}
