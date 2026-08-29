# Day 56 — Merge Two Sorted Arrays Without Extra Space

## 📌 Problem Statement

Given two sorted arrays, merge them so that:

* `arr1` contains the smallest elements.
* `arr2` contains the remaining largest elements.
* Both arrays should remain sorted.
* No third array should be used.

---

## 🧪 Example

### Input

```text
3 3
1 4 8
2 3 5
```

### Your Output

```text
nums1: 1 2 3
nums2: 4 5 8
```

Combined sorted array:

```text
1 2 3 4 5 8
```

---

# 🔍 Pattern Recognition Clue

When you see:

```text
Two Sorted Arrays
+
Merge
+
Without Extra Space
```

Think:

```text
Sorted Arrays
      ↓
Compare boundary elements
      ↓
Smaller → left array
Larger  → right array
```

And if the problem specifically asks for **O(1) extra space**, think:

```text
Two Pointer / Swap
        OR
Gap Method
```

### Strong clue

If you see:

> "Merge two sorted arrays without using extra space"

your brain should immediately ask:

```text
Can I rearrange the two existing arrays
instead of creating a third array?
```

---

# Approach 1 — Swap + Sort

## 💡 Idea

Because both arrays are already sorted:

```text
arr1 → smallest side
arr2 → largest side
```

We only need to check the boundary:

```text
arr1's largest
        ↓
arr2's smallest
```

If:

```text
arr1[last] > arr2[first]
```

then they are on the wrong side.

So swap them.

---

## Example

```text
arr1 = [1, 4, 8]
arr2 = [2, 3, 5]
```

Compare:

```text
arr1 largest = 8
arr2 smallest = 2
```

Since:

```text
8 > 2
```

swap:

```text
arr1 = [1, 4, 2]
arr2 = [8, 3, 5]
```

Now we may have disturbed the ordering.

Therefore sort both arrays again:

```text
arr1 = [1, 2, 4]
arr2 = [3, 5, 8]
```

---

## Complexity

Swapping phase:

```text
O(min(n,m))
```

Sorting:

```text
O(n log n) + O(m log m)
```

Overall:

```text
Time  = O(n log n + m log m)
Space = O(1)
```

---

# ⚠️ Important Code Detail

The valid elements of `nums1` are only:

```text
0 → m-1
```

if the LeetCode-style signature is:

```cpp
merge(nums1, m, nums2, n)
```

Therefore:

```cpp
int left = m - 1;
```

not:

```cpp
int left = n - 1;
```

The variable names `m` and `n` can easily cause confusion, so always check which variable represents the size of which array.

---

# Approach 2 — Optimal: Gap Method

## 💡 Main Idea

Instead of sorting each array separately, imagine both arrays as **one virtual array**.

Example:

```text
arr1 = [1 4 8 10]
arr2 = [2 3 9]
```

Imagine:

```text
[1 4 8 10 | 2 3 9]
```

We don't physically combine them.

We only use their indices as if they were one array.

---

# 🧠 Why Is It Called Gap Method?

Because instead of comparing adjacent elements immediately, we initially compare elements separated by a large **gap**.

For total length:

```text
len = n + m
```

Initial gap:

```text
gap = ceil(len / 2)
```

In integer C++ arithmetic:

```cpp
gap = (len / 2) + (len % 2);
```

Then:

```text
Large Gap
   ↓
Smaller Gap
   ↓
Even Smaller Gap
   ↓
Gap = 1
```

When:

```text
gap = 1
```

we compare neighboring elements.

---

# 🔄 Gap Example

Suppose:

```text
arr1 = [1 4 8 10]
arr2 = [2 3 9]
```

Virtual array:

```text
Index:  0  1  2  3 | 4  5  6
Value:  1  4  8 10 | 2  3  9
```

Total:

```text
len = 7
```

Initial:

```text
gap = ceil(7/2)
    = 4
```

So:

