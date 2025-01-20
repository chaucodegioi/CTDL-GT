function dfs(graph, start)
    stack = [start]
    visited = Set{Char}()

    while !isempty(stack)
        vertex = pop!(stack)

        if !(vertex in visited)
            print(vertex, " ")
            push!(visited, vertex)

            neighbors = reverse(graph[vertex])
            append!(stack, neighbors)

            println("Đã đẩy các nút kề của '$vertex' vào ngăn xếp: ", neighbors)
        end
    end
    println()
end

graph = Dict(
    'A' => ['B', 'C'],
    'B' => ['D', 'E'],
    'C' => ['F'],
    'D' => [],
    'E' => ['F'],
    'F' => []
)

println("DFS từ nút A:")
dfs(graph, 'A')
