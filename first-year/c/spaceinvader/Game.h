//
// Created by ziyad on 01/12/2023.
//

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <stdbool.h>

#endif //GAME_H
struct color {
    int r;
    int g;
    int b;
    int a;
};

struct spaceship {
    int x;
    int y;
    int h;
    int w;

    int speed;
};

struct rock {
    int x;
    int y;
    int h;
    int w;

    int speed;
    bool Exist;
};

void gameloop(SDL_Renderer *renderer);
void render(SDL_Renderer *renderer, struct spaceship *s, struct rock *r);
bool isColide (struct spaceship s, struct rock r);
void renderSpaceship(SDL_Renderer *renderer, struct spaceship s);
void renderRockArray(SDL_Renderer *renderer, struct rock *r, int size);
void initRockArray(struct rock *r, int size);

int Game();