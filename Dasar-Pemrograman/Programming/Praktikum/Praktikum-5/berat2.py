def stop(angka):
    if angka == -999:
        return True
    else:
        return False

def valid(angka):
    if 30 <= angka <= 200:
        return True
    else:
        return False

list = []
kondisi = True

berat = int(input())

if berat == -999:
    print("Data kosong")
else:
    list.append(berat)
    while kondisi:
        tempberat = int(input())
        kondisi = not(stop(tempberat))
        list.append(tempberat)

list_valid = []
for i in range(len(list)):
    if valid(list[i]):
        list_valid.append(list[i])

banyak = len(list_valid)
dibawah50 = 0
diatas100 = 0
jumlah = 0

if banyak == 0:
    print("Data kosong")
else:
    for i in range(banyak):
        if list_valid[i] <= 50:
            dibawah50 += 1
        elif list_valid[i] >= 100:
            diatas100 += 1
        jumlah += list[i]
    rata = jumlah/banyak

    print(banyak)
    print(dibawah50)
    print(diatas100)
    print(round(rata))