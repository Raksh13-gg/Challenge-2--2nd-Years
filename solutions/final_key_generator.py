import os


clue1 = 385  
clue2 = 4    
clue3 = 4    


hex_clue1 = hex(clue1)[2:]

clue2_repeated = str(clue2) * clue3

final_key = f"{hex_clue1}-{clue2_repeated}"


BASE_DIR = os.path.dirname(os.path.abspath(__file__))
output_path = os.path.join(BASE_DIR, "final_key.txt")

with open(output_path, "w", encoding="utf-8") as f:
    f.write(final_key)

print("Final Key:", final_key)
