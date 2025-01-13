#include <iostream>
#include <vector>
#include <limits.h>
#include <chrono>  // Thêm thư viện chrono

int FindMax(const std::vector<int>& A) {
    if (A.empty()) {
        std::cerr << "Error: Empty array!" << std::endl;
        return INT_MIN; // Return minimum integer value
    }
    
    int max = A[0];
    for (size_t i = 1; i < A.size(); ++i) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

int main() {
    std::vector<int> A = {3, 5, 2, 9, 1};
    
    // Đo thời gian bắt đầu
    auto start = std::chrono::high_resolution_clock::now();
    
    int maxVal = FindMax(A);
    
    // Đo thời gian kết thúc
    auto end = std::chrono::high_resolution_clock::now();
    
    if (maxVal != INT_MIN) {
        std::cout << "Giá trị lớn nhất trong mảng là: " << maxVal << std::endl;
    }
    
    // Tính toán thời gian thực thi
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Thời gian thực thi: " << duration.count() << " micro giây" << std::endl;

    return 0;
}
