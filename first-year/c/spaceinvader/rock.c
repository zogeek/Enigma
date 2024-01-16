//
// Created by ziyad on 01/12/2023.
//
#include "rock.h"
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct rock {
    int x;
    int y;
    int h;
    int w;
};
void rock(SDL_Renderer *renderer){

    SDL_Rect rock = {50,50,50,50};
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&rock);




};