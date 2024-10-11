import time
import random

def bubblesort(a):
    start = time.time()
    for i in range(len(a) - 1):
        for j in range(len(a) - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
    end = time.time()
    print("Bubble sort time =", (end - start) * 1000, "ms")

def selectionsort(a):
    start = time.time()
    for i in range(len(a) - 1):
        min_index = i
        for j in range(i + 1, len(a)):
            if a[j] < a[min_index]:
                min_index = j
        a[i], a[min_index] = a[min_index], a[i]
    end = time.time()
    print("Selection sort time =", (end - start) * 1000, "ms")

def insertionsort(a):
    start = time.time()
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and key < a[j]:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key
    end = time.time()
    print("Insertion sort time =", (end - start) * 1000, "ms")

def merge(arr, lb, mid, ub):
    n1 = mid - lb + 1
    n2 = ub - mid
    L = arr[lb:mid+1]
    R = arr[mid+1:ub+1]

    i = j = 0
    k = lb

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def mergesort(arr, lb, ub):
    if lb < ub:
        mid = (lb + ub) // 2
        mergesort(arr, lb, mid)
        mergesort(arr, mid + 1, ub)
        merge(arr, lb, mid, ub)

def mergesort_1(arr, lb, ub):
    start = time.time()
    mergesort(arr, lb, ub)
    end = time.time()
    print("Merge sort time =", (end - start) * 1000, "ms")

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quicksort(arr, low, pi - 1)
        quicksort(arr, pi + 1, high)

def quicksort_1(arr, low, high):
    start = time.time()
    quicksort(arr, low, high)
    end = time.time()
    print("Quick sort time =", (end - start) * 1000, "ms")

def main():
    terms = int(input("Enter number of terms: "))
    arr1 = [random.randint(0, 10000) for _ in range(terms)]
    arr2 = arr1[:]
    arr3 = arr1[:]
    arr4 = arr1[:]
    arr5 = arr1[:]

    quicksort_1(arr5, 0, terms - 1)
    mergesort_1(arr4, 0, terms - 1)
    insertionsort(arr3)
    selectionsort(arr2)
    bubblesort(arr1)

if __name__ == "__main__":
    main()
