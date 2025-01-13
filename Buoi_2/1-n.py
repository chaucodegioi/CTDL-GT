function sum_1_to_n(n)
    s = 0  # Khởi tạo s = 0
    for i in 1:n  # Lặp từ 1 đến n
        s += i  # Cộng dồn vào s
    end
    return s
end

n = 5
println("Tong 1..n = $(sum_1_to_n(n))")
