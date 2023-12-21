//
// Created by ziyad on 08/12/2023.
//

#include "keyboardinput.h"
#include <SDL.h>
#include <stdbool.h>

bool keyLeft = false;
bool keyRight = false;

void eventPlayer(SDL_Event *event) {
    switch (event->type) {
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym) {
                case SDLK_ESCAPE:
                    SDL_Quit();
                exit(0);
                case SDLK_d:
                    keyRight = true;
                break;
                case SDLK_q:
                    keyLeft = true;
                break;
            }
        break;
        case SDL_KEYUP:
            switch (event->key.keysym.sym) {
                case SDLK_d:
                    keyRight = false;
                break;
                case SDLK_q:
                    keyLeft = false;
                break;
            }
        break;
    }
}