//
// Created by ziyad on 04/12/2023.
//

#ifndef GAME_H
#define GAME_H

#endif //GAME_H
#include <SDL.h>
struct brick {
    int x;
    int y;
    int h;
    int w;
    int life;
};

struct ball {
    int x;
    int y;
    int h;
    int w;
    int speedX;
    int speedY;
};

struct player {
    int x;
    int y;
    int h;
    int w;
    int speed;
};

void game(SDL_Renderer *renderer);