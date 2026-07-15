# Frequency Counting using unordered_map

## 📌 Problem Statement

Given an array `arr` of size `n` and another array `queries` of size `q`, determine the frequency of every query element.

Solve the problem efficiently using **unordered_map**.

---

## 📝 Example

**Input**

```text
n = 5

arr = [1, 2, 1, 3, 2]

q = 5

queries = [1, 3, 4, 2, 10]
```

**Output**

```text
[2, 1, 0, 2, 0]
```

---

## 💡 Approach

Instead of creating a frequency array, use an **unordered_map** to store the frequency of each element.

### Steps

1. Create an empty unordered_map.
2. Traverse the array once.
3. Increment the frequency of every element.
4. For each query:
   - If the key exists in the map, return its frequency.
   - Otherwise return `0`.

---

## 🧠 Dry Run

### Input

```text
arr = [1,2,1,3,2]
```

Build Hash Map

```text
1 → 2

2 → 2

3 → 1
```

Queries

```text
1 → 2

3 → 1

4 → Not Found → 0

2 → 2

10 → Not Found → 0
```

Output

```text
[2,1,0,2,0]
```

---

## 📊 Complexity Analysis

| Metric | Complexity |
|:------|:----------:|
| Average Time Complexity | **O(N + Q)** |
| Worst Case Time Complexity | **O(N × Q)** |
| Space Complexity | **O(N)** |

---

## 🚀 Optimization

Unlike Array Hashing, `unordered_map` does **not** require knowing the maximum element beforehand.

It also supports:

- Large numbers
- Negative numbers
- Sparse values

without wasting memory.

---

## ⚖️ Array Hashing vs unordered_map

| Feature | Array Hashing | unordered_map |
|:--------|:-------------:|:-------------:|
| Lookup | O(1) | O(1) Average |
| Supports Negative Numbers | ❌ | ✅ |
| Supports Large Values | ❌ | ✅ |
| Extra Memory | Depends on Maximum Element | Depends on Number of Unique Elements |
| Best For | Small Range Values | Large or Unknown Range Values |

---

## 🎯 Concepts Practiced

- Hashing
- unordered_map
- Frequency Counting
- Key-Value Storage
- Fast Lookup
- Space-Time Tradeoff

---

## 📚 What I Learned

- How unordered_map stores frequencies using key-value pairs.
- Why unordered_map is more flexible than Array Hashing.
- The difference between average-case and worst-case complexity.
- When to prefer unordered_map over a frequency array.

---

## 💡 Interview Takeaways

**Use unordered_map when:**

- Values are very large.
- Values can be negative.
- The maximum element is unknown.
- Memory optimization is important.

> **Key Insight:** `unordered_map` is the most commonly used hashing data structure in coding interviews because it provides fast average-case lookups while supporting almost any integer range.