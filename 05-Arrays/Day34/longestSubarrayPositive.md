# 📘 Day 34 - Longest Subarray with Sum K (Positive Numbers)

## Problem Statement

Given an array of **positive integers** `nums` and an integer `k`, return the **length of the longest subarray** whose sum is exactly equal to `k`.

---

## Example

### Input

```
nums = [1,2,1,1,1,3,2]

k = 5
```

### Output

```
4
```

### Explanation

The longest subarray is

```
[1,2,1,1]
```

whose sum is

```
1+2+1+1 = 5
```

Length = **4**

---

# Intuition

Since all elements are **positive**, the window sum behaves predictably.

- Add an element → Sum increases.
- Remove an element → Sum decreases.

That's why Sliding Window works.

---

# Algorithm

Initialize

```
left = 0
right = 0
sum = 0
maxLen = 0
```

While `right < n`

- Add `nums[right]`
- If sum > k
  - Remove left elements
- If sum == k
  - Update answer
- Move right

Return `maxLen`

---

# Dry Run

Input

```
nums=[1,2,1,1,1,3,2]

k=5
```

Initially

```
left=0

right=0

sum=0

maxLen=0
```

---

## right = 0

Window

```
[1]
```

```
sum=1
```

Less than k

Move right.

---

## right = 1

Window

```
[1,2]
```

```
sum=3
```

Move right.

---

## right = 2

Window

```
[1,2,1]
```

```
sum=4
```

Move right.

---

## right = 3

Window

```
[1,2,1,1]
```

```
sum=5
```

Target found.

```
Length = 4
```

```
maxLen=4
```

---

## right = 4

Window

```
[1,2,1,1,1]
```

```
sum=6
```

Too large.

Remove

```
1
```

Window

```
[2,1,1,1]
```

```
sum=5
```

Length

```
4
```

No update.

---

## right = 5

Window

```
[2,1,1,1,3]
```

```
sum=8
```

Remove left.

```
sum=6
```

Still greater.

Remove left.

```
sum=5
```

Window

```
[1,1,3]
```

Length

```
3
```

No update.

---

## right = 6

Window

```
[1,1,3,2]
```

```
sum=7
```

Shrink window.

No better answer.

---

# Final Answer

```
Longest Length = 4
```

---

# Time Complexity

## Current Solution

```
O(n)
```

Both pointers move at most `n` times.

---

## Best Possible

```
O(n)
```

Cannot be improved for this problem.

---

# Space Complexity

```
O(1)
```

No extra data structure is used.

---

# Why Sliding Window?

Because the array contains **only positive numbers**.

Adding increases the sum.

Removing decreases the sum.

This property makes Sliding Window possible.

---

# If Negative Numbers Exist?

❌ Sliding Window fails.

Use

```
Prefix Sum + HashMap
```

instead.

---

# Learning

Pattern Used

- Two Pointer
- Sliding Window

---

# Key Takeaways

✅ Only Positive Numbers

✅ Expand Window

✅ Shrink Window

✅ Maintain Current Sum

✅ Update Maximum Length