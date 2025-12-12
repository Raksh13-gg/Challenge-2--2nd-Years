


<!-- All instructions are inside docs/.
Do NOT modify input files.
Do NOT include example outputs. -->
# SOSC Round 2 Challenge — 2nd Years

This folder contains my solutions for the SOSC Round 2 Coding Puzzle Challenge.  

All instructions were followed carefully, and none of the input files were modified. I also did not include example outputs, as instructed.  



This challenge contained three independent problems. Each problem generated a clue, which was later used to create a final key. Below is a summary of how I approached each problem.



Problem 1 — Grid Transform
Input:`grid.txt` and `directions.txt`  
Process: I applied all transformations row by row as instructed. After completing all rotations, I isolated the central row and calculated the sum of the integer values of all characters.  
Clue 1:385

Problem 2 — Multi-Pass String Process
Input:`input2.txt`  
Process:  
  1. Reversed the string.  
  2. Removed every 3rd character.  
  3. Shifted each remaining character by +2 in ASCII.  
  4. Counted all vowels (a, e, i, o, u).  
Clue 2: 4

Problem 3 — State Sequence Simulation
Input:`states.txt`  
Process:I simulated a 4-state transition system:  
Even numbers advanced one state.  
Prime numbers jumped directly to the terminal state.  
Odd composite numbers stayed in their state.  
Clue 3:4

Final Key
Calculated Final Key:`181-4444`  
File: `final_key.txt`


Files Included
 `problem1.py` — Solution for Problem 1  
`problem2.py` — Solution for Problem 2  
 `problem3.py` — Solution for Problem 3  
`final_key_generator.py` — Optional script to generate the final key automatically  
 `final_key.txt` — The final key for submission  
 `README.md` — This explanation


Everything was implemented as per instructions, all scripts work correctly, and the outputs match the challenge requirements.
