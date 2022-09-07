# NIM / Nama : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal : 27/10/2021
# Deskripsi : Program membagi bilangan N menjadi jumlah dari k bilangan dan tentukan nilai maks perkalian bilangan k

# Kamus

# Algoritma
# N > 1
# 1 < k < N
N = int(input("Masukkan bilangan N: "))
nilai_maks = 0
kombinasi_nilai_maks = ""
condition = True
nilai_sementara = 0

# Cek semua kombinasi faktor
for i in range(1, N):
    j = N - i
    if (i * j) > nilai_maks and (i + j) == N:
        nilai_maks = i * j                    # Set nilai maks
        kombinasi_nilai_maks = f"{i} , {j}"
    for j in range(1, N-1):
        k = N - i - j
        if (i * j * k) > nilai_maks and (i + j + k) == N:
            nilai_maks = i * j * k
            kombinasi_nilai_maks = f"{i}, {j}, {k}"
        for k in range(1, N-2):
            l = N - i - j - k
            if (i * j * k * l) > nilai_maks and (i + j + k + l) == N:
                nilai_maks = i * j * k * l
                kombinasi_nilai_maks = f"{i}, {j}, {k}, {l}"

print("Nilai maksimalnya adalah", nilai_maks)
print(kombinasi_nilai_maks)

    
