#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>

void dfs(const std::unordered_map<char, std::vector<char>>& graph, char start) {
    std::stack<char> stack;
    std::set<char> visited;
    stack.push(start);

    while (!stack.empty()) {
        char vertex = stack.top();
        stack.pop();

        if (visited.find(vertex) == visited.end()) {
            std::cout << vertex << " ";
            visited.insert(vertex);

            std::vector<char> neighbors = graph.at(vertex);
            std::reverse(neighbors.begin(), neighbors.end()); // Đảo ngược thứ tự
            for (char neighbor : neighbors) {
                stack.push(neighbor);
            }

            std::cout << "Đã đẩy các nút kề của '" << vertex << "' vào ngăn xếp: ";
            for (char neighbor : neighbors) {
                std::cout << neighbor << " ";
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

int main() {
    std::unordered_map<char, std::vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };

    std::cout << "DFS từ nút A:\n";
    dfs(graph, 'A');
    return 0;
}
