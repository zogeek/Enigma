#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Configuration de la matrice LED
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4
#define CS_PIN 16
#define DATA_PIN 4
#define CLK_PIN 17

// Initialisation de l'objet Parola
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Position initiale du point lumineux
int x = 0;  // Colonne
int y = 0;  // Ligne

// Pins des boutons
const int BTN_UP = 13;
const int BTN_DOWN = 14;
const int BTN_LEFT = 26;
const int BTN_RIGHT = 27;

// Initialisation des directions
int direction = 0;  // Pas de mouvement par défaut

void setup() {
  Serial.begin(115200);
  Serial.println("Initialisation...");
  
  // Initialisation des boutons
  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);
  pinMode(BTN_LEFT, INPUT);
  pinMode(BTN_RIGHT, INPUT);

  // Initialisation de la matrice LED
  P.begin();
  P.setIntensity(5);  // Réglage de la luminosité (0-15)
  P.displayClear();
}

void loop() {
  // Détecter quelle direction est activée
  if (digitalRead(BTN_UP) == HIGH) {
    direction = 1;  // Haut
  } else if (digitalRead(BTN_DOWN) == HIGH) {
    direction = 2;  // Bas
  } else if (digitalRead(BTN_LEFT) == HIGH) {
    direction = 3;  // Gauche
  } else if (digitalRead(BTN_RIGHT) == HIGH) {
    direction = 4;  // Droite
  } else {
    direction = 0;  // Pas de mouvement
  }

  // Utiliser un switch pour gérer les directions
  switch (direction) {
    case 1:  // Haut
      if (y > 0) y--;
      break;
    case 2:  // Bas
      if (y < 7) y++;
      break;
    case 3:  // Gauche
      if (x > 0) x--;
      break;
    case 4:  // Droite
      if (x < 31) x++;
      break;
    default:  // Pas de mouvement
      break;
  }

  // Mise à jour de l'affichage
  P.displayClear();
  P.setPoint(y, x, true);  // Allume la LED à la position (y, x)

  // Pause pour limiter la vitesse du mouvement
  delay(200);
}
wo