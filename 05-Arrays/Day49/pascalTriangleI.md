# 📘 Day 49 — Pascal Triangle I

## Problem Statement

Given the row number `r` and column number `c` of Pascal's Triangle, return the element present at that position.

The row and column numbers are **1-based**.

---

## Example

### Input

```text
5 3
```

Pascal Triangle:

```text
          1
        1   1
      1   2   1
    1   3   3   1
  1   4   6   4   1
```

The element at:

```text
row = 5
column = 3
```

is:

```text
6
```

### Output

```text
6
```

---

# Main Idea

Every element of Pascal's Triangle can be calculated using the combination formula:

```text
nCr
```

For row `r` and column `c`:

```text
n = r - 1
k = c - 1
```

Therefore:

```text
answer = (r - 1) C (c - 1)
```

---

# Why `r - 1` and `c - 1`?

The problem uses **1-based indexing**.

For example:

```text
Row 1 → index 0
Row 2 → index 1
Row 3 → index 2
```

Therefore:

```cpp
int n = r - 1;
int k = c - 1;
```

For:

```text
r = 5
c = 3
```

we get:

```text
n = 4
k = 2
```

So we need:

```text
4C2
```

which is:

```text
6
```

---

# Calculating nCr

The normal formula is:

```text
nCr = n! / (r! × (n-r)!)
```

For example:

```text
4C2 = 4! / (2! × 2!)
```

```text
   = 24 / 4
```

```text
   = 6
```

But calculating factorials is unnecessary.

Instead, we calculate the result step by step.

The formula can be written as:

```text
nCk =
n × (n-1) × (n-2) ... 
----------------------
1 × 2 × 3 ...
```

The code:

```cpp
for (int i = 0; i < k; i++) {

    res = res * (n - i);
    res = res / (i + 1);
}
```

---

# Dry Run

Suppose:

```text
r = 5
c = 3
```

Convert:

```text
n = r - 1 = 4
k = c - 1 = 2
```

We need:

```text
4C2
```

Initially:

```text
res = 1
```

---

## Iteration 1

```text
i = 0
```

Calculate:

```text
res = res × (n - i)
```

```text
res = 1 × 4
```

```text
res = 4
```

Then:

```text
res = res / (i + 1)
```

```text
res = 4 / 1
```

```text
res = 4
```

---

## Iteration 2

```text
i = 1
```

Calculate:

```text
res = 4 × (4 - 1)
```

```text
res = 12
```

Then:

```text
res = 12 / (1 + 1)
```

```text
res = 6
```

Final:

```text
res = 6
```

Therefore:

```text
5th row, 3rd column = 6
```

---

# Important Optimization

There is an important property:

```text
nCk = nC(n-k)
```

For example:

```text
10C3 = 10C7
```

Both have the same answer.

Therefore, instead of always calculating using a large `k`, we use the smaller one:

```cpp
if (k > n - k) {
    k = n - k;
}
```

Example:

```text
n = 10
k = 7
```

Instead of calculating:

```text
10C7
```

we calculate:

```text
10C3
```

because:

```text
7 > 10 - 7
7 > 3
```

So:

```text
k = 3
```

This reduces the number of iterations.

---

# Why `long long`?

We use:

```cpp
long long res = 1;
```

instead of:

```cpp
int res = 1;
```

because intermediate multiplication can become larger than the range of `int`.

For example:

```cpp
res * (n - i)
```

can temporarily become large.

`long long` provides a larger integer range.

---

# Complexity

We perform at most `k` iterations.

Because of:

```cpp
k = min(k, n-k)
```

the number of iterations is at most approximately `n/2`.

Therefore:

```text
Time = O(min(k, n-k))
```

or simply:

```text
Time = O(n)
```

in terms of the row number.

Extra space:

```text
Space = O(1)
```

---

# Comparison With Building the Entire Triangle

One possible approach would be:

```text
Build entire Pascal Triangle
        ↓
Go to row r
        ↓
Go to column c
```

But that would calculate many unnecessary elements.

Our approach directly calculates:

```text
required element
      ↓
   nCr
```

So we don't need to construct the entire triangle.

---

# Learning Focus

The important learning from Day 49 is not just Pascal Triangle.

It is:

```text
Pascal Triangle
      ↓
Combination
      ↓
nCr
      ↓
Calculate nCr without factorial
      ↓
Use nCr = nC(n-r)
      ↓
Reduce unnecessary iterations
```

---

# Key Pattern

For a Pascal Triangle position:

```text
row = r
column = c
```

convert:

```text
n = r - 1
k = c - 1
```

then calculate:

```text
nCk
```

using:

```cpp
res = res * (n - i);
res = res / (i + 1);
```

---

# Final Complexity

```text
Time  = O(min(k, n-k))
Space = O(1)
```

### Core Learning

**Don't build the whole Pascal Triangle when you only need one element. Directly calculate the required `nCr`.**