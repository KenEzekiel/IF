# NIM / Nama : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal : 01 / 11 / 2021
# Deskripsi : Program untuk menulis kembali bilangan secara terbalik

# Kamus

# Algoritma
N = int(input("Masukkan N: "))
array = []

for i in range(N):
    a = int(input(""))
    array.append(a)

print("Hasil dibalik:")
for i in range(len(array)-1, -1, -1):
    print(array[i])