#include <stdio.h>
#include <stdbool.h>


bool isEmpty(char gameField[7][6], int col, int row) {
    return gameField[col][row] == ' ';
}

int askPlayerAMove() {
    int input = -1;
    do{
        printf("Entrez la colonne ou vous voulez jouer:");
        scanf("%d", &input);

    }while(input < 0 || input > 6);
    return input;
}

void playMove(char gameField[7][6], int col, char token){
    if (gameField[col][5] == ' '){
        gameField[col][5] = token;
    }else if (gameField[col][4] == ' '){
        gameField[col][4] = token;
    }else if (gameField[col][3] == ' '){
        gameField[col][3] = token;
    }else if (gameField[col][2] == ' '){
        gameField[col][2] = token;
    }else if (gameField[col][1] == ' '){
        gameField[col][1] = token;
    }else if (gameField[col][0] == ' '){
        gameField[col][0] = token;
    }
}

char getPlayerturn(int turnCpt, char tokenPlayer1, char tokenPlayer2){
    if(turnCpt%2 == 0){
        return tokenPlayer1;
    }else{
        return tokenPlayer2;
    }
}

void displayGameBoard(char gameField[7][6]){
    for(int i = 0; i < 7; i++){
        for( int j = 0; j < 6; j++){
            printf(" %c ", gameField[i][j]);
            if(j < 6){
                printf("|");
            }
        }
        printf("\n-----------------------------\n");
    }
}

bool isFull(char gameField[7][6]){
    for(int x = 0; x < 7; x++){
        for(int y = 0; y < 6; y++) {
            if(gameField[x][y] == ' '){
                return false;
            }
        }
    }
    return true;
}

char checkWinner(char gameField[7][6]){
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

    char gameField[6][7] = {{' ', ' ', ' ',' ',' ',' ',' '},
                            {' ', ' ', ' ',' ',' ',' ',' '},
                            {' ', ' ', ' ',' ',' ',' ',' '},
                            {' ', ' ', ' ',' ',' ',' ',' '},
                            {' ', ' ', ' ',' ',' ',' ',' '},
                            {' ', ' ', ' ',' ',' ',' ',' '}};

    char tokenP1 = 'R';
    char tokenp2 = 'J';
    int turnCpt = 0;
    bool gameIsOver = false;

    while(!gameIsOver){
        int col = -1;
        int row = -1;
        do{
            displayGameBoard(gameField);
            col = askPlayerAMove();
        }while(!isEmpty(gameField, col , row));
        playMove(gameField, col, getPlayerturn(turnCpt, tokenP1, tokenp2));
        turnCpt++;

        if(checkWinner(gameField) != '0'){
            gameIsOver = true;
        }
    }
    displayWinner(checkWinner(gameField));
    return 0;
}

