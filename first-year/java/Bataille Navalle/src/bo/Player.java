package bo;

public class Player {
    private String name;

    public Carte Plateau1;
    private Carte Plateau2;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Carte getPlateau1() {
        return Plateau1;
    }

    public void setPlateau1(Carte Plateau1) {
        this.Plateau1 = Plateau1;
    }

    public Carte getPlateau2() {
        return Plateau2;
    }

    public void setPlateau2(Carte Plateau2) {
        this.Plateau2 = Plateau2;
    }

    public Player(String name) {
        this.name = name;
        this.Plateau1 = new Carte(10);
        this.Plateau2 = new Carte(10);
    }

}
