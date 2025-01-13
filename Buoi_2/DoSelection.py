import time

def selection_sort(arr): 
    n = len(arr)
    for i in range(n - 1):
        # Tìm chỉ số của phần tử nhỏ nhất trong [i..n-1] 
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]: 
                min_index = j
        # Hoán đổi nếu min_index khác i
        if min_index != i:
            arr[i], arr[min_index] = arr[min_index], arr[i]

if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5]
    
    # Ghi lại thời gian bắt đầu
    start_time = time.time()
    
    selection_sort(arr)
    
    # Ghi lại thời gian kết thúc
    end_time = time.time()
    
    # Tính toán và in ra thời gian thực hiện
    execution_time = end_time - start_time
    print("Kết quả sau Selection Sort:", arr)
    print(f"Thời gian thực hiện: {execution_time} giây")
