# Frequency Counting using Array Hashing

## 📌 Problem Statement

Given an array `arr` of size `n` and another array `queries` of size `q`, determine how many times each query element appears in the array.

Return the frequency of every query in the same order as the queries.

> **Note:**
>
> - If a query element does not exist in the array, its frequency is `0`.
> - Solve the problem using **Array Hashing (Frequency Array)**.

---

## 📝 Example

### Input

```text
n = 5

arr = [1, 2, 1, 3, 2]

q = 5

queries = [1, 3, 4, 2, 10]
```

### Output

```text
[2, 1, 0, 2, 0]
```

### Explanation

| Query | Frequency |
|------:|:---------:|
| 1 | 2 |
| 3 | 1 |
| 4 | 0 |
| 2 | 2 |
| 10 | 0 |

---

## 💡 Approach

Instead of scanning the array for every query:

1. Find the maximum element.
2. Create a frequency array of size `maxElement + 1`.
3. Store the frequency of every number.
4. Answer each query directly using the frequency array.

---

## 🧠 Dry Run

### Array

```text
[1,2,1,3,2]
```

Maximum Element

```text
3
```

Frequency Array

```text
Index : 0 1 2 3

Value : 0 2 2 1
```

Queries

```text
1 → hash[1] = 2

3 → hash[3] = 1

4 → Out of Range → 0

2 → hash[2] = 2

10 → Out of Range → 0
```

Final Answer

```text
[2,1,0,2,0]
```

---

## 📊 Complexity Analysis

| Metric | Complexity |
|:-------|:----------:|
| **Time Complexity** | **O(N + Q)** |
| **Space Complexity** | **O(Max Element)** |

---

## 🚀 Optimization

Compared to brute force:

```text
Brute Force

O(Q × N)
```

↓

```text
Array Hashing

O(N + Q)
```

---

## 🎯 Concepts Practiced

- Hashing
- Frequency Array
- Preprocessing
- Time Optimization
- Space-Time Tradeoff

---

## 📚 What I Learned

- How a frequency array stores occurrences of every number.
- Why preprocessing avoids repeated traversals.
- How direct indexing gives constant-time lookup.
- Why array hashing is extremely fast for small ranges.

---

## 💡 Interview Takeaways

Array hashing is the fastest hashing technique when the values are within a small known range.

> **Key Insight:** Array hashing provides constant-time lookup using array indices but requires extra memory proportional to the maximum element.