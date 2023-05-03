package Mahasiswa;

import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Mahasiswa mahasiswa;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Class<? extends Mahasiswa> mahasiswaClass = this.mahasiswa.getClass();

        Method method = mahasiswaClass.getDeclaredMethod("addMatkul", String.class);

        method.setAccessible(true);

        method.invoke(this.mahasiswa, name);
    }

    public int getNIM() throws Exception {
        Class<? extends Mahasiswa> mahasiswaClass = this.mahasiswa.getClass();

        Field field = mahasiswaClass.getDeclaredField("NIM");

        field.setAccessible(true);

        return (Integer) field.get(this.mahasiswa);
    }

    public double getIPK() throws Exception {
        Class<? extends Mahasiswa> mahasiswaClass = this.mahasiswa.getClass();

        Field field = mahasiswaClass.getDeclaredField("IPK");

        field.setAccessible(true);

        return (Double) field.get(this.mahasiswa);
    }

}
