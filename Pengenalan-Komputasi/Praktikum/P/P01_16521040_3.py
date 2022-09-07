# NIM / Nama : 16521040
# Tanggal    : Kenneth Ezekiel Suprantoni
# Deskripsi  : Program untuk mengecek data tebak-tebakan

# Kamus
# jumlah_kaki, jumlah_orangtua, jumlah_anak, maks_kaki, min_kaki : int

# Algoritma
jumlah_kaki = int(input("Banyak kaki yang menginjak lantai: "))
jumlah_orangtua = int(input("Banyak orang tua: "))
jumlah_anak = int(input("Banyak anak: "))

# Kaki maksimum jika semua anak tidak digendong
maks_kaki = (jumlah_orangtua + jumlah_anak) * 2

# Kaki minimum jika semua anak digendong dengan 1 orang tua maksimum menggendong 2 anak
if jumlah_anak <= (jumlah_orangtua * 2):
    # Kaki minimum hanya dari orang tua karena semua anak dapat digendong
    min_kaki = (jumlah_orangtua) * 2
elif jumlah_anak > (jumlah_orangtua * 2):
    # Kaki minimum dari orang tua ditambah kaki minimum dari anak yang tidak tergendong (total anak - jumlah anak yang digendong)
    min_kaki = (jumlah_orangtua * 2) + (jumlah_anak - (jumlah_orangtua * 2)) * 2

# Cek data

if (min_kaki <= jumlah_kaki <= maks_kaki) and (jumlah_kaki % 2) == 0:
        print("Data Tuan Dip mungkin benar")
else:
        print("Data Tuan Dip tidak mungkin benar")

