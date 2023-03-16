
public class YellowCard extends Card {
    public YellowCard() {
        super();
    }

    public YellowCard(Double number) {
        super(number);
    }

    public void printInfo() {
        System.out.println("Kartu Kuning: " + this.number);
    }

    public Double value() {
        return this.number * 10 + 3;
    }
}
