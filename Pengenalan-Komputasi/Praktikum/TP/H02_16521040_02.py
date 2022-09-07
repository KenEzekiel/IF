# NIM/Nama : 16521040/Kenneth Ezekiel
# Tanggal : 12/10/2021
# Deskripsi : Program menuliskan bilangan terkecil 10 pangkat x yang lebih dari N

# Algoritma
N = int(input("Masukkan N: "))
condition = True
x = 0
result = 0

while condition:
    if N < (10**x):
        result = (10**x)
        break
    x += 1

print(result)

     