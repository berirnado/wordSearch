#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool verificaAdjacentes(char board[3][4], int i, int j, int wordIndex, char* word){
    printf("\nTesting:\n");
    printf("Current position: [%d][%d]: %c\n", i, j, board[i][j]);
    printf("Current word letter: %c\n", word[wordIndex]);

    //Se tentar acessar um índice maior que a palavra quer dizer que ele encontrou a palavra
    if(wordIndex == strlen(word)){
        return true;
    }

    bool achou = false;

    if(board[i+1][j] == word[wordIndex]){
        printf("%c", board[i+1][j]);
        achou = verificaAdjacentes(board, i+1, j, (wordIndex + 1), word);
    }
    if(achou == false && board[i][j+1] == word[wordIndex]){
        printf("%c", board[i][j+1]);
        achou = verificaAdjacentes(board, i, j+1, (wordIndex + 1), word);
    }
    if(achou == false && board[i-1][j] == word[wordIndex]){
        printf("%c", board[i-1][j]);
        achou = verificaAdjacentes(board, i-1, j, (wordIndex + 1), word);
    }
    if(achou == false && board[i][j-1] == word[wordIndex]){
        printf("%c", board[i][j-1]);
        achou = verificaAdjacentes(board, i, j-1, (wordIndex + 1), word);
    }

    return achou;
}

bool exist(char board[3][4], int boardSize, int boardColSize, char* word) {
    bool result = false;
    int wordIndex = 0;

    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardColSize; j++){
            if(board[i][j] == word[0]){
                result = verificaAdjacentes(board, i, j, 1, word);
                if(result == true){
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
        printf("Existe");
    }else{
        printf("Não existe");
    }
}