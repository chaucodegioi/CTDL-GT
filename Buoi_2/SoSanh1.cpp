#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   
using namespace std;

// Hàm Bubble Sort 
int bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    int swapCount = 0; // Đếm số lần hoán đổi
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++; // Tăng số lần hoán đổi
                swapped = true;
            }
        }
        if (!swapped) break; // Thoát nếu không có hoán đổi
    }
    return swapCount;
}

// Hàm Selection Sort 
int selectionSort(vector<int>& arr) {
    int n = arr.size();
    int swapCount = 0; // Đếm số lần hoán đổi
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swapCount++; // Tăng số lần hoán đổi
        }
    }
    return swapCount;
}

int main() {
    srand(time(0)); 
    vector<int> arr(10);
    for (int& x : arr) x = rand() % 100; // Các phần tử trong khoảng [0, 99]

    // In mảng ban đầu
    cout << "Mang ban dau: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Đếm hoán đổi Bubble Sort
    vector<int> arr1 = arr; // Sao chép mảng
    int bubbleSwaps = bubbleSort(arr1);

    // Đếm hoán đổi Selection Sort
    vector<int> arr2 = arr; // Sao chép mảng
    int selectionSwaps = selectionSort(arr2);

    // In kết quả
    cout << "Ket qua Bubble Sort: ";
    for (int x : arr1) cout << x << " ";
    cout << "\nSo lan hoan doi (Bubble Sort): " << bubbleSwaps << endl;

    cout << "Ket qua Selection Sort: ";
    for (int x : arr2) cout << x << " ";
    cout << "\nSo lan hoan doi (Selection Sort): " << selectionSwaps << endl;

    // So sánh số lần hoán đổi
    if (bubbleSwaps < selectionSwaps) {
        cout << "Bubble Sort thuc hien it hoan doi hon Selection Sort." << endl;
    } else if (bubbleSwaps > selectionSwaps) {
        cout << "Selection Sort thuc hien it hoan doi hon Bubble Sort." << endl;
    } else {
        cout << "Hai thuat toan thuc hien so lan hoan doi bang nhau." << endl;
    }

    return 0;
}
