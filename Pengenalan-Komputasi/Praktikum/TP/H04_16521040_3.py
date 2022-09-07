# NIM/Nama  : 16521040/Kenneth Ezekiel Suprantoni
# Tanggal   : 15/11/2021
# Deskripsi : Program menerima masukan N dan menuliskan matriks segitiga pascal berukuran NxN

# Kamus
# N, matrix : int

# Algoritma
N = int(input("Masukkan N: "))
matrix = [[1 for i in range(N)] for i in range(N)]
print(matrix)

for i in range(1, N):
    for j in range(1, N):
        matrix[i][j] = (matrix[i][j-1] + matrix[i-1][j])

for i in range(N):
    print("")
    for j in range(N):
        print(matrix[i][j], end=" ")

