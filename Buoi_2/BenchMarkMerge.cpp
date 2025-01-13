#include <iostream>
#include <vector>
#include <chrono> // Để đo thời gian
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};
    auto start = chrono::high_resolution_clock::now(); // Bắt đầu đo thời gian
    mergeSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now(); // Kết thúc đo thời gian
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Kết quả sau MergeSort: ";
    for (int x : arr) cout << x << " ";
    cout << "\nThời gian thực hiện MergeSort: " << duration.count() << " microseconds\n";
    return 0;
}