```text
0 ↔ 4
1 ↔ 5
2 ↔ 6
```

Comparisons:

```text
1 ↔ 2    → no swap
4 ↔ 3    → swap
8 ↔ 9    → no swap
```

Now the arrays become conceptually:

```text
[1 3 8 10 | 2 4 9]
```

Next:

```text
gap = 2
```

Then:

```text
gap = 1
```

Finally the arrays become:

```text
[1 2 3 4 | 8 9 10]
```

---

# 🧩 Three Cases in Gap Method

Because we have two physical arrays but one virtual array, every comparison can fall into three cases.

## Case 1 — Left in arr1, Right in arr2

```text
left < n
right >= n
```

Example:

```text
arr1[left]
arr2[right - n]
```

So:

```cpp
swapIfGreater(arr1, arr2, left, right - n);
```

---

## Case 2 — Both in arr2

```text
left >= n
```

Both indices belong to `arr2`.

Convert virtual indices to arr2 indices:

```cpp
left - n
right - n
```

Then compare:

```cpp
swapIfGreater(
    arr2,
    arr2,
    left - n,
    right - n
);
```

---

## Case 3 — Both in arr1

If neither of the above conditions is true, both positions belong to `arr1`.

So:

```cpp
swapIfGreater(
    arr1,
    arr1,
    left,
    right
);
```

---

# 🧠 Virtual Array Visualization

This is the most important visualization for understanding the algorithm:

```text
             Virtual Array
                  ↓

      arr1                arr2
┌──────────────────┬──────────────┐
│ 1  4  8  10      │ 2  3  9     │
└──────────────────┴──────────────┘
  0  1  2   3        4  5  6
```

We pretend this is:

```text
[1, 4, 8, 10, 2, 3, 9]
```

but we never actually create this array.

That's how we achieve:

```text
O(1) extra space
```

---

# ⭐ Why `swapIfGreater()`?

Instead of writing:

```cpp
if (arr1[i] > arr2[j]) {
    swap(arr1[i], arr2[j]);
}
```

again and again, we create:

```cpp
swapIfGreater(...)
```

Its entire job is:

```text
If left value > right value
        ↓
      SWAP
```

This keeps the Gap Method code cleaner.

---

# ⏱️ Complexity

For the Gap Method:

```text
Time ≈ O((n + m) log(n + m))
Space = O(1)
```

The important achievement is:

```text
No third array
No HashMap
No extra vector
```

Only swaps are performed inside the original arrays.

---

# 📊 Comparison

| Approach    | Main Idea                              |                 Time | Extra Space |
| ----------- | -------------------------------------- | -------------------: | ----------: |
| Swap + Sort | Swap boundary elements, then sort both | O(n log n + m log m) |        O(1) |
| Gap Method  | Treat arrays as one virtual array      |    O((n+m) log(n+m)) |        O(1) |

---

# 🎯 Day56 Learning

### Approach 1

```text
arr1 largest
      ↓
arr2 smallest
      ↓
Wrong order?
      ↓
SWAP
      ↓
Sort both arrays
```

### Approach 2

```text
Two arrays
    ↓
Virtual combined array
    ↓
Large GAP
    ↓
Smaller GAP
    ↓
GAP = 1
    ↓
Sorted arrays
```

---

# 🔥 Final Pattern

```text
Two Sorted Arrays
        +
No Extra Space
        ↓
Compare / Rearrange boundaries
        ↓
If O(1) space is required
        ↓
Think GAP METHOD
```

### One-line memory trick

```text
"Do arrays ko physically merge mat karo,
virtual array samjho aur gap se compare karo."
```

---

# ⚠️ Important Difference

Don't confuse this problem with normal merge sort merging.

Normal merge:

```text
arr1 + arr2
     ↓
third array
```

This problem:

```text
arr1 + arr2
     ↓
NO third array
     ↓
rearrange existing arrays
```

That's why the Gap Method is important.
