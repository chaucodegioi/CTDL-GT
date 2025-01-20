
class Robot:
    def __init__(self):
        self.position = [0, 0] # [x, y]
        self.direction = 'N' # N, E, S, W
        self.history=[] # Ngăn xếp lưu trữ các lệnh

    def move_forward(self,is_undo=False):
        if self.direction == 'N' :
            self.position[1] += 1
        elif self.direction == 'E':
            self.position[0] += 1
        elif self.direction == 'S':
            self.position[1] -= 1
        elif self.direction == 'W':
            self.position[0] -= 1 
        if not is_undo:
            self.history.append('forward')
        print(f"Đang tiến lên. Vị trí hiện tại: {self.position}, Hướng: {self.direction}")

    def move_backward(self,is_undo=False):
        if self.direction == 'N':
            self.position[1] -= 1
        elif self.direction == 'E':
            self.position[0] -= 1
        elif self.direction == 'S':
            self.position[1] += 1
        elif self.direction == 'W' :
            self.position[0] += 1
        if not is_undo:
            self.history.append('backward')
        print(f"Đang lùi lại. Vị trí hiện tại: {self.position}, Hướng: {self.direction}")

    def turn_left(self,is_undo=False):
        dirs = ['N', 'W', 'S', 'E']
        idx = dirs.index(self.direction)
        self.direction = dirs[(idx + 1) % 4]
        if not is_undo:
            self.history.append('left')
        print(f"Đang quay trái. Vị trí hiện tại: {self.position}, Hướng: {self.direction}")

    def turn_right(self,is_undo=False):
        dirs = ['N', 'E', 'S', 'W']
        idx = dirs.index (self.direction) 
        self.direction = dirs[(idx + 1) % 4]
        if not is_undo:
            self.history.append('right')
        print(f"Đang quay phải. Vị trí hiện tại: {self.position}, Hướng: {self.direction}")

    def undo (self):
        if not self.history:
            print("Không có lệnh nào để hoàn tác.")
            return
        last_command = self.history.pop() 
        print(f"Hoàn tác lệnh: {last_command}") 
        if last_command == 'forward':
            self.move_backward(is_undo=True)
        elif last_command == 'backward':
            self.move_forward(is_undo=True)
        elif last_command == 'left':
            self.turn_right(is_undo=True)
        elif last_command == 'right': 
            self.turn_left(is_undo=True)

    def display_status(self):
        print(f"Vị trí: {self.position}, Hướng: {self.direction}")
# Minh họa
if __name__ == "__main__":
    robot=Robot()
    robot.move_forward()
    robot.turn_right()
    robot.move_forward()
    robot.turn_left()
    robot.move_backward()
    robot.display_status()
    
    print("\nThực hiện Undo:")
    robot.undo()
    robot.undo()
    robot.display_status()