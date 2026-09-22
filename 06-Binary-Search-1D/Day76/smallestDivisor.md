# Day 76 — Find the Smallest Divisor

## 📌 Problem

Given an array `nums` and an integer `limit`, find the **smallest positive divisor** such that the sum of the ceiling divisions of every element is less than or equal to `limit`.

For a divisor `d`:

```text
ceil(nums[i] / d)
```

must be calculated for every element.

We need the smallest `d` satisfying:

```text
sum <= limit
```

### Example

**Input**

```text
nums = [1, 2, 5, 9]
limit = 6
```

Try divisor `5`:

```text
ceil(1/5) = 1
ceil(2/5) = 1
ceil(5/5) = 1
ceil(9/5) = 2
```

Sum:

```text
1 + 1 + 1 + 2 = 5
```

Since:

```text
5 <= 6
```

divisor `5` is valid.

The smallest valid divisor is:

```text
5
```

---

# 🔹 Approach 1 — Brute Force

## 💡 Idea

The smallest possible divisor is `1`.

The largest useful divisor is:

```text
max(nums)
```

because once the divisor reaches the maximum element, every element contributes at most `1`.

So we try every divisor:

```text
1, 2, 3, ..., max(nums)
```

For each divisor, calculate the total sum.

The **first divisor whose sum is <= limit** is the answer.

---

## 🧠 Pattern Recognition Clue

Whenever you see:

> Find the **smallest value** that satisfies a condition.

Ask:

1. What is the possible answer range?
2. Can I check whether a candidate is valid?
3. If I increase the candidate, does the condition become easier or harder?

Here:

```text
Small divisor
     ↓
larger division result
     ↓
larger total sum
```

As the divisor increases:

```text
total sum decreases or stays the same
```

So there is a monotonic pattern.

The brute-force solution helps us discover this pattern.

---

## 🔄 Dry Run

For:

```text
nums = [1, 2, 5, 9]
limit = 6
```

### Divisor = 1

```text
1 + 2 + 5 + 9 = 17
```

```text
17 > 6
```

Invalid.

### Divisor = 2

```text
ceil(1/2) = 1
ceil(2/2) = 1
ceil(5/2) = 3
ceil(9/2) = 5
```

Sum:

```text
10
```

Invalid.

### Divisor = 3

```text
1 + 1 + 2 + 3 = 7
```

Invalid.

### Divisor = 4

```text
1 + 1 + 2 + 3 = 7
```

Invalid.

### Divisor = 5

```text
1 + 1 + 1 + 2 = 5
```

Valid.

Therefore:

```text
Answer = 5
```

Because we check divisors from smallest to largest, the first valid divisor is automatically the smallest one.

---

## ⏱️ Time Complexity

Let:

```text
N = nums.size()
M = max(nums)
```

For each of the `M` possible divisors, we scan all `N` elements.

**Time:** `O(N × M)`

**Space:** `O(1)`

---

# 🔹 Approach 2 — Binary Search

## 💡 Observation

The brute-force solution checks every divisor.

But notice the important property:

```text
divisor increases
       ↓
ceil(nums[i] / divisor) decreases or stays same
       ↓
total sum decreases or stays same
```

Therefore, the condition is monotonic.

For example:

```text
Divisor:  1   2   3   4   5   6   7 ...
Sum:     17  10   7   7   5   5   5 ...
Valid:    ❌  ❌  ❌  ❌  ✅  ✅  ✅ ...
```

Once a divisor becomes valid, every larger divisor will also remain valid.

So we can Binary Search for the **first valid divisor**.

---

## 🧠 Pattern Recognition Clue

This is the main pattern of Day76:

```text
Find the smallest value
        +
Can check whether a value is valid
        +
Validity is monotonic
        ↓
Binary Search on Answer
```

Ask yourself:

> **"If this candidate works, will every larger candidate also work?"**

Here:

```text
d works
↓
larger divisor
↓
smaller/equal sum
↓
still works
```

Therefore, we need the **first `true`** position.

Think:

```text
FALSE FALSE FALSE FALSE TRUE TRUE TRUE
                         ↑
                    answer
```

This is a very important Binary Search pattern.

---

## 🔄 Dry Run

Consider:

```text
nums = [1, 2, 5, 9]
limit = 6
```

