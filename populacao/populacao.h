#ifndef POPULACAO_H
#define POPULACAO_H

#include "individuo/individuo.h"
#include "simulacoes/simulacoes.h"

typedef struct TNoPopulacao {
    TGenotipo genotipo;
    struct TNoPopulacao* prox;
} TNoPopulacao;

typedef struct {
    TNoPopulacao *inicio;
    int totalIndividuos;
}TLinkedList;

/**
 * Cria instâncias da lista simplesmente encadeada.
 * @return TLinkedList* ponteiro para a lista alocada.
 */
TLinkedList* list_create();

/**
 * Cria uma novo Nó 
 * @param TGenotipo* genotipo
 * @return TNoPopulacao*
 */
TNoPopulacao* TNo_create(TGenotipo* );


/**
 * Cria uma população (Inserção no inicio)
 * @param TLinkedList* 
 */
void populacao_create(TLinkedList*, unsigned int);

void populacao_print(TLinkedList*, Labirinto);

#endif