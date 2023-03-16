public class TempatTinggal {
    protected int luas;
    protected double hargaBahanBangunan;

    public TempatTinggal(int luas, double hargaBahanBangunan) {
        this.luas = luas;
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public double hitungBiayaBangun() {
        return this.luas * this.hargaBahanBangunan;
    }

    public void setLuas(int luas) {
        this.luas = luas;
    }

    public void setHargaBahanBangunan(double hargaBahanBangunan) {
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public int getLuas() {
        return this.luas;
    }

    public double getHargaBahanBangunan() {
        return this.hargaBahanBangunan;
    }

    // public static void main(String[] args) {
    // Rumah a = new Rumah(2, 5);
    // a.setLuas(4);
    // System.out.println(a.hitungBiayaBangun(5));
    // }

}

class Rumah extends TempatTinggal {

    public Rumah(int luas, double hargaBahanBangunan) {
        super(luas, hargaBahanBangunan);
    }

    public Rumah(int lebarTanah, int panjangTanah, double hargaBahanBangunan) {
        super(lebarTanah * panjangTanah, hargaBahanBangunan);
    }

    public double hitungBiayaBangun(double biayaOrmas) {
        return (this.luas * this.hargaBahanBangunan) + biayaOrmas;
    }

    public void setLuas(int lebarTanah, int panjangTanah) {
        this.setLuas(lebarTanah * panjangTanah);
    }

}

interface Kendaraan {
    public float hitungJarakTempuh();
}

class Karavan extends TempatTinggal implements Kendaraan {
    protected float bensin;
    protected float pemakaianBensin;

    public Karavan() {
        super(0, 0);

    }

    public Karavan(int luas, double hargaBahanBangunan, float bensin, float pemakaianBensin) {
        super(luas, hargaBahanBangunan);
        this.bensin = bensin;
        this.pemakaianBensin = pemakaianBensin;
    }

    public double hitungBiayaBangun() {
        return this.luas * this.hargaBahanBangunan * 3;
    }

    public float hitungJarakTempuh() {
        return this.bensin * this.pemakaianBensin;
    }

    public float getBensin() {
        return this.bensin;
    }

    public void setBensin(float bensin) {
        this.bensin = bensin;
    }

    public float getPemakaianBensin() {
        return this.pemakaianBensin;
    }

    public void setPemakaianBensin(float pemakaianBensin) {
        this.pemakaianBensin = pemakaianBensin;
    }
}
