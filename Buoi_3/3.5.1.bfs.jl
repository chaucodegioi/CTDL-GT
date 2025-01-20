function bfs(graph, start)
    queue = [start]
    visited = Set()
    
    while !isempty(queue)
        vertex = popfirst!(queue)
        
        if !(vertex in visited)
            print(vertex, " ")
            push!(visited, vertex)
            println("Đã thêm các nút kề của '$vertex' vào hàng đợi: ", graph[vertex])
            append!(queue, graph[vertex])
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

println("BFS từ nút A: ")
bfs(graph, 'A')
