# Kamus
# elemen arr1, arr2 : float
# n : int

# Algoritma
def MSE(N, a1, a2):
    out = 1/N                       # set value awal output
    sigma = 0
    for i in range(n):
        sigma += (a1[i] - a2[i])**2 # set fungsi sigma
    out *= sigma                    # value awal out * hasil sigma
    return out

n = int(input("Masukkan nilai n (banyak data yang dipelajari): "))

if n > 0:
    arr1 = [0 for i in range(n)]
    arr2 = [0 for i in range(n)]
    for i in range(n):
        arr1[i] = float(input(f"Masukkan array T0 elemen ke-{i+1}: "))
    for i in range(n):
        arr2[i] = float(input(f"Masukkan array T1 elemen ke-{i+1}: "))
    out = MSE(n, arr1, arr2)
    print(out)
else:
    print("Tidak ada data yang tersedia")