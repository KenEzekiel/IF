def get_max(arr: list, index_start: int):
  # mendapatkan maksimum array dari indeks indeks_start sampai selesai
    max = arr[index_start]
    for i in range(index_start + 1, len(arr)):
        if arr[i] > max:
            max = arr[i]
    return max


def get_idx(arr: list, number: int):
   # mendapatkan index dari suatu angka dalam array
    for i in range(len(arr)):
        if arr[i] == number:
            return i


def swap(array: list, indeks_1: int, indeks_2: int):
  # swap elemen array indeks 1 dengan indeks 2
    temp = array[indeks_1]
    array[indeks_1] = array[indeks_2]
    array[indeks_2] = temp


def sort(arr):
  for i in range(len(arr)):
    maxArr = get_max(arr, i)
    maxIdx = get_idx(arr, maxArr)
    swap(arr, i, maxIdx)
  print(arr)

N = int(input())
arr = [0 for i in range(N)]

for i in range(N):
    arr[i] = int(input())

sort(arr)