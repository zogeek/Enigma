package bo;

public class Ship {
    private int size;
    private char representation;

    public Ship(int size, char representation) {
        this.size = size;
        this.representation = representation;
    }

    public int getSize() {
        return size;
    }

    public char getRepresentation() {
        return representation;
    }
}