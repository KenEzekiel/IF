# NIM/Nama  : 16521040/Kenneth Ezekiel Suprantoni
# Tanggal   : 15/11/2021
# Deskripsi : Program menuliskan matrix lalu menghitung berapa banyak bilangan positif

# Kamus

# Algoritma
N = int(input("Masukkan N: "))
M = int(input("Masukkan M: "))
matrix = [[0 for i in range(M)] for j in range(N)]
pos_counter = 0
print(matrix)

for i in range(N):
    for j in range(M):
        matrix[i][j] = int(input(f"Masukkan nilai A[{i+1}][{j+1}]: "))

for i in range(N):
    for j in range(M):
        if matrix[i][j] > 0:
            pos_counter += 1

print(f"Ada {pos_counter} bilangan positif di matriks.")
for i in range(N):
    print("")
    for j in range(M):
        print(matrix[i][j], end=" ")