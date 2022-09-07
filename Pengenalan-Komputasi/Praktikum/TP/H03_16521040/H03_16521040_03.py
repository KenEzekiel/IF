# NIM / Nama : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal : 01 / 11 / 2021
# Deskripsi : Program untuk menentukan apakah sebuah string palindrom atau bukan

# 2 approach: memecah string menjadi 2 bagian lalu dibandingkan, atau membalikkan katanya lalu dibandingkan

# Kamus

# Algoritma
panjang_string = int(input("Masukkan panjang string: "))
string = input("Masukkan string (huruf kecil): ")
inverted = ""

if len(string) != panjang_string:
    print("input salah")
else:
    for i in range(panjang_string-1, -1, -1):
        inverted += string[i]
        # print(inverted)
    if inverted == string:
        print(f"{string} adalah palindrom")
    else:
        print(f"{string} bukan palindrom")
