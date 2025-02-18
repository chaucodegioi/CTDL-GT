def count_chars(string):
    char_count = {}
    for char in string:
        if char.isalpha():  
            char_count[char] = char_count.get(char, 0) + 1
    return char_count

# Test case
print("Nhập 1 từ để đếm số kí tự: ")
string=input()
print(count_chars(string))

