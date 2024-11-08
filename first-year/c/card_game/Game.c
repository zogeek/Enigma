//
// Created by ziyad on 30/11/2023.
//

#include "Game.h"
#include "deck.h"
#include <stdio.h>
#include <stdlib.h>



void Game(){
    struct deck* d = malloc(sizeof (struct deck));
    d->firstElem = NULL;

    struct card c1 = {1, "pique"};
    struct card c2= {2, "coeur"};
    struct card c3 = {3, "trefle"};

    AddCardInDeck(d, &c1);
    AddCardInDeck(d, &c2);
    AddCardInDeck(d, &c3);
    RemoveCardInDeck(d, 1);

    while(d->firstElem != NULL){
        struct card* c = PopCardInDeck(d);
        printf("la carte est le %d de %s \n", c->value, c->color);
    }


    free(d);
}