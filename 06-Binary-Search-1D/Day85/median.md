# Day 85 — Median of Two Sorted Arrays

## 📌 Problem

Given two sorted arrays `arr1` and `arr2`, find the **median** of the combined sorted array.

The arrays are individually sorted.

### Example

```text
arr1 = [1, 3]
arr2 = [2]
```

Combined sorted order:

```text
[1, 2, 3]
```

Median:

```text
2
```

Output:

```text
2.0
```

---

# 🔹 Approach 1 — Merge Both Arrays

## 💡 Idea

Since both arrays are already sorted, we can use the standard **merge technique**.

Maintain two pointers:

```text
i → arr1
j → arr2
```

Compare:

```text
arr1[i] vs arr2[j]
```

Take the smaller element and move that pointer forward.

Continue until both arrays are completely processed.

Then calculate the median from the merged array.

---

## 🧠 Pattern Recognition Clue

Whenever you see:

> **Two sorted arrays**

immediately think:

```text
Two Pointers
+
Merge
```

This is the same fundamental idea used in the merge step of **Merge Sort**.

The key clue is:

```text
Both inputs are sorted
        ↓
Compare current elements
        ↓
Take smaller one
        ↓
Move that pointer
```

---

## 🔄 Dry Run

```text
arr1 = [1, 3]
arr2 = [2, 4]
```

### Step 1

```text
1 < 2
```

Take `1`.

```text
merge = [1]
```

---

### Step 2

```text
3 > 2
```

Take `2`.

```text
merge = [1, 2]
```

---

### Step 3

```text
3 < 4
```

Take `3`.

```text
merge = [1, 2, 3]
```

---

### Step 4

Take remaining `4`.

```text
merge = [1, 2, 3, 4]
```

There are 4 elements.

Median:

```text
(2 + 3) / 2
```

Therefore:

```text
2.5
```

---

## ⏱️ Time Complexity

If:

```text
n = arr1.size()
m = arr2.size()
```

We process every element:

```text
O(n + m)
```

## 💾 Space Complexity

We create a merged array:

```text
O(n + m)
```

---

# 🔹 Approach 2 — Two Pointer Without Storing the Merged Array

## 💡 Idea

We don't actually need the complete merged array.

We only need the elements around the median.

For:

```text
total = n + m
```

the important positions are:

```text
total / 2
```

and, for an even-sized array:

```text
total / 2 - 1
```

So we continue merging logically but only remember the two elements needed for the median.

---

## 🧠 Pattern Recognition Clue

This is an important optimization thought:

> **Do I really need to store the entire result?**

If the final answer only depends on a few positions, we can often avoid creating the complete structure.

Here:

```text
Need complete merged array? ❌
Need only median positions? ✅
```

Therefore:

```text
Merge logic
+
Track only required positions
```

---

## 🔄 Dry Run

```text
arr1 = [1, 3]
arr2 = [2, 4]
```

Total:

```text
4
```

Important indexes:

```text
ind1 = 1
ind2 = 2
```

Merged order conceptually:

```text
index:  0  1  2  3
value:  1  2  3  4
```

We only need:

```text
index 1 → 2
index 2 → 3
```

So:

```text
median = (2 + 3) / 2
       = 2.5
```

---

## ⏱️ Time Complexity

We still may process all elements:

```text
O(n + m)
```

## 💾 Space Complexity

No merged array is created:

```text
O(1)
```

This is better than Approach 1 in space usage.

---

# 🔹 Approach 3 — Binary Search Partition

This is the **optimal approach**.

## 💡 Core Idea

Instead of actually merging the arrays, we divide them into two halves.

We want:

```text
LEFT HALF | RIGHT HALF
```

such that:

1. Left half contains half of the total elements.
2. Every element in the left half is smaller than or equal to every element in the right half.

For example:

```text
arr1 = [1, 3]
arr2 = [2, 4]
```

We want:

```text
[1, 2] | [3, 4]
```

The median is determined by the elements immediately around this partition.

---

# 🧠 Pattern Recognition — Most Important Part

This problem is a classic example of **Binary Search on a Partition**.

When you see:

> Two sorted arrays + median

think:

```text
Can I partition both arrays
so that the left side contains half
of all elements?
```

If yes, binary search can be applied to the partition position.

---

## 🔑 Partition Thinking

Suppose:

```text
arr1 = [1, 3, 8]
arr2 = [2, 4, 9, 10]
```

Total elements:

```text
7
```

We need:

```text
(7 + 1) / 2 = 4
```

elements on the left.

Suppose we take:

```text
2 elements from arr1
2 elements from arr2
```

Partition:

```text
arr1: [1, 3 | 8]
arr2: [2, 4 | 9, 10]
```

Combined:

```text
[1, 2, 3, 4] | [8, 9, 10]
```

The partition is correct because:

```text
left elements <= right elements
```

Specifically:

```text
3 <= 9
4 <= 8
```

---

# 🧩 The Four Boundary Values

At every partition we care about four values:

```text
        LEFT       RIGHT

arr1   l1  |  r1

arr2   l2  |  r2
```

For a valid partition:

```text
l1 <= r2
AND
l2 <= r1
```

This is the central condition.

---

# 🔍 Why These Conditions Matter

We don't need to compare every element.

Because the arrays are already sorted, only the elements touching the partition can violate the ordering.

