import time

def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1): 
        swapped = False
        for j in range(n - 1 - i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j] 
                swapped = True
        if not swapped:
            break

if __name__ == "__main__": 
    arr = [5, 2, 9, 1, 5]

    # Ghi lại thời gian bắt đầu
    start_time = time.time()
    
    bubble_sort(arr)
    
    # Ghi lại thời gian kết thúc
    end_time = time.time()
    
    # Tính toán và in ra thời gian thực hiện
    execution_time = end_time - start_time
    print("Kết quả sau Bubble Sort:", arr)
    print(f"Thời gian thực hiện: {execution_time} giây")
