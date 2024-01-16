package bo;

public class Ship {
    protected String name;
    protected String id;
    protected int length;
    protected int startRow;
    protected int startCol;
    protected int endRow;
    protected int endCol;
    protected PlayerBoard playerBoard;

    protected boolean isSunk = false;

    public final int A_ASCII_VALUE = 65;

    public Ship(String name, String id, int length, String beginning, String ending, PlayerBoard playerBoard) {
        this.name = name;
        this.id = id;
        this.length = length;

        // Calculs des positions
        this.startRow = beginning.charAt(0) - A_ASCII_VALUE;
        this.endRow = ending.charAt(0) - A_ASCII_VALUE;
        this.startCol = Integer.parseInt(beginning.replaceAll("^[0-9]", "")) - 1;
        this.endCol = Integer.parseInt(ending.replaceAll("^[0-9]", "")) - 1;

        this.playerBoard = playerBoard;
    }

    public void checkIfSunk() {
        int hitCounter = 0;

        // Check la position (Horizontale, Verticale)
        if(startRow==endRow)
            System.out.println("Le systeme est horizontale");
        if(startCol==endCol)
            System.out.println("Le systeme est verticale");
        //      Bouclé sur le bateau
        //          Si la case est égal à "T"
        //              hitCounter++
        //      Si hitCounter est égale à la longueur du bateau
        //          isSunk = true


    }
}
