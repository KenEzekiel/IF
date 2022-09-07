# NIM / Nama : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal : 03/11/2021
# Deskripsi : Program menentukan huruf vokal dan konsonan

# Kamus
# N, vokal, konsonan : int
# string : str

# Algoritma
N = int(input("Masukkan N: "))
string = input("Masukkan string: ")
vokal = 0
konsonan = 0

if len(string) == N:
    for i in range(0, N):
        if string[i] == "a" or string[i] == "i" or string[i] == "u" or string[i] == "e" or string[i] == "o":
            vokal += 1              # jika vokal
        elif string[i] == " ":
            pass                    # jika kosong
        else:
            konsonan += 1           # jika konsonan

print(f"Terdapat {vokal} huruf vokal dan {konsonan} huruf konsonan")