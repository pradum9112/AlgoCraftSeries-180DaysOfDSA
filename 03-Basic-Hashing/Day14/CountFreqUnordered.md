# Count Frequency of Each Element (Using unordered_map)

## 📌 Problem Statement

Given an integer array `nums`, count the frequency of every distinct element and return each unique element along with its frequency.

The solution should efficiently count occurrences using **Hashing (`unordered_map`)**.

> **Note:** The order of elements in the output may vary because `unordered_map` does **not** maintain insertion order.

---

## 📝 Example

**Input**

```text
nums = [2, 3, 5, 6, 2, 6]
```

**Possible Output**

```text
2 2
3 1
5 1
6 2
```

Another valid output could be

```text
6 2
2 2
5 1
3 1
```

Both outputs are correct because `unordered_map` stores keys in no particular order.

---

## 💡 Approach (Hashing using unordered_map)

Instead of comparing every element with the remaining elements, use a hash table to store the frequency of each number.

### Steps

1. Create an empty `unordered_map`.
2. Traverse the array once.
3. Increase the frequency of the current element in the map.
4. Traverse the map and store each `(element, frequency)` pair in the answer.
5. Return the final result.

Since each element is processed only once, this approach is much faster than the brute-force solution.

---

## 🧠 Dry Run

### Input

```text
nums = [2, 3, 5, 6, 2, 6]
```

Initially

```text
Map = { }
```

---

Read **2**

```text
{
2 → 1
}
```

---

Read **3**

```text
{
2 → 1
3 → 1
}
```

---

Read **5**

```text
{
2 → 1
3 → 1
5 → 1
}
```

---

Read **6**

```text
{
2 → 1
3 → 1
5 → 1
6 → 1
}
```

---

Read **2**

```text
{
2 → 2
3 → 1
5 → 1
6 → 1
}
```

---

Read **6**

```text
{
2 → 2
3 → 1
5 → 1
6 → 2
}
```

---

Final Frequency Table

```text
2 → 2

3 → 1

5 → 1

6 → 2
```

---

## 📊 Complexity Analysis

| Metric | Complexity |
|:------|:----------:|
| **Average Time Complexity** | **O(N)** |
| **Worst Case Time Complexity** | **O(N²)** |
| **Space Complexity** | **O(N)** |

---

## ⏱️ Why is the Average Time Complexity O(N)?

The algorithm performs two traversals.

### Step 1

Traverse the array once.

```text
O(N)
```

### Step 2

Traverse all unique elements stored in the hash map.

```text
O(U)

where U ≤ N
```

Overall

```text
O(N)
```

---

## 🚀 Optimization

Compared to the brute-force solution:

### Brute Force

```text
Nested Loops

↓

O(N²)
```

### unordered_map

```text
Hash Table

↓

O(N)
```

The improvement comes from replacing repeated comparisons with direct key lookups.

---

## ⚖️ Brute Force vs unordered_map

| Approach | Time | Space |
|:---------|:----:|:-----:|
| Brute Force + Visited Array | O(N²) | O(N) |
| Hashing (`unordered_map`) | O(N) Average | O(N) |

---

## 🎯 Concepts Practiced

- Hashing
- unordered_map
- Frequency Counting
- Key-Value Pairs
- Fast Lookup
- Time Complexity Optimization

---

## 📚 What I Learned

- How `unordered_map` stores data as **key-value pairs**.
- How hashing avoids repeated traversals of the array.
- Why frequency counting becomes much faster using hashing.
- The difference between average-case and worst-case complexity.
- Why `unordered_map` is one of the most commonly used STL containers in coding interviews.

---

## ⚠️ Important Note

`unordered_map` **does not preserve the insertion order** of elements.

Therefore, the frequency pairs may appear in a different order each time the program runs.

If maintaining the original order is important, additional techniques such as a separate traversal or an ordered container may be required.

---

## 💡 Interview Takeaways

Before solving a frequency-counting problem, ask yourself:

- Can hashing replace nested loops?
- Is the order of output important?
- Should I use `unordered_map` or `map`?
- Is average **O(1)** lookup sufficient for this problem?

> **Key Insight:** `unordered_map` is one of the most powerful STL containers for frequency-counting problems because it stores frequencies in a hash table, allowing average **O(1)** insertion and lookup, reducing the overall complexity from **O(N²)** to **O(N)**.