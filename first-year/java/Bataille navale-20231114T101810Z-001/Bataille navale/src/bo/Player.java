package bo;

public class Player {
    protected String name;
    public PlayerBoard playerBoard;
    protected AttackBoard attackBoard;

    public Player(String name) {
        this.name = name;
        this.playerBoard = new PlayerBoard();
        this.attackBoard = new AttackBoard();
    }
}