#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#iclude <stdtool.h>

void clearScreen() {
    system("cls");
}
void displayBoard() {
    char board[] = "1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9";
    printf(board);
    printf("\n");
}

void morpion() {
    clearScreen();
    printf("Morpion de ta mere\n");
    displayBoard();
    char joueur1 = 'X';
    char joueur2 = 'O';
    int winPossibilities[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };
    int board[9] = {0,0,0,0,0,0,0,0,0};

}
bool isEmpty(int gameField[3][3], int col, int row) {
    return gameField[col][row] == ' ';
}


void playMove(char GameField[3][3], int col, int row, char token) {
    GameField[col][row] = token;
}
char getPlayerturn(int turnCpt) {
    if (turnCpt % 2 == 0) {
        return tokenPlayer1;
    } else {
        return 'X';
    }
}
void displayWinner(char winner) {
    printf("Le joueur %c a gagne !\n", winner);
}


void displayGameField(int gameField[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; j++) {
            printf("%c ", gameField[i][j]);
            if j < 2 {
                printf("|");
            }
        }
        printf("\n");
    }
}

int askPlayerAMove() {
    int input;
    do {
        printf("Entre le valeur ou je te tape!");
        scanf("%d", &input);
    }while(input < 0 || input > 2);
}

char checkWinner(char gameField[3][3]) {
    char state = '0';
    for (int i = 0; i < 8; i++) {
        int cpt = 0;
        for (int j = 0; j < 3; j++) {
            if (gameField[winPossibilities[i][j]] == 'X') {
                cpt++;
            } else if (gameField[winPossibilities[i][j]] == 'O') {
                cpt--;
            }
        }
        if (cpt == 3) {
            state = 'X';
        } else if (cpt == -3) {
            state = 'O';
        }
    }
}
bool isFull(gameField[3][3]) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            if (gameField[i][j] == ' ') {
                return false;
            }
        }
    }
}

int main() {

    int gameField[3][3] = {
        {' ','',''},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    char TokenP1 = 'O';
    char TokenP2 = 'X';
    int TurnCpt = 0;
    bool GameIsOver = false;
    while (!gameIsOver) {
        int col = -1;
        int row = -1;
        do {
            int col = askPlayerAMove();
            int row = askPlayerAMove();
        }while (!isEmpty(gameField, col, row));
        playMove(gameField, col, row, getPlayerturn(turnCpt), TokenP1,tokenp2);


    }




    return 0;
}
