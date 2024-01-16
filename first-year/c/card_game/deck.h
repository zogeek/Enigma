//
// Created by ziyad on 30/11/2023.
//
#ifndef CARDPACK_DECK_H
#define CARDPACK_DECK_H

#endif //CARDPACK_DECK_H



struct card {
    int value;
    char* color;
};

struct elem{
    struct card* elem;
    struct elem* nextElem;
};

struct deck{
    struct elem* firstElem;
};

int CountCardInDeck(struct deck* d);
void AddCardInDeck(struct deck* d, struct card *c);
void RemoveCardInDeck(struct deck* d, int index);
struct card* GetCardInDeckAt(struct deck* d, int index);
struct card* PopCardInDeck(struct deck* d);
void MixDeck(struct deck* d);