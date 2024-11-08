package bo;

public class CatLike extends Animal {
    private String race;
    static final int CATLIKE_MAX_AGE = 24;
    static final String CATLIKE_SHOUT = "Miaou!";


    public CatLike(String name, int age, String race){
        super(name, age, CATLIKE_MAX_AGE, CATLIKE_SHOUT);
        this.race = race;
    }

    public Sring toString(){
        String s = this.getName() + "is a" + this.getClass().getName() + ", is it" + getAge() + "years old.";
        return s
    }
}