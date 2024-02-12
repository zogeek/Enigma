#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

int main()
{
    struct deck *d = malloc(sizeof(struct deck));
    d->firstElem = NULL;


    struct card c1 = {1, "Pique"};
    struct card c2 = {2, "Coeur"};
    struct card c3 = {3, "Carreau"};
    struct card c4 = {4, "Trefle"};

    AddCardInDeck(d, &c1);
    AddCardInDeck(d, &c2);
    AddCardInDeck(d, &c3);
    AddCardInDeck(d, &c4);

    while (d->firstElem != NULL){
        struct card *c = PopCardInDeck(d);
        printf("La carte est le %d de %s\n", c->value, c->color);
    }

    free(d);

    return 0;
}
