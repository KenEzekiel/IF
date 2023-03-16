public class Karavan extends TempatTinggal implements Kendaraan {
    protected float bensin;
    protected float pemakaianBensin;

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

    public float getPemakaianBensin() {
        return this.pemakaianBensin;
    }
}
