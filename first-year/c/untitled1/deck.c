//
// Created by ziyad on 30/11/2023.
//

#include "deck.h"
#include <stdio.h>
#include <stdlib.h>


struct elem* GetElementAt (struct deck* d, int index) {
    if (index < 0 || index > CountCardInDeck(d)) {
        printf("Index out of range");
        return NULL;
    }
    struct elem* e = d->firstElem;
    for (int i = 1; i <= index; i++) {
        e = e->nextElem;
    }
    return e;
}

int CountCardInDeck (struct deck* d) {
    int cpt = 0;
    if (d->firstElem == NULL) {
        return cpt;
    }
    struct elem* e = d->firstElem;
    cpt++;
    while (e->nextElem != NULL) {
        cpt++;
        e = e->nextElem;
    }
    return cpt;

}

void AddCardInDeck (struct deck* d, struct card* c) {
    struct elem* element = malloc(sizeof(struct elem));
    element->elem = c;
    element->nextElem = NULL;
    if (d->firstElem == NULL) {
        d->firstElem = element;
        return;
    }

    struct elem* lastElement = d->firstElem;
    while (lastElement->nextElem != NULL) {
        lastElement = lastElement->nextElem;
    }
    lastElement->nextElem = element;
}

void RemoveCardInDeck (struct deck* d, int index) {
    if (index < 0 || index > CountCardInDeck(d)) {
        printf("Index out of range");
        return;
    }
    struct elem* elemDel = GetElementAt(d, index);


    if (index == 0) {
        d->firstElem = GetElementAt(d, 1);
    }else if (index == CountCardInDeck(d)-1) {
        GetElementAt(d, index - 1)->nextElem = NULL;
    }
    else {
        GetElementAt(d, index - 1)->nextElem = GetElementAt(d, index + 1);
    }
    free(elemDel);
}

struct card *GetCardInDeck (struct deck* d, int index) {
    if (index < 0 || index > CountCardInDeck(d)) {
        printf("Index out of range");
        return NULL;
    }
    return GetElementAt(d, index)->elem;
}



struct card* PopCardInDeck (struct deck* d) {
    struct elem* e = d->elem;
    d->firstElem = d->nextElem;
    return e->elem;

}


