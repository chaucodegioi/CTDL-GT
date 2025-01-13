def partition (arr, low, high):
    pivot = arr[high] 
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i] 
    arr[i+1], arr[high] = arr[high], arr[i+1] 
    return i+1
def quick_sort (arr, low, high):
    if low < high:
        p = partition (arr, low, high) 
        quick_sort(arr, low, p-1) 
        quick_sort(arr, p+1, high)
# Tìm vị trí pivot
# Sắp xếp phần bên trái của pivot # Sắp xếp phần bên phải của pivot
if __name__== "__main__":
    arr = [5, 2, 9, 1, 5, 6]
    quick_sort(arr, 0, len(arr)-1)
    print("Kết quả Quick Sort:", arr)