#include <iostream>
using namespace std;

char board[3][3] = {
    {' ' , ' ' , ' '},
    {' ' , ' ' , ' '},
    {' ' , ' ' , ' '}
};

void drawBoard() {
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << '\n';
        if (i < 2) {
            cout << "---|---|---" << '\n';
        }
    }
}

void userInput(char player) {
    string position;
    bool validMove = false;

    while (!validMove) {
        cout << "Player " << player << " turn. Enter position: ";
        cin >> position;

        int row = -1, col = -1;
        if (position == "middle") { row = 1; col = 1; }
        else if (position == "top-left") { row = 0; col = 0; }
        else if (position == "top-middle") { row = 0; col = 1; }
        else if (position == "top-right") { row = 0; col = 2; }
        else if (position == "middle-left") { row = 1; col = 0; }
        else if (position == "middle-right") { row = 1; col = 2; }
        else if (position == "bottom-left") { row = 2; col = 0; }
        else if (position == "bottom-middle") { row = 2; col = 1; }
        else if (position == "bottom-right") { row = 2; col = 2; }

        if (row != -1 && col != -1 && board[row][col] == ' ') {
            board[row][col] = player;
            validMove = true;
        }
        else {
            cout << "Invalid move! Try again.\n";
        }
    }
}

bool checkWinner(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    drawBoard();

    for (int turn = 0; turn < 9; turn++) {
        char currentPlayer = (turn % 2 == 0) ? 'X' : '0';
        userInput(currentPlayer);
        drawBoard();

        if (checkWinner(currentPlayer)) {
            cout << "The winner is " << currentPlayer << "!\n";
            return 0;
        }

        if (isDraw()) {
            cout << "It's a draw!\n";
            return 0;
        }
    }

    return 0;
}
