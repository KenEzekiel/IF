# NIM/Nama  : 16521040/Kenneth Ezekiel Suprantoni
# Tanggal   : 04/10/2021
# Deskripsi : Buatlah program yang menentukan apakah sebuah bilangan adalah bilangan positif, negatif, atau nol. Khusus untuk bilangan positif, tuliskan juga apakah ganjil atau genap.

# Program Program Penentu Bilangan

# Kamus
# X : int
# hasil_satu, hasil_dua : str

# Algoritma
X = int(input("Masukkan X: "))
hasil_satu = ""
hasil_dua = ""

if X == 0:
    print("X adalah bilangan nol")
elif X > 0:
    hasil_satu = "positif"
elif X < 0:
    hasil_satu = "negatif"

if (X % 2) != 0:
    hasil_dua = "ganjil"
elif (X != 0) and ((X % 2) == 0):
    hasil_dua = "genap"

if hasil_satu != "":
    print("X adalah bilangan", hasil_satu, hasil_dua)