#include "simulacoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int simular_caminho(Labirinto mapa, TGenotipo* genotipo, Posicao* pos){

    // Inicializa a posição atual com a posição de início do labirinto
    Posicao atual = mapa.inicio; // (1,1)
    *pos = mapa.inicio;

    // Contador de colisões
    int colisoes = 0;

    for(int i = 0; i <genotipo->cromossomo; i++){
        
        // Usada para Inicializa a posição atual com a posição de início do labirinto
        Posicao proxima = atual; 
        char movimento = genotipo->movimentos[i];

        if (movimento == 'C') proxima.linha--; // Cima (move para a linha anterior)
        else if (movimento == 'B') proxima.linha++; // Baixo (move para a próxima linha)
        else if (movimento == 'E') proxima.coluna--; // Esquerda (move para a coluna anterior)
        else if (movimento == 'D') proxima.coluna++; // Direita (move para a próxima coluna)

        // Verifica se a próxima posição está fora dos limites do labirinto.
        if(proxima.linha < 0 || proxima.linha >= mapa.linhas || proxima.coluna < 0 || proxima.coluna >= mapa.colunas){
            colisoes++;
            break; 
        }

        // Verifica se a próxima posição é uma parede (#) no labirinto.
        if(mapa.labirinto[proxima.linha][proxima.coluna] == '#'){
            colisoes++;
            continue;
        }

        // Atualiza a posição atual para a próxima posição
        atual = proxima;

        //Atualiza o ponteiro pos para armazenar a posição atual
        *pos = atual;

        if (atual.linha == mapa.final.linha && atual.coluna == mapa.final.coluna) {
            break; // Para ao alcançar final (E)
        }
    }
    return colisoes;
}