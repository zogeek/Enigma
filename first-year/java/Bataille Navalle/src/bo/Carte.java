package bo;

public class Carte {
    private int size;
    private String[][] grille;

    protected final int A_ASCII_VALUE = 65;

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public String[][] getGrille() {
        return grille;
    }

    public void setGrille(String[][] grille) {
        this.grille = grille;
    }

    public Carte(int size){
        this.size = size;
        this.grille = new String[size][size];
        initGrille();
    }
    public void initGrille() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grille[i][j] = ".";
            }
        }
    }
    public void printBoard() {
        System.out.println("  1 2 3 4 5 6 7 8 9 10");
        int asciiValue = A_ASCII_VALUE;
        for(int i = 0; i < size; i++) {
            System.out.print((char) asciiValue + " ");
            asciiValue++;
            for(int j = 0; j < size; j++) {
                System.out.print(grille[i][j] + " ");
            }
            System.out.print("\n");
        }
    }
}
