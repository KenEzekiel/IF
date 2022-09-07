def validasi(x):
    if x == -999:
        return True
    else:
        return False

berat = int(input())
arrayberat = []
input_valid = False
if berat == -999:
    print("Data kosong")
else:
    arrayberat.append(berat)
    while not input_valid:
        tempberat = int(input())
        arrayberat.append(tempberat)
        input_valid = validasi(tempberat)
        
    arrayvalid = []
    for i in range (len(arrayberat)):
        if 30 <= arrayberat[i] <= 200:
            arrayvalid.append(arrayberat[i])

    less50 = 0
    more100 = 0
    total = 0
    avg = 0
    if len(arrayvalid) == 0:
        print("Data kosong")
    else:
        for i in range (len(arrayvalid)):
            if arrayvalid[i] <= 50:
                less50 += 1
            elif arrayvalid[i] >= 100:
                more100 += 1
            total = total + arrayvalid[i]

        avg = total/len(arrayvalid)
        print(len(arrayvalid))
        print(less50)
        print(more100)
        print(round(avg))