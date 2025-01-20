#include <iostream>
#include <stack>
#include <string>

std::string decimal_to_binary(int n) {
    std::stack<int> stack;
    std::cout << "Chuyển đổi số thập phân: " << n << " sang nhị phân.\n";
    if (n == 0) {
        stack.push(0);
        std::cout << "Đã đẩy phần dư '0' vào ngăn xếp.\n";
    }

    while (n > 0) {
        int remainder = n % 2;
        stack.push(remainder);
        std::cout << "Chia " << n << " cho 2, phần dư: " << remainder << " --> Đẩy " << remainder << " vào ngăn xếp\n";
        n = n / 2;
        std::cout << "Thương mới: " << n << "\n";
    }

    std::string binary = "";
    std::cout << "Chuyển đổi ngăn xếp thành số nhị phân:\n";
    while (!stack.empty()) {
        binary += std::to_string(stack.top());
        std::cout << "Lấy " << stack.top() << " từ ngăn xếp và nối vào kết quả.\n";
        stack.pop();
    }
    return binary;
}

int main() {
    int number = 13;
    std::string binary = decimal_to_binary(number);
    std::cout << "Số thập phân " << number << " chuyển sang nhị phân là " << binary << "\n";
    return 0;
}
