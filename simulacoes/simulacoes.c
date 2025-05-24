#include "simulacoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int simular_caminho(Labirinto mapa, TGenotipo* genotipo, Posicao* pos){

    Posicao atual = mapa.inicio; // (1,1)
    *pos = mapa.inicio;

    // Contador de colisões
    int colisoes = 0;

    for(int i = 0; i <genotipo->cromossomo; i++){
        
  
        Posicao proxima = atual; 
        char movimento = genotipo->movimentos[i];

        if (movimento == 'C') proxima.linha--; // move para a linha anterior
        else if (movimento == 'B') proxima.linha++; // move para a próxima linha
        else if (movimento == 'E') proxima.coluna--; // move para a coluna anterior
        else if (movimento == 'D') proxima.coluna++; //move para a próxima coluna

        // Verifica se a próxima posição está fora dos limites do labirinto.
        if(proxima.linha < 0 || proxima.linha >= mapa.linhas || proxima.coluna < 0 || proxima.coluna >= mapa.colunas){
            colisoes++;
            break; 
        }

        // Verifica se a próxima posição é uma parede..
        if(mapa.labirinto[proxima.linha][proxima.coluna] == '#'){
            colisoes++;
            break;
        }

        // Atualiza a posição atual para a próxima posição.
        atual = proxima;

        //Atualiza o ponteiro pos para armazenar a posição atual.
        *pos = atual;

        if (atual.linha == mapa.final.linha && atual.coluna == mapa.final.coluna) {
            break; // Para ao alcançar o final do labirinto (E)
        }
    }
    return colisoes;
}