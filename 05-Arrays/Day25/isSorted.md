# Day 25 - Check if Array is Sorted

## Problem
Given an integer array `nums`, determine whether the array is sorted in non-decreasing order.

### Example
Input:
nums = [1, 2, 2, 4, 5]

Output:
true

---

## Dry Run

Input:
nums = [1, 2, 2, 4, 5]

| i | nums[i] | nums[i+1] | Comparison | Result |
|---|---------|-----------|------------|--------|
| 0 | 1 | 2 | 1 <= 2 | Continue |
| 1 | 2 | 2 | 2 <= 2 | Continue |
| 2 | 2 | 4 | 2 <= 4 | Continue |
| 3 | 4 | 5 | 4 <= 5 | Continue |

No element is greater than its next element.

**Answer = true**

---

### Dry Run (Unsorted Case)

Input:
nums = [1, 3, 2, 4, 5]

| i | nums[i] | nums[i+1] | Comparison | Result |
|---|---------|-----------|------------|--------|
| 0 | 1 | 3 | 1 <= 3 | Continue |
| 1 | 3 | 2 | 3 > 2 | Return false |

The array is not sorted.

---

## Approach

- Traverse the array from left to right.
- Compare each element with its next element.
- If `nums[i] > nums[i + 1]`, return `false`.
- If the loop completes, return `true`.

---

## Time Complexity

- **O(n)**

## Space Complexity

- **O(1)**

---

## What I Learned

- How to check whether an array is sorted using a single traversal.
- Early termination improves efficiency by stopping as soon as an unsorted pair is found.
- Difference between **strictly increasing** and **non-decreasing** arrays.