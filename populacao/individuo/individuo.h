#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#define MAX_MOVIMENTOS 50

typedef struct {

    char movimentos[MAX_MOVIMENTOS];
    int cromossomo; 
    double fitness;

}TGenotipo;

/**
 * Inicializa um genótipo com movimentos aleatórios
 * @param genotipo Ponteiro para a estrutura TGenotipo
 */
void individuo_create(TGenotipo *);

#endif