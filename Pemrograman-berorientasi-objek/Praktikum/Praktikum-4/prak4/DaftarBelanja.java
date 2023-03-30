class DaftarBelanja {
    protected Barang[] listBelanja;
    protected int numOfBarang;
    protected int max;

    public DaftarBelanja(int Max) {
        this.listBelanja = new Barang[Max];
        this.numOfBarang = 0;
        this.max = Max;
    }

    public void belanja(int lorong, String keterangan) {
        if (this.numOfBarang >= this.max) {
            return;
        }
        String nama = keterangan;
        nama += " (lorong ";
        nama += lorong;
        nama += ")";
        
        Barang baru = new Barang(nama, 1);
        this.listBelanja[this.numOfBarang] = baru;
        this.numOfBarang++;
    }

    public void belanja(int lorong, int qty, String keterangan) {
        if (this.numOfBarang >= this.max) {
            return;
        }
        String nama = keterangan;
        nama += " (lorong ";
        nama += lorong;
        nama += ")";
        
        Barang baru = new Barang(nama, qty);
        this.listBelanja[this.numOfBarang] = baru;
        this.numOfBarang++;
    }

    public void belanja(String barang) {
        if (this.numOfBarang >= this.max) {
            return;
        }
        Barang baru = new Barang(barang, 1);
        this.listBelanja[this.numOfBarang] = baru;
        this.numOfBarang++;
    }

    public void belanja(String barang, int qty) {
        if (this.numOfBarang >= this.max) {
            return;
        }
        Barang baru = new Barang(barang, qty);
        this.listBelanja[this.numOfBarang] = baru;
        this.numOfBarang++;
    }

    public void print() {
        for (int i = 0; i < this.numOfBarang; i++) {
            System.out.print(i + 1);
            System.out.print(". ");
            System.out.print(this.listBelanja[i]);
            System.out.println();
        }
    }

    // public static void main(String[] args) {
    //     DaftarBelanja a = new DaftarBelanja(6);

    //     a.belanja(5, 10, "Yang merah2 itu");
    //     a.belanja(10, 25, "Yang biru itu deh");
    //     a.belanja(100, "BLUEBAND MAMA");
    //     a.belanja("PADDEL PAP");
    //     a.belanja("molto", 1000);
    //     a.print();
    // }
}