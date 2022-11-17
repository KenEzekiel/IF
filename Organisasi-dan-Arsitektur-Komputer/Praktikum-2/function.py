def baris(suku):
    if (suku == 1):
        return 1
    elif (suku == 2):
        return 2;
    else:
        if ((suku % 2) == 0):
            return ((suku - 1) + baris(suku - 1))
        else:
            return ((suku - 1) * baris(suku - 1))

print(baris(1))
print(baris(2))
print(baris(3))
print(baris(4))
print(baris(5))
print(baris(6))