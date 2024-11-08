package bo;

import java.util.Random;
import java.util.Scanner;

public class Ship{
    private static int x;
    private static int y;
    protected static int size = 0;
    private final String name;
    private static String direction = null;
    private double[][] grille;
    private static char id;

    public static int getX() {
        return x;
    }

    public static void setX(int x) {
        Ship.x = x;
    }

    public static int getY() {
        return y;
    }

    public static void setY(int y) {
        Ship.y = y;
    }

    public static int getSize() {
        return size;
    }

    public static void setSize(int size) {
        Ship.size = size;
    }

    public String getName() {
        return name;
    }

    public static char getId() {
        return id;
    }

    public static void setId(char id) {
        Ship.id = id;
    }

    public Ship(String name, int size, char id, String direction) {
        this.name = name;
        Ship.size = size;
        Ship.direction = direction; // h ou v
    }

/*
    public static void ajtBat(Ship Ship){
        int x =0;
        int y = 0;
        boolean result = false;
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.println("Entrez les coordonnées de votre bateau");
            System.out.println("x : ");
            x = scanner.nextInt();
            System.out.println("y : ");
            y = scanner.nextInt();
            System.out.println("Entrez l'orientation de votre bateau");
            System.out.println("h : horizontal");
            System.out.println("v : vertical");
            String orientation = scanner.next();
            if (orientation.equals("h")) {
                if (x + Ship.getSize() > 10) {
                    System.out.println("Votre bateau ne peut pas être placé ici");
                } else {
                    result = true;
                }
            } else if (orientation.equals("v")) {
                if (y + Ship.getSize() > 10) {
                    System.out.println("Votre bateau ne peut pas être placé ici");
                } else {
                    result = true;
                }
            } else {
                System.out.println("Votre bateau ne peut pas être placé ici");
            }
        } while (!result);
    }


    public boolean placerNavire(Ship navire, int x, int y, boolean horizontal) {

        for (int i = 0; i < Ship.getSize(); i++) {
            int newX = horizontal ? x + i : x;
            int newY = horizontal ? y : y + i;

            if (newX < 0 || newX >= size || newY < 0 || newY >= size || grille[newX][newY] != '~') {
                return false;  // L'emplacement n'est pas valide
            }
        }

        // Placez le navire sur la carte
        for (int i = 0; i < Ship.getSize(); i++) {
            int newX = horizontal ? x + i : x;
            int newY = horizontal ? y : y + i;

            grille[newX][newY] = 'O';  // Marquez la case comme occupée par un navire
        }

        return true;
    }


*/



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
                            J.Plateau1.Carte[y1][Y] = id;
                        }
                    }
                    if (sens == 1){
                        for (int y1 = X; y1<X + bo.Ship.size; y1++){
                            J.p1.Carte[y1][Y] = id;
                        }
                    }
                    result = true;
                }
            }

        }while (!result);
    }
}


