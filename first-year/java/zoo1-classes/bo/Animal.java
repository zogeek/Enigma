package bo;


public class Animal{
    private String name;
    private int age;
    private int ageMax;
    private String shout;

    public Animal (String name, int age, int ageMax, String shout){
        this.name = name;
        this.age = age;
        this.ageMax = ageMax;
        this.shout = shout;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public boolean setAge(int age) {
        this.age = age;
        return false;
    }

    public int getAgeMax() {
        return ageMax;
    }

    public void setAgeMax(int ageMax) {
        this.ageMax = ageMax;
    }

    public String getShout() {
        return shout;
    }

    public void setShout(String shout) {
        this.shout = shout;
    }

    public boolean GetOlder(int age){
        this.age = age+1;
        if (age> ageMax) return false;
        else {
            return setAge(age + 1);
        }
    }

    public String eat(){
        return getName()+" "+ getShout();
    }
}