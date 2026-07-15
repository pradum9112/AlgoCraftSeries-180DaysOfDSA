Perfect! Since this is your Day 12 – Hashing (Brute Force Frequency Counting), here's a professional README.md for your repository following the same style as previous days.

### 📘 README.md

### Day 12 – Frequency Counting (Brute Force using Nested Loops)

🟢 Easy

### 📌 Problem Statement

Given an array arr of size n and another array queries of size q, find how many times each query element appears in the array.

Return the frequency of every query in the same order as the queries.

### 📝 Example

Input

n = 5

arr = [1, 2, 1, 3, 2]

q = 5

queries = [1, 3, 4, 2, 10]

Output

[2, 1, 0, 2, 0]

Explanation

| Query | Frequency |
| ----- | --------- |
| 1     | 2         |
| 3     | 1         |
| 4     | 0         |
| 2     | 2         |
| 10    | 0         |

### 💡 Approach (Brute Force)

For every query element:

* Initialize a counter.

* Traverse the entire array.

* Increment the counter whenever the current array element matches the query.

* Store the final count.

This process is repeated for all queries.

### 🧠 Dry Run

Array

arr = [1, 2, 1, 3, 2]

### Query = 1

Count = 2

1 == 1

✓

2 == 1

✗

1 == 1

✓

3 == 1

✗

2 == 1

✗

### Query = 3

Count = 1

1 == 3

✗

2 == 3

✗

1 == 3

✗

3 == 3

✓

2 == 3

✗

### Query = 4

Count = 0

No element matches 4.

### 📊 Complexity Analysis

| Metric           | Complexity |
| ---------------- | ---------- |
| Time Complexity  | O(Q × N)   |
| Space Complexity | O(Q)       |

### ⏱️ Why Time Complexity is O(Q × N)?

* For each query, we traverse the entire array.

* If there are Q queries and the array size is N, total operations become Q × N.

Example

Operations

N = 5

Q = 3

15 operations

N = 100000

Q = 100000

10¹⁰ operations

Extremely slow

### 🚀 Optimization Insight

### Better Approach: Hashing

Instead of scanning the array for every query:

* Store frequencies once in a hash table.

* Answer each query in approximately O(1) time.

| Approach    | Complexity |
| ----------- | ---------- |
| Brute Force | O(Q × N)   |
| Hashing     | O(N + Q)   |

### 🎯 Concepts Practiced

* Nested Loops

* Frequency Counting

* Array Traversal

* Brute Force Technique

* Time Complexity Analysis

* Space Complexity Analysis

### 📚 What I Learned

* How to count the frequency of elements manually.

* How nested loops increase time complexity.

* Why repeated scanning of an array becomes inefficient for large inputs.

* The importance of preprocessing data.

* How hashing can optimize frequency-counting problems.

### 💡 Interview Takeaways

Before solving a frequency problem, ask yourself:

* Will the array be queried multiple times?

* Am I repeating the same traversal again and again?

* Can I preprocess the frequencies once?

Key Insight: Brute force frequency counting is a good starting point, but for large inputs, hashing is the preferred interview solution because it reduces the complexity from O(Q × N) to O(N + Q).
