import os

def read_grid(path='inputs/grid.txt'):
    with open(path, 'r', encoding='utf-8') as f:
        raw = [line.rstrip('\n') for line in f if line.strip() != '']
    grid = []
    for line in raw:
        parts = line.split()
        if len(parts) == 1:
            grid.append(parts[0])
        else:
           
            grid.append(''.join(parts))
    return grid

def read_directions(path='inputs/directions.txt'):
    instr = []
    if not os.path.exists(path):
        return instr
    with open(path, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            if not line: continue
            parts = line.split()
            if len(parts) < 3:
                continue
            try:
                r = int(parts[0])
                d = parts[1]
                amt = int(parts[2])
                instr.append((r, d.upper(), amt))
            except:
             
                continue
    return instr

def rotate_row(row, amt, direction):
    if amt == 0: return row
    n = len(row)
    if n == 0: return row
    amt = amt % n
    if amt == 0: return row
    if direction == 'RIGHT':
        return row[-amt:] + row[:-amt]
    else:
      
        return row[amt:] + row[:amt]

def apply_instructions(grid, instr):
    R = len(grid)
  
    if any(r >= R for (r,_,_) in instr) and any(r > 0 for (r,_,_) in instr):
        instr = [(r-1,d,a) if r-1 >= 0 else (r,d,a) for (r,d,a) in instr]
    for (r, d, a) in instr:
        if 0 <= r < R:
            grid[r] = rotate_row(grid[r], a, d)
    return grid

def compute_clue1(grid):
    if len(grid) == 0:
        return 0
    mid = len(grid) // 2 
    row = grid[mid]
    total = sum(ord(ch) for ch in row)
    return total

def main():
    grid = read_grid('../inputs/grid.txt')
    instr = read_directions('../inputs/directions.txt')

    grid = apply_instructions(grid, instr)
    clue1 = compute_clue1(grid)
    print(clue1)

    with open('_clue1.txt','w',encoding='utf-8') as f:

        f.write(str(clue1))

if __name__ == '__main__':
    main()