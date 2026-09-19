# Day 73 — Find Peak Element

## Problem

Given an array where adjacent elements are different, find any **peak element**.

A peak element is an element that is greater than its neighboring elements.

For boundary elements, only the existing neighbor needs to be smaller.

Return the index of any peak element.

---

## Example

### Input

```text
6
1 2 3 4 3 2
```

### Output

```text
Peak Element Index: 3
Peak Element: 4
```

Here:

```text
1 < 2 < 3 < 4 > 3 > 2
            ↑
           Peak
```

---

# Approach 1 — Linear Search

### Idea

We can simply check every element from left to right.

If:

```text
arr[i] > arr[i + 1]
```

then `arr[i]` can be a peak because we are moving from an increasing side to a decreasing side.

We also separately check the last element.

### Steps

1. If there is only one element, return index `0`.
2. Check whether the last element is greater than the previous element.
3. Traverse the array.
4. Whenever `arr[i] > arr[i + 1]`, return `i`.
5. If nothing is found, return `-1`.

### Dry Run

Array:

```text
[1, 2, 3, 4, 3, 2]
```

Start checking:

```text
1 > 2 → No
2 > 3 → No
3 > 4 → No
4 > 3 → Yes
```

Therefore:

```text
Peak index = 3
Peak value = 4
```

### Complexity

* Time: **O(N)**
* Space: **O(1)**

---

# Approach 2 — Binary Search

The important observation is that we don't necessarily need to check every element.

Suppose we are at:

```text
arr[mid]
```

There are two important situations.

### Case 1 — Increasing slope

If:

```text
arr[mid] < arr[mid + 1]
```

we are going uphill.

Example:

```text
2  4  6  8
      ↑  ↑
     mid
```

A peak must exist somewhere on the **right side**, so:

```cpp
low = mid + 1;
```

---

### Case 2 — Decreasing slope

If:

```text
arr[mid] > arr[mid + 1]
```

we are going downhill.

Example:

```text
8  6  4  2
   ↑
  mid
```

A peak exists at `mid` or somewhere on the **left side**.

Therefore:

```cpp
high = mid - 1;
```

---

### Case 3 — Actual Peak

If:

```cpp
arr[mid] > arr[mid - 1] &&
arr[mid] > arr[mid + 1]
```

then we found our answer.

---

## Binary Search Dry Run

Array:

```text
[1, 2, 3, 4, 3, 2]
```

Ignore boundaries initially.

```text
low = 1
high = 4
```

### Iteration 1

```text
mid = 2

arr[mid] = 3
left  = 2
right = 4
```

Check:

```text
3 > 2  → Yes
3 > 4  → No
```

So `mid` is not a peak.

But:

```text
arr[mid] < arr[mid + 1]
3 < 4
```

We are on an increasing slope.

Therefore move right:

```text
low = mid + 1
low = 3
```

### Iteration 2

```text
low = 3
high = 4

mid = 3
```

Now:

```text
arr[3] = 4
```

Neighbors:

```text
arr[2] = 3
arr[4] = 3
```

Therefore:

```text
4 > 3
4 > 3
```

Peak found.

```text
index = 3
value = 4
```

---

# Pattern Recognition Clue

When you see:

* **Sorted / partially structured array**
* Need to find an element/property
* The problem allows eliminating **half of the search space**
* There is a directional relationship such as:

  * increasing
  * decreasing
  * left/right half
  * monotonic behavior

Think:

> **Can I determine which half definitely contains the answer?**

For this problem specifically:

```text
arr[mid] < arr[mid + 1]
```

means we are moving **uphill**, so go right.

```text
arr[mid] > arr[mid + 1]
```

means we are moving **downhill**, so go left.

This is the key binary-search pattern.

---

# Approach Comparison

| Approach      | Idea                        |     Time | Space |
| ------------- | --------------------------- | -------: | ----: |
| Linear Search | Check elements one by one   |     O(N) |  O(1) |
| Binary Search | Use slope to eliminate half | O(log N) |  O(1) |

### Why Binary Search is Optimal

Linear search may inspect almost every element:

```text
O(N)
```

Binary search eliminates roughly half the remaining search space after every comparison:

```text
N
↓
N/2
↓
N/4
↓
N/8
↓
...
```

Therefore:

```text
O(log N)
```

---

# Important Learning

The most important part of this problem is **not memorizing the code**.

Understand this decision:

```cpp
if (arr[mid] < arr[mid + 1])
    low = mid + 1;
else
    high = mid - 1;
```

The decision comes from the **slope** around `mid`.

### Mental Model

```text
Increasing:
    /
   /
  /   → go RIGHT

Peak:
   /\
  /  \
     ↑ answer

Decreasing:
   \
    \
     \
      → go LEFT
```

This type of reasoning is useful for recognizing binary-search problems where the answer is determined by a **direction/property**, rather than by directly comparing the target with `arr[mid]`.

---

# Files

```text
Day73/
│
├── findPeakElementBruteForce.cpp
├── findPeakElementBinarySearch.cpp
└── findPeakElement.md
```

**Brute Force:** `O(N)`

**Optimal Binary Search:** `O(log N)`
