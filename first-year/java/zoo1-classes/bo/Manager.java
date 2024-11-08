package bo;

public class Manager{
    private String name;
    private int ysSeniority;


    public Manager(String name, int ysSeniority) {
        this.name = name;
        this.ysSeniority = ysSeniority;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    public int getysSeniority(){
        return ysSeniority;
    }
    
    public void setysSeniority(int ysSeniority){
        this.ysSeniority = ysSeniority;
    }
}