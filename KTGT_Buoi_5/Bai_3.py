import re
from collections import Counter

def word_count(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        text = file.read().lower()  
        words = re.findall(r'\b[a-zA-Z]+\b', text)  
    return dict(Counter(words)) 


file_path = r'C:\Users\bangv\Desktop\KTGT_Buoi_5\P1_data.txt'  
word_counts = word_count(file_path)
print(word_counts)
