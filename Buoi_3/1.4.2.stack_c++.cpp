#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> stack;

    stack.push("Sách A");
    cout << "Đã thêm 'Sách A' vào ngăn xếp." << endl;
    stack.push("Sách B");
    cout << "Đã thêm 'Sách B' vào ngăn xếp." << endl;
    stack.push("Sách C");
    cout << "Đã thêm 'Sách C' vào ngăn xếp." << endl;

    cout << "Phần tử ở đỉnh ngăn xếp: " << stack.top() << endl; 
    stack.pop();
    cout << "Đã lấy phần tử ra khỏi ngăn xếp." << endl;

    cout << "Phần tử ở đỉnh ngăn xếp sau khi pop: " << stack.top() << endl; 

    if (stack.empty()) {
        cout << "Ngăn xếp trống!" << endl;
    } else {
        cout << "Ngăn xếp không trống." << endl; 
    }

    return 0;
}
