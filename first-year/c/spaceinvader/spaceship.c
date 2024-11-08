//
// Created by ziyad on 01/12/2023.
//

#include "spaceship.h"
#include "rock.h"
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct spaceship {
    int x;
    int y;
    int h;
    int w;
};

void spaceship(SDL_Renderer *renderer){
    struct spaceship s = {50,50,50,50};
    SDL_Rect spaceship = {s.x,s.y,s.w,s.h};
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&spaceship);
    SDL_RenderPresent(renderer);



};