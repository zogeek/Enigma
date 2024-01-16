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

void menu(SDL_Renderer *renderer) {
  // Chargement de l'image
  SDL_Surface *image = IMG_Load("../main_menu_background.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

  // Définition de la texture comme fond
  SDL_RenderCopy(renderer, texture, NULL, NULL);

  // Chargement de l'image du bouton
  SDL_Surface *button_surface = IMG_Load("../start.png");
  SDL_Texture *button_texture = SDL_CreateTextureFromSurface(renderer, button_surface);

  // Création de la structure du bouton
  SDL_Rect button_rect = {
    .x = 220,
    .y = 300,
    .w = 200,
    .h = 200,
  };

  // Définir la taille de la police
  int font_size = 7;

  // Charger la police avec la nouvelle taille
  TTF_Font* font = TTF_OpenFont("../arial.ttf", font_size);
  if (font == NULL) {
      printf("Failed to load font: %s\n", TTF_GetError());
      // Gérer l'erreur
  }
  SDL_Color text_color;
  text_color.r = 255; // Red component
  text_color.g = 0; // Green component
  text_color.b = 0; // Blue component
  text_color.a = 255; // Alpha component (transparency)
   // Création de la surface de texte
  SDL_Surface *text_surface = TTF_RenderText_Solid(font, "Main Menu", text_color);

  // Création de la texture du texte
  SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

  // Destruction de la surface de texte
  SDL_FreeSurface(text_surface);


  // Boucle principale
  while (true) {
    // Mise à jour de l'état de la SDL
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        return 0;
      }
      SDL_Point point = { event.button.x, event.button.y };
      if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT &&
          SDL_PointInRect(&point, &button_rect)) {
        gameloop(renderer);
      }
    }
    // Affichage du texte
    SDL_RenderCopy(renderer, text_texture, NULL, NULL);
    // Affichage de l'image du bouton
    SDL_RenderCopy(renderer, button_texture, NULL, &button_rect);
    // Affichage de la fenêtre
    SDL_RenderPresent(renderer);
  }

}