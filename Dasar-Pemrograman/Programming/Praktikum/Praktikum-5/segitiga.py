alas_tinggi = input()
alas = ""
tinggi = ""
state = 0
for i in range(len(alas_tinggi)):
    if state == 0 and alas_tinggi[i] != " ":
        alas += alas_tinggi[i]
    elif state == 0 and alas_tinggi[i] == " ":
        state += 1
    elif state == 1 and alas_tinggi[i] != " ":
        tinggi += alas_tinggi[i]
    elif state == 2:
        break

alas = int(alas)
tinggi = int(tinggi)

if alas > 0 and tinggi > 0:
    luas = round(0.5 * alas * tinggi)
    print(luas)
else:
    print("Alas dan tinggi harus > 0")