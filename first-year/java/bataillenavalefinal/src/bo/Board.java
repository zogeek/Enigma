package bo;



public class Board {
    private char[][] grid;
    private static final int SIZE = 10;
    private boolean orientation;

    public Board() {
        this.grid = new char[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = '~'; // '~' représente l'eau
            }
        }
    }

    public boolean placeShip(Ship ship, int x, int y, boolean isHorizontal) {
        // Vérifiez si la position est valide
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            // Vérifiez si la position est libre
            for (int i = 0; i < ship.getSize(); i++) {
                if (isHorizontal) {
                    if (y + i >= SIZE || grid[x][y + i] != '~') {
                        return false; // Si la position n'est pas libre, retournez false
                    }
                } else {
                    if (x + i >= SIZE || grid[x + i][y] != '~') {
                        return false; // Si la position n'est pas libre, retournez false
                    }
                }
            }
            // Placez le navire
            for (int i = 0; i < ship.getSize(); i++) {
                if (isHorizontal) {
                    grid[x][y + i] = ship.getRepresentation();
                } else {
                    grid[x + i][y] = ship.getRepresentation();
                }
            }
            return true; // Le navire a été placé avec succès, retournez true
        }
        return false; // La position n'est pas valide, retournez false
    }

    public boolean isHit(int x, int y) {
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            if (grid[x][y] != '~' && grid[x][y] != 'X') {
                grid[x][y] = 'X'; // 'X' représente un coup réussi
                return true;
            }
        }
        return false;
    }

    public void printBoard() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
    }

    public int getSize() {
        return SIZE;
    }

    public char[][] getGrid() {
        return grid;
    }
}