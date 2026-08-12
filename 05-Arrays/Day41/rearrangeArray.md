# 📘 Rearrange Array Elements by Sign

## Problem Statement

Given an array containing positive and negative integers, rearrange the elements so that:

```text
Positive, Negative, Positive, Negative, ...
```

The relative order of the positive elements and the relative order of the negative elements should be maintained.

Assume that the array contains an equal number of positive and negative elements.

---

# Example

## Input

```text
nums = [3, 1, -2, -5, 2, -4]
```

## Output

```text
[3, -2, 1, -5, 2, -4]
```

The pattern is:

```text
Positive → Negative → Positive → Negative → Positive → Negative
```

---

# Optimal Approach

Instead of repeatedly searching for positive and negative positions, create a new array and reserve:

```text
Even indexes  → Positive numbers
Odd indexes   → Negative numbers
```

For example:

```text
Index:

0   1   2   3   4   5
↓   ↓   ↓   ↓   ↓   ↓
+   -   +   -   +   -
```

Therefore:

```cpp
int posIndex = 0;
int negIndex = 1;
```

---

# Core Idea

When we find a positive number:

```cpp
ans[posIndex] = nums[i];
posIndex += 2;
```

When we find a negative number:

```cpp
ans[negIndex] = nums[i];
negIndex += 2;
```

Why `+2`?

Because the next position for the same sign is two indexes away.

---

# Visualization

Suppose:

```text
nums = [3, -2, 1, -5, 2, -4]
```

Initially:

```text
posIndex = 0
negIndex = 1
```

Array:

```text
[ _, _, _, _, _, _ ]
  ↑
 pos
```

---

# Dry Run

## Step 1

Current element:

```text
3
```

`3` is positive.

Put it at:

```text
posIndex = 0
```

Array:

```text
[3, _, _, _, _, _]
```

Move positive pointer:

```text
posIndex = 2
```

---

## Step 2

Current:

```text
-2
```

Negative.

Put it at:

```text
negIndex = 1
```

Array:

```text
[3, -2, _, _, _, _]
```

Move:

```text
negIndex = 3
```

---

## Step 3

Current:

```text
1
```

Positive.

Put at:

```text
posIndex = 2
```

Array:

```text
[3, -2, 1, _, _, _]
```

Move:

```text
posIndex = 4
```

---

## Step 4

Current:

```text
-5
```

Negative.

Put at:

```text
negIndex = 3
```

Array:

```text
[3, -2, 1, -5, _, _]
```

Move:

```text
negIndex = 5
```

---

## Step 5

Current:

```text
2
```

Positive.

Put at:

```text
posIndex = 4
```

Array:

```text
[3, -2, 1, -5, 2, _]
```

Move:

```text
posIndex = 6
```

---

## Step 6

Current:

```text
-4
```

Negative.

Put at:

```text
negIndex = 5
```

Final array:

```text
[3, -2, 1, -5, 2, -4]
```

---

# Pointer Visualization

Think of two separate parking lanes:

```text
Positive lane:

0 → 2 → 4 → 6

Negative lane:

1 → 3 → 5 → 7
```

So:

```text
Index:     0   1   2   3   4   5
          +   -   +   -   +   -
```

`posIndex` always tells us:

> Next positive number kaha rakhna hai?

`negIndex` always tells us:

> Next negative number kaha rakhna hai?

---

# Why Do We Need `ans`?

We use:

```cpp
vector<int> ans(n);
```

because we want to place positive and negative elements at their correct positions directly.

We don't need to repeatedly swap elements inside the original array.

---

# Time Complexity

We traverse the array only once:

```text
Time = O(n)
```

---

# Space Complexity

We create another array of size `n`:

```text
Space = O(n)
```

So:

```text
Time  = O(n)
Space = O(n)
```

---

# Why Is This Optimal?

Every element needs to be examined at least once.

Therefore:

```text
Minimum possible time = O(n)
```

Our solution takes:

```text
O(n)
```

So the time complexity is optimal.

The extra space is required by this approach because we construct the rearranged array.

---

# Important Learning

The main trick is not complicated swapping.

It is **index planning**.

Remember:

```text
Positive → even indexes

Negative → odd indexes
```

Therefore:

```cpp
posIndex = 0;
negIndex = 1;
```

and after placing an element:

```cpp
index += 2;
```

---

# Pattern

This problem teaches:

- Index manipulation
- Two-pointer-like thinking
- Building an answer array
- Maintaining relative order
- One-pass array processing

---

# Quick Revision

Remember this picture:

```text
[ + | - | + | - | + | - ]
  ↑   ↑
  0   1

Positive pointer:
0 → 2 → 4

Negative pointer:
1 → 3 → 5
```

Core logic:

```cpp
if (nums[i] > 0) {
    ans[posIndex] = nums[i];
    posIndex += 2;
}
else {
    ans[negIndex] = nums[i];
    negIndex += 2;
}
```

Final complexity:

```text
Time  = O(n)
Space = O(n)
```