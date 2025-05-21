#include "mapa/mapa.h"
#include "populacao/populacao.h"
#include "populacao/individuo/individuo.h"
#include "simulacoes/simulacoes.h"
#include "fitness/fitness.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL));

    // Labirinto
    Labirinto labirinto = labirinto_carregar("mapa.txt");

    puts("\n=-=-=-=-=-=-== Labirinto =-=-=-=-=-=-==\n");
    labirinto_print(labirinto);
    printf("Posicao Inicial (S) do labirinto: (%d, %d)\n", labirinto.inicio.linha, labirinto.inicio.coluna);
    printf("Posicao Final (E) do labirinto: (%d, %d)\n", labirinto.final.linha, labirinto.final.coluna);
   
   //População
   puts("\n=-=-=-=-=-=-== Populacao =-=-=-=-=-=-==\n");
   TLinkedList* lista_populacao = list_create();
   unsigned int tamanhoPopulacao = 50;
   populacao_create(lista_populacao, tamanhoPopulacao);
   populacao_print(lista_populacao, labirinto);

   
   labirinto_free(labirinto);


    return 0;
}