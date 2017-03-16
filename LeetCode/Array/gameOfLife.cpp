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

int ** nextState(int ** board, int n, int m) {
    int ** newState = board;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int numNeighbors = 0;
            for (int row = -1; i <= 1; ++i) {
                for (int col = -1; j <= 1; ++j) {
                    if (i + row <= n-1 && i + row >= 0 && j + col <= m-1 && j + col >= 0) {
                       numNeighbors += 1; 
                    }
                }
            }
            if (numNeighbors > 3 || numNeighbors < 2) {
                newState[i][j] = 0;
            } else if (numNeighbors == 3) {
                newState[i][j] = 1;
            }
            // else numNeighbors == 2, alive cell will stay alive and dead cell
            // will stay dead. No need to check for it.
        }
    }
    return newState;
}

int main() {
    return 0;
}
