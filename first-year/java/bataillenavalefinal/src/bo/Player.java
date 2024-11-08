package bo;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Player {
    private String name;
    private Board board;
    private AttackBoard attackBoard;
    private List<Ship> ships;

    public Player(String name, List<Ship> ships) {
        this.name = name;
        this.board = new Board();
        this.attackBoard = new AttackBoard();
        this.ships = new ArrayList<>(ships);
    }

    public void placeShips() {
        Scanner scanner = new Scanner(System.in);
        // Pour chaque navire dans la liste de navires
        for (Ship ship : ships) {
            boolean isPlaced = false;
            do {
                // Demandez au joueur la position du navire
                System.out.println("Enter the x position for " + ship.getRepresentation() + ":");
                int x = scanner.nextInt();
                System.out.println("Enter the y position for " + ship.getRepresentation() + ":");
                int y = scanner.nextInt();
                // Demandez au joueur l'orientation du navire
                System.out.println("Enter 0 for horizontal or 1 for vertical orientation for " + ship.getRepresentation() + ":");
                int input = scanner.nextInt();
                boolean isHorizontal = (input == 0);

                // Essayez de placer le navire à cette position
                isPlaced = board.placeShip(ship, x, y, isHorizontal);
                if (!isPlaced) {
                    System.out.println("Invalid position. Please try again.");
                }
            } while (!isPlaced);
        }
    }

    public void placeautoShips() {
        // Pour chaque navire dans la liste de navires
        for (Ship ship : ships) {
            boolean isPlaced = false;
            do {
                // Choisissez une position aléatoire pour le navire
                int x = (int) (Math.random() * board.getSize());
                int y = (int) (Math.random() * board.getSize());
                // Choisissez une orientation aléatoire pour le navire
                int input = (int) (Math.random() * 2);
                boolean isHorizontal = (input == 0);

                // Essayez de placer le navire à cette position
                isPlaced = board.placeShip(ship, x, y, isHorizontal);
            } while (!isPlaced);
        }
    }

    public boolean hasLost() {
        // Parcourez le plateau de jeu
        for (int i = 0; i < board.getSize(); i++) {
            for (int j = 0; j < board.getSize(); j++) {
                // Si une case contient un navire (c'est-à-dire, n'est pas de l'eau ou un coup manqué),
                // alors le joueur n'a pas encore perdu
                if (board.getGrid()[i][j] != '~' && board.getGrid()[i][j] != 'X') {
                    return false;
                }
            }
        }
        // Si aucune case ne contient de navire, alors le joueur a perdu
        return true;
    }

    public Board getBoard() {
        return board;
    }

    public AttackBoard getAttackBoard() {
        return attackBoard;
    }

    public String getName() {
        return name;
    }
}