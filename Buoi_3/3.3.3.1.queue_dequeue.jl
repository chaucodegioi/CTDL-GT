using DataStructures

mutable struct Queue
    elements :: Deque{Any} 
    Queue() = new(Deque{Any}())
end

function enqueue!(q::Queue, item)
    push!(q.elements, item) 
    println("Đã thêm '$item' vào hàng đợi.")
end

function dequeue!(q::Queue)
    if !isempty(q.elements)
        item = popfirst!(q.elements) 
        println("Đã lấy '$item' ra khỏi hàng đợi.") 
        return item
    else
        println("Hàng đợi trống!")
        return nothing
    end
end


function front(q::Queue)
    if !isempty(q.elements)
        return first(q.elements) 
    else
        println("Hàng đợi trống!") 
        return nothing
    end
end
function is_empty(q::Queue)
    return isempty(q.elements)
end

function display(q::Queue)
    println("Hàng đợi (đầu đến cuối): ", collect(q.elements))
end

function main()
    queue = Queue()
    enqueue!( queue, "Tài Liệu 1")
    enqueue!( queue, "Tài Liệu 2")
    enqueue!( queue, "Tài Liệu 3")
    display(queue)
front_item = front(queue)
println("Phần tử ở đầu hàng đợi: ", front_item) 
dequeue!(queue)
display(queue) 
println("Hàng đợi có trống không? ", is_empty(queue) ? "Có" : "Không") 
end

main()