#ifndef POPULACAO_H
#define POPULACAO_H

#include "../populacao/individuo/individuo.h"

typedef struct{
    TGenotipo genotipo;
    struct TNoPopulacao *prox;
}TNoPopulacao;

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
 * Cria uma população 
 * @param TLinkedList* lista 
 */
void populacao_create(TLinkedList* );


#endif