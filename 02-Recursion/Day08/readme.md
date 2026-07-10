# Day 08 – Introduction to Recursion

Welcome to **Day 08** of the **AlgoCraftSeries – 180 Days of DSA** journey.

Today's focus was understanding the fundamentals of **Recursion**. Instead of jumping into difficult recursive problems, the goal was to build intuition about how recursive calls work, how the call stack behaves, and how the position of the recursive call changes the output.

---

# 📚 Problems Solved

| Problem | Difficulty |
| :------ | :--------: |
| Print 1 to N using Recursion | 🟢 Easy |
| Print N to 1 using Recursion | 🟢 Easy |
| Factorial of a Given Number | 🟢 Easy |

---

# 📌 Problem 1 – Print 1 to N using Recursion

## Problem Statement

Given an integer `n`, print all numbers from **1** to **n** using recursion.

> **Constraints**
>
> - Do not use loops.
> - Print each number on a separate line.

### Example

**Input**

```text
n = 5
```

**Output**

```text
1
2
3
4
5
```

---

## 💡 Approach

- Stop recursion when `n` becomes `0`.
- First solve the smaller problem by calling the function with `n - 1`.
- Print the current number while returning from recursion.

---

## 🧠 Dry Run

Input

```text
n = 3
```

Recursive Calls

```text
print(3)
↓
print(2)
↓
print(1)
↓
print(0)
↓
Base Case
```

Returning Phase

```text
Print 1
↑
Print 2
↑
Print 3
```

---

## ⏱ Time Complexity

```text
O(n)
```

---

## 💾 Space Complexity

```text
O(n)
```

---

# 📌 Problem 2 – Print N to 1 using Recursion

## Problem Statement

Given an integer `n`, print all numbers from **n** to **1** using recursion.

> **Constraints**
>
> - Do not use loops.
> - Print one number per line.

### Example

**Input**

```text
n = 5
```

**Output**

```text
5
4
3
2
1
```

---

## 💡 Approach

- Stop recursion when `n` becomes `0`.
- Print the current number first.
- Then recursively call the function with `n - 1`.

---

## 🧠 Dry Run

Input

```text
n = 3
```

Execution

```text
Print 3
↓
Print 2
↓
Print 1
↓
Base Case
```

---

## ⏱ Time Complexity

```text
O(n)
```

---

## 💾 Space Complexity

```text
O(n)
```

---

# 📌 Problem 3 – Factorial of a Given Number

## Problem Statement

Given an integer `n`, return the value of **n! (Factorial)**.

The factorial of a number is the product of all positive integers less than or equal to the number.

### Example

**Input**

```text
n = 4
```

**Output**

```text
24
```

**Explanation**

```text
4! = 4 × 3 × 2 × 1 = 24
```

---

## 💡 Approach

- Stop recursion when `n` becomes `0`.
- Assume the factorial of `n - 1` is already known.
- Multiply the current number `n` with the result returned by the recursive call.

---

## 🧠 Dry Run

Input

```text
n = 4
```

Recursive Calls

```text
factorial(4)
↓
4 × factorial(3)
↓
4 × (3 × factorial(2))
↓
4 × (3 × (2 × factorial(1)))
↓
4 × (3 × (2 × (1 × factorial(0))))
↓
Base Case → return 1
```

Returning Phase

```text
1
↑
1 × 1 = 1
↑
2 × 1 = 2
↑
3 × 2 = 6
↑
4 × 6 = 24
```

---

## ⏱ Time Complexity

```text
O(n)
```

---

## 💾 Space Complexity

```text
O(n)
```

---

# 🎯 Concepts Practiced

- Introduction to Recursion
- Base Case
- Recursive Calls
- Function Call Stack
- Returning Phase
- Backtracking
- Mathematical Recursion
- Time Complexity Analysis
- Space Complexity Analysis

---

# 📚 What I Learned

- Every recursive function must have a **Base Case** to avoid infinite recursion.
- Every recursive call creates a **new stack frame** in memory.
- Printing **before** the recursive call produces **N → 1**.
- Printing **after** the recursive call produces **1 → N**.
- Recursive functions solve a problem by reducing it into smaller subproblems.
- The **return value** from one recursive call is used to compute the answer for the current function.
- Recursion uses **O(n)** auxiliary space because each recursive call is stored on the call stack.
- Understanding recursion is the foundation for solving advanced topics like **Backtracking**, **Binary Trees**, **Graphs**, and **Dynamic Programming**.

---

# 💡 Interview Takeaways

Before solving any recursion problem, always ask yourself:

1. What is the **Base Case**?
2. What is the **smaller subproblem**?
3. What should happen **before** the recursive call?
4. What should happen **after** the recursive call?
5. What value should the function **return**?

> **Golden Rule:** Never memorize recursion. Instead, trust that the recursive call solves the smaller problem, and focus only on how to use its result to solve the current problem.