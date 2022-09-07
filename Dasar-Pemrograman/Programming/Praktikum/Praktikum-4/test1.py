angka = int(input("angka (ganjil): "))
matrix = [[] for i in range(angka)]
for i in range(angka // 2 + 1):
    baris = ["" for x in range(angka)]
    for j in range(angka):
        if j+1 <= (angka - ((i+1)*2 - 1)):
            baris[j] = " "
        else:
            baris[j] = "*"
    matrix[i] = baris
    matrix[angka - i - 1] = baris

matrixbaru = [[] for i in range(angka)]
for i in range(angka):
    if angka // 2 - i > 0:
        matrixbaru[i] = matrix[angka//2 - i]
    else:
        matrixbaru[i] = matrix[i - angka//2]

for x in range(len(matrixbaru)):
    for y in range((len(matrixbaru[x]))):
        print(matrixbaru[x][y], end="")
    print("")