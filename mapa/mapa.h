#ifndef MAPA_H
#define MAPA_H

typedef struct {
    int linha;
    int coluna;
} Posicao;

// Estrutura para o labirinto
typedef struct {
    char** labirinto; // Matriz dinâmica
    Posicao inicio;
    Posicao final;    
    int linhas;       
    int colunas;      
} Labirinto;


/**
 * Vai carregar um labirinto de um arquivo.txt
 * @param const char* arquivo_labirinto.
 * @return Retorna uma estrutura do tipo Labirinto
 */
Labirinto labirinto_carregar(const char* );

/**
 * Vai encontrar a posição incial (S) e final (E) do labirinto
 * @param Labirinto* mapa Estrutura Labirinto 
 */
 void labirinto_posicoes(Labirinto* );

/**
 * Vai imprimir o labirinto.
 * @param Labirinto mapa Estrutura Labirinto
 */
 void labirinto_print(Labirinto );

/**
 * Libera a memória alocada para o labirinto
 * @param Labirinto mapa Estrutura Labirinto
 */
void labirinto_free(Labirinto );

#endif