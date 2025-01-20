from collections import deque
class Queue:
    def __init__(self):
        self.elements = deque() 
    def enqueue(self, item):
        self.elements.append(item) 
        print(f"Đã thêm '{item}' vào hàng đợi.")
    def dequeue(self):
        if not self.is_empty():
            item = self.elements.popleft() 
            print(f"Đã lấy '{item}' ra khỏi hàng đợi.")
        else:
            return item
            print("Hàng đợi trống!")
        return None
    def front(self):
        if not self.is_empty():
            return self.elements[0] 
        else:
            print("Hàng đợi trống!")
            return None
    def is_empty(self):
        return len(self.elements)== 0 
    def size(self):
        return len(self.elements) 
    def display(self):
        print("Hàng đợi (đầu đến cuối):", list(self.elements)) 

if __name__ == "__main__": 
    queue = Queue()
    queue.enqueue("Tài Liệu 1") 
    queue.enqueue("Tài Liệu 2")
    queue.enqueue("Tài Liệu 3")
    queue.display() 
    front_item= queue.front()
    print("Phần tử ở đầu hàng đợi:", front_item) 
    queue.dequeue()
    queue.display() 
    print("Hàng đợi có trống không?", queue.is_empty()) 