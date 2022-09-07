ip = float(input())
pot = float(input())

def beasiswa(i, p):
    if i >= 3.5:
        return 4
    elif p < 1 and i < 3.5:
        return 1
    elif 1 <= p < 5 and ip < 3.5:
        if ip >= 2.0:
            return 3
        else:
            return 2
    else:
        return 0

print(beasiswa(ip, pot))