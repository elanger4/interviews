// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    // Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    // Any live cell with two or three live neighbors lives on to the next generation.
    // Any live cell with more than three live neighbors dies, as if by over-population..
    // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    // Write a function to compute the next state (after one update) of the board given its current state.

// Follow up: 
// Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

#include <algorithm>
#include <array>
#include <iostream>
#include "stdlib.h"

int getNumNeighbors(int ** board, int i, int j,int n, int m) {

    int numNeighbors = 0;
    for (int row = std::max(i-1, 0); row <= std::min(i+1, n-1); ++row) {
        for (int col = std::max(j-1, 0); col <= std::min(j+1, m-1); ++col) {
            numNeighbors += board[row][col] & 1; 
        }
    }

    return numNeighbors - (board[i][j] & 1);
}

int ** nextState(int ** board, int n, int m) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int numNeighbors = getNumNeighbors(board, i, j, n, m);
            if (board[i][j] == 1 && numNeighbors <= 3 && numNeighbors >= 2) {
                board[i][j] = 3;
            } 
            if (board[i][j] == 0 && numNeighbors == 3) {
                board[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            board[i][j] >>= 1;
        }
    }

    return board;
}

void printBoard(int ** board, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

int main() {

    int n = 20;
    int m = 20;

    int ** board = (int **)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        board[i] = (int*) malloc(sizeof(int) * m);
    }

    int i;
    for (i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            board[i][j] = rand() % 2;
        }
    }

    printBoard(board, n, m);
    std::cout << std::endl;


    i = 0;
    while(i < 100) {
        board = nextState(board, n, m);
        printBoard(board, n, m);
        ++i;
        std::cout << std::endl;
    }

    for (i = 0; i < n; ++i) {
        free(board[i]); 
    }
    free(board); 
}
