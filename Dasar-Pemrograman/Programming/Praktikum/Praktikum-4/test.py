angka = int(input())

if angka > 0 and (angka % 2) == 1:
    
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

    for x in range(len(matrix)):
        for y in range((len(matrix[x]))):
            print(matrix[x][y], end="")
        print("")

else:
    print("Masukan tidak valid")