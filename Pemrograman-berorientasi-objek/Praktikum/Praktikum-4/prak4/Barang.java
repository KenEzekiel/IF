class Barang {
    protected String nama;
    protected int amount;

    public Barang(String Nama, int Amount) {
        this.nama = Nama;
        this.amount = Amount;
    }

    @Override
    public String toString() {
        String a = ""; 
        a += this.amount;
        a += " ";
        a += this.nama.toString();
        return a;
    }
}