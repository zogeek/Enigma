package bo;

public class Bird extends Animal {
    private String color;
    static final int BIRD_MAX_AGE = 24;
    static final String BIRD_SHOUT = "Cuicui!";


    public Bird(String name, int age, String color){
        super(name, age, BIRD_MAX_AGE, BIRD_SHOUT);
        this.race = race;
    }
    public String toString(){
        String s = this.getName() + "is a" + this.getClass().getName() + ", is it" + getAge() + "years old.";
        return s
    }
}