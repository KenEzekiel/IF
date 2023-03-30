/**
 * Gajah.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

public class Gajah extends Animal {
    protected int basePower;
    protected int age;

    public Gajah(int basePower, int age) {
        super(4);
        this.basePower = basePower;
        this.age = age;
    }

    public int getAge() { return age; }
    public int getAnimalPower() {
        return 3 * (basePower + age + children);
    }
}
