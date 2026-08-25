# Day 53 — Longest Subarray with Sum 0

## Problem Statement

Given an array containing positive and negative integers, find the length of the **longest subarray whose sum is equal to 0**.

---

## Example

### Input

```text
5
15 -2 2 -8 8
```

### Output

```text
4
```

### Explanation

The longest zero-sum subarray is:

```text
[-2, 2, -8, 8]
```

Its sum is:

```text
-2 + 2 - 8 + 8 = 0
```

Length:

```text
4
```

---

# Approach 1 — Brute Force

## Idea

Choose every possible starting index `i`.

Then extend the subarray using `j`.

Instead of calculating the sum again and again, maintain a running sum.

```text
i = starting index
j = ending index
```

For every `j`:

```text
current_sum += arr[j]
```

If:

```text
current_sum == 0
```

then:

```text
length = j - i + 1
```

Update the maximum length.

---

## Example

```text
arr = [15, -2, 2, -8, 8]
```

Starting from index `1`:

```text
[-2]
sum = -2

[-2, 2]
sum = 0
length = 2

[-2, 2, -8]
sum = -8

[-2, 2, -8, 8]
sum = 0
length = 4
```

Therefore:

```text
max_len = 4
```

---

## Complexity

```text
Time = O(n²)
Space = O(1)
```

---

# Approach 2 — Optimal: Prefix Sum + HashMap

## Main Idea

Maintain a running prefix sum:

```text
sum += arr[i]
```

Store:

```text
prefix_sum → first index
```

in a HashMap.

---

# ⭐ Most Important Observation

Suppose:

```text
prefixSum at index i = X
```

and later:

```text
prefixSum at index j = X
```

Then:

```text
sum(0...i) = X
sum(0...j) = X
```

Subtract them:

```text
sum(i+1...j) = 0
```

Therefore, whenever the **same prefix sum appears again**, the subarray between the two positions has sum `0`.

---

# Example Dry Run

Array:

```text
[15, -2, 2, -8, 8]
```

Initially:

```text
sum = 0
max_len = 0
```

HashMap:

```text
{}
```

---

## i = 0

```text
sum = 15
```

`15` is not in the map.

Store:

```text
15 → 0
```

Map:

```text
{15: 0}
```

---

## i = 1

```text
sum = 15 + (-2)
    = 13
```

`13` is not present.

Store:

```text
13 → 1
```

Map:

```text
{15: 0, 13: 1}
```

---

## i = 2

```text
sum = 13 + 2
    = 15
```

Now `15` already exists.

It was first seen at:

```text
index = 0
```

Current index:

```text
2
```

Therefore:

```text
length = 2 - 0
       = 2
```

Subarray:

```text
[-2, 2]
```

Sum:

```text
0
```

So:

```text
max_len = 2
```

---

## i = 3

```text
sum = 15 + (-8)
    = 7
```

`7` is not present.

Store:

```text
7 → 3
```

---

## i = 4

```text
sum = 7 + 8
    = 15
```

`15` already exists at index `0`.

Therefore:

```text
length = 4 - 0
       = 4
```

Subarray:

```text
[-2, 2, -8, 8]
```

Sum:

```text
-2 + 2 - 8 + 8 = 0
```

Update:

```text
max_len = 4
```

---

# Why Store Only the First Occurrence?

This is extremely important.

Suppose:

```text
prefix sum = 15
```

appears at:

```text
index 0
index 2
index 4
```

For the longest subarray, we want the **earliest index**.

From index `0` to `4`:

```text
length = 4 - 0 = 4
```

If we replaced the first occurrence:

```text
15 → 2
```

then later:

```text
length = 4 - 2 = 2
```

We would lose the longest answer.

Therefore:

```cpp
if (mpp.find(sum) == mpp.end()) {
    mpp[sum] = i;
}
```

means:

> Store the prefix sum only when seeing it for the first time.

---

# Case 1 — Prefix Sum Itself Becomes 0

Suppose:

```text
arr = [1, -1, 2]
```

At index `1`:

```text
sum = 1 + (-1)
    = 0
```

Therefore:

```text
arr[0...1]
```

has sum `0`.

Length:

```text
i + 1
```

So:

```cpp
if (sum == 0) {
    max_len = i + 1;
}
```

---

# Case 2 — Same Prefix Sum Appears Again

Suppose:

```text
sum = 15
```

was first found at:

```text
index = 0
```

and appears again at:

```text
index = 4
```

Then:

```text
arr[1...4]
```

has sum `0`.

Length:

```text
4 - 0 = 4
```

Therefore:

```cpp
int len = i - mpp[sum];
```

---

# 🧠 Visualization

Think of prefix sum as your **running balance**.

```text
Start
  |
 15
  |
 13
  |
 15  ← same balance again
```

When you return to the same prefix sum:

```text
15 ───────────────→ 15
       middle
         ↓
       SUM = 0
```

So:

> **Same prefix sum twice = middle subarray has sum 0.**

This is the key theory of the optimal solution.

---

# Why HashMap?

Without HashMap, searching whether a prefix sum appeared before would take extra time.

HashMap allows approximately:

```text
find → O(1)
insert → O(1)
```

on average.

Therefore we can solve the problem in one traversal.

---

# Complexity

### Brute Force

```text
Time = O(n²)
Space = O(1)
```

### Prefix Sum + HashMap

```text
Time = O(n)
Space = O(n)
```

---

# Comparison

| Approach             |  Time | Space | Technique   |
| -------------------- | ----: | ----: | ----------- |
| Brute Force          | O(n²) |  O(1) | Running Sum |
| Prefix Sum + HashMap |  O(n) |  O(n) | Prefix Sum  |

---

# 🔗 Connection With Previous Problems

You have already seen this idea in:

### Longest Subarray with Sum K

```text
current_sum - k
```

was searched in the HashMap.

For sum `0`:

```text
current_sum - 0
```

becomes:

```text
current_sum
```

So the idea is actually the same:

```text
Longest Subarray with Sum K
        ↓
Prefix Sum + HashMap
        ↓
Find previous prefix_sum - K
```

For:

```text
K = 0
```

it becomes:

```text
Find previous same prefix_sum
```

---

# ⭐ Key Learning

Remember just these 3 points:

### 1. Calculate Prefix Sum

```cpp
sum += arr[i];
```

### 2. Same Prefix Sum Again

```text
same prefix sum
       ↓
middle part has sum 0
```

### 3. Store First Occurrence

```cpp
if (mpp.find(sum) == mpp.end()) {
    mpp[sum] = i;
}
```

Why?

```text
earliest index
     ↓
longest possible subarray
```

---

# Final Pattern

```text
Prefix Sum
    ↓
Have I seen this sum before?
    ↓
YES
 ↓
Current Index - First Index
 ↓
Zero-Sum Subarray
```

**Day53 Main Concept:**

> **Same prefix sum appearing at two different indices means the subarray between those indices has sum 0.**
