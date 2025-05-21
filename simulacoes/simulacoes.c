#include "simulacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int simular_caminho(Labirinto mapa, TGenotipo* genotipo, Posicao* pos){

    Posicao atual = mapa.inicio; // (1,1)
    int colisoes = 0;

    for(int i = 0; i <genotipo->cromossomo; i++){
        Posicao proxima = atual;
        char movimento = genotipo->movimentos[i];

        if (movimento == 'C') proxima.linha--; // Cima
        else if (movimento == 'B') proxima.linha++; // Baixo
        else if (movimento == 'E') proxima.coluna--; // Esquerda
        else if (movimento == 'D') proxima.coluna++; // Direita

        if(proxima.linha < 0 || proxima.linha >= mapa.linhas || proxima.coluna < 0 || proxima.coluna >= mapa.colunas){
            colisoes++;
            break; 
        }

        if(mapa.labirinto[proxima.linha][proxima.coluna] == '#'){
            colisoes++;
            break;
        }

        atual = proxima;
        *pos = atual;

        if (atual.linha == mapa.final.linha && atual.coluna == mapa.final.coluna) {
            break; // Para ao alcançar final (E)
        }
    }
    return colisoes;
}