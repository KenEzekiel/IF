# NIM/Nama  : 16521040/Kenneth Ezekiel Suprantoni
# Tanggal   : 04/10/2021
# Deskripsi : Buatlah sebuah program kalkulator sederhana yang menerima 2 buah angka dan sebuah karakter operasi,dan menuliskan hasil perhitungannya. Operator yang diterima adalah+(tambah), - (kurang), * (kali),/(bagi,dibulatkan ke bawah), % (sisa bagi).

# Program Kalkulator Sederhana

# Kamus
# angka_pertama, angka_kedua, hasil : int
# operator : str

# Algoritma
angka_pertama = int(input("Masukkan angka pertama: "))
angka_kedua = int(input("Masukkan angka kedua: "))
operator = input("Masukkan operator: ")
hasil = 0

if operator == "+":
    hasil = angka_pertama + angka_kedua
elif operator == "-":
    hasil = angka_pertama - angka_kedua
elif operator == "*":
    hasil = angka_pertama * angka_kedua
elif operator == "/":
    hasil = angka_pertama // angka_kedua
elif operator == "%":
    hasil = angka_pertama % angka_kedua

print(hasil)