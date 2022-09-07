t = int(input())
b = int(input())
k = int(input())


if t > 100 and b <= 150:
        list = [2, 3, 4]
elif t <= 100 and b <= 150:
    if b > 30:
        list = [1, 2]
    else:
        list = [1]
elif b > 150:
    if t <= 100:
        list = [2]
    elif 100 < t <= 200:
        list = [2, 3]
    else:
        list = [0]
else:
    list = [0]


def check(l, k):
    for a in l:
        if a == k:
            return "TRUE"
    return "FALSE"

print(check(list, k))
