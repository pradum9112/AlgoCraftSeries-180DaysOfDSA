# Day93 — Median in a Row-Wise Sorted Matrix

## Problem

Given a matrix in which every row is sorted in ascending order, find the median of all its elements.

For the standard version of this problem, the total number of elements is odd. The median is the middle element after sorting all elements.

### Example

```text
Matrix:
1  3  5
2  6  9
3  6  9

Output: 5
```

Sorted elements:

```text
1  2  3  3  5  6  6  9  9
```

There are 9 elements. The middle element is at index `9 / 2 = 4`, so the median is `5`.

---

# Approach 1 — Brute Force

## Idea

The matrix is sorted row-wise, but the rows are not necessarily sorted relative to one another.

Therefore:

1. Traverse the complete matrix.
2. Store all elements in a temporary vector.
3. Sort the vector.
4. Return the element at index `(n * m) / 2`.

## Pattern Recognition

When a problem asks for the median of multiple collections of values, a straightforward approach is to combine all values and sort them.

**Pattern:** Flatten → Sort → Select the middle element.

```text
2D Matrix
    ↓
1D Vector
    ↓
Sort all elements
    ↓
Return middle element
```

## Dry Run

Matrix:

```text
1  3  5
2  6  9
3  6  9
```

### Step 1 — Flatten

```text
[1, 3, 5, 2, 6, 9, 3, 6, 9]
```

### Step 2 — Sort

```text
[1, 2, 3, 3, 5, 6, 6, 9, 9]
```

### Step 3 — Find the middle index

```text
n = 3
m = 3

midIndex = (3 * 3) / 2
         = 4
```

### Step 4 — Return the element

```text
temp[4] = 5
```

**Answer: `5`**

## Time Complexity

Flattening takes `O(n × m)` and sorting takes `O(n × m log(n × m))`.

* **Time:** `O(n × m log(n × m))`

## Space Complexity

The temporary vector stores all `n × m` elements.

* **Auxiliary space:** `O(n × m)`

---

# Approach 2 — Binary Search on the Answer

## Idea

Instead of sorting all elements, binary-search the possible median value.

Since each row is sorted, we can count the elements less than or equal to a value using `upper_bound`.

### Helper Function

For each row:

```text
upper_bound(row.begin(), row.end(), mid)
```

This returns the iterator to the first element strictly greater than `mid`.

Subtracting the row's beginning iterator gives the number of elements less than or equal to `mid`.

Add these counts across all rows.

### Median Condition

Let:

```text
req = (n * m) / 2
```

For an odd number of elements, the median is the **smallest value for which the count of elements less than or equal to that value is greater than `req`**.

* If `count <= req`, the candidate is too small or equal to a value before the median. Search to the right.
* If `count > req`, the candidate may be the median or larger. Search to the left.

When the search finishes, `low` is the median.

## Pattern Recognition

Look for these clues:

* Each row is sorted.
* Sorting every element is expensive.
* We can efficiently count elements less than or equal to a candidate value.
* The count increases monotonically as the candidate value increases.

**Pattern:** Binary Search on Answer + Counting with `upper_bound`.

```text
Choose a candidate value
          ↓
Count elements <= candidate
          ↓
Count <= req?
     ↙           ↘
   Yes            No
     ↓             ↓
Search right    Search left
```

## Dry Run

Matrix:

```text
1  3  5
2  6  9
3  6  9
```

The smallest matrix value is `1`; the largest is `9`.

```text
low = 1
high = 9
req = 9 / 2 = 4
```

### Step 1

```text
mid = 5
```

Count elements `<= 5`:

* Row 1: `1, 3, 5` → 3 elements
* Row 2: `2` → 1 element
* Row 3: `3` → 1 element

Total:

```text
count = 5
```

Since `5 > req (4)`, the candidate is large enough. Search left.

```text
high = 4
```

### Step 2

```text
low = 1
high = 4
mid = 2
```

Count elements `<= 2`:

* Row 1: `1` → 1
* Row 2: `2` → 1
* Row 3: none → 0

Total:

```text
count = 2
```

Since `2 <= req (4)`, search right.

```text
low = 3
```

### Step 3

```text
low = 3
high = 4
mid = 3
```

Count elements `<= 3`:

* Row 1: `1, 3` → 2
* Row 2: `2` → 1
* Row 3: `3` → 1

Total:

```text
count = 4
```

Since `4 <= req (4)`, search right.

```text
low = 4
```

### Step 4

```text
low = 4
high = 4
mid = 4
```

Count elements `<= 4`:

* Row 1: `1, 3` → 2
* Row 2: `2` → 1
* Row 3: `3` → 1

Total:

```text
count = 4
```

Since `4 <= req`, move right again.

```text
low = 5
high = 4
```

The loop ends because `low > high`.

Return:

```text
low = 5
```

**Answer: `5`**

## Time Complexity

Let `V = max(matrix) - min(matrix) + 1`.

* Binary search takes `O(log V)` iterations.
* Each iteration runs `upper_bound` on every row.
* Each row requires `O(log m)` time.

Therefore:

* **Time:** `O(n × log(m) × log(V))`

## Space Complexity

The optimized approach uses only a few variables and does not create a flattened vector.

* **Auxiliary space:** `O(1)`

---

# Approach Comparison

| Feature          | Brute Force      | Binary Search              |
| ---------------- | ---------------- | -------------------------- |
| Strategy         | Flatten and sort | Search possible values     |
| Time             | `O(nm log(nm))`  | `O(n log(m) log(V))`       |
| Auxiliary space  | `O(nm)`          | `O(1)`                     |
| Uses row sorting | No               | Yes, through `upper_bound` |

Here, `V = max(matrix) - min(matrix) + 1`.

# Edge Cases

1. **Single element:** The element itself is the median.
2. **Single row:** The median is the middle element of that sorted row.
3. **Duplicate values:** The counting approach handles duplicates correctly.
4. **Negative values:** The binary-search bounds are taken from the matrix, so negative values are supported.
5. **Large value range:** Binary search may require more iterations when the range is large.
6. **Even number of elements:** The standard problem assumes an odd number of elements. If even-sized matrices are permitted, the problem must define whether to return the lower median, upper median, or average of the two middle values.

# What I Learned

* The median is the middle value after sorting.
* Flattening and sorting is a simple baseline.
* `upper_bound` counts the elements less than or equal to a candidate in a sorted row.
* Binary search on the answer works when the counting condition is monotonic.
* The search must find the smallest value whose count exceeds `req`, not merely any value with a sufficiently large count.

# Revision Shortcut

```text
Median in Row-Wise Sorted Matrix
             ↓
low = minimum matrix value
high = maximum matrix value
req = (n * m) / 2
             ↓
mid = low + (high - low) / 2
             ↓
Count elements <= mid using upper_bound
             ↓
count <= req → low = mid + 1
count > req  → high = mid - 1
             ↓
Return low
```

# Final Takeaway

The brute-force approach sorts all elements. The optimized approach avoids sorting the matrix by using binary search on the answer and counting elements in sorted rows.

**Core pattern:** Binary Search on Answer + Monotonic Counting.
