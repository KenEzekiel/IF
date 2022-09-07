# NIM/Nama  : 16521040/Kenneth Ezekiel Suprantoni
# Tanggal   : 15/11/2021
# Deskripsi : Program menulis hasil dari fungsi A sampai B

# Kamus

# Algoritma
A = int(input("Masukkan A: "))
B = int(input("Masukkan B: "))

# Membuat fungsi
def fungsi(x):
    hasil = (x**2) - (2*x) + 5
    return print(f"f({i}) = {hasil}")

for i in range(A, B+1, 1):
    fungsi(i)