Search range:

```text
low = 1
high = 9
```

### Step 1

```text
mid = 5
```

Sum:

```text
1 + 1 + 1 + 2 = 5
```

Since:

```text
5 <= 6
```

`5` is valid.

But we need the **smallest** valid divisor.

So search left:

```text
high = 4
```

---

### Step 2

```text
low = 1
high = 4

mid = 2
```

Sum:

```text
1 + 1 + 3 + 5 = 10
```

Invalid.

So search right:

```text
low = 3
```

---

### Step 3

```text
low = 3
high = 4

mid = 3
```

Sum:

```text
1 + 1 + 2 + 3 = 7
```

Invalid.

Search right:

```text
low = 4
```

---

### Step 4

```text
low = 4
high = 4

mid = 4
```

Sum:

```text
1 + 1 + 2 + 3 = 7
```

Invalid.

So:

```text
low = 5
```

Now:

```text
low > high
```

The previously stored valid answer is:

```text
5
```

Therefore:

```text
Answer = 5
```

---

# 🔢 Calculating Ceiling Division

The solution calculates:

```text
ceil(num / divisor)
```

using:

```text
(num + divisor - 1) / divisor
```

For example:

```text
9 / 5
```

Normal integer division gives:

```text
1
```

but:

```text
ceil(9/5) = 2
```

Using the formula:

```text
(9 + 5 - 1) / 5
= 13 / 5
= 2
```

This avoids using floating-point arithmetic.

---

# ⚖️ Approach Comparison

| Feature        | Brute Force              | Binary Search           |
| -------------- | ------------------------ | ----------------------- |
| Search Method  | Check every divisor      | Binary Search           |
| Search Space   | `1 ... max(nums)`        | `1 ... max(nums)`       |
| Validity Check | Sum of ceiling divisions | Same                    |
| Time           | `O(N × M)`               | `O(N × log M)`          |
| Space          | `O(1)`                   | `O(1)`                  |
| Pattern        | Sequential checking      | Binary Search on Answer |
| Optimal        | ❌                        | ✅                       |

Where:

```text
N = number of elements
M = maximum element
```

The major optimization is:

```text
O(N × M)
      ↓
O(N × log M)
```

---

# 🚨 Edge Cases

### 1. Single Element

```text
nums = [10]
limit = 1
```

Answer:

```text
10
```

because:

```text
ceil(10 / 10) = 1
```

---

### 2. Large Limit

If the limit is large enough, a small divisor may already satisfy the condition.

---

### 3. Maximum Element as Answer

Sometimes the answer can be:

```text
max(nums)
```

especially when the limit is very small.

---

### 4. Duplicate Values

Duplicates don't change the Binary Search pattern.

Each occurrence contributes separately to the total sum.

---

# 🧩 Important Observations

### Observation 1

The answer lies in:

```text
1 ... max(nums)
```

### Observation 2

For a fixed divisor, we can calculate whether it is valid.

### Observation 3

Increasing the divisor never increases the total sum.

Therefore:

```text
FALSE → FALSE → FALSE → TRUE → TRUE → TRUE
```

### Observation 4

We need the **smallest valid divisor**, so Binary Search should continue searching left after finding a valid candidate.

---

# 🧠 What I Learned

* How to convert a brute-force search into Binary Search on Answer.
* How to identify a monotonic validity condition.
* How to find the **first valid value** using Binary Search.
* How ceiling division can be calculated using integer arithmetic.
* The important relationship:

```text
Larger divisor
      ↓
Smaller/equal quotient
      ↓
Smaller/equal sum
```

* The key pattern is:

```text
Find minimum valid answer + monotonic condition
                    ↓
          Binary Search on Answer
```

---

# 🎯 Revision Shortcut

Remember this mental model:

```text
Need smallest divisor
        ↓
Answer range = 1 ... max(nums)
        ↓
Can check sum for any divisor
        ↓
Divisor ↑ → Sum ↓
        ↓
Monotonic
        ↓
FALSE FALSE FALSE TRUE TRUE TRUE
                    ↑
                 Answer
        ↓
Binary Search for first TRUE
```

**Pattern:** Binary Search on Answer

**Brute Force:** `O(N × M)`

**Optimal:** `O(N × log M)`

**Space:** `O(1)`
