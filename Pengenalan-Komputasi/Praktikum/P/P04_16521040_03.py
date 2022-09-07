# NIM / Nama    : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal       : 17/11/2021
# Deskripsi     : Menentukan keliling pulau

# Kamus
# baris, kolom : int

# Algoritma
baris = int(input("Masukkan nilai baris: "))
kolom = int(input("Masukkan nilai kolom: "))

peta = [[0 for i in range(kolom)] for j in range(baris)]

for i in range(baris):
    for j in range(kolom):
        peta[i][j] = int(input(f"Masukkan nilai petak baris {i+1} kolom {j+1}: "))

for i in range(baris):
    for j in range(kolom):
        print(peta[i][j], end=" ")
    print("")

def hitungKeliling(map):
    total_keliling = 0
    for i in range(baris):
        for j in range(kolom):
            kel = 4
            if map[i][j] == 1:              # Cek apakah daratan atau bukan
                # Jika daratan, cek semua neighboring block nya dan kurangi 1 unit keliling untuk setiap neighboring block yang bernilai 1
                if (i - 1) >= 0:
                    if map[i - 1][j] == 1:
                        kel -= 1
                if (i + 1) < baris:
                    if map[i + 1][j] == 1:
                        kel -= 1
                if (j - 1) >= 0:
                    if map[i][j - 1] == 1:
                        kel -= 1
                if (j + 1) < kolom:
                    if map[i][j + 1] == 1:
                        kel -= 1
                # print("kel", kel)
                total_keliling += kel
            # print("total", total_keliling)
    return total_keliling

print(f"Keliling pulau tersebut adalah {hitungKeliling(peta)}.")
