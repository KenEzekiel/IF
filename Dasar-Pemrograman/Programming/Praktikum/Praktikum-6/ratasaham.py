# Program RataRataSaham
# Spesifikasi : ....
import tulisdata

# KAMUS
# namafile: string
mark = "99999999"
        

# ALGORITMA PROGRAM UTAMA
namafile = input()
tulisdata.TulisDataSaham(namafile)

file = open(namafile, "r")
array_item = []
item1 = file.readline()

if item1 == mark:
    print("File kosong")
else:
    while item1 != mark:
        item2 = file.readline()
        item3 = file.readline()
        item_tuple = (int(item1), item2, int(item3))
        array_item.append(item_tuple)
        item1 = file.readline()
    
    array_item.sort(key=lambda tup: tup[0])
    array_item.append("mark")
    i = 0
    while array_item[i] != "mark":
        pemilik = array_item[i][0]
        total = 0
        count = 0
        while True:
            total += array_item[i][2]
            count += 1
            i += 1
            if pemilik != array_item[i][0]:
                break
        rata = "%.2f" %(total / count)
        print(str(pemilik) + "=" + str(rata))

file.close()