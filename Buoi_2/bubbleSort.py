
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1): 
        swapped = False
        for j in range(n - 1 - i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+ 1] = arr[j+1], arr[j] 
                swapped = True
        if not swapped:
            break
if __name__ == "__main__": 
    arr = [5, 2, 9, 1, 5] 
    bubble_sort(arr)
    print("Kết quả sau Bubble Sort:", arr)