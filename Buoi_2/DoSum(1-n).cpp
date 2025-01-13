#include <iostream>
#include <chrono>  // Thêm thư viện chrono

using namespace std;

int sum_1_to_n(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}

int main() {
    cout << "Nhap n: ";
    int n;
    cin >> n;
    
    // Đo thời gian bắt đầu
    auto start = chrono::high_resolution_clock::now();
    
    int result = sum_1_to_n(n);
    
    // Đo thời gian kết thúc
    auto end = chrono::high_resolution_clock::now();
    
    cout << "Tong 1..n = " << result << endl;
    
    // Tính toán thời gian thực thi
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Thoi gian thuc thi: " << duration.count() << " micro giay" << endl;

    return 0;
}
