#include <iostream>
#include <vector>
#include <chrono> // Thư viện để đo thời gian

using namespace std;
using namespace chrono; // Để dễ gọi các đối tượng từ chrono

// Hàm Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) { // Giảm dần phạm vi sắp xếp
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};

    // Đo thời gian bắt đầu
    auto start = high_resolution_clock::now();

    bubbleSort(arr);

    // Đo thời gian kết thúc
    auto end = high_resolution_clock::now();

    // Tính toán thời gian thực thi
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Thoi gian thuc hien Bubble Sort: " << duration.count() << " microseconds" << endl;

    // In kết quả sau khi sắp xếp
    cout << "Ket qua sau Bubble Sort: ";
    for (int x : arr) 
        cout << x << " ";
    cout << endl;

    return 0;
}
