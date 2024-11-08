//
// Created by ziyad on 30/11/2023.
//

#ifndef DECK_H
#define DECK_H

#endif //DECK_H

struct card {
    int value;
    char color;
};

struct elem {
    struct card* elem;
    struct deck* nextElem;
};

struct deck {
    struct elem* firstElem;
};

int CountCardInDeck (struct deck* d);
void AddCardInDeck (struct deck* d, struct card* card);
void RemoveCardInDeck (struct deck* d, int index);
struct card *GetCardInDeck (struct deck* d, int index);
struct card* PopCardInDeck (struct deck* d);