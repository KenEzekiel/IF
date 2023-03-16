
public class GreenCard extends Card {
    public GreenCard() {
        super();
    }

    public GreenCard(Double number) {
        super(number);
    }

    public void printInfo() {
        System.out.println("Kartu Hijau: " + this.number);
    }

    public Double value() {
        return this.number * 10 + 1;
    }
}
