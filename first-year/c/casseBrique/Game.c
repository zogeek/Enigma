//
// Created by ziyad on 04/12/2023.
//

#include "Game.h"
#include "keyboardinput.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>


void game(SDL_Renderer *renderer) {
    SDL_bool quit = false;
    SDL_Event event;

    struct ball b = {50,50,25,25,1,1 };
    struct player p = {270,450,10,100,5 };
    struct brick br[10][3];
    int brick_h = 15;
    int brick_w = 52.5;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            br[i][j].h = brick_h;
            br[i][j].w = brick_w;
            br[i][j].x = i * brick_w*1.2 + 10;
            br[i][j].y = j * brick_h*2 + 20;
            br[i][j].life = 1;
        }
    }

    int lastTimer = SDL_GetTicks();

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }else {
                void eventPlayer(SDL_Event *event);
            }
        }

        if (b.x > 640 - b.w) {
            b.x = 640 - b.w - 1;
            b.speedX = -b.speedX;
        }else if (b.x < 0) {
            b.x = 1;
            b.speedX = -b.speedX;
        }else if (b.y > 480 - b.h) {
            b.y = 480 - b.w - 1;
            b.speedY = -b.speedY;
        }else if (b.y < 0) {
            b.y = 1;
            b.speedY = -b.speedY;
        }

        if (SDL_GetTicks() - lastTimer > 10) {
            b.x += b.speedX;
            b.y += b.speedY;
            lastTimer = SDL_GetTicks();
        }

        if (p.x > 640 - p.w) {
            p.x = 0;
        }else if (p.x < 0) {
            p.x = 640 - p.w;
        }

        if(p.y < b.y + b.h && b.x < p.x + p.w && p.x +- p.w < b.x + b.w ){
            b.speedY = -b.speedY;
        }

        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 3; j++) {
                SDL_SetRenderDrawColor(renderer,0 ,255 , 0,255 );
                SDL_Rect brick = { br[i][j].x, br[i][j].y, br[i][j].w,br[i][j].h };
                SDL_RenderFillRect(renderer, &brick);
            }
        }



        /*
        // Chargement de l'image
        SDL_Surface *image = IMG_Load("../data/img/background.jpg");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
        // Définition de la texture comme fond
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        */


        SDL_Rect playerRect = {p.x,p.y,p.w,p.h};
        SDL_SetRenderDrawColor(renderer,0,255,0,255);
        SDL_RenderFillRect(renderer,&playerRect);
        SDL_Rect ballRect = {b.x,b.y,b.w,b.h};
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderFillRect(renderer,&ballRect);

        SDL_RenderPresent(renderer);
    }
}