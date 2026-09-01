# Day 58 — Count Inversions

## 📌 Problem Statement

Given an array `nums`, count the number of inversion pairs.

An inversion is a pair of indices `(i, j)` such that:

```text
i < j
AND
nums[i] > nums[j]
```

Return the total number of inversions.

---

## 🧪 Example

### Input

```text
5
5 3 2 4 1
```

### Your Output

```text
8
```

### Explanation

The inversion pairs are:

```text
(5,3)
(5,2)
(5,4)
(5,1)
(3,2)
(3,1)
(2,1)
(4,1)
```

Total:

```text
8
```

---

# 🔍 Pattern Recognition

When you see:

```text
i < j
+
nums[i] > nums[j]
```

Think:

```text
INVERSION
```

If the task is simply to check all pairs:

```text
Brute Force
```

If the array is large and you need an efficient solution:

```text
Merge Sort + Inversion Counting
```

### Recognition Flow

```text
Array
  ↓
Pair / Index condition
  ↓
i < j && nums[i] > nums[j]
  ↓
Inversion
  ↓
Need count?
  ↓
Merge Sort
```

---

# Approach 1 — Brute Force

## 💡 Idea

Check every possible pair `(i, j)`.

For every:

```text
i < j
```

check:

```text
nums[i] > nums[j]
```

If true:

```text
count++
```

### Example

```text
nums = [5, 3, 2]
```

Pairs:

```text
5,3 → inversion
5,2 → inversion
3,2 → inversion
```

Answer:

```text
3
```

### Complexity

```text
Time  = O(N²)
Space = O(1)
```

---

# Approach 2 — Merge Sort

The optimal solution uses merge sort.

Normally merge sort does:

```text
Divide
  ↓
Sort left
  ↓
Sort right
  ↓
Merge
```

Here we add one extra job:

```text
Merge ke time inversions count karo.
```

---

# 🧠 Important Observation

Suppose during merging:

```text
Left  = [2, 5, 6]
Right = [1, 4]
```

We compare:

```text
2 > 1
```

Because the left half is already sorted:

```text
[2, 5, 6]
```

we know:

```text
2 > 1
5 > 1
6 > 1
```

So one comparison tells us about **multiple inversions**.

Therefore:

```text
count += mid - left + 1
```

This is the main trick.

---

# 🔄 Dry Run

Consider:

```text
[5, 3, 2, 4, 1]
```

Merge sort divides the array:

```text
[5, 3, 2] [4, 1]
```

Eventually we get small sorted pieces.

For example:

```text
[5] [3]
```

Merge:

```text
5 > 3
```

So:

```text
count = 1
```

Sorted result:

```text
[3, 5]
```

---

Another merge:

```text
[4] [1]
```

Since:

```text
4 > 1
```

count:

```text
+1
```

---

Now larger pieces are merged.

The important part is that both halves are already sorted.

Suppose:

```text
Left  = [2, 3, 5]
Right = [1, 4]
```

Compare:

```text
2 > 1
```

Since the remaining left elements are:

```text
2, 3, 5
```

all are greater than `1`.

Therefore:

```text
3 inversions
```

instead of checking:

```text
2 > 1
3 > 1
5 > 1
```

individually.

This is how merge sort reduces the complexity.

---

# ⚡ Why `mid - left + 1`?

Suppose:

```text
left = 2
mid = 4
```

Then left half contains:

```text
index 2
index 3
index 4
```

Number of elements:

```text
4 - 2 + 1 = 3
```

Therefore:

```cpp
count += (mid - left + 1);
```

---

# 📊 Complexity

### Brute Force

```text
Time  = O(N²)
Space = O(1)
```

### Merge Sort

```text
Time  = O(N log N)
Space = O(N)
```

---

# 🎯 What You Learned

### Brute Force

```text
Check every pair
      ↓
nums[i] > nums[j]
      ↓
count++
```

### Optimal

```text
Merge Sort
    ↓
Divide array
    ↓
Sort both halves
    ↓
Merge
    ↓
Count cross inversions
```

---

# 🧠 One-Line Memory Trick

```text
"Inversion = left index smaller, but left value bigger."
```

Or simply:

```text
i < j && nums[i] > nums[j]
```

For a large `N`:

```text
Inversion → Merge Sort
```
