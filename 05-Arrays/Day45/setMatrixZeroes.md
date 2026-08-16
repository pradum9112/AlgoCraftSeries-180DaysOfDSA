# 📘 Day 45 — Set Matrix Zeroes

## Problem Statement

Given a matrix, if an element is `0`, set its entire row and column to `0`.

The changes should be made according to the **original zero positions**.

---

## Example

### Input

```text
1 1 1
1 0 1
1 1 1
```

The zero is at:

```text
row = 1
col = 1
```

Therefore its entire row and column become zero.

### Output

```text
1 0 1
0 0 0
1 0 1
```

---

# Day 45 Learning Progression

I solved this problem using three approaches:

```text
Brute Force
    ↓
Better
    ↓
Optimal
```

This progression is important because the main learning is not just solving the problem.

The goal is to understand:

```text
How can I reduce extra work?
How can I reduce extra space?
```

---

# Approach 1 — Brute Force Marking

## Idea

Whenever we find:

```text
matrix[i][j] == 0
```

we mark the entire row and column with:

```text
-1
```

We don't immediately make them zero because that could create **new zeros** that were not present in the original matrix.

After all original zeros have been processed:

```text
-1 → 0
```

---

## Why Use `-1`?

Suppose:

```text
1 1 1
1 0 1
1 1 1
```

If we immediately change everything to zero, the newly created zeros could be treated as original zeros.

That would cause unnecessary processing.

So we temporarily use:

```text
-1
```

to mean:

> "This element should become zero later."

---

## Complexity

If there are many zeroes, every zero can cause a row and column traversal.

Worst case:

```text
Time = O((n × m) × (n + m))
```

Extra space:

```text
O(1)
```

apart from the matrix itself.

---

# Approach 2 — Dummy Row + Dummy Column

Instead of modifying the matrix while finding zeroes, maintain two arrays:

```cpp
vector<int> dummyRow(n, 0);
vector<int> dummyCol(m, 0);
```

Think of them as:

```text
dummyRow
   ↓
Which rows contain zero?

dummyCol
   ↓
Which columns contain zero?
```

---

## Example

Matrix:

```text
1 1 1
1 0 1
1 1 1
```

Zero is at:

```text
row 1
column 1
```

So:

```text
dummyRow:

[0, 1, 0]
```

and:

```text
dummyCol:

[0, 1, 0]
```

Then while traversing the matrix:

```cpp
if (dummyRow[i] == 1 || dummyCol[j] == 1)
    matrix[i][j] = 0;
```

---

## Complexity

We scan the matrix twice.

Therefore:

```text
Time = O(n × m)
```

Extra arrays:

```text
dummyRow = O(n)
dummyCol = O(m)
```

Therefore:

```text
Space = O(n + m)
```

---

# Approach 3 — Optimal

The key observation is:

> We already have a matrix. Why create separate arrays to remember which rows and columns contain zero?

We can use the **first row and first column of the matrix itself as markers**.

---

# Main Idea

Suppose:

```text
1 2 3
4 0 6
7 8 9
```

The zero is at:

```text
row 1
column 1
```

Instead of:

```text
dummyRow[1] = 1
dummyCol[1] = 1
```

we store that information inside:

```text
matrix[1][0] = 0
matrix[0][1] = 0
```

So the first column tells us:

```text
Which rows should become zero?
```

And the first row tells us:

```text
Which columns should become zero?
```

---

# Visualization

Think:

```text
       Columns
       ↓
    0  1  2
  ┌─────────
0 │ X  C  C
1 │ R  C  C
2 │ R  C  C
```

Where:

```text
First row    → column markers
First column → row markers
```

This removes the need for:

```text
dummyRow[]
dummyCol[]
```

---

# Why `col0` Is Needed

There is one problem.

The cell:

```text
matrix[0][0]
```

belongs to BOTH:

```text
first row
```

and:

```text
first column
```

So one cell cannot independently tell us whether:

```text
first row should be zero
```

and:

```text
first column should be zero
```

Therefore we use:

```cpp
int col0 = 1;
```

to separately remember the first column.

---

# Step 1 — Create Markers

For every zero:

```cpp
if (matrix[i][j] == 0) {
    matrix[i][0] = 0;
    matrix[0][j] = 0;
}
```

Meaning:

```text
matrix[i][0] = 0
        ↓
row i should become zero

matrix[0][j] = 0
        ↓
column j should become zero
```

---

# Step 2 — Update Inner Matrix

We don't immediately modify the first row and first column.

Start from:

```text
i = 1
j = 1
```

For every inner cell:

```cpp
if (matrix[i][0] == 0 || matrix[0][j] == 0)
```

make it zero.

Meaning:

```text
Row marker == 0
        OR
Column marker == 0
        ↓
Make current cell 0
```

---

# Step 3 — First Row

After using the first row as markers, we finally handle it.

```cpp
if (matrix[0][0] == 0)
```

then:

```text
First row → all zero
```

---

# Step 4 — First Column

We use:

```cpp
if (col0 == 0)
```

then:

```text
First column → all zero
```

---

# Dry Run

Consider:

```text
1 2 3
4 0 6
7 8 9
```

Initial:

```text
1 2 3
4 0 6
7 8 9
```

The zero is:

```text
matrix[1][1]
```

So mark:

```text
matrix[1][0] = 0
matrix[0][1] = 0
```

Matrix becomes:

```text
1 0 3
0 0 6
7 8 9
```

Important:

These are **markers**, not the final answer yet.

---

## Inner Matrix

Check:

```text
matrix[1][0] == 0
```

Therefore row 1 becomes zero.

Also:

```text
matrix[0][1] == 0
```

Therefore column 1 becomes zero.

Final:

```text
1 0 3
0 0 0
7 0 9
```

---

# Why We Don't Process From `(0,0)`

The first row and first column are being used as our storage space.

Therefore:

```text
First row
First column
```

must be handled separately at the end.

That's why the main update loop starts from:

```cpp
i = 1
j = 1
```

---

# Complexity Comparison

| Approach | Time | Extra Space |
|---|---:|---:|
| Brute Force Marking | O((n×m)(n+m)) worst case | O(1) |
| Dummy Row + Column | O(n×m) | O(n+m) |
| **Optimal Markers** | **O(n×m)** | **O(1)** |

---

# Learning Progression

The important evolution is:

```text
Approach 1

Find zero
   ↓
Directly mark row/column
   ↓
Use -1 to avoid affecting original zero logic
```

Then:

```text
Approach 2

Find zero
   ↓
Remember row/column separately
   ↓
Apply zeroes later
```

Finally:

```text
Approach 3

Find zero
   ↓
Use matrix's first row/column
as memory
   ↓
O(1) extra space
```

---

# Key Learning

The biggest lesson from this problem is:

> **Before creating extra arrays, ask whether the input structure itself can store the required information.**

Here:

```text
dummyRow[]
dummyCol[]
```

were replaced by:

```text
matrix[i][0]
matrix[0][j]
```

That's how we went from:

```text
O(n + m)
```

extra space to:

```text
O(1)
```

---

# Quick Revision

Remember:

```text
Zero found at (i, j)

        ↓

matrix[i][0] = 0
        ↓
Mark ROW

matrix[0][j] = 0
        ↓
Mark COLUMN
```

Then:

```text
Use markers
    ↓
Zero inner matrix
    ↓
Handle first row
    ↓
Handle first column
```

### Optimal Complexity

```text
Time  = O(n × m)
Space = O(1)
```