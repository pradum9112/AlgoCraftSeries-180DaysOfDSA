# Day90 — Search in a 2D Matrix

## Problem

Given a 2D matrix `mat` and a target value, determine whether the target exists in the matrix.

### Matrix Property

The matrix is sorted such that:

* Every row is sorted in ascending order.
* The first element of every row is greater than the last element of the previous row.

Therefore, the complete matrix can be treated like **one sorted 1D array**.

### Example

```text
Matrix:

1   3   5   7
10  11  16  20
23  30  34  60

Target = 3

Output = true
```

---

# Approach 1 — Brute Force

## Idea

Visit every element of the matrix one by one.

For each element:

* If `mat[i][j] == target`, return `true`.
* If the complete matrix is searched and target is not found, return `false`.

This approach does not use the sorted property of the matrix.

## Pattern Recognition

When the problem asks:

> "Search for an element in a 2D matrix"

The simplest approach is:

**Traverse every cell → compare with target.**

For a matrix containing `n × m` elements, there can be `n × m` comparisons.

### Key Pattern

```text
2D Matrix
   ↓
Nested Loops
   ↓
Check every element
```

## Dry Run

Matrix:

```text
1   3   5   7
10  11  16  20
23  30  34  60
```

Target = `16`

### Step 1

Check:

```text
1 != 16
```

### Step 2

```text
3 != 16
```

### Step 3

```text
5 != 16
```

Continue searching.

Eventually:

```text
16 == 16
```

Therefore:

```text
return true
```

## Time Complexity

There are `n × m` elements.

```text
O(n × m)
```

## Space Complexity

No extra data structure is used.

```text
O(1)
```

---

# Approach 2 — Binary Search

## Idea

The important observation is that the entire matrix behaves like a **sorted 1D array**.

For:

```text
1   3   5   7
10  11  16  20
23  30  34  60
```

We can imagine:

```text
1  3  5  7  10  11  16  20  23  30  34  60
```

There are `n × m` total elements.

So instead of searching row by row, perform binary search on indices:

```text
0 → n*m - 1
```

The only challenge is converting a 1D index back into its matrix position.

### 1D → 2D Conversion

For a matrix with `m` columns:

```text
row = mid / m
col = mid % m
```

This gives:

```text
mat[row][col]
```

## Pattern Recognition

This is an important **Binary Search on a sorted matrix** pattern.

Whenever:

* Each row is sorted.
* The first element of the next row is greater than the last element of the previous row.

Think:

```text
2D Matrix
   ↓
Flatten conceptually
   ↓
Sorted 1D array
   ↓
Binary Search
```

### Core Trick

We do **not** actually create a new 1D array.

Instead:

```text
mid
 ↓
row = mid / m
col = mid % m
 ↓
mat[row][col]
```

This keeps the extra space `O(1)`.

## Dry Run

Matrix:

```text
1   3   5   7
10  11  16  20
23  30  34  60
```

Target:

```text
16
```

Here:

```text
n = 3
m = 4
```

Total elements:

```text
3 × 4 = 12
```

Therefore:

```text
low = 0
high = 11
```

### Step 1

```text
mid = 5
```

Convert index `5`:

```text
row = 5 / 4 = 1
col = 5 % 4 = 1
```

So:

```text
mat[1][1] = 11
```

Compare:

```text
11 < 16
```

Target is on the right.

```text
low = 6
```

### Step 2

```text
low = 6
high = 11
mid = 8
```

Convert:

```text
row = 8 / 4 = 2
col = 8 % 4 = 0
```

So:

```text
mat[2][0] = 23
```

Compare:

```text
23 > 16
```

Target is on the left.

```text
high = 7
```

### Step 3

```text
low = 6
high = 7
mid = 6
```

Convert:

```text
row = 6 / 4 = 1
col = 6 % 4 = 2
```

So:

```text
mat[1][2] = 16
```

Target found.

```text
return true
```

## Time Complexity

There are `n × m` total elements.

Binary search takes:

```text
O(log(n × m))
```

Therefore:

```text
O(log(n × m))
```

## Space Complexity

No extra matrix or array is created.

```text
O(1)
```

---

# Approach Comparison

| Approach      | Idea                            |            Time |  Space |
| ------------- | ------------------------------- | --------------: | -----: |
| Brute Force   | Check every cell                |      `O(n × m)` | `O(1)` |
| Binary Search | Treat matrix as sorted 1D array | `O(log(n × m))` | `O(1)` |

### Which is better?

**Binary Search** is better because it uses the sorted property of the matrix and reduces the search space by half at every step.

---

# Edge Cases

### 1. Target is the first element

```text
target = 1
```

Should return:

```text
true
```

### 2. Target is the last element

```text
target = 60
```

Should return:

```text
true
```

### 3. Target does not exist

```text
target = 15
```

Should return:

```text
false
```

### 4. Single element matrix

```text
[5]
```

Works correctly for both approaches.

### 5. Single row

```text
1  3  5  7
```

Binary search works like normal 1D binary search.

### 6. Single column

```text
1
3
5
7
```

The 1D index conversion still works.

---

# What I Learned

* A sorted 2D matrix can sometimes be treated as a sorted 1D array.
* We don't need to actually flatten the matrix.
* `row = mid / m` converts a 1D index to a row.
* `col = mid % m` converts a 1D index to a column.
* Binary Search can reduce `O(n × m)` search to `O(log(n × m))`.
* The most important step is recognizing when the matrix's ordering allows us to use binary search.

---

# Revision Shortcut

Remember:

```text
Sorted Matrix
      ↓
Think 1D
      ↓
low = 0
high = n*m - 1
      ↓
mid
      ↓
row = mid / m
col = mid % m
      ↓
Binary Search
```

### One-Line Pattern

> **"If the entire 2D matrix is globally sorted, flatten it conceptually and apply Binary Search."**

---

# Final Takeaway

The main learning of Day90 is not just binary search.

It is **recognizing that a 2D structure can sometimes be transformed conceptually into a 1D sorted search space without actually creating another array.**

```text
O(n × m)  →  O(log(n × m))
```

This is a very important **2D Arrays + Binary Search** pattern.

---

# Test Case

### Input

```text
Matrix:
1 3 5 7
10 11 16 20
23 30 34 60

Target:
16
```

### Output

```text
true
```

➡️ **NEXT: Day91**
