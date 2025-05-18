# Leetcode 79 - Bernardo Robaina - M2

## Descrição
Dada uma matriz m x n de caracteres chamada board, e uma string chamada word, retorne true se a string existir na grid.

A palavra pode ser construída de células adjacentes, células adjacentes são aquelas que são vizinhas verticais ou horizontais.
A mesma célula não pode ser lida duas vezes.

## Caso teste 1:
*Input*: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
*Output*: true

## Caso teste 2:
*Input*: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
*Output*: true

## Caso teste 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false