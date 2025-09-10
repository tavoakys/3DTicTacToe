#include <iostream>
using namespace std;

char board[4][4][4];
char player = 'X';
int movesMade = 0;

void start() {
    for (int z = 0; z < 4; z++) {
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                board[z][y][x] = ' ';
            }
        }
    }
}

void printBoard() {
    cout << "\n=== 4x4x4 Tic-Tac-Toe ===\n";
    for (int z = 0; z < 4; z++) {
        cout << "Layer z = " << (z + 1) << " (x ->, y down)\n";
        cout << "    x: 1   2   3   4\n";
        for (int y = 0; y < 4; y++) {
            cout << " y=" << (y + 1) << "  ";
            for (int x = 0; x < 4; x++) {
                char c = board[z][y][x];
                if (c == ' ') c = '.';
                cout << c;
                if (x < 3) cout << " | ";
            }
            cout << "\n";
            if (y < 3) cout << "     ---+---+---+---\n";
        }
        if (z < 3) cout << "-------------------------\n";
    }
    cout << "\nEnter coordinates as: x y z (each 1-4)\n";
}

bool checkLine(char a, char b, char c, char d) {
    return (a != ' ') && (a == b) && (b == c) && (c == d);
}

bool checkWin() {

    for (int z = 0; z < 4; z++) {
        for (int y = 0; y < 4; y++) {
            if (checkLine(board[z][y][0], board[z][y][1], board[z][y][2], board[z][y][3])) {
                return true;
            }
        }
    }

    for (int z = 0; z < 4; z++) {
        for (int x = 0; x < 4; x++) {
            if (checkLine(board[z][0][x], board[z][1][x], board[z][2][x], board[z][3][x])) {
                return true;
            }
        }
    }

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (checkLine(board[0][y][x], board[1][y][x], board[2][y][x], board[3][y][x])) {
                return true;
            }
        }
    }

    for (int z = 0; z < 4; z++) {
        if (checkLine(board[z][0][0], board[z][1][1], board[z][2][2], board[z][3][3])) {
            return true;
        }
        if (checkLine(board[z][0][3], board[z][1][2], board[z][2][1], board[z][3][0])) {
            return true;
        }
    }

    for (int x = 0; x < 4; x++) {
        if (checkLine(board[0][0][x], board[1][1][x], board[2][2][x], board[3][3][x])) {
            return true;
        }
        if (checkLine(board[0][3][x], board[1][2][x], board[2][1][x], board[3][0][x])) {
            return true;
        }
    }

    for (int y = 0; y < 4; y++) {
        if (checkLine(board[0][y][0], board[1][y][1], board[2][y][2], board[3][y][3])) {
            return true;
        }
        if (checkLine(board[0][y][3], board[1][y][2], board[2][y][1], board[3][y][0])) {
            return true;
        }
    }

    if (checkLine(board[0][0][0], board[1][1][1], board[2][2][2], board[3][3][3])) {
        return true;
    }
    if (checkLine(board[0][0][3], board[1][1][2], board[2][2][1], board[3][3][0])) {
        return true;
    }
    if (checkLine(board[0][3][0], board[1][2][1], board[2][1][2], board[3][0][3])) {
        return true;
    }
    if (checkLine(board[0][3][3], board[1][2][2], board[2][1][1], board[3][0][0])) {
        return true;
    }

    return false;
}

bool checkTie() {
    return movesMade >= 64;
}

int main() {
    cout << "Welcome to 4x4x4 Tic-Tac-Toe!\n";
    cout << "Players take turns. X goes first.\n";
    start();

    while (true) {
        printBoard();
        cout << "Player " << player << ", enter x y z (1-4): ";

        int x, y, z;
        if (!(cin >> x >> y >> z)) {
            cout << "Input error.\n";
            return 0;
        }

        x--; y--; z--;

        if (x < 0 || x > 3 || y < 0 || y > 3 || z < 0 || z > 3) {
            cout << "Out of range. Try again.\n";
            continue;
        }
        if (board[z][y][x] != ' ') {
            cout << "Cell already taken. Try again.\n";
            continue;
        }

        board[z][y][x] = player;
        movesMade++;

        if (checkWin()) {
            printBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (checkTie()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }

        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}
