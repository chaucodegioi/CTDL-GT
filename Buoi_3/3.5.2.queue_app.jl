mutable struct RequestQueue
    queue::Vector{String}
end

# Hàm khởi tạo
function RequestQueue()
    return RequestQueue(String[])
end

function add_request(rq::RequestQueue, request::String)
    push!(rq.queue, request)
    println("Đã thêm yêu cầu '$request' vào hàng đợi.")
end

function process_request(rq::RequestQueue)
    if !isempty(rq.queue)
        request = popfirst!(rq.queue)
        println("Đang xử lý yêu cầu: $request")
    else
        println("Không có yêu cầu nào để xử lý.")
    end
end

function display_queue(rq::RequestQueue)
    if isempty(rq.queue)
        println("Hàng đợi yêu cầu: Rỗng")
    else
        println("Hàng đợi yêu cầu: ", rq.queue)
    end 
end

# Main
rq = RequestQueue()  # Khởi tạo đối tượng hàng đợi
add_request(rq, "Yêu Cầu 1")
add_request(rq, "Yêu Cầu 2")
add_request(rq, "Yêu Cầu 3")
display_queue(rq)
process_request(rq)
display_queue(rq)
process_request(rq)
display_queue(rq)
process_request(rq)
display_queue(rq)
process_request(rq)
