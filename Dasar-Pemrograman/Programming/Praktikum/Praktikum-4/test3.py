def cek(a,b,c,hub):
  benar = ["s","S","p","P"]
  if a>0 and b>0 and c>0 and hub in benar:
    return True
  else:
    print("Masukan salah") 
    return False

kondisi = False
while kondisi == False:
  r1 = float(input())
  r2 = float(input())
  r3 = float(input())
  hub = str(input())
  kondisi = cek(r1,r2,r3,hub)
if hub == "s" or hub == "S":
  total = r1+r2+r3
else:
  total = 1/(1/r1+1/r2+1/r3)
print("%.2f" % total)