#include "fitness.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double calcular_fitness(Labirinto mapa, TGenotipo* genotipo, Posicao pos) {

    double fitness = 1000.0;

    // Distância de Manhattan
    double distancia = abs(pos.linha - mapa.final.linha) + abs(pos.coluna - mapa.final.coluna);
    fitness -= distancia;

    // Recalcular colisões
    Posicao aux;
    int colisoes = simular_caminho(mapa, genotipo, &aux);

    // Penalidade por colisões
    fitness -= colisoes * 10;

    // Penalidade se não chegar à saída
    if (aux.linha != mapa.final.linha || aux.coluna != mapa.final.coluna) {
        fitness -= 100;
    }

    // Para não ficar negativo
    if (fitness < 0) {
        fitness = 0;
    }

    genotipo->fitness = fitness;

    return fitness;
}

