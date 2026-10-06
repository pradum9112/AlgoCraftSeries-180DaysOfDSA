# Day 89 — Row With Maximum 1s

## 📌 Problem

Given a binary matrix `mat` where each row contains `0`s followed by `1`s, find the index of the row that contains the maximum number of `1`s.

If multiple rows contain the same maximum number of `1`s, return the index of the first such row.

If the matrix contains no `1`, return `-1`.

### Example

**Input**

```text
mat = [
    [0, 0, 0, 1],
    [0, 1, 1, 1],
    [0, 0, 1, 1],
    [0, 0, 0, 0]
]
```

**Output**

```text
1
```

Because:

```text
Row 0 → 1 one
Row 1 → 3 ones
Row 2 → 2 ones
Row 3 → 0 ones
```

Therefore:

```text
Row 1 has the maximum number of 1s.
```

---

# 🔹 Approach 1 — Brute Force

## 💡 Idea

Simply visit every element of the matrix.

For every row:

1. Count how many `1`s are present.
2. Compare the count with the maximum count found so far.
3. If the current row has more `1`s, update:

   * `maxOnesCount`
   * `rowIndex`

After checking every row, return the row index.

### Pattern Recognition

When the problem asks:

```text
Find the row with maximum number of 1s
```

and there is no need to exploit any special property yet, the direct approach is:

```text
Traverse every row
        ↓
Count 1s in each row
        ↓
Keep maximum
        ↓
Return row index
```

This is a straightforward **2D Matrix Traversal** pattern.

The important observation is that every element needs to be inspected.

---

## 🔄 Dry Run

Consider:

```text
mat = [
    [0, 0, 0, 1],
    [0, 1, 1, 1],
    [0, 0, 1, 1],
    [0, 0, 0, 0]
]
```

### Row 0

```text
[0, 0, 0, 1]
```

Number of `1`s:

```text
1
```

So:

```text
maxOnesCount = 1
rowIndex = 0
```

### Row 1

```text
[0, 1, 1, 1]
```

Number of `1`s:

```text
3
```

Since:

```text
3 > 1
```

Update:

```text
maxOnesCount = 3
rowIndex = 1
```

### Row 2

```text
[0, 0, 1, 1]
```

Number of `1`s:

```text
2
```

Since:

```text
2 < 3
```

No update.

### Row 3

```text
[0, 0, 0, 0]
```

Number of `1`s:

```text
0
```

No update.

Final:

```text
rowIndex = 1
```

---

## ⏱️ Time Complexity

If the matrix has:

```text
n rows
m columns
```

we visit every element once.

```text
Time: O(n × m)
```

## 💾 Space Complexity

Only a few variables are used.

```text
Space: O(1)
```

---

# 🔹 Approach 2 — Binary Search

## 💡 Idea

The important property of this problem is:

> Every row is sorted — all `0`s come before all `1`s.

For example:

```text
[0, 0, 0, 1, 1, 1]
```

Instead of counting every `1` one by one, we can find the **first occurrence of `1`** using Binary Search.

Suppose a row has:

```text
[0, 0, 0, 1, 1, 1]
```

The first `1` is at index:

```text
3
```

If there are `m` columns, then the number of `1`s is:

```text
m - firstOneIndex
```

So for every row:

```text
Find first 1
        ↓
Count 1s = m - firstOneIndex
        ↓
Compare with maximum
```

In C++, `lower_bound(..., 1)` gives the first position containing `1`.

---

## 🔍 Pattern Recognition

This is the key learning from the problem.

Whenever you see a matrix where every row is sorted:

```text
0 0 0 1 1 1
```

and the problem asks about:

```text
first 1
number of 1s
first occurrence
lower bound
```

think:

> **Binary Search on each sorted row.**

The pattern is:

```text
Sorted row
    ↓
Need first 1
    ↓
Lower Bound
    ↓
Number of 1s = columns - firstOneIndex
```

This connects directly with the earlier Binary Search concept:

```text
Lower Bound = first position where value >= target
```

Here:

```text
target = 1
```

Therefore:

```text
first position where mat[i][j] >= 1
```

is exactly the first `1`.

---

## 🔄 Dry Run

Consider:

```text
mat = [
    [0, 0, 0, 1],
    [0, 1, 1, 1],
    [0, 0, 1, 1],
    [0, 0, 0, 0]
]
```

There are:

```text
m = 4
```

columns.

### Row 0

```text
[0, 0, 0, 1]
```

First `1`:

```text
index = 3
```

Number of `1`s:

```text
4 - 3 = 1
```

So:

```text
maxOnesCount = 1
rowIndex = 0
```

### Row 1

```text
[0, 1, 1, 1]
```

First `1`:

```text
index = 1
```

Number of `1`s:

