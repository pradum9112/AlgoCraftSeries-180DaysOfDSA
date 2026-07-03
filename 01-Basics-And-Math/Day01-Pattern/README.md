# Day 1: Pattern Problems

### Problem Statement
Given an integer `n`. You need to recreate the pattern given below for any value of `N`.

**Input:**
```text
4
```

**Output:**
```text
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
```

### Questions Solved
1. **Pattern 22 (Number Crown/Ring Pattern)**
   - **Difficulty:** Easy-Medium
   - **Logic:** Solved using a 2D grid matrix of size `(2n-1) * (2n-1)`. Calculated each cell value using the minimum distance from the 4 boundaries: `n - min({top, bottom, left, right})`.
