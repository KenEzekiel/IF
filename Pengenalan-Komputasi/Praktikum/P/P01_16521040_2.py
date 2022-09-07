# NIM / Nama : 16521040
# Tanggal    : Kenneth Ezekiel Suprantoni
# Deskripsi  : Program untuk menentukan harga kursi 

# Kamus
# nomor, harga : int
# posisi, tipe_kursi : str

# Algoritma
nomor = int(input("Tentukan nomor kursi (XXX): "))
posisi = input("Tentukan posisi kursi: ")
harga = 0
tipe_kursi = ""

if (1 <= nomor <= 20) or (51 <= nomor <= 60):
    tipe_kursi = "Hot Seat"
    if (posisi == "A") or (posisi == "F"):
        harga = 1600000
    elif (posisi == "B") or (posisi == "E"):
        harga = 1550000
    elif (posisi == "C") or (posisi == "D"):
        harga = 1500000
elif (21 <= nomor <= 50) or (61 <= nomor <= 100):
    tipe_kursi = "Regular"
    if (posisi == "A") or (posisi == "F"):
        harga = 1000000
    elif (posisi == "B") or (posisi == "E"):
        harga = 950000
    elif (posisi == "C") or (posisi == "D"):
        harga = 900000

print("Tuan Kil memilih kursi", tipe_kursi, "dengan harga", harga)