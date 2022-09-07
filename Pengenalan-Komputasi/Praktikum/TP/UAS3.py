# Kamus


# Algoritma
# Matriks terbesar ukuran 10x10
# Matriks: baris (n) x kolom(m)
# 0 <= b&k <= n&m

def cariRataRata(arr, row, col):
    mean = 1/(row*col)
    sigma = 0
    for i in range(row):
        for j in range(col):
            sigma += arr[i][j]
    mean *= sigma
    return mean


print("Ukuran Matriks")
n = int(input("Baris = "))
m = int(input("Kolom = "))
mat = [[0 for i in range(m)] for j in range(n)]

print("Masukkan matriks")
for i in range(n):
    for j in range(m):
        mat[i][j] = int(input(f"Elemen [{i}][{j}] = "))

b = int(input("Indeks baris dihapus = "))
k = int(input("Indeks kolom dihapus = "))

print("Nilai rata-rata elemen matriks =", round(cariRataRata(mat, n, m), 2))

newmat = []
for i in range(n):
    if i != b:
        newcol = []
        for j in range(m):
            if j != k:
                newcol.append(mat[i][j])
        newmat.append(newcol)

for i in range(n-1):
    print(newmat[i])

print("Nilai rata-rata elemen submatriks =", round(cariRataRata(newmat, n-1, m-1), 2))