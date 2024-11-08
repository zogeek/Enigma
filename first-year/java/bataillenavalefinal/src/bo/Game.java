package bo;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Game {
    private Player player1;
    private Player player2;
    private List<Ship> ships;

    //Initialise la game avec 5 navires de tailles différentes
    public Game() {
        this.ships = new ArrayList<>();
        ships.add(new Ship(5, 'P'));
        ships.add(new Ship(4, 'C'));
        ships.add(new Ship(3, 'T'));
        ships.add(new Ship(3, 'S'));
        ships.add(new Ship(2, 't'));

        this.player1 = new Player("Player 1", ships);
        this.player2 = new Player("Player 2", ships);
    }

    public void start() {
        System.out.println("Enter 1 for player vs player or 2 for player vs robot:");
        Scanner scanner = new Scanner(System.in);
        int gameMode = scanner.nextInt();
        if (gameMode == 1) {
            play(false);
        } else {
            play(true);
        }
    }

    private void play(boolean isPlayer2Robot) {
        player1.placeautoShips();
        if (isPlayer2Robot) {
            player2.placeautoShips();
        } else {
            player2.placeShips();
        }

        while (true) {
            takeTurn(player1, player2);
            if (player2.hasLost()) {
                System.out.println("Player 1 wins!");
                break;
            }

            if (isPlayer2Robot) {
                takeAutoTurn(player2, player1);
            } else {
                takeTurn(player2, player1);
            }
            if (player1.hasLost()) {
                System.out.println("Player 2 wins!");
                break;
            }
        }
    }

    private void takeAutoTurn(Player activePlayer, Player opponent) {
        int x = (int) (Math.random() * opponent.getBoard().getSize());
        int y = (int) (Math.random() * opponent.getBoard().getSize());

        if (opponent.getBoard().isHit(x, y)) {
            activePlayer.getAttackBoard().markShot(x, y, 'T');
        } else {
            activePlayer.getAttackBoard().markShot(x, y, 'W');
        }
    }

    private void takeTurn(Player activePlayer, Player opponent) {
        System.out.println("---------------------------------");
        System.out.println("Here's your opponent board:");
        opponent.getBoard().printBoard();
        System.out.println("Here's your board:");
        activePlayer.getBoard().printBoard();
        Scanner scanner = new Scanner(System.in);

        System.out.println(activePlayer.getName() + ", it's your turn.");
        System.out.println("Enter the x-coordinate of your shot:");
        int x = scanner.nextInt();
        System.out.println("Enter the y-coordinate of your shot:");
        int y = scanner.nextInt();

        if (opponent.getBoard().isHit(x, y)) {
            System.out.println("You hit a ship!");
            activePlayer.getAttackBoard().markShot(x, y, 'T');
            // Vérifiez si le navire est coulé et marquez-le comme 'C' si c'est le cas
        } else {
            System.out.println("You missed.");
            activePlayer.getAttackBoard().markShot(x, y, 'W');
        }
        System.out.println("Here's your attack board:");
        activePlayer.getAttackBoard().printBoard();
    }
}