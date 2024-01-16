//
// Created by ziyad on 04/12/2023.
//

#include "Game.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>


void game(SDL_Renderer *renderer, int difficulty) {
    SDL_bool quit = false;
    SDL_Event event;


    int bonusActive = 0;
    int bonusTimer = 0;
    struct ball b = {200,200,25,25,1,1 , 1 };
    struct player p = {270,450,10,100,5,3 };
    if(difficulty == 0) {
        p.w = 150;
        b.speedX = 0.5;
        b.speedY = 0.5;
    }
    if(difficulty == 1) {
        p.w = 100;
        b.speedX = 1;
        b.speedY = 1;
    }
    if(difficulty == 2) {
        p.w = 50;
        b.speedX = 2;
        b.speedY = 2;
    }
    struct brick br[10][3];
    int brick_h = 15;
    int brick_w = 52.5;




    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            br[i][j].h = brick_h;
            br[i][j].w = brick_w;
            br[i][j].x = i * brick_w*1.2 + 10;
            br[i][j].y = j * brick_h*2 + 20;
            br[i][j].life = rand() % 3 + 1;  // Set the brick's life to a random number between 1 and 3
        }
    }

    int lastTimer = SDL_GetTicks();

    while (!quit) {
        bool keyLeft = false;
        bool keyRight = false;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
                break;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) {
                keyLeft = true;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d) {
                keyRight = true;
            }
        }
        if(keyRight == true){
            p.x += p.speed;
        }else
        if(keyLeft == true){
            p.x -= p.speed;
        }

        if (b.x > 640 - b.w) {
            b.x = 640 - b.w - 1;
            b.speedX = -b.speedX;
        }else if (b.x < 0) {
            b.x = 1;
            b.speedX = -b.speedX;
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

        if(p.y < b.y + b.h && b.x < p.x + p.w && p.x + p.w > b.x){
            b.speedY = -b.speedY;
            // Change la direction de la balle en fonction de l'endroit où elle frappe la raquette
            b.speedX = ((b.x + b.w / 2) - (p.x + p.w / 2)) / (p.w / 2);
            // Place la balle au-dessus du joueur
            b.y = p.y - b.h;
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);


        for (int i = 0; i < p.life; i++) {
            SDL_Rect lifeRect = {10 + i * 20, 10, 10, 10}; // Chaque carré a une taille de 10x10 et ils sont espacés de 10 pixels
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Couleur rouge
            SDL_RenderFillRect(renderer, &lifeRect);
        }

        int score = 0;
        int bricksLeft = 10 * 3;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 3; j++) {
                if (br[i][j].life > 0) {
                    if (b.x < br[i][j].x + brick_w &&
                        b.x + b.w > br[i][j].x &&
                        b.y < br[i][j].y + brick_h &&
                        b.y + b.h > br[i][j].y) {
                        b.speedY = -b.speedY;

                        br[i][j].life = br[i][j].life - b.damage;  // Decrease the brick's life by the ball's damage
                        score += 100;
                        bricksLeft--;
                        // Adjust ball position
                        if (b.speedY > 0) {
                            b.y = br[i][j].y + brick_h;
                        } else {
                            b.y = br[i][j].y - b.h;
                        }
                        }
                }
            }
        }

        // Draw bricks
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 3; j++) {
                if (br[i][j].life > 0) {  // Only draw the brick if its life is greater than 0
                    switch(br[i][j].life) {
                        case 1:
                            SDL_SetRenderDrawColor(renderer,0 ,255 , 0,255 ); // Vert pour 1 vie
                        break;
                        case 2:
                            SDL_SetRenderDrawColor(renderer,0 ,0 , 255,255 ); // Bleu pour 2 vies
                        break;
                        case 3:
                            SDL_SetRenderDrawColor(renderer,255 ,0 , 0,255 ); // Rouge pour 3 vies
                        break;
                        default:
                            SDL_SetRenderDrawColor(renderer,255 ,255 , 255,255 ); // Blanc pour les autres cas
                        break;
                    }
                    SDL_Rect brick = { br[i][j].x, br[i][j].y, br[i][j].w,br[i][j].h };
                    SDL_RenderFillRect(renderer, &brick);
                }
            }
        }
        if (b.y > 480) {
            p.life--;
            b.x = 200;
            b.y = 200;
            b.speedX = 1;
            b.speedY = 1;
        }

if(p.life == 0) {
    SDL_RenderClear(renderer);
    nolife(renderer);
    quit = true;
    break;
}





        SDL_Rect playerRect = {p.x,p.y,p.w,p.h};
        SDL_SetRenderDrawColor(renderer,0,255,0,255);
        SDL_RenderFillRect(renderer,&playerRect);
        SDL_Rect ballRect = {b.x,b.y,b.w,b.h};
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderFillRect(renderer,&ballRect);

        SDL_RenderPresent(renderer);
    }
}


void nolife(SDL_Renderer* renderer){

    SDL_Rect gameover_rect = {
        .x = 0,
        .y = 0,
        .w = 640,
        .h = 480,
    };

    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                return;
            }

        }

        // Chargement de l'image
        SDL_Surface *image = IMG_Load("../data/img/background.jpg");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

        // Définition de la texture comme fond
        SDL_RenderCopy(renderer, texture, NULL, NULL);

        //afichage de la texture game over
        SDL_Surface *gameover_surface = IMG_Load("../data/img/gameover.png");
        SDL_Texture *gameover_texture = SDL_CreateTextureFromSurface(renderer, gameover_surface);

        SDL_RenderCopy(renderer, gameover_texture, NULL, &gameover_rect);



        // Affichage de la fenêtre
        SDL_RenderPresent(renderer);
    }
}