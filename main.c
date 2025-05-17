#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool verificaAdjacentes(char board[3][4], int i, int j, int linhas, int colunas, int wordIndex, char* word, bool **visitados){
    if(visitados[i][j] == true){
        printf("Já foi visitado, retornando falso");
        return false;
    }
    //Se chegou no final da palavra
    if(wordIndex == strlen(word)) return true;
    
    printf("\nTesting:\n");
    printf("Posição atual: [%d][%d] Letra: %c\n", i, j, board[i][j]);
    printf("Procurando letra: %c\n", word[wordIndex]);


    bool achou = false;

    if((i+1 < linhas) && board[i+1][j] == word[wordIndex]){
        visitados[i][j] = true;
        printf("%c", board[i+1][j]);
        achou = verificaAdjacentes(board, i+1, j, linhas, colunas,(wordIndex + 1), word, visitados);
    }
    if((j+1 < colunas) && achou == false && board[i][j+1] == word[wordIndex]){
        visitados[i][j] = true;
        printf("%c", board[i][j+1]);
        achou = verificaAdjacentes(board, i, j+1, linhas, colunas,(wordIndex + 1), word, visitados);
    }
    if((i-1 >=0) && achou == false && board[i-1][j] == word[wordIndex]){
        visitados[i][j] = true;
        printf("%c", board[i-1][j]);
        achou = verificaAdjacentes(board, i-1, j, linhas, colunas,(wordIndex + 1), word, visitados);
    }
    if((j-1 >=0) && achou == false && board[i][j-1] == word[wordIndex]){
        visitados[i][j] = true;
        printf("%c", board[i][j-1]);
        achou = verificaAdjacentes(board, i, j-1, linhas, colunas,(wordIndex + 1), word, visitados);
    }

    visitados[i][j] = false;

    return achou;
}

bool exist(char board[3][4], int boardSize, int boardColSize, char* word) {
    bool result = false;

    // matriz de visitados (para nao verificar a mesma célula duas vezes)
    bool** visitados = malloc(boardSize * sizeof(bool*));
    for (int i = 0; i < boardSize; i++) {
        visitados[i] = calloc(boardColSize, sizeof(bool));
    }

    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardColSize; j++){
            if(board[i][j] == word[0]){
                result = verificaAdjacentes(board, i, j, boardSize, boardColSize, 1, word, visitados);
                if(result == true){
                    for(int k = 0; k < boardSize; k++){
                        free(visitados[k]);
                    }
                    free(visitados);

                    return result;
                }
            }
        }
    }

    return result;
}

void main(){
    char matrix[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    int matrixSize = sizeof(matrix) / sizeof(char);
    char* word = "ABCB";

    bool existe = exist(matrix, 3, 4, word);

    if(existe){
        printf("\nExiste");
    }else{
        printf("\nNão existe");
    }
}