# Day91 — Search in a 2D Matrix

## Problem

Given a matrix and a target, determine whether the target exists in the matrix.

**Matrix property:** Each row is sorted in ascending order, and the first element of each row is greater than the last element of the previous row.

### Example

```text
Matrix:
1   3   5   7
10  11  16  20
23  30  34  60

Target = 16
Output = true
```

---

## Approach 1 — Brute Force

### Idea

Traverse every row and every column. Compare each element with the target. Return `true` when a match is found; otherwise, return `false` after the complete traversal.

### Pattern Recognition

When no ordering property is used, checking every cell is the straightforward approach.

**Pattern:** Nested loops → compare each element → return on match.

### Dry Run

Target = `16`

1. Check `1`, `3`, `5`, and `7`: no match.
2. Check `10` and `11`: no match.
3. Check `16`: match found.
4. Return `true`.

### Time Complexity

There are `n × m` cells.

* **Worst case:** `O(n × m)`

### Space Complexity

* **Auxiliary space:** `O(1)`

---

## Approach 2 — Binary Search

### Idea

Because the entire matrix is globally sorted, treat it conceptually as one sorted 1D array without creating a new array.

For a matrix with `m` columns, convert a 1D index `mid` into a 2D position:

* `row = mid / m`
* `col = mid % m`

Then compare `matrix[row][col]` with the target and adjust the binary-search boundaries.

### Pattern Recognition

Look for these properties:

* Every row is sorted.
* The first element of a row is greater than the last element of the preceding row.

These conditions allow **Binary Search on a flattened index range**.

### Dry Run

```text
Matrix:
1   3   5   7
10  11  16  20
23  30  34  60

Target = 16
n = 3, m = 4
low = 0, high = 11
```

**Step 1**

```text
mid = 5
row = 5 / 4 = 1
col = 5 % 4 = 1
matrix[1][1] = 11
```

Since `11 < 16`, search the right half.

```text
low = 6
```

**Step 2**

```text
mid = 8
row = 8 / 4 = 2
col = 8 % 4 = 0
matrix[2][0] = 23
```

Since `23 > 16`, search the left half.

```text
high = 7
```

**Step 3**

```text
mid = 6
row = 6 / 4 = 1
col = 6 % 4 = 2
matrix[1][2] = 16
```

Target found. Return `true`.

### Time Complexity

Binary search halves the search range in each iteration.

* **Time:** `O(log(n × m))`

### Space Complexity

No additional array is created.

* **Auxiliary space:** `O(1)`

---

## Approach Comparison

| Approach      | Time Complexity | Auxiliary Space |
| ------------- | --------------- | --------------- |
| Brute Force   | `O(n × m)`      | `O(1)`          |
| Binary Search | `O(log(n × m))` | `O(1)`          |

## Edge Cases

* Target is the first element.
* Target is the last element.
* Target is absent.
* Matrix has one row or one column.
* Matrix has a single element.

The implementation assumes the matrix is non-empty. Handle an empty matrix before accessing `matrix[0]` if the problem permits empty input.

## What I Learned

* Recognize when a 2D matrix can be treated as a sorted 1D search space.
* Convert a 1D index to a matrix position using division and modulo.
* Use binary search to reduce the number of comparisons.
* Always verify that the matrix satisfies the global sorted-order condition before applying this approach.

## Revision Shortcut

```text
low = 0
high = n * m - 1

mid = low + (high - low) / 2
row = mid / m
col = mid % m

Compare matrix[row][col] with target.
```

**Final takeaway:** Global matrix ordering enables binary search in `O(log(n × m))` time without allocating a flattened array.
