
public class Rumah extends TempatTinggal {

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
