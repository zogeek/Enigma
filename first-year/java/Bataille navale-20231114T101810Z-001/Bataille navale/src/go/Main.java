package go;
import bo.Player;

import java.util.Scanner;
import bo.*;

public class Main {
    public final int CARRIER_LENGTH = 5;
    public final int BATTLESHIP_LENGTH = 4;
    public final int CRUISER_LENGTH = 3;
    public final int DESTROYER_LENGTH = 2;
    public final int A_ASCII_VALUE = 65;
    public final int TOTAL_SHIPS = 5;
    // Initialiser le scanner
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Bienvenue sur la Bataille Navale !\n");
        Player player1 = new Player("Player 1");
        Player player2 = new Player("Player 2");
        player1.playerBoard.printPlayerBoard();

        // lancer la fonction de jeu avec le joueur 1 et joueur 2 comme paramètres


    }

    // fonction selectShips

    // fonction isValidCoordinates

    // fonction isValidAttack
}
