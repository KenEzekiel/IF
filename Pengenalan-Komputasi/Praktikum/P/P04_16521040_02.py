# NIM / Nama    : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal       : 17/11/2021
# Deskripsi     : Membantu Tuan Ric mengajari adiknya permutasi

# Kamus
# string_len, result, count : int
# string : str
# skip : bool

# Algoritma
string_len = int(input("Masukkan panjang string: "))
string = input("Masukkan string: ")

def faktorial(x):
    result = 1
    for i in range(x, 0, -1):
        result *= i
    print(result)
    return result

def kemungkinan(panjang, str):
    result = faktorial(panjang)
    skip = False
    for i in range(panjang):
        count = 0
        for k in range(0, i):       # Cek apakah huruf tersebut sudah pernah dihitung atau belum
            if str[k] == str[i]:
                skip = True
        if not skip:                # Jika belum, hitung frekuensi huruf tersebut
            for j in range(i, panjang):   
                if str[i] == str[j]:
                    count += 1
        # print("count",str[i], count) # enable to see the counts
        if count > 1:
            result /= faktorial(count)
    return result

print(f"String tersebut dapat membentuk {int(kemungkinan(string_len, string))} kata berbeda.")