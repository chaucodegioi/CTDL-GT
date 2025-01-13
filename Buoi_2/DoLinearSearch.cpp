#include <iostream>
#include <vector>
#include <chrono>  // Thêm thư viện chrono

int LinearSearch(const std::vector<int>& A, int x) {
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] == x) {
            return static_cast<int>(i);
        }
    }
    return -1; // Not found
}

int main() {
    std::vector<int> A = {3, 5, 2, 9, 1};
    int x = 9;
    
    // Đo thời gian bắt đầu
    auto start = std::chrono::high_resolution_clock::now();
    
    int index = LinearSearch(A, x);
    
    // Đo thời gian kết thúc
    auto end = std::chrono::high_resolution_clock::now();
    
    if (index != -1) {
        std::cout << "Giá trị " << x << " được tìm thấy tại vị trí: " << index << std::endl;
    } else {
        std::cout << "Giá trị " << x << " không tồn tại trong mảng." << std::endl;
    }

    // Tính toán thời gian thực thi
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Thời gian thực thi: " << duration.count() << " micro giây" << std::endl;

    return 0;
}
