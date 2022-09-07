# KAMUS

# ALGORITMA
def resistor():
    R1 = float(input())
    R2 = float(input())
    R3 = float(input())
    pilihan = input().lower()
    valid = ['S', 's', 'P', 'p']
    if R1 > 0 and R2 > 0 and R3 > 0 and pilihan in valid:
        return [True, R1, R2, R3, pilihan]
    else:
        return[False, 0, 0, 0, "x"]

while True:
    array = resistor()
    if array[0]:
        if array[4] == ('s' or 'S'):
            Rt = array[1] + array[2] + array[3]
            print("%.2f" % Rt)
            break
        elif array[4] == ('p' or 'P'):
            Rp = 1/array[1] + 1/array[2] + 1/array[3]
            Rt = 1/Rp
            print("%.2f" % Rt)
            break
    else:
        print("Masukan salah")

