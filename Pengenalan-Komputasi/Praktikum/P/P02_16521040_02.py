# NIM / Nama : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal : 27/10/2021
# Deskripsi : Program menghitung volume ember x y untuk mengisi penuh kolam

# Kamus
# x, y, z, total, count_x, count_y : int
# is_substractable, final_value : bool


# Algoritma
# ember x y mengisi penuh kolam z
# tulis 1 jawaban saja

from typing import Counter


x = int(input("Masukkan x: "))
y = int(input("Masukkan y: "))
z = int(input("Masukkan z: "))
is_substractable = True
total = 0
count_x = 0
final_value = False

# Cek apakah nilai x melebihi z
if (z - x) > 0:
    is_substractable = True
else:
    is_substractable = False

# nested loop, outer loop untuk count x, inner loop untuk count y
# cek kombinasi untuk setiap x dan y, x 1 kali + y semua, lalu ke x 2 kali + y semua
while is_substractable and (z - total) > 0:
    count_x += 1            
    total = count_x * x
    count_y = 0
    while total < z:
        total += y
        count_y += 1
    if total == z:
        final_value = True
        print(count_x, "kali ember x,", count_y, "kali ember y")
        is_substractable = False
    total = 0

if not final_value:
    print("Tidak mungkin")