class DebitCard implements IPaymentMethod {
    double balance;

    // TODO
    // Inisialisasi balance menjadi 0
    public DebitCard() {
        this.balance = 0;
    }

    // TODO
    // Getter
    public double getBalance() { return balance; }

    // TODO
    // Menambahkan amount ke balance
    // Mengembalikan true
    public boolean deposit(double amount) { this.balance += amount; return true; }
    // TODO
    // Mengurangi amount dari balance
    // Mengembalikan false apabila amount melebihi balance
    public boolean withdraw(double amount) {
        if (amount > this.balance) {
            return false;
        } else {
            this.balance -= amount;
            return true;
        }
    }
    // TODO
    // Mengurangi amount dari balance
    // Mengembalikan false apabila amount melebihi balance
    public boolean pay(double price) {
        return withdraw(price);
    }

    // public static void main(String[] args) {
    //     DebitCard a = new DebitCard();
    //     a.deposit(50);
    //     System.out.println(a.pay(40));
    //     System.out.println(a.getBalance());
    // }
}