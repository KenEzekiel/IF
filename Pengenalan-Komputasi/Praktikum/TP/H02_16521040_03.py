# NIM/Nama : 16521040/Kenneth Ezekiel
# Tanggal : 12/10/2021
# Deskripsi : Program mencari bilangan prima

# Algoritma
N = int(input("Masukkan N: "))
counter = 0

for i in range(2, N):
    if (N / i) == (N // i):
        print(i, "membagi", N)
        counter += 1

if N <= 1:
    print(N, "bukan bilangan prima")
elif counter == 0:
    print(N, "adalah bilangan prima")
else:
    print(N, "bukan bilangan prima")