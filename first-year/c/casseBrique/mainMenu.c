//
// Created by ziyad on 04/12/2023.
//
#include "Mainmenu.h"
#include <SDL.h>
#include <stdbool.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Game.h"

int menu(SDL_Renderer* renderer){
    // Chargement de l'image
    SDL_Surface *image = IMG_Load("../data/img/background.jpg");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

    // Définition de la texture comme fond
    SDL_RenderCopy(renderer, texture, NULL, NULL);

        // Chargement de l'image du bouton play
    SDL_Surface *button_play_surface = IMG_Load("../data/img/play.png");
    SDL_Texture *button_play_texture = SDL_CreateTextureFromSurface(renderer, button_play_surface);

        // Chargement de l'image du bouton options
    SDL_Surface *button_options_surface = IMG_Load("../data/img/options.png");
    SDL_Texture *button_options_texture = SDL_CreateTextureFromSurface(renderer, button_options_surface);

    // Chargement de l'image du bouton exit
    SDL_Surface *button_exit_surface = IMG_Load("../data/img/exit.png");
    SDL_Texture *button_exit_texture = SDL_CreateTextureFromSurface(renderer, button_exit_surface);



    // Création de la structure du bouton play
    SDL_Rect button_rect_play = {
        .x = 195,
        .y = 100,
        .w = 250,
        .h = 90,
    };
        // Création de la structure du bouton options
    SDL_Rect button_rect_options = {
        .x = 195,
        .y = 200,
        .w = 250,
        .h = 90,
    };

    // Création de la structure du bouton exit
    SDL_Rect button_rect_exit = {
        .x = 195,
        .y = 300,
        .w = 250,
        .h = 90,
    };





    // Boucle principale
    while (true) {
        // Mise à jour de l'état de la SDL
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 0;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                return 0;
            }else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_KP_ENTER ) {
                game(renderer);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, texture, NULL, NULL);
            }

                        SDL_Point play = { event.button.x, event.button.y };
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT &&
                    SDL_PointInRect(&play, &button_rect_play)) {
                game(renderer);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, texture, NULL, NULL);

            }
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT &&
                    SDL_PointInRect(&play, &button_rect_options)) {
                options(renderer);
            }



            SDL_Point exit = { event.button.x, event.button.y };
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT &&
                    SDL_PointInRect(&exit, &button_rect_exit)) {
                return 0;
            }
        }



        // Affichage de l'image du bouton play
        SDL_RenderCopy(renderer, button_play_texture, NULL, &button_rect_play);

        // Affichage de l'image du bouton options
        SDL_RenderCopy(renderer, button_options_texture, NULL, &button_rect_options);

        // Affichage de l'image du bouton exit
        SDL_RenderCopy(renderer, button_exit_texture, NULL, &button_rect_exit);
        // Affichage de la fenêtre
        SDL_RenderPresent(renderer);
    }

}

void options(SDL_Renderer *renderer) {
    // Chargement de l'image
    SDL_Surface *image = IMG_Load("../data/img/background.jpg");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

    // Définition de la texture comme fond
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}