So:

```text
l1 <= r2
l2 <= r1
```

means the partition is correctly positioned.

Once this happens, we have found the median boundary.

---

# 🔄 Binary Search Decision

Suppose:

```text
l1 > r2
```

This means:

```text
Too many elements were taken from arr1.
```

Therefore move left:

```text
high = mid1 - 1
```

Otherwise:

```text
l2 > r1
```

means we need more elements from `arr1`.

So move right:

```text
low = mid1 + 1
```

Therefore:

```text
l1 > r2
      ↓
move LEFT

l2 > r1
      ↓
move RIGHT
```

---

# 🔄 Dry Run — Binary Search Partition

Consider:

```text
arr1 = [1, 3]
arr2 = [2, 4]
```

Total:

```text
4
```

Required left elements:

```text
4 / 2 = 2
```

We binary search on the **smaller array**.

Initial:

```text
low = 0
high = 2
```

---

### Step 1

Suppose:

```text
mid1 = 1
```

Then:

```text
mid2 = 2 - 1
     = 1
```

Partition:

```text
arr1: [1 | 3]
arr2: [2 | 4]
```

So:

```text
l1 = 1
r1 = 3

l2 = 2
r2 = 4
```

Check:

```text
l1 <= r2
1 <= 4 ✅

l2 <= r1
2 <= 3 ✅
```

Correct partition found.

---

### Since total length is even

Median is:

```text
max(l1, l2) + min(r1, r2)
--------------------------------
               2
```

Therefore:

```text
max(1, 2) = 2
min(3, 4) = 3
```

So:

```text
median = (2 + 3) / 2
       = 2.5
```

---

# ⚠️ Why Search the Smaller Array?

This is an important optimization.

If we binary search the smaller array:

```text
O(log(min(n, m)))
```

instead of potentially searching the larger array.

Therefore, we ensure:

```text
n1 <= n2
```

before starting binary search.

---

# ⚠️ Boundary Cases

Sometimes the partition is at the very beginning or end of an array.

For example:

```text
mid1 = 0
```

There is no left element from `arr1`.

We treat it as:

```text
l1 = -∞
```

Similarly, if:

```text
mid1 = n1
```

there is no right element.

We treat:

```text
r1 = +∞
```

In C++ this is represented using:

```text
INT_MIN
INT_MAX
```

This lets the same partition logic work without special complicated cases.

---

# ⚖️ Approach Comparison

| Feature              |    Merge | Two Pointer | Binary Search Partition |
| -------------------- | -------: | ----------: | ----------------------: |
| Uses sorted property |        ✅ |           ✅ |                       ✅ |
| Builds merged array  |        ✅ |           ❌ |                       ❌ |
| Time                 | `O(n+m)` |    `O(n+m)` |      `O(log(min(n,m)))` |
| Extra Space          | `O(n+m)` |      `O(1)` |                  `O(1)` |
| Difficulty           |     Easy |      Medium |                    Hard |
| Optimal              |        ❌ |           ❌ |                       ✅ |

---

# 🎯 Pattern Recognition Summary

This problem contains several useful DSA patterns.

### Pattern 1 — Two Sorted Arrays

```text
Two sorted arrays
      ↓
Two pointers / merge
```

---

### Pattern 2 — Don't Build What You Don't Need

If you only need the median:

```text
Don't necessarily store merged array
```

Track only the required positions.

---

### Pattern 3 — Binary Search on Partition

When you see:

```text
Two sorted arrays
+
Median
```

think:

```text
Partition both arrays
        ↓
Left contains half
        ↓
Check boundary elements
        ↓
Move partition left/right
        ↓
Binary Search
```

---

# 🚨 Important Questions to Ask Yourself

Before jumping into the optimal solution, ask:

### Question 1

Are both arrays sorted?

```text
YES
```

So merging/two-pointer is possible.

### Question 2

Do I need the complete merged array?

```text
NO
```

So space can be reduced.

### Question 3

Can I determine the median by dividing the combined data into two equal halves?

```text
YES
```

### Question 4

Can I binary search the partition?

```text
YES
```

Therefore:

```text
Binary Search on Partition
```

---

# 🧠 What I Learned

* Two sorted arrays can be merged using two pointers.
* We don't always need to construct the complete merged array.
* The median depends only on the middle element(s).
* The optimal solution uses a partition rather than actual merging.
* The partition must satisfy:

```text
l1 <= r2
l2 <= r1
```

* Binary Search is performed on the smaller array.
* Searching the smaller array gives:

```text
O(log(min(n,m)))
```

* `INT_MIN` and `INT_MAX` help handle partition boundaries.
* This is a classic **Binary Search on Partition** problem.

---

# 🎯 Revision Shortcut

Remember this picture:

```text
arr1:      l1 | r1
arr2:      l2 | r2
             ↓
      LEFT | RIGHT
```

Need:

```text
l1 <= r2
l2 <= r1
```

If:

```text
l1 > r2
```

move left.

If:

```text
l2 > r1
```

move right.

When partition is valid:

```text
Odd:
median = max(l1, l2)

Even:
median = (max(l1,l2) + min(r1,r2)) / 2
```

### Pattern

**Binary Search on Partition**

### Optimal Complexity

```text
Time:  O(log(min(n,m)))
Space: O(1)
```
