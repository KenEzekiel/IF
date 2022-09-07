# Program SortSiswa
# Spesifikasi : ....
import tulisdata

# KAMUS
# namafile: string
mark = "99999999"

def sort(array: list):
    for idx_pass in range(1, len(array)):
        temp = array[idx_pass]
        i = idx_pass - 1

        while (temp[0] < array[i][0]) and (i >= 0):
            array[i+1] = array[i]
            i -= 1
        
        array[i+1] = temp

# ALGORITMA PROGRAM UTAMA
namafile = input()
tulisdata.TulisDataSiswa(namafile)

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
    
    sort(array_item)

    for i in range(len(array_item)):
        print(array_item[i][0], end=",")
        print(array_item[i][1].rstrip(), end=",")
        print(array_item[i][2])

file.close()