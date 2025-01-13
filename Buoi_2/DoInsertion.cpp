#include <iostream>
#include <vector>
#include <chrono> // Thư viện để đo thời gian

using namespace std;
using namespace chrono; // Để dễ gọi các đối tượng từ chrono

// Hàm Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Di chuyển các phần tử lớn hơn key sang phải
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j];
            j--;
        }
        // Chèn key vào vị trí đúng
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};

    // Đo thời gian bắt đầu
    auto start = high_resolution_clock::now();

    insertionSort(arr);

    // Đo thời gian kết thúc
    auto end = high_resolution_clock::now();

    // Tính toán thời gian thực thi
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Thoi gian thuc hien Insertion Sort: " << duration.count() << " microseconds" << endl;

    // In kết quả sau khi sắp xếp
    cout << "Ket qua sau Insertion Sort: ";
    for (int x : arr) 
        cout << x << " ";
    cout << endl;

    return 0;
}
