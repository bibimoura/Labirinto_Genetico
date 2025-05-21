#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Labirinto labirinto_carregar(const char* arquivo_labirinto) {
    Labirinto mapa = {0}; // Inicializa todos os campos da estrutura com zeros.
    
    //Abertura do arquivo
    FILE *arquivo = fopen(arquivo_labirinto, "r");
    
    if (arquivo == NULL) { // Verifica se deu certo
        printf("ERRO ao abrir o arquivo %s\n", arquivo_labirinto);
        exit(1);
    }

    // Passo 1: contagem de linhas e colunas máximas
    int lin = 0; // contador de linhas
    int max_cols = 0; // colunas
    char linha[1024]; // Buffer(armazena as linhas )

    // lê cada linha do arquivo até o final (Lê uma linha do arquivo para o buffer linha)
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0'; // Remove '\n'
        int len = strlen(linha); // Calcula o comprimento da linha lida
        if (len > max_cols) max_cols = len; // Atualiza max_cols
        lin++;
    }

    // Verifica se o arquivo está vazio
    if (lin == 0) {
        printf("ERRO: Arquivo vazio ou inválido.\n");
        fclose(arquivo);
        exit(1);
    }

    // Passo 3: Aloca matriz dinâmica
    mapa.labirinto = (char**)malloc(lin * sizeof(char*)); // Cria a primeira dimensão da matriz dinâmica
    if (!mapa.labirinto) {
        printf("ERRO: Falha na alocação de memória.\n");
        fclose(arquivo);
        exit(1);
    }
    for (int i = 0; i < lin; i++) {
        // Aloca memória para cada linha da matriz
        mapa.labirinto[i] = (char*)malloc(max_cols * sizeof(char));
        if (!mapa.labirinto[i]) {
            printf("ERRO: Falha na alocação de memória.\n");
            fclose(arquivo);
            exit(1);
        }
    }

    // Volta ao início do arquivo (Prepara o arquivo para ser lido novamente)
    rewind(arquivo);

    lin = 0;
    // Passo 4: carrega o labirinto (Lê o arquivo novamente, copiando cada linha para a matriz dinâmica.)
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(mapa.labirinto[lin], linha);
        lin++;
    }

    mapa.linhas = lin;
    mapa.colunas = max_cols;

    fclose(arquivo);

    //Passo 5: Encontra as posições de inicio (S)  e final (E)
    labirinto_posicoes(&mapa);

    puts("Carregando o labirinto...");
    printf("Labirinto carregado com sucesso! (%d linhas, %d colunas)\n", mapa.linhas, mapa.colunas);

    return mapa;
}

void labirinto_posicoes(Labirinto* mapa) {

    int encontrou_Inicio = 0, encontrou_Final = 0;

    for (int i = 0; i < mapa->linhas; i++) {
        for (int j = 0; j < mapa->colunas; j++) {

            if (mapa->labirinto[i][j] == 'S') {
                mapa->inicio.linha = i;
                mapa->inicio.coluna = j;

                encontrou_Inicio = 1; // Posição (S) encontrada
            } else if (mapa->labirinto[i][j] == 'E') {
                mapa->final.linha = i;
                mapa->final.coluna = j;

                encontrou_Final = 1; // Posição (E) encontrada
            }
        }
    }
    
    // Verifica se S e E foram encontrados
    if (!encontrou_Inicio || !encontrou_Final) {
        printf("ERRO: Não foi possivel encontrar as posições no labirinto");
        labirinto_free(*mapa);
        exit(1);
    }
}

void labirinto_print(Labirinto mapa) {
    if (mapa.linhas <= 0 || mapa.colunas <= 0) { // Verifica se existe 
        printf("ERRO: Labirinto inválido.\n");
        return;
    }

    for (int i = 0; i < mapa.linhas; i++) {
        for (int j = 0; j < mapa.colunas; j++) {
            printf("%c", mapa.labirinto[i][j]);
        }
        printf("\n");
    }
}

void labirinto_free(Labirinto mapa) {
    for (int i = 0; i < mapa.linhas; i++) {
        free(mapa.labirinto[i]);
    }
    free(mapa.labirinto);
}