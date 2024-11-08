package bo;

public class Pokemon {
    private String name;
    private int PV;
    private int level;
    private String fightshout;
    private String defeatshout;
    private String victoryshout;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPV() {
        return PV;
    }

    public void setPV(int PV) {
        this.PV = PV;
    }

    public int getLevel() {
        return level;
    }

    public void setLevel(int level) {
        this.level = level;
    }

    public String getFightshout() {
        return fightshout;
    }

    public void setFightshout(String fightshout) {
        this.fightshout = fightshout;
    }

    public String getDefeatshout() {
        return defeatshout;
    }

    public void setDefeatshout(String defeatshout) {
        this.defeatshout = defeatshout;
    }

    public String getVictoryshout() {
        return victoryshout;
    }

    public void setVictoryshout(String victoryshout) {
        this.victoryshout = victoryshout;
    }

    public Pokemon(String name, int PV, int level){
        this.name = name;
        this.PV = PV;
        this.level = level;
    }
}
