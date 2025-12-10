
import os


BASE_DIR = os.path.dirname(os.path.abspath(__file__))


input2_path = os.path.join(BASE_DIR, "../inputs/input2.txt")


with open(input2_path, "r", encoding="utf-8") as f:
    original_string = f.read().strip()

reversed_string = original_string[::-1]


k = 3
filtered_string = ''.join([c for i, c in enumerate(reversed_string, 1) if i % k != 0])

shifted_string = ''.join([chr(ord(c) + 2) for c in filtered_string])


vowels = "aeiouAEIOU"
clue2 = sum(1 for c in shifted_string if c in vowels)


print("Clue 2:", clue2)


