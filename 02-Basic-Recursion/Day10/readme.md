# Check if a String is Palindrome using Recursion

## 📌 Problem Statement

Given a string `s`, determine whether it is a **palindrome** or not using **recursion**.

Return `true` if the string is a palindrome; otherwise, return `false`.

> **Note:**
>
> - A palindrome reads the same from left to right and right to left.
> - Comparison is case-sensitive unless specified otherwise.

---

## 📝 Example

**Input**

```text
s = "hannah"
```

**Output**

```text
true
```

**Explanation**

The reverse of `"hannah"` is `"hannah"`, which is identical to the original string. Therefore, it is a palindrome.

---

## 💡 Approach

The idea is to compare the characters from both ends of the string recursively.

### Steps

1. Initialize two pointers:
   - `start = 0`
   - `end = s.length() - 1`
2. Compare the characters at `start` and `end`.
3. If they are different, return `false`.
4. If they are the same, recursively check the remaining substring:
   - `start++`
   - `end--`
5. Stop when `start >= end`. At this point, every character has been matched successfully, so return `true`.

---

## 🧠 Dry Run

### Input

```text
s = "hannah"
```

### Initial State

```text
Index : 0 1 2 3 4 5
String: h a n n a h
        ↑         ↑
      start      end
```

### Step 1

Compare

```text
h == h ✓
```

Recursive Call

```text
start = 1
end = 4
```

---

### Step 2

Compare

```text
a == a ✓
```

Recursive Call

```text
start = 2
end = 3
```

---

### Step 3

Compare

```text
n == n ✓
```

Recursive Call

```text
start = 3
end = 2
```

---

### Step 4

Now,

```text
start >= end
```

Base case is reached.

Return

```text
true
```

The recursion unwinds, returning `true` from every previous call.

---

## 🚀 Optimization

Instead of creating a reversed copy of the string, compare characters directly from both ends.

This approach:

- Uses no extra string.
- Stops immediately when a mismatch is found.
- Performs only the necessary comparisons.

---

## ⏱️ Time Complexity

```text
O(n)
```

### Why?

Only half of the string is compared.

```text
Number of comparisons = n / 2
```

Ignoring constant factors,

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

Recursive function calls are stored in the call stack.

Maximum recursion depth:

```text
n / 2
```

Ignoring constants,

```text
O(n)
```

---

## 🎯 Concepts Practiced

- Recursion
- Two Pointers
- String Manipulation
- Base Case
- Recursive Function Calls
- Time Complexity Analysis
- Space Complexity Analysis

---

## 📚 What I Learned

- A palindrome can be checked by comparing characters from both ends.
- Recursion naturally solves the problem by reducing it to a smaller substring.
- The base case is reached when the pointers meet or cross.
- Returning `false` immediately on the first mismatch improves efficiency.
- Although only `n/2` comparisons are performed, the time complexity is still **O(n)** because constant factors are ignored in Big-O notation.

---

## 💡 Interview Takeaways

Before solving any recursion problem, ask yourself:

- What is the **Base Case**?
- What is the **smaller subproblem**?
- When should the recursion stop?
- Can I terminate early if I already know the answer?

> **Key Insight:** After verifying the first and last characters are equal, the remaining problem is simply checking whether the substring between them is also a palindrome. This smaller problem has the same structure as the original one, making recursion an ideal approach.