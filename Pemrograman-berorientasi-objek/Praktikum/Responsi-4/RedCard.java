
public class RedCard extends Card {
    public RedCard() {
        super();
    }

    public RedCard(Double number) {
        super(number);
    }

    public void printInfo() {
        System.out.println("Kartu Merah: " + this.number);
    }

    public Double value() {
        return this.number * 10 + 4;
    }
}
