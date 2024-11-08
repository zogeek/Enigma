package bo;

public class AttackBoard extends Board {
    public void markShot(int x, int y, char mark) {
        getGrid()[x][y] = mark;
    }
}