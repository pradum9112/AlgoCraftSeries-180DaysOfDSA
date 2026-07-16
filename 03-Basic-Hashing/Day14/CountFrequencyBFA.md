# Count Frequency of Each Element (Brute Force)

## 📌 Problem Statement

Given an integer array `nums`, count the frequency of every distinct element and return each element along with its frequency.

The output should contain each unique element only once, in the order of its first appearance.

---

## 📝 Example

**Input**

```text
nums = [2, 3, 5, 6, 2, 6]
```

**Output**

```text
2 2
3 1
5 1
6 2
```

**Explanation**

| Element | Frequency |
|:-------:|:---------:|
| 2 | 2 |
| 3 | 1 |
| 5 | 1 |
| 6 | 2 |

---

## 💡 Approach (Brute Force + Visited Array)

The idea is to avoid counting the frequency of the same element multiple times.

### Steps

1. Create a `visited` array initialized with `false`.
2. Traverse the array from left to right.
3. If the current element is already marked as visited, skip it.
4. Otherwise:
   - Initialize the frequency as `1`.
   - Traverse the remaining elements.
   - Whenever the same element is found:
     - Increase the frequency.
     - Mark that duplicate index as visited.
5. Store the element along with its frequency.
6. Continue until all elements are processed.

---

## 🧠 Dry Run

### Input

```text
nums = [2, 3, 5, 6, 2, 6]
```

Initially

```text
Visited

F F F F F F
```

---

### Step 1

Current Element = 2

Check remaining elements

```text
2 ✓
```

Frequency = 2

Visited

```text
F F F F T F
```

Store

```text
(2, 2)
```

---

### Step 2

Current Element = 3

No duplicate found.

Store

```text
(3, 1)
```

---

### Step 3

Current Element = 5

No duplicate found.

Store

```text
(5, 1)
```

---

### Step 4

Current Element = 6

Duplicate found at last index.

Visited

```text
F F F F T T
```

Store

```text
(6, 2)
```

---

### Step 5

Current index already visited.

Skip.

---

### Final Output

```text
2 2

3 1

5 1

6 2
```

---

## 📊 Complexity Analysis

| Metric | Complexity |
|:------|:----------:|
| **Time Complexity** | **O(N²)** |
| **Space Complexity** | **O(N)** |

---

## ⏱️ Why Time Complexity is O(N²)?

For every unvisited element, we scan the remaining part of the array to count its frequency.

```text
Outer Loop

↓

Inner Loop

↓

O(N × N)

↓

O(N²)
```

---

## 🚀 Optimization

Instead of comparing every element with all remaining elements, we can use **Hashing**.

### Better Approach

Store the frequency of each element in a hash table (`unordered_map`) while traversing the array only once.

Time Complexity becomes

```text
O(N)
```

---

## ⚖️ Brute Force vs Hashing

| Approach | Time | Space |
|:---------|:----:|:-----:|
| Brute Force + Visited Array | O(N²) | O(N) |
| Hashing (`unordered_map`) | O(N) | O(N) |

---

## 🎯 Concepts Practiced

- Nested Loops
- Visited Array
- Frequency Counting
- Duplicate Handling
- Brute Force Technique
- Time Complexity Analysis

---

## 📚 What I Learned

- How to count the frequency of distinct elements using a visited array.
- Why duplicate indices should be marked as visited.
- The importance of skipping already processed elements.
- How brute-force solutions work before learning optimized approaches.
- The difference between brute-force frequency counting and hashing.

---

## 💡 Interview Takeaways

Before solving a frequency-counting problem, ask yourself:

- Can I avoid processing the same element multiple times?
- Is a visited array sufficient?
- Can hashing reduce the time complexity?

> **Key Insight:** The visited-array approach is an excellent way to understand frequency counting, but for large inputs, hashing (`unordered_map`) is the preferred solution because it reduces the complexity from **O(N²)** to **O(N)**.