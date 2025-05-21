#include "individuo.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void individuo_create(TGenotipo *genotipo) {
    char direcoes[4] = {'C', 'B', 'E', 'D'}; // Direções
    for(int i = 0; i < MAX_MOVIMENTOS; i++ ){
        genotipo->movimentos[i] = direcoes[rand() % 4];

    }

    genotipo->cromossomo = MAX_MOVIMENTOS;
    genotipo->fitness = 0.0;

}