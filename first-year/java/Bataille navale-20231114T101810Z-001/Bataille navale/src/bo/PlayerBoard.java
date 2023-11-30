package bo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class PlayerBoard {

    protected final int BOARD_SIZE = 10;
    protected final int A_ASCII_VALUE = 65;

    protected ArrayList<Ship> Ships;
    protected String[][] Board = new String[BOARD_SIZE][BOARD_SIZE];
    protected HashSet<String> sunkenships;

    public PlayerBoard() {
        for (String[] Row: Board) {
            Arrays.fill(Row, "~");
        }

        this.Ships = new ArrayList<>();
        this.sunkenships = new HashSet<>();
    }

    public void printPlayerBoard() {
        System.out.println("  1 2 3 4 5 6 7 8 9 10");
        int asciiValue = A_ASCII_VALUE;
        for(int i = 0; i < BOARD_SIZE; i++) {
            System.out.print((char) asciiValue + " ");
            asciiValue++;
            for(int j = 0; j < BOARD_SIZE; j++) {
                System.out.print(Board[i][j] + " ");
            }
            System.out.print("\n");
        }
    }

    public void placeShip(Ship ship, String beginning, String ending) {
        int startRow = beginning.charAt(0) - A_ASCII_VALUE;
        int endRow = ending.charAt(0) - A_ASCII_VALUE;
        int startCol = Integer.parseInt(beginning.replaceAll("^[0-9]", "")) - 1;
        int endCol = Integer.parseInt(ending.replaceAll("^[0-9]", "")) - 1;

        if (startRow > endRow) {
            int temp = startRow;
            startRow = endRow;
            endRow = temp;
        }

        if (startCol > endCol) {
            int temp = startCol;
            startCol = endCol;
            endCol = temp;
        }

        if (endRow == startRow) {
            for (int i = 0; i < BOARD_SIZE; i++) {
                Board[startRow][i] = ship.id;
            }
        }

        if (endCol == startCol) {
            for (int i = 0; i < BOARD_SIZE; i++) {
                Board[i][startCol] = ship.id;
            }
        }
    }

    public String checkAttack(String attackCoordinate) {
        int Row = attackCoordinate.charAt(0) - A_ASCII_VALUE;
        int Col = Integer.parseInt(attackCoordinate.replaceAll("^[0-9]", "")) - 1;
        String[] values = {"C", "c", "S", "D", "B"};

        if (Arrays.stream(values).anyMatch(v -> v == Board[Row][Col])) {
            System.out.println("Touché");
            Board[Row][Col] = "T";
            return "T";
        } else {
            System.out.println("Manqué");
            Board[Row][Col] = "W";
            return "W";
        }
    }


    public boolean checkGameOver() {
        int sunkCounter = 0;

        for (Ship i : Ships) {
            i.checkIfSunk();
            if (i.isSunk) {
                sunkCounter++;
                sunkenships.add(i.name);
            }
        }

        return sunkCounter == 5;

    }

}
