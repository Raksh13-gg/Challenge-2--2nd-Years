import os
import math

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(math.isqrt(n)) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True


BASE_DIR = os.path.dirname(os.path.abspath(__file__))


states_path = os.path.join(BASE_DIR, "../inputs/states.txt")


with open(states_path, "r", encoding="utf-8") as f:
    data = f.read().strip()


states = list(map(int, data.split()))


final_state = 3


terminal_count = 0
for n in states:
    if n % 2 == 0:
    
        state = min(final_state, 1)
    elif is_prime(n):
      
        state = final_state
    else:
   
        state = 0  

    if state == final_state:
        terminal_count += 1


clue3 = terminal_count
print("Clue 3:", clue3)
