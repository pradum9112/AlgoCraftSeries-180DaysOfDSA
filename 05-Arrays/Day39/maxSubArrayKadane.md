# 📘 Maximum Subarray Sum - Kadane's Algorithm

## Problem Statement

Given an integer array `nums`, find the contiguous subarray whose sum is maximum and return its sum.

A subarray must contain consecutive elements.

---

## Example

### Input

```text
nums = [-2,1,-3,4,-1,2,1,-5,4]
```

### Output

```text
6
```

### Explanation

The maximum-sum subarray is:

```text
[4,-1,2,1]
```

Its sum is:

```text
4 + (-1) + 2 + 1 = 6
```

Therefore:

```text
Maximum Subarray Sum = 6
```

---

# Approaches

## Brute Force

Try every possible starting point and extend the subarray.

```text
Time  = O(n²)
Space = O(1)
```

This works, but it checks many unnecessary possibilities.

---

# Optimal Approach - Kadane's Algorithm

Kadane's Algorithm solves the problem in:

```text
Time  = O(n)
Space = O(1)
```

We maintain two variables:

```cpp
int currentSum = 0;
int maxSum = INT_MIN;
```

### `currentSum`

Stores the sum of the current subarray.

### `maxSum`

Stores the maximum subarray sum found so far.

---

# Core Idea

For every element:

```cpp
currentSum += num;
```

Then update:

```cpp
maxSum = max(maxSum, currentSum);
```

If:

```cpp
currentSum < 0
```

reset it:

```cpp
currentSum = 0;
```

---

# Why Do We Reset When `currentSum < 0`?

This is the most important idea of Kadane's Algorithm.

Suppose:

```text
currentSum = -5
```

Now suppose the next element is:

```text
10
```

If we continue:

```text
-5 + 10 = 5
```

But if we start fresh from `10`:

```text
10
```

The fresh subarray is better.

A negative sum can only reduce the sum of the future subarray.

Therefore:

```text
Negative running sum → Throw it away
```

and start a new subarray.

---

# Dry Run

Consider:

```text
nums = [-2,1,-3,4,-1,2,1,-5,4]
```

Initially:

```text
currentSum = 0
maxSum = INT_MIN
```

---

## Step 1

Current element:

```text
-2
```

Add:

```text
currentSum = 0 + (-2)
           = -2
```

Update:

```text
maxSum = -2
```

Since:

```text
currentSum < 0
```

reset:

```text
currentSum = 0
```

---

## Step 2

Current:

```text
1
```

```text
currentSum = 0 + 1
           = 1
```

Update:

```text
maxSum = max(-2,1)
       = 1
```

Current sum is positive, so don't reset.

---

## Step 3

Current:

```text
-3
```

```text
currentSum = 1 + (-3)
           = -2
```

`maxSum` remains:

```text
1
```

Current sum is negative.

Reset:

```text
currentSum = 0
```

---

## Step 4

Current:

```text
4
```

```text
currentSum = 4
```

Update:

```text
maxSum = 4
```

---

## Step 5

Current:

```text
-1
```

```text
currentSum = 4 - 1
           = 3
```

Maximum remains:

```text
4
```

---

## Step 6

Current:

```text
2
```

```text
currentSum = 3 + 2
           = 5
```

Update:

```text
maxSum = 5
```

---

## Step 7

Current:

```text
1
```

```text
currentSum = 5 + 1
           = 6
```

Update:

```text
maxSum = 6
```

---

## Step 8

Current:

```text
-5
```

```text
currentSum = 6 - 5
           = 1
```

It is still positive.

So don't reset.

---

## Step 9

Current:

```text
4
```

```text
currentSum = 1 + 4
           = 5
```

`maxSum` remains:

```text
6
```

Final answer:

```text
6
```

---

# Visualization

Think of `currentSum` as your **running power**.

```text
-2
 ↓
negative → throw away

1
 ↓
start fresh

1 + (-3)
 ↓
negative → throw away

4
 ↓
4 + (-1)
 ↓
3 + 2
 ↓
5 + 1
 ↓
6  ← BEST
```

The important sequence is:

```text
4 → -1 → 2 → 1
```

Sum:

```text
4 - 1 + 2 + 1 = 6
```

---

# Important Point

We reset:

```cpp
currentSum = 0;
```

but we **do not reset `maxSum`**.

Why?

Because `maxSum` remembers the best answer we have already found.

Example:

```text
[-5,-2,-8]
```

Even though every `currentSum` becomes negative, the answer should be:

```text
-2
```

not `0`.

That's why we initialize:

```cpp
maxSum = INT_MIN;
```

instead of:

```cpp
maxSum = 0;
```

---

# Why `INT_MIN`?

The array can contain only negative numbers.

Example:

```text
[-5,-2,-8]
```

Correct answer:

```text
-2
```

If we used:

```cpp
maxSum = 0;
```

we would incorrectly return:

```text
0
```

Therefore:

```cpp
int maxSum = INT_MIN;
```

is safer.

---

# Complexity

### Brute Force

```text
Time  = O(n²)
Space = O(1)
```

### Kadane's Algorithm

```text
Time  = O(n)
Space = O(1)
```

---

# Comparison

| Approach | Time | Space |
|---|---:|---:|
| Brute Force | O(n²) | O(1) |
| Kadane's Algorithm | **O(n)** | **O(1)** |

Kadane's Algorithm is the optimal approach for maximum subarray sum.

---

# Key Learning

Remember these three steps:

```text
1. Add current element
2. Update maximum
3. If current sum becomes negative → reset
```

In code:

```cpp
currentSum += num;

maxSum = max(maxSum, currentSum);

if (currentSum < 0) {
    currentSum = 0;
}
```

---

# Revision Trick

Think:

> **"Negative baggage ko carry nahi karna."**

If my previous subarray has a negative total, it will only hurt the next subarray.

So:

```text
Negative Sum
     ↓
Discard
     ↓
Start Fresh
```

This is the core intuition behind **Kadane's Algorithm**.