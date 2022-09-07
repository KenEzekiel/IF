# KAMUS

# ALGORITMA

def validN(n):
    if (0 < n) and (n <= 100):
        return True
    else:
        return False

N = int(input())

while not validN(N):
    print("Masukan salah. Ulangi!")
    N = int(input())

array = [0 for i in range(N)]
for i in range(N):
    array[i] = int(input())

X = int(input())
def nilaiX(arr, eks):
    if eks == 0:
        if 0 in arr:
            for i in range(len(arr)):
                if arr[i] == 0:
                    print(str(i+1))
                    break
        else:
            print("Tidak ada 0")
    elif eks == -1:
        ada_negatif = False
        for i in range(len(arr)):
            if arr[i] < 0:
                print(str(i+1) + " " + str(arr[i]))
                ada_negatif = True
                break
        if not ada_negatif:
            print("Tidak ada negatif")
    elif eks == 1:
        ada_positif = False
        for i in range(len(arr)):
            if arr[i] > 0:
                print(str(i+1) + " " + str(arr[i]))
                ada_positif = True
                break
        if not ada_positif:
            print("Tidak ada positif")
    else:
        print("Tidak diproses")
    
nilaiX(array, X)