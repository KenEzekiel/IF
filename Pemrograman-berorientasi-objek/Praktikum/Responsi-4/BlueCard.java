
public class BlueCard extends Card {
    public BlueCard() {
        super();
    }

    public BlueCard(Double number) {
        super(number);
    }

    public void printInfo() {
        System.out.println("Kartu Biru: " + this.number);
    }

    public Double value() {
        return this.number * 10 + 2;
    }
}
