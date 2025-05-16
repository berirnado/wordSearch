#include <stdio.h>
#include <stdbool.h>

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    bool result = false;

    return result
}

void main(){
    char matrix[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    int matrixSize = sizeof(matrix) / sizeof(char);
    char word = "ABCCED";

    bool existe = exist(matrix, matrixSize, 4, word);
}