# Day 80 — Kth Missing Positive Number

## 📌 Problem

Given a strictly increasing array of positive integers `arr` and an integer `k`, find the **k-th positive integer that is missing from the array**.

### Example

**Input**

```text
arr = [2, 3, 4, 7, 11]
k = 5
```

Positive numbers are:

```text
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
```

Numbers missing from the array:

```text
1, 5, 6, 8, 9, 10, ...
```

The 5th missing number is:

```text
9
```

### Output

```text
9
```

---

# 🔹 Approach 1 — Linear Search

## 💡 Idea

We start with:

```text
k = required missing number
```

Traverse the array from left to right.

For every element:

```text
if arr[i] <= k
```

it means this array element occupies one position that would otherwise have been a missing number.

Therefore we increase:

```text
k++
```

If:

```text
arr[i] > k
```

we have found the answer.

Finally, `k` itself represents the k-th missing positive number.

---

## 🔍 Pattern Recognition Clue

Whenever you have:

* a sorted array
* positive integers
* some numbers missing
* need the k-th missing number

first ask:

> **"Can I track how many missing numbers have appeared before the current element?"**

For the linear solution, we can avoid explicitly counting missing numbers.

The useful observation is:

```text
arr[i] <= k
       ↓
This number pushes the k-th missing number forward
       ↓
k++
```

This gives a simple linear solution.

---

## 🔄 Dry Run

Input:

```text
arr = [2, 3, 4, 7, 11]
k = 5
```

### Start

```text
k = 5
```

### `arr[0] = 2`

```text
2 <= 5
```

So:

```text
k = 6
```

### `arr[1] = 3`

```text
3 <= 6
```

So:

```text
k = 7
```

### `arr[2] = 4`

```text
4 <= 7
```

So:

```text
k = 8
```

### `arr[3] = 7`

```text
7 <= 8
```

So:

```text
k = 9
```

### `arr[4] = 11`

```text
11 > 9
```

Stop.

Final answer:

```text
9
```

---

## ⏱️ Time Complexity

```text
O(N)
```

where `N` is the size of the array.

## 💾 Space Complexity

```text
O(1)
```

---

# 🔹 Approach 2 — Binary Search

## 💡 Observation

Because the array is sorted, we can determine how many positive integers are missing before any index.

For index `mid`:

```text
expected numbers = mid + 1
```

because indices start from `0`.

The actual number is:

```text
arr[mid]
```

Therefore:

```text
missing numbers = arr[mid] - (mid + 1)
```

This is the key formula.

---

## 🧠 Pattern Recognition Clue

This problem contains several strong Binary Search signals:

### 1. Sorted array

```text
arr = [2, 3, 4, 7, 11]
```

### 2. We need the k-th missing position

We can calculate how many numbers are missing at every index.

### 3. Missing count is monotonic

For example:

```text
Index       0   1   2   3   4
Array       2   3   4   7  11
Missing     1   1   1   3   6
```

The number of missing elements never decreases:

```text
1 → 1 → 1 → 3 → 6
```

So we can binary search for the **first index where missing numbers >= k**.

This is the important pattern:

> **Sorted search space + monotonic condition → Binary Search**

---

# 🔑 Missing Number Formula

At index `i`:

```text
missing = arr[i] - (i + 1)
```

Why?

Suppose:

```text
arr[i] = 7
i = 3
```

There should have been:

```text
1, 2, 3, 4
```

four positive numbers up to index `3`.

But the actual value is `7`.

Therefore:

```text
7 - 4 = 3
```

So three positive numbers are missing before `7`:

```text
1, 5, 6
```

---

# 🔄 Dry Run — Binary Search

Input:

```text
arr = [2, 3, 4, 7, 11]
k = 5
```

Initial:

```text
low = 0
high = 4
```

---

### Step 1

```text
mid = 2
arr[mid] = 4
```

Missing numbers:

```text
4 - (2 + 1)
= 1
```

We need:

```text
5 missing numbers
```

But currently there are only:

```text
1
```

So search right:

```text
low = 3
```

---

### Step 2

```text
low = 3
high = 4

mid = 3
arr[mid] = 7
```

Missing:

```text
7 - (3 + 1)
= 3
```

Still:

```text
3 < 5
```

Search right:

```text
low = 4
```

---

### Step 3

```text
low = 4
high = 4

mid = 4
arr[mid] = 11
```

Missing:

```text
11 - (4 + 1)
= 6
```

Now:

```text
6 >= 5
```

So this index is too far/right.

Search left:

```text
high = 3
```

Now:

```text
low = 4
high = 3
```

Search ends.

Therefore:

```text
low = 4
```

---

# 🎯 Why `low + k` Is the Answer

After Binary Search:

```text
low = 4
```

There are:

```text
k = 5
```

missing numbers.

The answer is:

```text
low + k
```

Therefore:

```text
4 + 5 = 9
```

Answer:

```text
9
```

---

# ⚖️ Approach Comparison

| Feature               | Linear Search                                               | Binary Search                  |
| --------------------- | ----------------------------------------------------------- | ------------------------------ |
| Technique             | Direct traversal                                            | Binary Search                  |
| Main idea             | Increase `k` when array element occupies a missing position | Search based on missing count  |
| Time                  | `O(N)`                                                      | `O(log N)`                     |
| Space                 | `O(1)`                                                      | `O(1)`                         |
| Requires sorted array | Yes                                                         | Yes                            |
| Pattern               | Missing-number tracking                                     | Monotonic missing-count search |
| Optimal               | ❌                                                           | ✅                              |

---

# 🧩 Core Pattern to Remember

This problem teaches an important Binary Search pattern:

```text
Sorted Array
     ↓
Calculate property at mid
     ↓
Missing count
     ↓
Is missing count < k?
     ↓
YES → move right
NO  → move left
```

The key formula:

```text
missing = arr[mid] - (mid + 1)
```

And the final answer:

```text
answer = low + k
```

---

# 🚨 Edge Cases

### 1. First number is missing

```text
arr = [2, 3, 4]
k = 1
```

Answer:

```text
1
```

### 2. Missing number occurs between elements

```text
arr = [2, 3, 4, 7]
k = 3
```

Missing:

```text
1, 5, 6
```

Answer:

```text
6
```

### 3. Answer comes after the entire array

```text
arr = [2, 3, 4, 7, 11]
k = 5
```

Answer:

```text
9
```

### 4. No missing numbers inside the array

The answer can be directly after the last element.

---

# 🧠 What I Learned

* The array is sorted, which allows Binary Search.
* At index `i`, the number of missing positive integers before `arr[i]` is:

```text
arr[i] - (i + 1)
```

* Missing count is monotonic.
* We search for the **first position where missing count becomes >= k**.
* This is another example of **Binary Search on a monotonic condition**.
* The linear solution tracks the missing position directly.
* The optimal solution uses the missing-count formula.

---

# 🎯 Revision Shortcut

Remember:

```text
arr[i] - (i + 1)
        ↓
Missing numbers before arr[i]
```

Then:

```text
missing < k
     ↓
move right
```

```text
missing >= k
     ↓
move left
```

Finally:

```text
answer = low + k
```

### Pattern

```text
Sorted Array
+
Monotonic Missing Count
+
Find First Valid Position
        ↓
Binary Search
```

### Complexity

```text
Linear:
O(N) time
O(1) space

Binary Search:
O(log N) time
O(1) space
```
