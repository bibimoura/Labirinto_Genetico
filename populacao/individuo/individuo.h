#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#define MAX_MOVIMENTOS 30

typedef struct {

    char movimentos[MAX_MOVIMENTOS];
    int cromossomo; 
    int fitness;

}TGenotipo;

/**
 * Cria um genótipo (indivíduo) que contém uma sequência de movimentos aleatórios.
 * @param TGenotipo* genotipo Ponteiro para o genótipo a ser inicializado
 */
void individuo_create(TGenotipo *);

#endif