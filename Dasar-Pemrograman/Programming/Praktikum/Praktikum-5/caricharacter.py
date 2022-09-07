lanjut = False
while not lanjut:
    N = int(input())
    if 0 < N <= 100:
        lanjut = True
    else:
        print("Masukan salah. Ulangi!")

arraychar = ['' for i in range(N)]
for i in range(N):
    arraychar[i] = input()

hurufkecil = 'abcdefghijklmnopqrstuvwxyz'
hurufbesar = hurufkecil.upper()

CC = input()

if CC == 'S' or CC == 's':
    found = False
    for i in range(len(arraychar)):
        if arraychar[i] in hurufkecil:
            found = True
            print(i+1, arraychar[i])
            break
    if not found:
        print("Tidak ada huruf kecil")
elif CC == 'L' or CC == 'l':
    found = False
    for i in range(len(arraychar)):
        if arraychar[i] in hurufbesar:
            found = True
            print(i+1, arraychar[i])
            break
    if not found:
        print("Tidak ada huruf besar")
elif CC == 'X' or CC == 'x':
    found = False
    for i in range(len(arraychar)):
        if (arraychar[i] not in hurufbesar) and (arraychar[i] not in hurufkecil):
            found = True
            print(i+1, arraychar[i])
            break
    if not found:
        print("Semua huruf")
else:
    print("Tidak diproses")
