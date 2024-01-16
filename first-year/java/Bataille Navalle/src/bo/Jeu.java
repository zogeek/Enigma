package bo;

import java.util.Random;
import java.util.Scanner;



public class Jeu {
    public int Random(int num){
        Random r = new Random();
        return r.nextInt(num);
    }
    public void ajtBoat(Ship Ship, Player J){
        int X = 0;
        int Y = 0;
        int sens = 0;
        boolean result = false;
        do {
            X = Random(10);
            Y = Random(10);
            sens = Random(1);
            if (X + bo.Ship.size < 10){
                if (Y+bo.Ship.size<10){
                    if (sens == 0){
                        for (int y1 = X; y1<X + bo.Ship.size; y1++){
                            J.getPlateau1[y1][Y] = bo.Ship.getId();
                        }
                    }
                    if (sens == 1){
                        for (int y1 = X; y1<X + bo.Ship.size; y1++){
                            J.p1.Carte[y1][Y] = bo.Ship.getId();
                        }
                    }
                    result = true;
                }
            }

        }while (!result);


    }
    public static void Game() {


        Carte carte = new Carte(10);
        carte.printBoard();
        Player player1 = new Player("Player1");
        Player player2 = new Player("Player2");
        Ship Ship = new Ship("porte-avion", 5, 'P', null);
        Ship Ship2 = new Ship("croiseur", 4, 'C', null);
        Ship Ship3 = new Ship("contre-torpilleur", 3, 'T', null);
        Ship Ship4 = new Ship("sous-marin", 3, 'S', null);
        Ship Ship5 = new Ship("torpilleur", 2, 'T', null);








        Scanner scanner = new Scanner(System.in);
        System.out.print("Ecrire un nombre: ");
        int nombre = scanner.nextInt();
        System.out.println(nombre);









//        System.out.println("Player1, placez vos bateaux");
//        placeBateaux(carte, player1);
//        System.out.println("Player2, placez vos bateaux");
//        placeBateaux(carte, player2);
//        System.out.println("Player1, c'est à vous");
//        System.out.println("Player2, c'est à vous");



    }
}
