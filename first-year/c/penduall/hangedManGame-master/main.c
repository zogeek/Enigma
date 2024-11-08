#include <string.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <time.h>

#define wordsPath "C:\\Users\\ziyad\\OneDrive - ENIGMA SCHOOL\\code\\first-year\\c\\penduall\\hangedManGame-master\\words.txt"



int main() {

    srand(time(NULL));

     mainGame("TEST");


    return 0;
}


char input() {

    char result = 0;

    result = getchar();
    result = toupper(result);


    while (getchar() != '\n');

    return result;

}


void mainGame(char word[]) {
    printf("hello dude, welcome to hanged man game! try to not move a lot and acsept your fate, if dont like pain ;)\n"
           "you have 10 trys to find secret word, god luck!\n");


    int trys = 10;

    char *mistery = NULL;

    mistery = malloc(sizeof(word));

    char c;

    for (int i = 0; i < strlen(word); ++i) {

        *(mistery + i) = '*';

    }


    while (strstr(word, mistery) != word && trys > -1) {

        printf("%s\n\n", mistery);

        c = input();

        boolean bool = false;

        for (int i = 0; i < strlen(word); ++i) {

            if (word[i] == c) {
                *(mistery + i) = c;
                bool = true;
            }

        }


        if (bool == true) {
            printf("yeah ma, great, the word : %s\ntrys : %d\n", mistery, trys);
        }
        if (bool == false) {
            printf("no fucking way, the word : %s\ntrys : %d\n", mistery, trys);
            trys--;
        }

    }

    free(mistery);
    if (trys > -1) {

        printf("you win, we wil hang you next time for sure, whant to try again? 1 = yes, 0 = no\n");
        int reponse = 0;
        scanf("%d", &reponse);
        if (reponse == true) {
            main();
        }

    } else {
        printf("you lose, and did die, whant to try again? maybe this time you will lern how breathe with your ass 1 = yes, 0 = no\n");
        int reponse = 0;
        scanf("%d", &reponse);
        if (reponse == 1) {
            main();
        }

    }


}


char *getWordFomDic() {
    //////////////////////////////////////////
    //code to open file and chek if it's ok//
    ////////////////////////////////////////
    FILE *file = NULL;
    file = fopen(wordsPath, "r");
    if (file == NULL) {
        exit(666);
    }
    rewind(file);
    /////////////////////////////////////////////
    ////////////////////////////////////////////

    /////////////////////////////////////////////
    //code to know ho many word in file
    ////////////////////////////////////////////
    int wordsAmount = 0;

    char curent = 0;

    int totalChars = 0;

    while (curent != EOF) {
        curent = fgetc(file);
        totalChars++;

        if (curent == '\n') {
            wordsAmount++;
        }
    }
    curent = 0;
    rewind(file);
    /////////////////////////////////////////////
    ////////////////////////////////////////////



    int randNum = (rand() % (wordsAmount - 0 + 1)) + 0;

    char *temp = malloc(sizeof(char) * totalChars);
    char *result = NULL;

    if (randNum == 0) {

        fscanf(file, "%s", temp);
        result = malloc(sizeof(char) * strlen(temp));
        strcpy(result, temp);
        free(temp);
        printf("%s", result);
    }
    else {

        for (int i,j = 0; i < totalChars; ++i) {
            curent = fgetc(file);
            if (curent == '\n'){
          j++;
            }
            if (j == randNum){
                fscanf(file, "%s", temp);
                result = malloc(sizeof(char) * strlen(temp));
                strcpy(result, temp);
                free(temp);
                printf("%s", result);
            }


        }
    }

    return result;

}
