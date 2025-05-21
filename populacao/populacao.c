#include "populacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void populacao_create(TLinkedList* lista, unsigned int populacao){
    if(lista == NULL) return;

    lista->inicio = NULL;
    lista->totalIndividuos = 0;
    TNoPopulacao* ultimo = NULL;

    for (unsigned int i = 0; i < populacao; i++) {
        TGenotipo genotipo;
        individuo_create(&genotipo);
        TNoPopulacao* aux = TNo_create(&genotipo);

        if(aux != NULL){
            if(lista->inicio == NULL){
                lista->inicio = aux;
                ultimo = aux;
            } else {
                ultimo->prox = aux;
                ultimo = aux;
            }
            lista->totalIndividuos++;
        }
    }
    if(ultimo != NULL){
        ultimo->prox = NULL; 
    }
}

void populacao_print(TLinkedList* lista, Labirinto mapa) {
    if (lista == NULL) {
        printf("A lista é nula.\n");
        return;
    }

    printf("Total de individuos: %u\n", lista->totalIndividuos);

    if (lista->inicio == NULL) {
        printf("A população está vazia.\n");
        return;
    }

    TNoPopulacao* atual = lista->inicio;
    unsigned int i = 0;

    while (atual != NULL) {
        Posicao pos_final;
        int colisoes = simular_caminho(mapa, &atual->genotipo, &pos_final);
        calcular_fitness(mapa, &atual->genotipo, pos_final);

        printf("Individuo [%u]: ", i);
        for (int j = 0; j < atual->genotipo.cromossomo; j++) {
            printf("%c ", atual->genotipo.movimentos[j]);
        }
        printf("\n[%d] Posicao final: (%d, %d), Colisoes: %d, Fitness: %.2f\n", i,
               pos_final.linha, pos_final.coluna, colisoes, atual->genotipo.fitness);
               puts("\n");

        atual = atual->prox;
        i++;
    }
}
