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

public class Penyihir implements Kelas {
    private String tongkat;
    private String sihir;

    public Penyihir(String tongkat, String sihir) {
        this.tongkat = tongkat;
        this.sihir = sihir;
    }

    // Getter and setter
    public String getTongkat() {
        return tongkat;
    }

    public String getSihir() {
        return sihir;
    }

    public void setTongkat(String tongkat) {
        this.tongkat = tongkat;
    }

    public void setSihir(String sihir) {
        this.sihir = sihir;
    }

    /**
     * Implementasikan method-method yang ada pada interface Kelas
     */

    // Apabila mempunyai 20 mana atau lebih, melakukan serangan dengan sihir pada
    // target dan
    // mengurangi health target sebesar 30. Mengurangi mana sebesar 20.
    // Apabila mempunyai mana kurang dari 20, memukul target dengan tongkat dan
    // mengurangi
    // health target sebesar 5.
    // Apabila menggunakan sihir, menampilkan pesan
    // "[nama karakter], merapal [nama sihir] kepada [nama target]"
    // Apabila menggunakan tongkat, menampilkan pesan
    // "[nama karakter], memukul [nama target] dengan [nama tongkat]"
    public void serang(Karakter self, Karakter target) {
        if (self.getMana() >= 20) {
            System.out.printf("%s, merapal %s kepada %s%n", self.getName(), this.getSihir(), target.getName());
            self.reduceMana(20);
            target.terimaSerangan(30);
        } else {
            System.out.printf("%s, memukul %s dengan %s%n", self.getName(), target.getName(), this.getTongkat());
            target.terimaSerangan(5);
        }
    }

    // Menyerap mana dari target sebesar 40. Apabila mana target kurang dari 40,
    // maka mana target
    // diserap sampai habis. Target harus hidup. Apabila target sudah mati, tidak
    // melakukan apa-apa.
    // Apabila target masih hidup, menampilkan pesan
    // "[nama karakter] menyerap [mana yang diserap] mana dari [nama target]"
    // "[nama target] memiliki [mana tersisa target] mana yang tersisa"
    // Apabila target sudah mati, menampilkan pesan
    // "[nama target] sudah mati, tidak bisa diserap mananya"
    public void gunakanKemampuan(Karakter self, Karakter target) {
        if (target.isHidup()) {
            int mana;
            if (target.getMana() < 40) {
                mana = target.getMana();
            } else {
                mana = 40;
            }
            System.out.printf("%s menyerap %d mana dari %s%n", self.getName(), mana, target.getName());
            target.reduceMana(mana);
            self.addMana(mana);
            System.out.printf("%s memiliki %d mana yang tersisa%n", target.getName(), target.getMana());
        } else {
            System.out.printf("%s sudah mati, tidak bisa diserap mananya%n", target.getName());
        }
    }

    // Menyihir target menjadi domba. Merubah kelas target.
    // Menampilkan pesan
    // "[nama karakter] menyihir [nama target] menjadi domba"
    public void gunakanUltimate(Karakter self, Karakter target) {
        System.out.printf("%s menyihir %s menjadi domba%n", self.getName(), target.getName());
        target.setKelas(new Domba());
    }

}
