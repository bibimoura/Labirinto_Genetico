#ifndef POPULACAO_H
#define POPULACAO_H

// Inclui os módulos que serão usados pela população
#include "individuo/individuo.h"
#include "simulacoes/simulacoes.h"
#include "fitness/fitness.h"
#include "mapa/mapa.h"

// Nó da lista (representa um indivíduo)
typedef struct no_Populacao {
    TGenotipo genotipo;          // Genótipo do indivíduo
    struct no_Populacao *prox;     
} TNoPopulacao;

// Estrutura da lista encadeada que representa a população
typedef struct {
    TNoPopulacao *inicio;      // Ponteiro para o primeiro nó
    int totalIndividuos;
} TLinkedList;

/**
 * Cria uma lista de população vazia
 * @return Ponteiro para a lista criada
 */
TLinkedList* list_create();

/**
 * Cria um novo nó de população com base no genótipo passado
 * @param genotipo Ponteiro para a estrutura TGenotipo
 * @return Ponteiro para o novo nó criado
 */
TNoPopulacao* TNo_create(TGenotipo* );

/**
 * Gera uma população aleatória com indivíduos iniciais
 * @param lista Ponteiro para a lista de população
 * @param populacao Quantidade de indivíduos desejada
 */
void populacao_create(TLinkedList* , unsigned int );

/**
 * Imprime os genótipos da população, seus caminhos simulados e seus fitness
 * @param lista Lista encadeada com os indivíduos
 * @param mapa Labirinto utilizado na simulação
 */
void populacao_print(TLinkedList* , Labirinto );

#endif