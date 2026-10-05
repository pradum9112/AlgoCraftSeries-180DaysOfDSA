# Day 88 — Largest Subarray Sum Minimized

## 📌 Problem

Given an array `a` of positive integers and an integer `k`, divide the array into **at most `k` contiguous subarrays** such that the **largest subarray sum is minimized**.

Return the minimum possible value of the largest subarray sum.

### Example

**Input**

```text
a = [10, 20, 30, 40]
k = 2
```

**Output**

```text
60
```

One optimal division is:

```text
[10, 20, 30] | [40]
```

Subarray sums:

```text
60 | 40
```

Therefore, the largest sum is `60`.

---

# 🔹 Approach 1 — Brute Force / Linear Search on Answer

## 💡 Idea

The answer lies between:

```text
maximum element → total sum of array
```

Why?

The largest subarray must contain at least the largest element.

So:

```text
low = max(a)
```

If the entire array is treated as one subarray:

```text
high = sum(a)
```

We check every possible maximum allowed subarray sum.

For every candidate value:

1. Traverse the array.
2. Keep adding elements to the current subarray.
3. If adding the next element exceeds the candidate limit, start a new subarray.
4. Count the required subarrays.
5. If the required number is at most `k`, the candidate is possible.
6. Return the first possible value.

---

## 🔍 Pattern Recognition

When a problem says:

```text
Divide an array into k contiguous parts
+
Minimize the maximum sum
```

think:

```text
Can I guess the maximum allowed sum?
        ↓
Can I check if the array can be divided within that limit?
```

The answer has a clear range:

```text
max(element) → sum(array)
```

This is the first clue for **Binary Search on Answer**.

The brute-force approach simply checks every possible answer in this range.

---

## 🔄 Dry Run

Consider:

```text
a = [10, 20, 30, 40]
k = 2
```

Search range:

```text
low = 40
high = 100
```

Suppose:

```text
maxSumLimit = 50
```

Start grouping:

```text
10 + 20 = 30
```

Adding `30`:

```text
30 + 30 = 60 > 50
```

So start a new subarray:

```text
[10, 20] | [30]
```

Adding `40`:

```text
30 + 40 = 70 > 50
```

So:

```text
[10, 20] | [30] | [40]
```

Required subarrays:

```text
3
```

But:

```text
k = 2
```

Therefore:

```text
50 is not possible ❌
```

Now try:

```text
maxSumLimit = 60
```

We can divide:

```text
[10, 20, 30] | [40]
```

Sums:

```text
60 | 40
```

Required subarrays:

```text
2
```

Therefore:

```text
60 is possible ✅
```

Answer:

```text
60
```

---

## ⏱️ Time Complexity

Let:

```text
S = sum of all elements
```

We may check every value from `max(a)` to `S`.

For every candidate, we scan the entire array.

```text
Time: O(n × S)
```

## 💾 Space Complexity

```text
Space: O(1)
```

---

# 🔹 Approach 2 — Binary Search on Answer

## 💡 Idea

Instead of checking every possible answer, we use Binary Search.

Search space:

```text
low = max(a)
high = sum(a)
```

For every `mid`, ask:

```text
Can the array be divided into at most k subarrays
such that every subarray has sum <= mid?
```

We use a feasibility function.

While traversing the array:

```text
currentSum + a[i] <= mid
```

then add the element to the current subarray.

Otherwise:

```text
start a new subarray
```

If the number of subarrays becomes greater than `k`:

```text
mid is impossible
```

Otherwise:

```text
mid is possible
```

---

## 🔍 Pattern Recognition

This is a classic:

```text
Binary Search on Answer
```

Recognize this pattern when you see:

```text
Minimize the maximum
        ↓
There is a possible answer range
        ↓
Can check whether a candidate is possible
        ↓
Feasibility is monotonic
        ↓
Binary Search
```

For this problem:

```text
Small maximum sum
        ↓
Need more subarrays
        ↓
May be impossible

Large maximum sum
        ↓
Need fewer subarrays
        ↓
More likely possible
```

The feasibility pattern becomes:

```text
FALSE FALSE FALSE FALSE TRUE TRUE TRUE
                         ↑
                      Answer
```

We need the **first possible value**.

---

# 🧠 Why Binary Search Works

Suppose a maximum allowed sum `X` is possible.

Then every value greater than `X` is also possible.

Because increasing the allowed maximum sum can never make the partition harder.

Therefore:

```text
Impossible → Impossible → Possible → Possible
```

This is a monotonic condition.

Hence Binary Search can find the smallest possible value.

---

## 🔄 Dry Run

Consider:

```text
a = [10, 20, 30, 40]
k = 2
```

Initial:

```text
low = 40
high = 100
```

### Step 1

```text
mid = 70
```

Possible division:

```text
[10, 20, 30] | [40]
```

Sums:

```text
60 | 40
```

Required subarrays:

```text
2
```

So:

```text
70 is possible ✅
```

Move left:

```text
high = 69
```

---

### Step 2

```text
mid = 54
```

Try grouping:

```text
10 + 20 = 30
```

Adding `30` exceeds `54`:

```text
30 + 30 = 60 > 54
```

So:

