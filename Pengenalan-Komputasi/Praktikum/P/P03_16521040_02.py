# NIM / Nama : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal : 03/11/2021
# Deskripsi : Program lampu tuan Kil

# Kamus
# n_lampu, n_tekan, tombol : int
# string : str
# array_lampu : arr

# Algoritma
n_lampu = int(input("Masukkan banyak lampu: "))
n_tekan = int(input("Masukkan berapa kali Tuan Kil menekan tombol: "))
string= ""
array_lampu = [0 for i in range(n_lampu)]
# print(array_lampu)

# indeks 0 == lampu 1
for i in range(n_tekan):
  tombol = int(input(f"Tombol yang ditekan ke {i+1}: "))
  for j in range(tombol-2, tombol+1, 1):
    if 0 <= j < n_lampu:          # Cek apakah lampu yang dinyala/matikan didalam indeks atau tidak
      if array_lampu[j] == 0:
        array_lampu[j] = 1
      elif array_lampu[j] == 1:
        array_lampu[j] = 0
  # print(array_lampu)

for e in array_lampu:
  string += str(e)
print("Keadaan akhir rangkaian lampu adalah", string)