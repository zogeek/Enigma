package bo;
public class Monkey extends Animal {
    static final int MONKEY_MAX_AGE = 24;
    static final String MONKEY_SHOUT = "Cuicui!";



    public String toString(){
        String s = this.getName() + "is a" + this.getClass().getName() + ", is it" + getAge() + "years old.";
        return s
    }
    public Monkey(String name, int age, int ageMax, String shout) {
        super(name, age, ageMax, shout);
    }
}