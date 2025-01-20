function decimal_to_binary(n)
    stack = Int[] # Sử dụng mảng như ngăn xếp
    println("Chuyển đổi số thập phân: $n sang nhị phân.")

    if n == 0
        push!(stack, 0)
        println("Đã đẩy phần dư '0' vào ngăn xếp.")
    end

    while n > 0
        remainder = n % 2
        push!(stack, remainder)
        println("Chia $n cho 2, phần dư: $remainder --> Đẩy $remainder vào ngăn xếp")
        n = div(n, 2) # Lấy thương nguyên
        println("Thương mới: $n")
    end

    binary = ""
    println("Chuyển đổi ngăn xếp thành số nhị phân:")
    while !isempty(stack)
        digit = pop!(stack)
        binary *= string(digit)
        println("Lấy $digit từ ngăn xếp và nối vào kết quả.")
    end

    return binary
end

number = 13
binary = decimal_to_binary(number)
println("Số thập phân $number chuyển sang nhị phân là $binary")
