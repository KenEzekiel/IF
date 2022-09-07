# NIM / Nama : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal : 01 / 11 / 2021
# Deskripsi : Menentukan anagram dari 2 array

# Kamus

# Algoritma
n_a = int(input("Masukkan banyaknya elemen A: "))
a = []
for i in range(1, n_a + 1):
    elemen_a = int(input(f"Masukkan elemen A ke-{i}: "))
    a.append(elemen_a)

n_b = int(input("Masukkan banyaknya elemen B: "))
b = []
for j in range(1, n_b + 1):
    elemen_b = int(input(f"Masukkan elemen B ke-{j}: "))
    b.append(elemen_b)

# Periksa apakah B merupakan anagram dari A
# Jumlah frekuensi elemen di B harus sama dengan frekuensi di A
# Asumsi nilai elemen a dan b maksimal 10

frekuensi_a = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for elements_a in a:
    frekuensi_a[elements_a] += 1
print(frekuensi_a)

frekuensi_b = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for elements_b in b:
    frekuensi_b[elements_b] += 1
print(frekuensi_b)

if frekuensi_a == frekuensi_b:
    print("B adalah anagram dari A")
else:
    print("B bukan anagram dari A")
