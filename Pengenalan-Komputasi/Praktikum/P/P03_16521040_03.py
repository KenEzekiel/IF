# NIM / Nama : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal : 03/11/2021
# Deskripsi : Program menghitung string yang menjadi substring

# Kamus
# n_string_1, n_string_2, word_counter, counter : int
# string_1, string_2 : str


# Algoritma
n_string_1 = int(input("Masukkan panjang string 1: "))
string_1 = input("Masukkan string 1: ")
# print(len(string_1))
n_string_2 = int(input("Masukkan panjang string 2: "))
string_2 = input("Masukkan string 2: ")
# print(len(string_2))
word_counter = 0

for i in range(n_string_2):           # Cek untuk setiap elemen dalam string 2
  counter = 0 
  for j in range(n_string_1):         # Cek untuk setiap elemen dalam string 1
    k = i + j
    if 0 <= k <= n_string_2-1:
      if string_2[k] == string_1[j]:  # Cek apakah elemen ke i sampai ke i + n_string_1 == string 1
        counter += 1                  # Jika ya, tambahkan counter
        # print(counter)
  if counter == n_string_1:           # Jika jumlah huruf yang sesuai == n_string_1
    word_counter += 1                 # Kata + 1

print(f"String 1 muncul sebanyak {word_counter} kali")