#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
private:
    vector<string> elements;  

public:
    void push(const string& item) {
        elements.push_back(item);
        cout << "Đã thêm '" << item << "' vào ngăn xếp." << endl;
    }

    void pop() {
        if (!isEmpty()) {
            string item = elements.back();
            elements.pop_back();
            cout << "Đã lấy '" << item << "' ra khỏi ngăn xếp." << endl;
        } else {
            cout << "Ngăn xếp trống!" << endl;
        }
    }

    string peek() const {
        if (!isEmpty()) {
            return elements.back();
        } else {
            throw out_of_range("Ngăn xếp trống!");
        }
    }

    bool isEmpty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }

    void display() const {
        cout << "Ngăn xếp (đỉnh đến đáy): ";
        for(auto it = elements.rbegin(); it != elements.rend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
};


int main() {
    Stack stack;
    stack.push("Sách A");
    stack.push("Sách B");
    stack.push("Sách C");
    stack.display();

    try {
        cout << "Phần tử ở đỉnh ngăn xếp: " << stack.peek() << endl;  
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    stack.pop();
    stack.display(); 
    cout << "Ngăn xếp có trống không? " << (stack.isEmpty() ? "Có" : "Không") << endl;  

    return 0;
}
