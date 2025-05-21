#ifndef SIMULACOES_H
#define SIMULACOES_H

#include "mapa/mapa.h"
#include "populacao/individuo/individuo.h"

/**
 * Simula a movimentação de um indivíduo no labirinto.
 * @param mapa Estrutura do labirinto.
 * @param genotipo Ponteiro para o genótipo a ser testado.
 * @param pos Ponteiro para armazenar a posição final do indivíduo após a simulação.
 * @return Retorna o número de colisões.
 */
int simular_caminho(Labirinto mapa, TGenotipo* genotipo, Posicao* pos);


#endif