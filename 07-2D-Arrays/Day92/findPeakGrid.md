# Day92 — Find a Peak Element in a 2D Matrix

## Problem

Given an `n × m` matrix, find any peak element and return its coordinates as `{row, column}`.

A cell is a **peak** if its value is strictly greater than its immediate neighbours: top, bottom, left and right.

For a neighbour outside the matrix boundary, no comparison is required.

### Example

```text
Matrix:
10  20  15
21  30  14
7   16  32

Output: [1, 1]
```

The value `30` at index `[1, 1]` is a peak because it is greater than `20`, `16`, `21` and `14`.

Another valid peak is `32` at `[2, 2]`.

---

## Approach 1 — Brute Force

### Idea

Visit each cell and compare it with its four neighbours.

For every cell:

1. Store its value in `current`.
2. Get the top, bottom, left and right neighbour values.
3. If `current` is greater than all four neighbours, return `{i, j}`.
4. If no peak is found after checking every cell, return `{-1, -1}`.

The code uses `-1` for neighbours outside the matrix. This is valid for the problem's positive-valued matrix; for arbitrary negative values, use a suitable boundary treatment instead.

### Pattern Recognition

When a problem asks for an element satisfying a condition involving its immediate neighbours, first consider checking each element directly.

**Pattern:** Matrix traversal + local neighbour comparisons.

```text
Visit a cell
     ↓
Check four neighbours
     ↓
Is current greater than all?
     ↓
Yes → Return coordinates
No  → Check next cell
```

### Dry Run

```text
10  20  15
21  30  14
7   16  32
```

Start at `[0, 0]`, value `10`.

* Top: outside the matrix.
* Left: outside the matrix.
* Bottom: `21`.
* Right: `20`.

Since `10` is not greater than `21` and `20`, it is not a peak.

Move to `[0, 1]`, value `20`.

* Left: `10`
* Right: `15`
* Bottom: `30`

Since `20 < 30`, it is not a peak.

Continue traversing until `[1, 1]`, value `30`.

* Top: `20`
* Bottom: `16`
* Left: `21`
* Right: `14`

All four comparisons are true:

```text
30 > 20
30 > 16
30 > 21
30 > 14
```

Return:

```text
[1, 1]
```

### Time Complexity

There are `n × m` cells, and each cell requires a constant number of comparisons.

* **Time:** `O(n × m)`

### Space Complexity

No additional data structure is used.

* **Auxiliary space:** `O(1)`

---

## Approach 2 — Binary Search on Columns

### Idea

Instead of checking every cell, binary-search the columns.

For each middle column:

1. Find the row containing the maximum element in that column.
2. Compare that element with its left and right neighbours.
3. If it is greater than both, return its coordinates.
4. If the left neighbour is greater, search the left half.
5. Otherwise, search the right half.

### Why Find the Column Maximum?

The maximum element in a column is greater than every other element in that column. Therefore, it is automatically greater than its top and bottom neighbours.

We only need to check its left and right neighbours to determine whether it is a peak.

If the left neighbour is greater, a peak exists somewhere in the left half. If the right neighbour is greater, a peak exists somewhere in the right half.

This allows us to discard half the columns after each unsuccessful iteration.

### Pattern Recognition

Look for these clues:

* The matrix has rows and columns.
* A peak depends on neighbouring cells.
* The problem permits returning any valid peak.
* We can identify a useful maximum within a middle column.

**Pattern:** Binary search on columns + maximum in a column + neighbour comparison.

```text
Choose middle column
         ↓
Find its maximum element
         ↓
Check left and right
         ↓
Peak found? ── Yes → Return coordinates
         │
         No
         ↓
Choose the half indicated
by the larger neighbour
```

### Dry Run

```text
10  20  15
21  30  14
7   16  32
```

There are `3` rows and `3` columns.

Initially:

```text
lowCol = 0
highCol = 2
midCol = 1
```

**Step 1 — Find the maximum in column 1**

The column contains:

```text
20
30
16
```

The maximum is `30`, at row `1`.

Therefore:

```text
maxRow = 1
current = mat[1][1] = 30
```

Check its horizontal neighbours:

```text
Left  = 21
Right = 14
```

Since:

```text
30 > 21
30 > 14
```

And `30` is already the maximum in its column, it is greater than its vertical neighbours too.

Return:

```text
[1, 1]
```

The answer is found in the first iteration.

### Time Complexity

Let `n` be the number of rows and `m` be the number of columns.

Finding the maximum in one column takes `O(n)` time. Binary search examines `O(log m)` columns.

* **Time:** `O(n log m)`

### Space Complexity

Only a few variables are used.

* **Auxiliary space:** `O(1)`

---

## Approach Comparison

| Feature         | Brute Force                | Binary Search                           |
| --------------- | -------------------------- | --------------------------------------- |
| Search strategy | Check every cell           | Search by columns                       |
| Main operation  | Four-neighbour comparisons | Column maximum + horizontal comparisons |
| Time complexity | `O(n × m)`                 | `O(n log m)`                            |
| Auxiliary space | `O(1)`                     | `O(1)`                                  |

## Edge Cases

1. **Single cell:** That cell is the peak.
2. **Single row:** Only horizontal neighbours need meaningful comparisons.
3. **Single column:** The maximum element in the column is a peak.
4. **Peak on a boundary:** Missing neighbours outside the matrix do not need to be checked.
5. **Multiple peaks:** Returning any valid peak is acceptable.
6. **Empty matrix:** Check for empty input before accessing `mat[0]` if the problem permits it.

## What I Learned

* A peak is defined by local neighbour comparisons.
* Brute force checks every cell.
* Finding the maximum in a column guarantees it is greater than its vertical neighbours.
* The larger horizontal neighbour guides binary search toward a peak.
* Binary search can be applied to one matrix dimension without searching every cell.

## Revision Shortcut

Remember the optimized approach:

```text
Binary search columns
        ↓
Find maximum row in mid column
        ↓
Compare left and right
        ↓
If both are smaller → Return peak
If left is greater → Search left
Otherwise → Search right
```

### Final Takeaway

Brute force takes `O(n × m)` time, while binary search on columns takes `O(n log m)` time by finding a column maximum and using its horizontal neighbours to eliminate half the search space.
