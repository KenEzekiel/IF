# NIM / Nama : 16521040
# Tanggal    : Kenneth Ezekiel Suprantoni
# Deskripsi  : Program untuk menghitung pajak penghasilan

# Kamus
# penghasilan : int
# pajak, total_pajak : float

# Algoritma
penghasilan = int(input("Masukkan penghasilan Tuan Ric: "))
pajak = 0.0

if penghasilan < 50000000:
    pajak = 0.05
elif 50000000 <= penghasilan < 250000000:
    pajak = 0.15
elif 250000000 <= penghasilan < 500000000:
    pajak = 0.25
elif penghasilan >= 500000000:
    pajak = 0.30

total_pajak = (float(penghasilan) * pajak)

print("Pajak yang harus dibayar tuan Ric sebesar", int(total_pajak), "rupiah")
