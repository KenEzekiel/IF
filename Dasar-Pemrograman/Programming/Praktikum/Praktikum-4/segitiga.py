# Tuliskan identitas di sini

# Program GambarSegitiga
# Input: N : integer
# Output: Jika N > 0 dan ganjil, gambar segitiga sesuai dengan N
#         Jika tidak, tampilkan pesan kesalahan: 

# KAMUS
# Variabel
#    N : int

def GambarSegitiga(N):
# I.S. N > 0 dan N ganjil
# F.S. Gambar segitiga dengan tinggi sebesar N sesuai spesifikasi soal
# Lengkapilah kamus lokal dan algoritma prosedur di bawah ini

    matrix = [[] for i in range(N)]
    for i in range(N // 2 + 1):
        baris = ["" for x in range(N)]
        for j in range(N):
            if j+1 <= (N - ((i+1)*2 - 1)):
                baris[j] = " "
            else:
                baris[j] = "*"
        matrix[i] = baris
        matrix[N - i - 1] = baris

    for x in range(len(matrix)):
        for y in range((len(matrix[x]))):
            print(matrix[x][y], end="")
        print("")

def IsValid(N):
# menghasilkan true jika N positif dan ganjil, false jika tidak
# Lengkapilah kamus lokal dan algoritma fungsi di bawah ini
    if N > 0 and (N % 2) == 1:
        return True
    else:
        return False

# ALGORITMA PROGRAM UTAMA
N = int(input())
if (IsValid(N)):  # lengkapi dengan pemanggilan fungsi IsValid
    GambarSegitiga(N)        # lengkapi dengan pemanggilan prosedur GambarSegitiga
else: # N tidak positif atau N tidak ganjil
    print("Masukan tidak valid")