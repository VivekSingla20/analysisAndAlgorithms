# Find Maximum and Minimum

This implementation finds the maximum and minimum elements in an array using a divide and conquer approach.

## Problem Description
Given an array of integers, find both the maximum and minimum elements using an efficient algorithm.

## Algorithm Details
- Uses divide and conquer strategy
- Time Complexity: O(n) where n is the number of elements
- Space Complexity: O(log n) for recursion stack
- More efficient than linear search which would require 2n-2 comparisons

## How to Use
1. Compile the program:
   ```
   g++ -o findMaxMin findMaxMin.cpp
   ```
2. Run the executable:
   ```
   ./findMaxMin
   ```
3. Enter the number of elements
4. Enter the elements
5. The program will display the maximum and minimum elements

## Example
Input:
```
Number of elements: 6
Elements: 5 2 8 1 9 3
```

Output:
```
Maximum element: 9
Minimum element: 1
``` 