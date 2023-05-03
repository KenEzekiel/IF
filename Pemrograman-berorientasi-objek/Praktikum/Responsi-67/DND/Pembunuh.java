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

public class Pembunuh implements Kelas {
    private String senjata;

    public Pembunuh(String senjata) {
        this.senjata = senjata;
    }

    // Getter and setter
    public String getSenjata() {
        return senjata;
    }

    public void setSenjata(String senjata) {
        this.senjata = senjata;
    }

    /**
     * Implementasikan method-method yang ada pada interface Kelas
     */

    // Menyerang target dan mengurangi health target sebesar 20.
    // Menampilkan pesan
    // "[nama karakter], sang pembunuh, menyerang [nama target] dengan [senjata]"
    public void serang(Karakter self, Karakter target) {
        System.out.printf("%s, sang pembunuh, menyerang %s dengan %s%n", self.getName(), target.getName(),
                this.senjata);
        target.terimaSerangan(20);
    }

    // Menyerap health target sebesar 20 (tentunya sembari mengurangi health
    // target).
    // Target harus hidup. Apabila darah target kurang dari 20, maka darah target
    // akan diserap
    // hingga mati. Jika target sudah mati, tidak melakukan apa-apa.
    // Jika target masih hidup, menampilkan pesan
    // "[nama karakter] menyerap health [nama target] sebesar [jumlah health yang
    // diserap]"
    // Jika target sudah mati, menampilkan pesan
    // "[nama target] sudah mati, tidak bisa diserap healthnya"
    public void gunakanKemampuan(Karakter self, Karakter target) {
        if (target.isHidup()) {
            int health;
            if (target.getHealth() < 20) {
                health = target.getHealth();
            } else {
                health = 20;
            }
            System.out.printf("%s menyerap health %s sebesar %d%n", self.getName(), target.getName(), health);
            target.terimaSerangan(health);
            self.addHealth(health);
        } else {
            System.out.printf("%s sudah mati, tidak bisa diserap healthnya%n", target.getName());
        }
    }

    // Menyalin wujud target (menyalin skillnya) lalu mengisi health sebesar 40 dan
    // mana sebesar 20.
    // Target harus sudah mati. Menyalin skill berarti mengubah kelas yang dimiliki
    // karakter.
    // Menampilkan pesan
    // "[nama karakter] menyalin wujud [nama target]"
    // Jika target sudah mati (penyalinan berhasil) menampilkan pesan
    // "[nama target] berhasil disalin wujudnya"
    // "[nama karakter] memperoleh 40 health dan 20 mana"
    // Jika target masih hidup, tidak melakukan apa-apa, dan menampilkan pesan
    // "[nama target] belum mati, tidak bisa disalin wujudnya"
    public void gunakanUltimate(Karakter self, Karakter target) {
        System.out.printf("%s menyalin wujud %s%n", self.getName(), target.getName());
        if (!target.isHidup()) {
            self.addHealth(40);
            self.addMana(20);
            System.out.printf("%s berhasil disalin wujudnya%n", target.getName());
            System.out.printf("%s memperoleh 40 health dan 20 mana%n", self.getName());
            self.setKelas(target.getKelas());
        } else {
            System.out.printf("%s belum mati, tidak bisa disalin wujudnya%n", target.getName());
        }
    }
}
