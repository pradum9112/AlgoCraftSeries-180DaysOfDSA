# 📘 Day 32 - Find Maximum Consecutive Ones

## 🔹 Problem Statement

Given a binary array `nums` containing only **0s** and **1s**, return the maximum number of consecutive `1`s present in the array.

### Example

**Input**

```
nums = [1,1,0,1,1,1]
```

**Output**

```
3
```

**Explanation**

The longest consecutive sequence of `1`s is:

```
1 1 1
```

So, the answer is **3**.

---

# 💡 Approach

We traverse the array only once.

- If the current element is `1`
  - Increase the current count.
  - Update the maximum count.
- If the current element is `0`
  - Reset the current count to `0`.

At the end of the traversal, `max_count` stores the answer.

---

# 📝 Dry Run

### Input

```
nums = [1,1,0,1,1,1,0,1]
```

Initial values

```
count = 0
max_count = 0
```

---

### i = 0

```
nums[0] = 1
```

Increase count

```
count = 1
max_count = max(0,1) = 1
```

---

### i = 1

```
nums[1] = 1
```

Increase count

```
count = 2
max_count = max(1,2) = 2
```

---

### i = 2

```
nums[2] = 0
```

Sequence breaks.

Reset count.

```
count = 0
max_count = 2
```

---

### i = 3

```
nums[3] = 1
```

```
count = 1
max_count = 2
```

---

### i = 4

```
nums[4] = 1
```

```
count = 2
max_count = 2
```

---

### i = 5

```
nums[5] = 1
```

```
count = 3
max_count = 3
```

---

### i = 6

```
nums[6] = 0
```

Reset count

```
count = 0
max_count = 3
```

---

### i = 7

```
nums[7] = 1
```

```
count = 1
max_count = 3
```

---

## ✅ Final Answer

```
Maximum Consecutive Ones = 3
```

---

# 🎯 Why does this algorithm work?

The variable `count` always stores the length of the **current consecutive sequence of 1s**.

Whenever we encounter:

- `1` → extend the current sequence.
- `0` → the sequence breaks, so start counting again.

`max_count` keeps track of the longest sequence seen so far.

---

# ⏱️ Time Complexity

We visit every element exactly **once**.

```
Time Complexity = O(n)
```

where **n** is the size of the array.

---

# 📦 Space Complexity

Only two integer variables are used.

```
Space Complexity = O(1)
```

---

# 📚 Learning

### ✔ Pattern Used

- Linear Traversal
- Running Count
- Sliding Count Technique

### ✔ Why O(n)?

Each element is processed only once.

### ✔ Can it be optimized further?

**No.**

To know the maximum consecutive `1`s, every element must be inspected at least once.

Therefore,

```
Best Possible Time Complexity = O(n)
```

This solution is already **Optimal**.

---

# 🔑 Key Takeaways

- Count consecutive occurrences using a running counter.
- Reset the counter whenever the sequence breaks.
- Update the answer while traversing instead of making another pass.
- This pattern is frequently used in array and string problems involving consecutive elements.