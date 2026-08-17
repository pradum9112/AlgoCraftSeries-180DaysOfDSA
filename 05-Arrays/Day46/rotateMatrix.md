# 📘 Day 46 — Rotate Matrix 90° Clockwise

## Problem Statement

Given an `n × n` square matrix, rotate the matrix **90 degrees clockwise**.

The rotation should be done in-place for the optimal solution.

---

## Example

### Input

```text
1 2 3
4 5 6
7 8 9
```

### Output

```text
7 4 1
8 5 2
9 6 3
```

---

# Approach 1 — Extra Matrix

The direct way to understand the rotation is to create another matrix.

For every element:

```text
matrix[i][j]
```

its new position after 90° clockwise rotation is:

```text
ans[j][n - 1 - i]
```

So:

```cpp
ans[j][n - 1 - i] = matrix[i][j];
```

---

## Position Visualization

For:

```text
1 2 3
4 5 6
7 8 9
```

The element:

```text
1
```

is at:

```text
(i, j) = (0, 0)
```

New position:

```text
(j, n - 1 - i)
```

For `n = 3`:

```text
(0, 0)
 ↓
(0, 2)
```

So `1` moves here:

```text
_ _ 1
```

Similarly:

```text
2 → position (1,2)
3 → position (2,2)
```

Eventually:

```text
7 4 1
8 5 2
9 6 3
```

---

# Complexity

We traverse the entire matrix:

```text
O(n²)
```

We also create another `n × n` matrix:

```text
O(n²)
```

Therefore:

```text
Time  = O(n²)
Space = O(n²)
```

---

# Approach 2 — Optimal

We can rotate the matrix **without creating another matrix**.

The trick is:

```text
Transpose
   ↓
Reverse every row
```

This gives a 90° clockwise rotation.

---

# Step 1 — Transpose

Transpose means:

```text
Rows become columns
```

For example:

```text
1 2 3
4 5 6
7 8 9
```

After transpose:

```text
1 4 7
2 5 8
3 6 9
```

This is done by swapping:

```cpp
matrix[i][j]
```

with:

```cpp
matrix[j][i]
```

---

# Why `j = i + 1`?

We don't need to swap the entire matrix.

If we swap both:

```text
matrix[i][j]
```

and:

```text
matrix[j][i]
```

then we would swap the same elements twice.

For example:

```text
matrix[0][1]
```

and:

```text
matrix[1][0]
```

are a pair.

So after swapping them once, don't swap them again.

Therefore:

```cpp
for (int i = 0; i < n - 1; i++) {

    for (int j = i + 1; j < n; j++) {

        swap(matrix[i][j], matrix[j][i]);
    }
}
```

The `i + 1` makes sure we only process the upper triangle.

---

# Step 2 — Reverse Every Row

After transpose:

```text
1 4 7
2 5 8
3 6 9
```

Reverse each row:

```text
7 4 1
8 5 2
9 6 3
```

This is exactly a 90° clockwise rotation.

---

# Complete Visualization

Start:

```text
1 2 3
4 5 6
7 8 9
```

### Transpose

```text
1 4 7
2 5 8
3 6 9
```

### Reverse each row

```text
7 4 1
8 5 2
9 6 3
```

### Final

```text
7 4 1
8 5 2
9 6 3
```

---

# Why Does Transpose + Reverse Work?

Think about what transpose does:

```text
Column → Row
```

Then reversing each row changes the direction.

Together:

```text
Transpose
    +
Reverse each row
    =
90° Clockwise Rotation
```

---

# Dry Run

Consider:

```text
1 2 3
4 5 6
7 8 9
```

## Transpose

Swap:

```text
2 ↔ 4
```

Matrix:

```text
1 4 3
2 5 6
7 8 9
```

Then:

```text
3 ↔ 7
```

Matrix:

```text
1 4 7
2 5 6
3 8 9
```

Then:

```text
6 ↔ 8
```

Final transpose:

```text
1 4 7
2 5 8
3 6 9
```

---

## Reverse Row 0

```text
1 4 7
```

becomes:

```text
7 4 1
```

---

## Reverse Row 1

```text
2 5 8
```

becomes:

```text
8 5 2
```

---

## Reverse Row 2

```text
3 6 9
```

becomes:

```text
9 6 3
```

Final:

```text
7 4 1
8 5 2
9 6 3
```

---

# Complexity Comparison

| Approach | Time | Extra Space |
|---|---:|---:|
| Extra Matrix | O(n²) | O(n²) |
| **Transpose + Reverse** | **O(n²)** | **O(1)** |

Both approaches take the same time because every matrix element has to be processed.

The major improvement is:

```text
O(n²) extra space
        ↓
O(1) extra space
```

---

# Important Learning

This problem is a good example of **space optimization**.

### First thought:

```text
I can create another matrix.
```

That's easy to understand.

Then ask:

> Can I modify the original matrix itself?

The answer is yes.

We can convert:

```text
Original
   ↓
Transpose
   ↓
Reverse rows
   ↓
Rotated matrix
```

without another matrix.

---

# Pattern to Remember

For **90° Clockwise Rotation**:

```text
TRANSPOSE
    ↓
REVERSE EACH ROW
```

For example:

```text
1 2 3
4 5 6
7 8 9

      ↓ transpose

1 4 7
2 5 8
3 6 9

      ↓ reverse rows

7 4 1
8 5 2
9 6 3
```

---

# Key Learning

The most important thing from Day 46:

```text
Don't just memorize:
"Transpose + Reverse"
```

Understand why:

```text
Transpose
→ rows become columns

Reverse each row
→ changes the direction

Together
→ 90° clockwise rotation
```

### Optimal Solution

```text
Time  = O(n²)
Space = O(1)
```