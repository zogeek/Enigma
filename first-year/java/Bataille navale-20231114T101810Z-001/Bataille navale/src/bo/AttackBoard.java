package bo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class AttackBoard {

    protected final int BOARD_SIZE = 10;
    protected final int A_ASCII_VALUE = 65;

    protected String[][] Board = new String[BOARD_SIZE][BOARD_SIZE];

    public AttackBoard() {
        for (String[] Row: Board) {
            Arrays.fill(Row, "~");
        }
    }

    public void attack(String attackCoordinate, String attackSymbol) {
        int Row = attackCoordinate.charAt(0) - A_ASCII_VALUE;
        int Col = Integer.parseInt(attackCoordinate.replaceAll("^[0-9]", "")) - 1;
        Board[Row][Col] = attackSymbol;
    }

    public void printAttackBoard() {
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
}