```text
[10, 20] | [30]
```

Then:

```text
30 + 40 = 70 > 54
```

So:

```text
[10, 20] | [30] | [40]
```

Required:

```text
3 subarrays
```

But:

```text
k = 2
```

Therefore:

```text
54 is impossible ❌
```

Move right:

```text
low = 55
```

---

### Step 3

```text
mid = 62
```

Possible:

```text
[10, 20, 30] | [40]
```

Sums:

```text
60 | 40
```

Required:

```text
2
```

Therefore:

```text
62 is possible ✅
```

Move left:

```text
high = 61
```

---

### Step 4

Binary Search continues narrowing the range.

Eventually:

```text
low = 60
high = 60
```

Therefore:

```text
Answer = 60
```

---

# ⏱️ Time Complexity

Let:

```text
S = sum of all elements
```

Binary Search works over the range:

```text
max(a) → S
```

Number of binary-search iterations:

```text
O(log S)
```

Each feasibility check scans the array:

```text
O(n)
```

Therefore:

```text
Time: O(n × log S)
```

## 💾 Space Complexity

```text
Space: O(1)
```

---

# ⚖️ Approach Comparison

| Feature           | Brute Force             | Binary Search           |
| ----------------- | ----------------------- | ----------------------- |
| Technique         | Linear Search on Answer | Binary Search on Answer |
| Search Space      | `max(a) → S`            | `max(a) → S`            |
| Feasibility Check | Yes                     | Yes                     |
| Time              | `O(n × S)`              | `O(n × log S)`          |
| Space             | `O(1)`                  | `O(1)`                  |
| Efficient         | ❌                       | ✅                       |
| Optimal           | ❌                       | ✅                       |

Where:

```text
S = sum of all elements
```

### Best Approach

Binary Search is optimal because:

```text
O(n × S)
        ↓
O(n × log S)
```

---

# 🧩 Core Pattern to Remember

The important pattern is:

```text
Minimize Maximum
        ↓
Define maximum allowed value
        ↓
Check feasibility
        ↓
Monotonic condition
        ↓
Binary Search on Answer
```

For this problem:

```text
Maximum subarray sum
        ↓
Guess mid
        ↓
Count required subarrays
        ↓
required > k
        → mid too small
        → low = mid + 1

required <= k
        → mid possible
        → high = mid - 1
```

---

# 🎯 Pattern Recognition Shortcut

Whenever you see:

```text
Split array into k parts
+
Minimize the maximum sum
```

think:

```text
Binary Search on Answer
```

Ask:

### 1. What is the search space?

```text
max(element) → sum(array)
```

### 2. Can I check `mid`?

```text
Can I divide the array using maximum sum = mid?
```

### 3. Is the condition monotonic?

```text
Small mid → impossible
Large mid → possible
```

If all three are true:

```text
Binary Search on Answer
```

---

# 🚨 Edge Cases

### 1. `k = 1`

The entire array becomes one subarray.

```text
Answer = total sum
```

### 2. `k >= n`

Every element can become its own subarray.

```text
Answer = maximum element
```

### 3. Single element

```text
a = [25]
k = 1
```

Answer:

```text
25
```

### 4. Large values

The total sum can become large.

Use `long long` where necessary to avoid integer overflow.

### 5. Element greater than `mid`

If:

```text
a[i] > mid
```

then `mid` is immediately impossible.

---

# 🧠 What I Learned

* The problem is about splitting an array into contiguous subarrays.
* The goal is to minimize the maximum subarray sum.
* The smallest possible answer is the maximum element.
* The largest possible answer is the total sum.
* We can check how many subarrays are required for a given maximum sum.
* If required subarrays exceed `k`, the candidate is too small.
* If `k` or fewer subarrays are enough, the candidate is possible.
* The feasibility condition is monotonic.
* Therefore Binary Search on Answer can be used.
* Brute Force takes `O(n × S)`.
* Binary Search reduces it to `O(n × log S)`.
* The same pattern appears in:

  * Book Allocation
  * Painter's Partition
  * Split Array Largest Sum
  * Ship Packages Within D Days

---

# 🎯 Revision Shortcut

```text
Minimize Maximum Subarray Sum
            ↓
Find answer range
            ↓
max(element) → sum(array)
            ↓
Guess mid
            ↓
Count required subarrays
            ↓
required > k
    → mid too small
    → low = mid + 1

required <= k
    → mid possible
    → high = mid - 1
            ↓
Find smallest possible mid
            ↓
Answer
```

**Pattern:** Binary Search on Answer

**Brute Force:** `O(n × S)`

**Optimal:** `O(n × log S)`

**Space:** `O(1)`

---

# ✅ Final Takeaway

The real DSA pattern is:

```text
Optimization Problem
        ↓
Minimize Maximum
        ↓
Guess the answer
        ↓
Check feasibility
        ↓
Monotonic condition
        ↓
Binary Search on Answer
```

For Day88:

```text
Array
→ Split into at most k contiguous subarrays
→ Minimize largest subarray sum
→ Binary Search on Answer
```

**Pattern:** `Binary Search on Answer`

**Optimal Complexity:** `O(n × log S)` time, `O(1)` space.

---
