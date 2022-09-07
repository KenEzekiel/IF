def cek(n):
  if n>= 0 and n<=100 :
    return True
  else:
    return False

n = int(input())
while not cek(n):
    print("Masukan salah. Ulangi!")
    n = int(input())
    cek(n)

array = [0 for i in range (n)]
for i in range (n):
  array[i] = (int(input()))
x = int(input())
iter = 0

if x == 0:
    ketemu = False
    for i in range(len(array)):
        if array[i] == 0:
            ketemu = True
            print(str(i+1))
            break
    if ketemu == False:
        print("Tidak ada 0")

elif x == 1:
    ketemu = False
    for i in range(len(array)):
        if array[i] > 0:
            ketemu = True
            print(str(i+1) + " " + str(array[i]))
            break
    if ketemu == False:
        print("Tidak ada positif")


elif x == -1:
    ketemu = False
    for i in range(len(array)):
        if array[i] < 0:
            ketemu = True
            print(str(i+1) + " " + str(array[i]))
            break
    if ketemu == False:
        print("Tidak ada negatif")

else:
  print("Tidak diproses")