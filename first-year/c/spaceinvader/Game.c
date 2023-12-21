//
// Created by ziyad on 01/12/2023.
//

#include "Game.h"
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createRock(SDL_Renderer *renderer, struct rock r) {
    SDL_Rect Rockrect = {r.x,r.y,r.w,r.h};
    SDL_SetRenderDrawColor(renderer,0,255,0,255);
    SDL_RenderFillRect(renderer,&Rockrect);
}



void gameloop(SDL_Renderer *renderer) {
    SDL_bool quit = false;
    SDL_Event event;
    int rand_x = rand() % 640;

    struct spaceship s = {350,350,50,50,6 };
    struct rock r1 = {rand_x,0,50,50,7,true };

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
                s.y = s.y + s.speed;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_z) {
                s.y = s.y - s.speed;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) {
                s.x = s.x - s.speed;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d) {
                s.x = s.x + s.speed;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP) {
                s.y = s.y - s.speed;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN) {
                s.y = s.y + s.speed;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT) {
                s.x = s.x - s.speed;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT) {
                s.x = s.x + s.speed;
            }
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        if (s.x + s.w + s.speed > 640 || s.x + s.speed < 0) {
            s.x = 640 - s.w;
        }
        if (s.y + s.h > 480) {
            s.y = 480 - s.h;
        }
        if (s.y + s.speed < 0) {
            s.y = 1;
        }
        if (SDL_GetTicks() - lastTimer > 1000/60) {
            r1.y = r1.y + r1.speed;
            lastTimer = SDL_GetTicks();
        }
        int size = 30;
        struct rock r[size];

        initRockArray(r, size);
        renderRockArray(renderer,r,30);
        renderSpaceship(renderer,s);


        SDL_RenderPresent(renderer);


    }


}

void render(SDL_Renderer *renderer, struct spaceship *s, struct rock *r) {
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    renderSpaceship(renderer,*s);
    renderRockArray(renderer,r,30);

    SDL_RenderPresent(renderer);
}

void renderSpaceship(SDL_Renderer *renderer, struct spaceship s) {
    SDL_Rect spaceshipRect = {s.x,s.y,s.w,s.h};
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer,&spaceshipRect);
}




/*bool isColide (struct spaceship s, struct rock r) {
    bool xColide = (rectA.x < rectB.x + rectB.w) && (rectA.x + rectA.w > rectB.x
        || (rectB.x < rectA.x + rectA.w) && (rectB.x + rectB.w > rectA.x));
    bool yColide = (rectA.y < rectB.y + rectB.h) && (rectA.y + rectA.h > rectB.y
        || (rectB.y < rectA.y + rectA.h) && (rectB.y + rectB.h > rectA.y));
    return xColide && yColide;
}*/

void initRockArray(struct rock *r, int size) {
    for (int i = 0; i < size; ++i) {
        r[i].Exist = false;
    }
}

void verifRock(struct rock *r, int size) {
    for (int i = 0; i < size; ++i ) {
        if (r[i].Exist == true && r[i].y > 480) {
            r[i].Exist = false;
        }
    }
}


void renderRockArray(SDL_Renderer *renderer,struct rock *r, int size) {
    for (int i = 0; i < size; ++i) {
        if (r[i].Exist == true) {
            createRock(renderer,r[i]);
        }
    }
}



void randomRock(struct rock *r) {
    int rand_x = rand() % 640;
    int rand_time = rand();

}