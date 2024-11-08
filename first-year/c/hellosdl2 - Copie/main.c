//
// Created by ziyad on 01/12/2023.
//
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


struct ball {
    int x;
    int y;
    int h;
    int w;

    int speedX;
    int speedY;
};
void gameloop(SDL_Renderer *renderer) {
    SDL_bool quit = false;
    SDL_Event event;

    struct ball b = {50,50,50,50,1,1 };
    struct ball b2 = {300,300,50,50,1,1 };

    int lastTimer = SDL_GetTicks();

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                    break;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s) {
                b.y = b.y + b.speedY;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_z) {
                b.y = b.y - b.speedY;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) {
                b.x = b.x - b.speedX;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d) {
                b.x = b.x + b.speedX;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP) {
                b.y = b.y - b.speedY;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN) {
                b.y = b.y + b.speedY;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT) {
                b.x = b.x - b.speedX;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT) {
                b.x = b.x + b.speedX;
            }
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        if (b.x + b.w + b.speedX > 640 || b.x + b.speedX < 0) {
            b.speedX *= -1;
        }
        if (b.y + b.h > 480 || b.y < 0) {
            b.speedY *= -1;
        }
        if (SDL_GetTicks() - lastTimer > 1000/60) {
            b2.x = b2.x + b2.speedX;
            b2.y = b2.y + b2.speedY;
            lastTimer = SDL_GetTicks();

        }



        SDL_Rect ballRect = {b.x,b.y,b.w,b.h};
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderFillRect(renderer,&ballRect);

        if (SDL_GetTicks() - lastTimer > 1000/60) {
            b2.x = b2.x + b2.speedX;
            b2.y = b2.y + b2.speedY;
            lastTimer = SDL_GetTicks();
        }
        if (b2.x + b2.w > 640 || b2.x  < 0) {
            b2.speedX *= -1;
        }
        if (b2.y + b2.h > 480 || b2.y < 0) {
            b2.speedY *= -1;
        }

        if( b.x + b.w > b2.x && b.x < b2.x + b2.w && b.y + b.h > b2.y && b.y < b2.y + b2.h) {
            b.speedX *= -1;
            b.speedY *= -1;
            b2.speedX *= -1;
            b2.speedY *= -1;
        }

        SDL_Rect ballRect2 = {b2.x,b2.y,b2.w,b2.h};
        SDL_SetRenderDrawColor(renderer,0,255,0,255);
        SDL_RenderFillRect(renderer,&ballRect2);

        SDL_RenderPresent(renderer);


    }


}

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if (NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == renderer) {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    gameloop(renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}