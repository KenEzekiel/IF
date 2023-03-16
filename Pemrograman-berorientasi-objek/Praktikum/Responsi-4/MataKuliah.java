import java.lang.Comparable;

public class MataKuliah implements Comparable<MataKuliah> {
    private String nama;
    private int kodeJurusan;
    private int tahunPengambilan;
    private float rating;

    public MataKuliah(String nama, int kodeJurusan, int tahunPengambilan, float rating) {
        this.nama = nama;
        this.kodeJurusan = kodeJurusan;
        this.tahunPengambilan = tahunPengambilan;
        this.rating = rating;
    }

    public String getNama() {
        return this.nama;
    }

    public int getKodeJurusan() {
        return this.kodeJurusan;
    }

    public int getTahunPengambilan() {
        return this.tahunPengambilan;
    }

    public float getRating() {
        return this.rating;
    }

    public int compareTo(MataKuliah m) {
        if (this.getKodeJurusan() < m.getKodeJurusan()) {
            return -1;

        }
        if (this.getKodeJurusan() == m.getKodeJurusan() && this.getTahunPengambilan() < m.getTahunPengambilan()) {
            return -1;
        }
        if (this.getKodeJurusan() == m.getKodeJurusan() && this.getTahunPengambilan() == m.getTahunPengambilan()
                && this.getRating() < m.getRating()) {
            return -1;
        }
        if (this.getKodeJurusan() == m.getKodeJurusan() && this.getTahunPengambilan() == m.getTahunPengambilan()
                && this.getRating() == m.getRating()) {
            return 0;
        }
        return 1;
    }

    // public static void main(String[] args) {

    // }
}