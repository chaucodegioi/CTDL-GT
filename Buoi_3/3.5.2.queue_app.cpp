#include <iostream>
#include <deque>
#include <string>

using namespace std;

class RequestQueue {
private:
    deque<string> queue;
public:
    void add_request(const string& request) {
        queue.push_back(request);
        cout << "Đã thêm yêu cầu '" << request << "' vào hàng đợi." << endl;
    }

    void process_request() {
        if (!queue.empty()) {
            string request = queue.front();
            queue.pop_front();
            cout << "Đang xử lý yêu cầu: " << request << endl;
        } else {
            cout << "Không có yêu cầu nào để xử lý." << endl;
        }
    }

    void display_queue() {
        cout << "Hàng đợi yêu cầu: ";
        for (const string& request : queue) {
            cout << request << " ";
        }
        cout << endl;
    }
};

int main() {
    RequestQueue rq;
    rq.add_request("Yêu Cầu 1");
    rq.add_request("Yêu Cầu 2");
    rq.add_request("Yêu Cầu 3");
    rq.display_queue();
    rq.process_request();
    rq.display_queue();
    rq.process_request();
    rq.display_queue();
    rq.process_request();
    rq.display_queue();
    rq.process_request();

    return 0;
}
