#include <stdio.h>
#include <stdbool.h>


bool isEmpty(char gameField[3][3], int col, int row) {
    return gameField[col][row] == ' ';
}

int askPlayerAMove() {
    int input = -1;
    do{
        printf("entre ta valeur ou je te tape!");
        scanf("%d", &input);

    }while(input < 0 || input > 2);
    return input;
}

void playMove(char gameField[3][3], int col, int row, char token){
    gameField[col][row] = token;
}

char getPlayerturn(int turnCpt, char tokenPlayer1, char tokenPlayer2){
    if(turnCpt%2 == 0){
        return tokenPlayer1;
    }else{
        return tokenPlayer2;
    }
}

void displayGameBoard(char gameField[3][3]){
    for(int i = 0; i < 3; i++){
        for( int j = 0; j < 3; j++){
            printf(" %c ", gameField[i][j]);
            if(j < 2){
                printf("|");
            }
        }
        printf("\n-----------\n");
    }
}

bool isFull(char gameField[3][3]){
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++) {
            if(gameField[x][y] == ' '){
                return false;
            }
        }
    }
    return true;
}

char checkWinner(char gameField[3][3]){
    char state = '0';

    for (int i = 0; i < 3; i++){
        if( gameField[i][0] == gameField[i][1] && gameField[i][0] == gameField[i][2] && gameField[i][0] != ' '){
            return gameField[i][0];
        }
        if( gameField[0][i] == gameField[1][i] && gameField[0][i] == gameField[2][i] && gameField[0][i] != ' '){
            return gameField[0][i];
        }
    }
    if( gameField[0][0] == gameField[1][1] && gameField[0][0] == gameField[2][2] && gameField[0][0] != ' '){
        return gameField[0][0];
    }
    if( gameField[0][2] == gameField[1][1] && gameField[2][0] == gameField[1][1] && gameField[1][1] != ' '){
        return gameField[0][2];
    }

    if(isFull(gameField)){
        return 'n';
    }
    return state;
}



void displayWinner(char token){
    if( token == 'n'){
        printf("c'est un match null");
    }else{
        printf(" le joueur %c gagne!", token);
    }

}

int main() {

    char gameField[3][3] = {{' ', ' ', ' '},
                           {' ', ' ', ' '},
                           {' ', ' ', ' '}};

    char tokenP1 = 'X';
    char tokenp2 = 'O';
    int turnCpt = 0;
    bool gameIsOver = false;

    while(!gameIsOver){
        int col = -1;
        int row = -1;
        do{
            displayGameBoard(gameField);
            col = askPlayerAMove();
            row = askPlayerAMove();
        }while(!isEmpty(gameField, col , row));
        playMove(gameField, col, row, getPlayerturn(turnCpt, tokenP1, tokenp2));
        turnCpt++;

        if(checkWinner(gameField) != '0'){
            gameIsOver = true;
        }
    }
    displayWinner(checkWinner(gameField));
    return 0;
}

