N = int(input())
array = [0 for i in range(N)]
for i in range(N):
    array[i] = int(input())

X = int(input())
minimal = min(array)
maximal = max(array)

found = False

for i in range(N):
    if X == array[i]:
        found = True

if found:
    if maximal == minimal and X == minimal:
        print("maksimum")
        print("minimum")
    else:
        if X == maximal:
            print("maksimum")
        elif X == minimal:
            print("minimum")
        else:
            print("N#A")
else:
    print(X, "tidak ada")