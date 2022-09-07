# NIM / Nama    : 16521040 / Kenneth Ezekiel Suprantoni
# Tanggal       : 17/11/2021
# Deskripsi     : Menghitung volume rumah Tuan Ric

# Kamus
# sisi_kubus, tinggi_limas : float

# Algoritma
sisi_kubus = float(input("Masukkan panjang sisi kubus: "))
tinggi_limas = float(input("Masukkan tinggi limas: "))

def volumeKubus(s):
    return s**3

def volumeLimas(s, t):
    return (s * s * t)/3

print(f"Volume rumah yang terbentuk adalah {volumeKubus(sisi_kubus) + volumeLimas(sisi_kubus, tinggi_limas)} meter kubik.")