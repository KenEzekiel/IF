# NIM / Nama : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal : 27/10/2021
# Deskripsi : Program menentukan jumlah langkah yang dibutuhkan untuk mengubah N menjadi 1

# Kamus
# N, counter : int

# Algoritma
# Jika N merupakan bilangan ganjil, maka kurangi N dengan 1
# Jika N merupakan bilangan genap, maka bagi N dengan 2

N = int(input("Masukkan bilangan N: "))
counter = 0

while N > 1:
    if (N % 2) == 0: # Jika genap
        N /= 2
        counter += 1
    else: # Jika ganjil
        N -= 1
        counter += 1

print("Banyak langkah yang diperlukan adalah", counter)