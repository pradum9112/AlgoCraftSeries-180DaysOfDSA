# Fibonacci Number using Recursion

## 📌 Problem Statement

The Fibonacci sequence is defined as:

```text
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2), for n > 1
```

Given an integer `n`, return the **nth Fibonacci number** using **recursion**.

> **Note:**
>
> - The first two Fibonacci numbers are fixed: `0` and `1`.
> - Every subsequent Fibonacci number is obtained by adding the previous two Fibonacci numbers.

---

## 📝 Example

**Input**

```text
n = 2
```

**Output**

```text
1
```

**Explanation**

```text
F(2) = F(1) + F(0)
     = 1 + 0
     = 1
```

---

## 💡 Approach

The Fibonacci sequence naturally follows a recursive pattern.

### Steps

1. If `n == 0`, return `0`.
2. If `n == 1`, return `1`.
3. Otherwise, recursively calculate:
   - `F(n-1)`
   - `F(n-2)`
4. Return the sum of these two values.

The problem keeps breaking into two smaller Fibonacci problems until it reaches the base cases.

---

## 🧠 Dry Run

### Input

```text
n = 5
```

### Recursive Calls

```text
fib(5)
│
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1) = 1
│   │   │   └── fib(0) = 0
│   │   └── fib(1) = 1
│   └── fib(2)
│       ├── fib(1) = 1
│       └── fib(0) = 0
│
└── fib(3)
    ├── fib(2)
    │   ├── fib(1) = 1
    │   └── fib(0) = 0
    └── fib(1) = 1
```

Now calculate from bottom to top:

```text
fib(2) = 1 + 0 = 1

fib(3) = 1 + 1 = 2

fib(4) = 2 + 1 = 3

fib(5) = 3 + 2 = 5
```

Final Answer

```text
5
```

---

## 🚀 Optimization

The basic recursive solution repeatedly calculates the same Fibonacci numbers.

Example:

```text
fib(5)

↓

fib(3) is calculated multiple times.

fib(2) is calculated multiple times.
```

This leads to unnecessary computations.

A better approach is:

- **Memoization (Top-Down DP)** → Store previously computed Fibonacci values.
- **Tabulation (Bottom-Up DP)** → Build the answer iteratively.
- **Space Optimized DP** → Keep only the last two Fibonacci numbers.

These optimized methods reduce the time complexity from **O(2ⁿ)** to **O(n)**.

---

## ⏱️ Time Complexity

```text
O(2ⁿ)
```

### Why?

Each function call makes **two recursive calls**.

```text
fib(n)

↓

fib(n-1)
fib(n-2)
```

The recursion tree grows exponentially, causing many repeated calculations.

---

## 💾 Space Complexity

```text
O(n)
```

### Why?

The maximum recursion depth is `n`, so the recursive call stack stores up to `n` function calls at a time.

---

## 🎯 Concepts Practiced

- Recursion
- Multiple Recursive Calls
- Base Case
- Recursion Tree
- Mathematical Recurrence Relation
- Time Complexity Analysis
- Space Complexity Analysis

---

## 📚 What I Learned

- Fibonacci is one of the best examples to understand **multiple recursion**.
- Every recursive call solves a smaller version of the original problem.
- Base cases prevent infinite recursion.
- Recursive solutions can be elegant but inefficient due to repeated computations.
- Dynamic Programming is introduced to eliminate these repeated calculations.
- Recursive depth contributes to the auxiliary space complexity.

---

## 💡 Interview Takeaways

Before solving any recursive problem, ask yourself:

- What are the **base cases**?
- How can the problem be divided into smaller subproblems?
- Is the same subproblem being solved multiple times?
- Can the recursive solution be optimized using **Dynamic Programming**?

> **Key Insight:** Fibonacci demonstrates why recursion alone is not always efficient. Although the recursive solution is simple and intuitive, it performs many repeated calculations. Recognizing these overlapping subproblems is the foundation of **Dynamic Programming**, one of the most important topics in coding interviews.