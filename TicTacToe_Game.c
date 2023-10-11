#include <stdio.h>
#include <stdbool.h>

char board[3][3];
char currentPlayer = 'X';

// Function to initialize the game board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard() {
    printf("   1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) {
                printf("  | ");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("  ---+----+---\n");
        }
    }
}

// Function to check if the game is over (win or draw)
bool isGameOver() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Row
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; // Column
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Diagonal from top-left to bottom-right
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Diagonal from top-right to bottom-left
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // There are empty cells, the game is not a draw yet
            }
        }
    }
    return true; // All cells are filled, it's a draw
}

// Function to handle player's move
void makeMove() {
    int row, col;
    printf("\nPlayer %c, enter your move (row column): ", currentPlayer);
    scanf("%d %d", &row, &col);
    row--;
    col--;

    // Check if the cell is valid and not already occupied
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
    } else {
        printf("Invalid move! Try again.\n");
        makeMove();
    }
}

int main() {
    initializeBoard();
    printf("Welcome to Tic-Tac-Toe!\n");

    while (1) {
        displayBoard();
        makeMove();

        if (isGameOver()) {
            displayBoard();
            if (currentPlayer == 'X') {
                printf("\nPlayer X wins!\n");
            } else {
                printf("\nPlayer O wins!\n");
            }
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}