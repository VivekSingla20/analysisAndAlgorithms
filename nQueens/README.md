# N-Queens Problem

This implementation solves the N-Queens problem using backtracking.

## Problem Description
The N-Queens problem is to place N queens on an N×N chessboard such that no two queens threaten each other. A queen can move horizontally, vertically, or diagonally.

## Algorithm Details
- Uses backtracking approach
- Time Complexity: O(N!) where N is the number of queens
- Space Complexity: O(N) for recursion stack
- Visualizes the solutions using a board representation

## How to Use
1. Compile the program:
   ```
   g++ -o nQueens nQueens.cpp
   ```
2. Run the executable:
   ```
   ./nQueens
   ```
3. Enter the number of queens (recommended: 4-8)
4. The program will display all possible solutions with board visualization

## Example
Input:
```
Enter number of queens: 4
```

Output:
```
Solution:
. Q . .
. . . Q
Q . . .
. . Q .

Solution:
. . Q .
Q . . .
. . . Q
. Q . .
```

Note: 
- 'Q' represents a queen
- '.' represents an empty square
- Each solution shows a valid arrangement of queens where no queen can attack another 