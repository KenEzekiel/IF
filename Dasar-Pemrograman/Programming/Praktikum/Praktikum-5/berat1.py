valid = True
array = []

while valid:
    berat = int(input())
    if berat >= 30 and berat <= 200:
        array.append(berat)
    elif berat == -999:
        valid = False

if len(array) == 0:
    print("Data kosong")
else:
    banyak = len(array)
    dibawah50 = 0
    diatas100 = 0
    jumlah = 0
    for i in range(banyak):
        if array[i] <= 50:
            dibawah50 += 1
        elif array[i] >= 100:
            diatas100 += 1
        jumlah += array[i]
    rata = jumlah/banyak

    print(array)
    print(len(array))
    print(dibawah50)
    print(diatas100)
    print(round(rata))
    