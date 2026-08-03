# Single Number (XOR Method)

## Problem Statement

Given an integer array `nums`, every element appears **exactly twice** except for **one element**, which appears only **once**.

Return that single element.

### Example

**Input**

```text
nums = [4, 1, 2, 1, 2]
```

**Output**

```text
4
```

---

# Approach (Bit Manipulation - XOR)

Instead of storing frequencies, we can use the **XOR (^)** operator.

The XOR operator has some special properties that make this problem very easy.

### XOR Properties

### 1.

```text
A ^ A = 0
```

Example

```text
5 ^ 5 = 0
```

Duplicate numbers cancel each other.

---

### 2.

```text
A ^ 0 = A
```

Example

```text
7 ^ 0 = 7
```

XOR with zero does not change the number.

---

### 3. Commutative Property

```text
A ^ B = B ^ A
```

Order does not matter.

---

### 4. Associative Property

```text
(A ^ B) ^ C = A ^ (B ^ C)
```

Grouping does not matter.

Because of Property 3 and Property 4, we can rearrange the entire expression in any order.

---

# Why Does XOR Work?

Suppose

```text
nums = [4, 1, 2, 1, 2]
```

We perform XOR on every element.

```text
4 ^ 1 ^ 2 ^ 1 ^ 2
```

Rearrange the expression.

```text
4 ^ (1 ^ 1) ^ (2 ^ 2)
```

Now apply XOR properties.

```text
1 ^ 1 = 0

2 ^ 2 = 0
```

So,

```text
4 ^ 0 ^ 0
```

Finally,

```text
4 ^ 0 = 4
```

Hence,

```text
Answer = 4
```

All duplicate numbers cancel each other automatically.

---

# Dry Run

Input

```text
nums = [4, 1, 2, 1, 2]
```

Initially

```text
ans = 0
```

---

### Step 1

Current Number

```text
4
```

Operation

```text
ans = 0 ^ 4
```

Result

```text
ans = 4
```

---

### Step 2

Current Number

```text
1
```

Operation

```text
ans = 4 ^ 1
```

Result

```text
ans = 5
```

---

### Step 3

Current Number

```text
2
```

Operation

```text
ans = 5 ^ 2
```

Result

```text
ans = 7
```

---

### Step 4

Current Number

```text
1
```

Operation

```text
ans = 7 ^ 1
```

Binary

```text
7 = 0111

1 = 0001

-----------
    0110
```

Result

```text
ans = 6
```

---

### Step 5

Current Number

```text
2
```

Operation

```text
ans = 6 ^ 2
```

Binary

```text
6 = 0110

2 = 0010

-----------
    0100
```

Result

```text
ans = 4
```

Loop finishes.

Final Answer

```text
4
```

---

# Algorithm

1. Initialize answer as **0**.
2. Traverse the array.
3. XOR every element with answer.
4. Duplicate numbers become **0**.
5. Only the unique element remains.
6. Return answer.

---

# Time Complexity

## Current Solution

```text
O(n)
```

Only one traversal of the array.

---

## Best Possible Time Complexity

```text
O(n)
```

Cannot be improved because every element must be visited at least once.

---

# Space Complexity

```text
O(1)
```

Only one integer variable is used.

No extra data structure is required.

---

# HashMap vs XOR

| HashMap               | XOR                        |
| --------------------- | -------------------------- |
| Stores frequencies    | Cancels duplicate elements |
| Extra memory required | No extra memory            |
| O(n) Space            | O(1) Space ✅               |
| Easy to understand    | Most optimal solution      |

---

# Key Learning

* XOR is one of the most important Bit Manipulation concepts.
* Duplicate numbers disappear because

```text
A ^ A = 0
```

* Zero never changes a number because

```text
A ^ 0 = A
```

* XOR is useful whenever the question says:

  * Every element appears twice except one.
  * Every element appears even number of times except one.
  * Missing Number
  * Bit Manipulation problems.

---

# Revision Notes

✅ Same numbers become **0**

```text
A ^ A = 0
```

✅ Zero keeps the number unchanged

```text
A ^ 0 = A
```

✅ Order does not matter

```text
A ^ B = B ^ A
```

✅ Grouping does not matter

```text
(A ^ B) ^ C = A ^ (B ^ C)
```

### Interview Trick

Whenever you read:

> **"Every element appears twice except one."**

Immediately think:

```text
XOR ( ^ )
```

This README matches the revision style you've been building for your DSA repository: theory → intuition → dry run → algorithm → complexities → interview takeaway.
