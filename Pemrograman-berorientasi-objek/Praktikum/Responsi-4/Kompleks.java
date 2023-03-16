
class Kompleks {
    private static int n_kompleks = 0;
    private int real;
    private int imaginer;

    public Kompleks() {
        this.real = 0;
        this.imaginer = 0;
        n_kompleks++;
    }

    public Kompleks(int real, int imaginer) {
        this.real = real;
        this.imaginer = imaginer;
        n_kompleks++;
    }

    public int getReal() {
        return this.real;
    }

    public int getImaginer() {
        return this.imaginer;
    }

    public void setReal(int real) {
        this.real = real;
    }

    public void setImaginer(int imaginer) {
        this.imaginer = imaginer;
    }

    public Kompleks plus(Kompleks b) {
        int real = this.real + b.getReal();
        int imaginer = this.imaginer + b.getImaginer();
        return new Kompleks(real, imaginer);
    }

    public Kompleks minus(Kompleks b) {
        int real = this.real - b.getReal();
        int imaginer = this.imaginer - b.getImaginer();
        return new Kompleks(real, imaginer);
    }

    public Kompleks multiply(Kompleks b) {
        int real = this.real * b.getReal() - this.imaginer * b.getImaginer();
        int imaginer = this.imaginer * b.getReal() + this.real * b.getImaginer();
        return new Kompleks(real, imaginer);
    }

    public Kompleks multiply(int b) {
        int real = this.real * b;
        int imaginer = this.imaginer * b;
        return new Kompleks(real, imaginer);
    }

    public static int countKompleksInstance() {
        return n_kompleks;
    }

    private void printIfNotZero(int a, String b) {
        if (a != 0) {
            System.out.print(a + b);
        }
    }

    public void print() {
        if (this.getReal() == 0 && this.getImaginer() == 0) {
            System.out.println(0);
        } else {
            if (this.getImaginer() < 0) {
                this.printIfNotZero(this.getReal(), "");
                this.printIfNotZero(this.getImaginer(), "i");
                System.out.println();
            } else {
                this.printIfNotZero(this.getReal(), "");
                if (this.getReal() != 0 && this.getImaginer() != 0) {
                    System.out.print("+");
                }
                this.printIfNotZero(this.getImaginer(), "i");
                System.out.println();

            }
        }
    }

    public static void main(String[] args) {
        Kompleks a = new Kompleks(-5, 4);
        Kompleks b = new Kompleks(-4, -5);
        System.out.println(a.getReal());
        a.print();
        b.print();
    }

}