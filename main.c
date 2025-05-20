#include "mapa/mapa.h"
#include <stdio.h>

int main() {

     
    Labirinto labirinto = labirinto_carregar("mapa.txt");
    labirinto_print(labirinto);
    printf("Posicao Inicial (S) do labirinto: (%d, %d)\n", labirinto.inicio.linha, labirinto.inicio.coluna);
    printf("Posicao Final (E) do labirinto: (%d, %d)\n", labirinto.final.linha, labirinto.final.coluna);
    labirinto_free(labirinto);


    return 0;
}