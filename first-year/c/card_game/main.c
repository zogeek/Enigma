#include <stdio.h>
#include <stdlib.h>


struct Cartes {
    char valeur;
    char couleur;
};

struct Jeu {
    struct Cartes* carte;
    struct Elem* nextElem;
};

void addElement(struct Jeu* jeu, struct Cartes* carte) {
    struct Jeu* elem = (struct Jeu*)malloc(sizeof(struct Jeu));
    elem->carte = carte;
    elem->nextElem = jeu->nextElem;
    jeu->nextElem = elem;
}

void Game() {
    char signe[4] = {'C', 'P', 'K', 'T'};
    char numero[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'V', 'D', 'R'};
    struct Jeu* jeu = NULL;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            struct Cartes* carte = (struct Cartes*)malloc(sizeof(struct Cartes));
            carte->valeur = j;
            carte->couleur = i;
            struct Jeu* elem = (struct Jeu*)malloc(sizeof(struct Jeu));
            elem->carte = carte;
            elem->nextElem = jeu;
            jeu = elem;
        }
    }
    printf("Jeu de cartes : \n");
    struct Jeu* tmp = jeu;
    while (tmp != NULL) {
        printf("%s de %s\n", numero[tmp->carte->valeur], signe[tmp->carte->couleur]);
        tmp = tmp->nextElem;
    }
    printf("\n");
    printf("Jeu de cartes melanges : \n");
    for (int i = 0; i < 52; i++) {
        int alea = rand() % (52 - i);
        struct Jeu* tmp = jeu;
        for (int j = 0; j < alea; j++) {
            tmp = tmp->nextElem;
        }
        printf("%s de %s\n", numero[tmp->carte->valeur], signe[tmp->carte->couleur]);
        tmp->carte->valeur = jeu->carte->valeur;
        tmp->carte->couleur = jeu->carte->couleur;
        jeu->carte->valeur = tmp->carte->valeur;
        jeu->carte->couleur = tmp->carte->couleur;
        jeu = jeu->nextElem;
    }
    printf("\n");
    printf("Jeu de cartes triees : \n");
    for (int i = 0; i < 52; i++) {
        struct Jeu* tmp = jeu;
        for (int j = 0; j < i; j++) {
            tmp = tmp->nextElem;
        }
        printf("%s de %s\n", numero[tmp->carte->valeur], signe[tmp->carte->couleur]);
    }
    printf("\n");
    printf("Jeu de cartes distribue : \n");
}



int main() {
    Game();
    return 0;
}