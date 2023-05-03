/**
 * Note:
 * 1. Tab pada komentar hanya untuk mempermudah pembacaan, tidak ada tab pada
 * saat melakukan print
 * suatu pesan.
 * 2. Self adalah karakter yang melakukan aksi, target adalah karakter yang
 * menjadi target aksi.
 * 3. Pastikan segala aksi yang mengurangi darah target memanggil method
 * terimaSerangan(), dipanggil
 * setelah menampilkan pesan yang berkaitan dengan aksi (serangan, kemampuan,
 * ultimate).
 */

public class Pendekar implements Kelas {
    private String senjata;
    private String perisai;

    public Pendekar(String senjata, String perisai) {
        this.senjata = senjata;
        this.perisai = perisai;
    }

    // Getter and setter
    public String getSenjata() {
        return senjata;
    }

    public String getPerisai() {
        return perisai;
    }

    public void setSenjata(String senjata) {
        this.senjata = senjata;
    }

    public void setPerisai(String perisai) {
        this.perisai = perisai;
    }

    /**
     * Implementasikan method-method yang ada pada interface Kelas
     */

    // Melakukan serangan dengan senjata pada target dan mengurangi health target
    // sebesar 15.
    // Menampilkan pesan
    // "[nama karakter], sang pendekar, menyerang [nama target] dengan [senjata]"
    public void serang(Karakter self, Karakter target) {
        System.out.printf("%s, sang pendekar, menyerang %s dengan %s%n", self.getName(), target.getName(),
                this.getSenjata());
        target.terimaSerangan(15);
    }

    // Melakukan serangan dengan perisai pada target dan mengurangi health target
    // sebesar 40.
    // Target harus hidup. Apabila target sudah mati, tidak melakukan apa-apa.
    // Apabila target masih hidup, menampilkan pesan
    // "[nama karakter] memukul mundur [nama target] dengan [perisai]"
    // Apabila target sudah mati, menampilkan pesan
    // "[nama target] sudah mati, tidak bisa dipukul mundur"
    public void gunakanKemampuan(Karakter self, Karakter target) {
        if (target.isHidup()) {
            System.out.printf("%s memukul mundur %s dengan %s%n", self.getName(), target.getName(), this.getPerisai());
            target.terimaSerangan(40);
        } else {
            System.out.printf("%s sudah mati, tidak bisa dipukul mundur%n", target.getName());
        }
    }

    // Menyerukan nada peperangan sembari menyerang target dengan senjata dan
    // perisai.
    // Menambahkan health sebesar 30 dan mana sebesar 20.
    // Mengurangi health target sebesar 55.
    // Target harus hidup. Apabila target sudah mati, tidak menambahkan health dan
    // mana maupun
    // mengurangi health target.
    // Apabila target masih hidup, menampilkan pesan
    // "[nama karakter] menyerukan nada peperangan"
    // "[nama karakter] mendapatkan 30 health dan 20 mana"
    // "[nama karakter] menyerang [nama target] dengan [senjata] dan [perisai]"
    // Apabila target sudah mati, menampilkan pesan
    // "[nama target] sudah mati, tidak bisa dipukul mundur"
    public void gunakanUltimate(Karakter self, Karakter target) {
        if (target.isHidup()) {
            System.out.printf("%s menyerukan nada peperangan%n", self.getName());
            System.out.printf("%s mendapatkan 30 health dan 20 mana%n", self.getName());
            self.addHealth(30);
            self.addMana(20);
            System.out.printf("%s menyerang %s dengan %s dan %s%n", self.getName(), target.getName(), this.getSenjata(),
                    this.getPerisai());
            target.terimaSerangan(55);
        } else {
            System.out.printf("%s sudah mati, tidak bisa dipukul mundur%n", target.getName());
        }
    }

}
