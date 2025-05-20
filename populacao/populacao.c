#include "populacao.h"

#include <stdio.h>
#include <stdlib.h>


#define TAM_INDIVIDUO 20


TLinkedList* list_create(){
    TLinkedList* nova = malloc(sizeof(TLinkedList));

    if(nova){
        nova->inicio = NULL;
        nova->totalIndividuos = 0;
    }
    return nova;
}

TNoPopulacao* TNo_create(TGenotipo *genotipo) {
    TNoPopulacao* novo = malloc(sizeof(TNoPopulacao));
    if (novo == NULL) return NULL;
    novo->genotipo = *genotipo;
    novo->prox = NULL;
    return novo;
}

void populacao_create(TLinkedList*lista ){
    if(lista == NULL) return;

    lista->inicio = NULL;
    for (int i = 0; i < TAM_INDIVIDUO; i++) {
        TGenotipo genotipo;
        individuo_create(&genotipo);
        TNoPopulacao* aux = TNo_create(&genotipo);

        if(aux != NULL){
            aux->prox = lista->inicio;
            lista->inicio = aux;
            lista->totalIndividuos++;

        }
    }
}