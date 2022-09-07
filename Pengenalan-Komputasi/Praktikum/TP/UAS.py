# Kamus
# x : float
# n : int

# Algoritma
# Membuat fungsi f(x) = 1 + x + x^2 + ... + x^n
# Dengan batas x dan n :
# -1 < x < 1 dan n > 1
def fungsi(x, n):
    y = 1                       # Setting nilai awal output 1, untuk + 1
    for i in range(1, n+1):     # Karena nilai awal = 1, x dimulai dari x pangkat 1, bukan pangkat 0
        y += x**i               # y = 1 + x + x**2 + ... + x***n (karena batas akhir n+1, maka value terakhir adalah n)
    return y

X = float(input("Masukkan nilai x: "))
N = int(input("Masukkan nilai n: "))

print(fungsi(X, N))