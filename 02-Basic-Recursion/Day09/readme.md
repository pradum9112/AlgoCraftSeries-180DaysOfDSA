# Reverse an Array using Recursion

## 📌 Problem Statement

Given an array `arr` containing `n` elements, reverse the array **in-place** using **recursion**.

> **Note:**
>
> - The array should be reversed without using any extra array.
> - The reversal must be performed by modifying the original array.

---

## 📝 Example

**Input**

```text
n = 5
arr = [1, 2, 3, 4, 5]
```

**Output**

```text
[5, 4, 3, 2, 1]
```

**Explanation**

The reverse of the array `[1, 2, 3, 4, 5]` is `[5, 4, 3, 2, 1]`.

---

## 💡 Approach

The idea is to recursively swap the elements from both ends of the array.

### Steps

1. Initialize two pointers:
   - `left = 0`
   - `right = n - 1`
2. Swap the elements at the `left` and `right` indices.
3. Move both pointers towards the center:
   - `left++`
   - `right--`
4. Recursively repeat the same process.
5. Stop when `left >= right`.

This works because after each swap, the remaining unsolved part of the array becomes smaller, making it an ideal recursion problem.

---

## 🧠 Dry Run

### Input

```text
arr = [1, 2, 3, 4, 5]
```

### Initial State

```text
Left = 0
Right = 4

1 2 3 4 5
↑       ↑
```

### Step 1

Swap first and last elements.

```text
5 2 3 4 1
  ↑   ↑
```

Recursive Call

```text
left = 1
right = 3
```

---

### Step 2

Swap second and second-last elements.

```text
5 4 3 2 1
    ↑
```

Recursive Call

```text
left = 2
right = 2
```

---

### Step 3

Now,

```text
left == right
```

The array is completely reversed.

Recursion stops.

---

## 🚀 Optimization

Instead of creating another array, the elements are swapped directly inside the original array.

This makes the solution **in-place**, requiring no additional array.

---

## ⏱️ Time Complexity

```text
O(n)
```

### Why?

Although the recursion makes only `n/2` recursive calls, each call performs a constant-time swap.

Ignoring constants:

```text
O(n/2)
↓

O(n)
```

---

## 💾 Space Complexity

```text
O(n)
```

### Why?

The recursive calls are stored in the call stack.

Maximum recursion depth:

```text
n/2
```

Ignoring constants:

```text
O(n)
```

---

## 🎯 Concepts Practiced

- Recursion
- Two Pointers
- In-place Array Manipulation
- Base Case
- Recursive Function Calls
- Time Complexity Analysis
- Space Complexity Analysis

---

## 📚 What I Learned

- Recursion can repeatedly solve a smaller version of the same problem.
- Two pointers help swap elements from both ends efficiently.
- The recursion stops when the pointers meet or cross each other.
- In-place algorithms save memory by modifying the original array.
- Even though only `n/2` swaps are performed, the time complexity is still written as **O(n)** because constant factors are ignored in Big-O notation.

---

## 💡 Interview Takeaways

Before solving any recursion problem, always ask yourself:

- What is the **Base Case**?
- What is the **smaller subproblem**?
- Which part of the array is already solved?
- What remains to be solved recursively?

> **Key Insight:** After swapping the first and last elements, the remaining middle portion of the array is the exact same problem on a smaller scale. This is why recursion is a natural fit for reversing an array.