/**
 * Elang.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

public class Elang extends Animal {
    public int basePower;
    public int jumlahTelur;

    public Elang(int basePower) {
        super(2);
        this.basePower = basePower;
        this.jumlahTelur = 0;
    }

    public int getJumlahTelur() { return jumlahTelur; }
    public void bertelur() { this.jumlahTelur++; }
    public int getAnimalPower() {
        return basePower * children - jumlahTelur;
    }
}
