#ifndef MAPA_H
#define MAPA_H

// Coordenadas
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
 * @return Retorna uma estrutura do tipo Labirinto.
 */
Labirinto labirinto_carregar(const char* );

/**
 * Identifica e armazena as posições de início (S) e final (E) no labirinto
 * @param mapa Ponteiro para a estrutura do labirinto
 */
 void labirinto_posicoes(Labirinto* );

/**
 * Imprime o labirinto na tela
 * @param mapa Estrutura do labirinto
 */
 void labirinto_print(Labirinto );

/**
 * Libera a memória alocada dinamicamente para o labirinto
 * @param mapa Estrutura do labirinto
 */
void labirinto_free(Labirinto );

#endif