```text
4 - 1 = 3
```

Since:

```text
3 > 1
```

update:

```text
maxOnesCount = 3
rowIndex = 1
```

### Row 2

```text
[0, 0, 1, 1]
```

First `1`:

```text
index = 2
```

Number of `1`s:

```text
4 - 2 = 2
```

No update because:

```text
2 < 3
```

### Row 3

```text
[0, 0, 0, 0]
```

There is no `1`.

`lower_bound` points to:

```text
index = 4
```

Therefore:

```text
4 - 4 = 0
```

No update.

Final answer:

```text
1
```

---

## ⏱️ Time Complexity

For every row, we perform Binary Search over `m` columns.

Binary Search:

```text
O(log m)
```

For `n` rows:

```text
Time: O(n × log m)
```

## 💾 Space Complexity

Only constant extra variables are used.

```text
Space: O(1)
```

---

# ⚖️ Approach Comparison

| Feature                        | Brute Force      | Binary Search             |
| ------------------------------ | ---------------- | ------------------------- |
| Technique                      | Matrix Traversal | Binary Search on Each Row |
| Main Idea                      | Count every `1`  | Find first `1`            |
| Uses Sorted Rows               | ❌                | ✅                         |
| Time                           | `O(n × m)`       | `O(n × log m)`            |
| Space                          | `O(1)`           | `O(1)`                    |
| Efficient                      | ❌                | ✅                         |
| Optimal among given approaches | ❌                | ✅                         |

Where:

```text
n = number of rows
m = number of columns
```

---

# 🧩 Core Pattern to Remember

The important learning is not just finding the maximum row.

The real pattern is:

```text
Every row is sorted
        ↓
Need first occurrence of 1
        ↓
Binary Search / Lower Bound
        ↓
Count 1s from first 1 to end
        ↓
Compare row counts
```

Formula:

```text
Number of 1s = m - firstOneIndex
```

---

# 🎯 Pattern Recognition Shortcut

When you see:

```text
Binary Matrix
+
Every row is sorted
+
Find maximum number of 1s
```

think:

```text
Sorted rows
     ↓
Find first 1
     ↓
Lower Bound
     ↓
Count = m - firstOneIndex
     ↓
Track maximum
```

### Key Connection

You already learned:

```text
Day62 → Lower Bound
```

Lower Bound means:

```text
First index where nums[i] >= target
```

Here:

```text
target = 1
```

Therefore:

```text
First index where mat[i][j] >= 1
```

gives the first `1`.

---

# 🚨 Edge Cases

### 1. All elements are `0`

```text
[
    [0, 0],
    [0, 0]
]
```

Output:

```text
-1
```

### 2. All elements are `1`

```text
[
    [1, 1],
    [1, 1]
]
```

Both rows have the same number of `1`s.

Return the first row:

```text
0
```

### 3. Only one row

```text
[
    [0, 1, 1]
]
```

Output:

```text
0
```

### 4. Only one column

```text
[
    [0],
    [1],
    [0]
]
```

Output:

```text
1
```

### 5. Multiple rows have the same maximum

Keep the first row because we update only when:

```text
currentOnes > maxOnesCount
```

not when:

```text
currentOnes >= maxOnesCount
```

---

# 🧠 What I Learned

* A matrix row can be treated as a sorted array when all `0`s come before `1`s.
* Brute Force counts every `1` by traversing the complete matrix.
* Binary Search can find the first `1` in every row.
* `lower_bound` is useful for finding the first position where the value is at least `1`.
* If the first `1` is at index `j`, the number of `1`s is:
  `m - j`
* The problem connects directly with the **Lower Bound** concept from Day62.
* The brute-force complexity is `O(n × m)`.
* Using Binary Search on every row reduces it to `O(n × log m)`.
* The sorted-row property is the main clue for optimization.

---

# 🎯 Revision Shortcut

```text
Row sorted?
     ↓
0 0 0 1 1 1
     ↓
Find first 1
     ↓
Lower Bound(1)
     ↓
ones = columns - firstOneIndex
     ↓
Track maximum
     ↓
Return row index
```

**Pattern:** Binary Search / Lower Bound on each sorted row

**Brute Force:** `O(n × m)`

**Better:** `O(n × log m)`

**Space:** `O(1)`

---

# ✅ Final Takeaway

The real DSA pattern is:

```text
Sorted Data
     ↓
Need First Valid Position
     ↓
Lower Bound
     ↓
Use Position to Calculate Answer
```

For Day89:

```text
2D Matrix
→ Each row sorted
→ Find first 1
→ Count remaining elements
→ Track maximum
```

**Pattern:** `Lower Bound on Sorted Rows`

**Best approach among given solutions:** `O(n × log m)` time, `O(1)` space.

---

