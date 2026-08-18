# 📘 Day 47 — Spiral Matrix

## Problem Statement

Given a matrix, return all its elements in **spiral order**.

We have to traverse the matrix like:

```text
→ Right
↓ Down
← Left
↑ Up
```

and continue moving inward until every element has been visited.

---

## Example

### Input

```text
1  2  3
4  5  6
7  8  9
```

### Spiral Order

```text
1 → 2 → 3
        ↓
4   5   6
↑       ↓
7 ← 8 ← 9
```

Therefore:

```text
1 2 3 6 9 8 7 4 5
```

---

# Main Idea

The easiest way to visualize this problem is to imagine that we have four boundaries:

```text
top
bottom
left
right
```

Initially:

```text
top = 0
bottom = n - 1

left = 0
right = m - 1
```

For:

```text
1 2 3
4 5 6
7 8 9
```

we have:

```text
top    = 0
bottom = 2
left   = 0
right  = 2
```

---

# Four Steps

Every round has four movements.

```text
1. → Right
2. ↓ Down
3. ← Left
4. ↑ Up
```

After completing one side, its boundary moves inward.

---

# Step 1 — Move Right

Traverse the top row:

```text
1 → 2 → 3
```

Code:

```cpp
for (int i = left; i <= right; i++) {
    ans.push_back(matrix[top][i]);
}
```

After finishing the top row:

```cpp
top++;
```

Why?

Because this row has already been processed.

So:

```text
top
 ↓

1 2 3  ← processed

4 5 6
7 8 9
```

---

# Step 2 — Move Down

Now traverse the right column:

```text
3
↓
6
↓
9
```

Code:

```cpp
for (int i = top; i <= bottom; i++) {
    ans.push_back(matrix[i][right]);
}
```

After processing:

```cpp
right--;
```

because the right column is already done.

---

# Step 3 — Move Left

Now traverse the bottom row from right to left:

```text
9 ← 8 ← 7
```

But `9` has already been included while moving down.

Therefore we start from:

```cpp
right
```

after it has been decreased.

Code:

```cpp
if (top <= bottom) {

    for (int i = right; i >= left; i--) {
        ans.push_back(matrix[bottom][i]);
    }

    bottom--;
}
```

After processing:

```cpp
bottom--;
```

---

# Step 4 — Move Up

Now traverse the left column from bottom to top:

```text
7
↑
4
```

Code:

```cpp
if (left <= right) {

    for (int i = bottom; i >= top; i--) {
        ans.push_back(matrix[i][left]);
    }

    left++;
}
```

After processing:

```cpp
left++;
```

Now one complete outer layer has been processed.

---

# Full Dry Run

Matrix:

```text
1 2 3
4 5 6
7 8 9
```

Initial boundaries:

```text
top = 0
bottom = 2
left = 0
right = 2
```

---

## Round 1

### → Right

```text
1 2 3
```

Answer:

```text
1 2 3
```

Update:

```text
top = 1
```

---

### ↓ Down

```text
6
9
```

Answer:

```text
1 2 3 6 9
```

Update:

```text
right = 1
```

---

### ← Left

```text
8 7
```

Answer:

```text
1 2 3 6 9 8 7
```

Update:

```text
bottom = 1
```

---

### ↑ Up

```text
4
```

Answer:

```text
1 2 3 6 9 8 7 4
```

Update:

```text
left = 1
```

---

# Remaining Matrix

Now only:

```text
5
```

is left.

Boundaries:

```text
top    = 1
bottom = 1
left   = 1
right  = 1
```

The condition:

```cpp
while (top <= bottom && left <= right)
```

is still true.

So:

```text
→ Right
```

adds:

```text
5
```

Final answer:

```text
1 2 3 6 9 8 7 4 5
```

---

# Why Do We Need the `if` Conditions?

These are very important:

```cpp
if (top <= bottom)
```

and:

```cpp
if (left <= right)
```

Imagine a matrix with only one remaining row or one remaining column.

Without these checks, we might visit an already processed element again.

For example:

```text
1 2 3 4
```

There is only one row.

After processing:

```text
1 2 3 4
```

we don't want to process the same row again while doing the "Left" step.

Therefore:

```cpp
if (top <= bottom)
```

protects the bottom-row traversal.

Similarly:

```cpp
if (left <= right)
```

protects the left-column traversal.

---

# Boundary Visualization

Think of the matrix as a box:

```text
┌───────────────────┐
│ → → → → → → → →  │
│ ↑               ↓ │
│ ↑               ↓ │
│ ↑               ↓ │
│ ← ← ← ← ← ← ← ←  │
└───────────────────┘
```

After completing one outer layer:

```text
┌───────────────────┐
│   ┌─────────────┐ │
│   │             │ │
│   │             │ │
│   └─────────────┘ │
└───────────────────┘
```

The four boundaries move inward:

```text
top    ++
bottom --
left   ++
right  --
```

This is the main visualization you should remember.

---

# Complexity

Every matrix element is visited exactly once.

If the matrix has:

```text
n × m
```

elements:

```text
Time = O(n × m)
```

The answer vector itself contains `n × m` elements:

```text
Output Space = O(n × m)
```

Apart from the returned answer, the algorithm uses only a constant number of variables:

```text
Extra Space = O(1)
```

So:

```text
Time       = O(n × m)
Extra Space = O(1)
Output     = O(n × m)
```

---

# Important Learning

The problem is **not really about four loops**.

The main concept is:

```text
CONTROL THE BOUNDARIES
```

Remember:

```text
top
 ↓
Process top row
 ↓
top++

right
 ↓
Process right column
 ↓
right--

bottom
 ↓
Process bottom row
 ↓
bottom--

left
 ↓
Process left column
 ↓
left++
```

---

# Pattern to Remember

```text
while (matrix is still remaining)

    → Right
    top++

    ↓ Down
    right--

    ← Left
    bottom--

    ↑ Up
    left++
```

with:

```cpp
while (top <= bottom && left <= right)
```

---

# Key Learning From Day 47

The most important thing is to visualize the matrix as **layers**.

```text
Outer Layer
    ↓
Remove it
    ↓
Inner Layer
    ↓
Remove it
    ↓
Next Inner Layer
```

And each layer is traversed:

```text
→ ↓ ← ↑
```

### Complexity

```text
Time        = O(n × m)
Extra Space = O(1)
```