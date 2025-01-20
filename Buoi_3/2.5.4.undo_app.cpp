#include <iostream>
#include <stack>
#include <string>

class TextEditor {
private:
    std::string text;
    std::stack<std::string> undo_stack;
    std::stack<std::string> redo_stack;

public:
    TextEditor() : text("") {}

    void type_text(const std::string& new_text) {
        undo_stack.push(text);
        text += new_text;
        while (!redo_stack.empty()) redo_stack.pop(); // Clear redo stack
        std::cout << "Đã gõ: " << new_text << std::endl;
        display();
    }

    void undo() {
        if (!undo_stack.empty()) {
            redo_stack.push(text);
            text = undo_stack.top();
            undo_stack.pop();
            std::cout << "Đã hoàn tác hành động." << std::endl;
            display();
        } else {
            std::cout << "Không có hành động nào để hoàn tác." << std::endl;
        }
    }

    void redo() {
        if (!redo_stack.empty()) {
            undo_stack.push(text);
            text = redo_stack.top();
            redo_stack.pop();
            std::cout << "Đã làm lại hành động." << std::endl;
            display();
        } else {
            std::cout << "Không có hành động nào để làm lại." << std::endl;
        }
    }

    void display() {
        std::cout << "Văn bản hiện tại: '" << text << "'\n" << std::endl;
    }
};

int main() {
    TextEditor editor;
    editor.type_text("Hello");
    editor.type_text(" World");
    editor.undo();
    editor.undo();
    editor.redo();
    return 0;
}
