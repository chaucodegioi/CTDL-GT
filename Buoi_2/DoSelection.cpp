#include <iostream>
#include <vector>
#include <chrono> // Thư viện để đo thời gian

using namespace std;
using namespace chrono; // Để dễ gọi các đối tượng từ chrono

// Hàm Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Tìm chỉ số của phần tử nhỏ nhất trong [i..n-1]
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }   
        }
        // Hoán đổi nếu minIndex khác i
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};
    
    // Đo thời gian bắt đầu
    auto start = high_resolution_clock::now();

    selectionSort(arr);

    // Đo thời gian kết thúc
    auto end = high_resolution_clock::now();

    // Tính toán thời gian thực thi
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Thoi gian thuc hien Selection Sort: " << duration.count() << " microseconds" << endl;

    // In kết quả sau khi sắp xếp
    cout << "Ket qua sau Selection Sort: ";
    for (int x : arr) 
        cout << x << " ";
    cout << endl;

    return 0;
}
