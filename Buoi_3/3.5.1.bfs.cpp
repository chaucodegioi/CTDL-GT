#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void bfs(unordered_map<char, vector<char>>& graph, char start) {
    queue<char> q;
    unordered_set<char> visited;
    
    q.push(start);
    
    while (!q.empty()) {
        char vertex = q.front();
        q.pop();
        
        if (visited.find(vertex) == visited.end()) {
            cout << vertex << " ";
            visited.insert(vertex);
            // Thêm tất cả các nút kề của vertex vào hàng đợi cùng lúc (giống Python)
            cout << "Đã thêm các nút kề của '" << vertex << "' vào hàng đợi: ";
            for (char neighbor : graph[vertex]) {
                q.push(neighbor);
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };
    
    cout << "BFS từ nút A: " << endl;
    bfs(graph, 'A');
    
    return 0;
}
