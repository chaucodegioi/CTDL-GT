function partition!(arr, low::Int,high::Int)
    pivot = arr[high]
    i = low - 1
    for j in low:(high-1)
        if arr[j] <= pivot
            i+=1
            arr[i], arr[j] = arr[j], arr[i] 
        end
    end
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1
end

function quick_sort!(arr, low::Int, high::Int)
    if low < high
        p = partition!(arr, low, high) 
        quick_sort!(arr, low, p-1) 
        quick_sort!(arr, p+1, high)
    end
    return arr
end
#TEST
arr=[5,2,9,1,5,6]
quick_sort!(arr,1,length(arr))
println("Kết quả của Quick Sort: ",arr)