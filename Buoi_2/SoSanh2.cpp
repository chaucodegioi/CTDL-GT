#include <iostream>
#include <vector>
#include <chrono> // Để đo thời gian
using namespace std;

// MergeSort
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

// BubbleSort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) { // Tối ưu phạm vi
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
    vector<int> arr1 = {5, 2, 9, 1, 5, 6, 3, 8, 7, 4}; 
    vector<int> arr2 = arr1; 

    // Đo thời gian MergeSort
    auto startMerge = chrono::high_resolution_clock::now();
    mergeSort(arr1, 0, arr1.size() - 1);
    auto endMerge = chrono::high_resolution_clock::now();
    auto durationMerge = chrono::duration_cast<chrono::microseconds>(endMerge - startMerge);

    cout << "Kết quả sau MergeSort: ";
    for (int x : arr1) cout << x << " ";
    cout << "\nThời gian thực hiện MergeSort: " << durationMerge.count() << " microseconds\n";

    // Đo thời gian BubbleSort
    auto startBubble = chrono::high_resolution_clock::now();
    bubbleSort(arr2);
    auto endBubble = chrono::high_resolution_clock::now();
    auto durationBubble = chrono::duration_cast<chrono::microseconds>(endBubble - startBubble);

    cout << "Kết quả sau BubbleSort: ";
    for (int x : arr2) cout << x << " ";
    cout << "\nThời gian thực hiện BubbleSort: " << durationBubble.count() << " microseconds\n";

    // So sánh thời gian
    if (durationMerge.count() < durationBubble.count()) {
        cout << "\nMergeSort nhanh hơn BubbleSort " << (durationBubble.count() - durationMerge.count()) << " microseconds.\n";
    } else if (durationMerge.count() > durationBubble.count()) {
        cout << "\nBubbleSort nhanh hơn MergeSort " << (durationMerge.count() - durationBubble.count()) << " microseconds.\n";
    } else {
        cout << "\nMergeSort và BubbleSort có thời gian thực hiện bằng nhau.\n";
    }

    return 0;
}
