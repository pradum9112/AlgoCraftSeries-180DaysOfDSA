# 📘 Majority Element - Boyer-Moore Voting Algorithm

## Problem Statement

Given an integer array `nums` of size `n`, find the **majority element**.

A majority element is an element that appears:

```text
More than n / 2 times
```

You may assume that the majority element always exists.

---

# Example

## Input

```text
nums = [2, 2, 1, 1, 1, 2, 2]
```

## Output

```text
2
```

## Explanation

Array size:

```text
n = 7
```

Majority condition:

```text
count > n / 2
count > 3
```

The number `2` appears `4` times.

Therefore:

```text
Answer = 2
```

---

# Optimal Approach

We use the **Boyer-Moore Voting Algorithm**.

The idea is to maintain two variables:

```cpp
int candidate = 0;
int count = 0;
```

---

# Core Logic

For every number:

## Case 1: `count == 0`

Choose the current number as the new candidate.

```cpp
if (count == 0) {
    candidate = num;
}
```

---

## Case 2: Current number equals candidate

Increase the count.

```cpp
if (num == candidate) {
    count++;
}
```

---

## Case 3: Current number is different

Decrease the count.

```cpp
else {
    count--;
}
```

---

# Main Intuition: Cancellation

Think of different elements as cancelling each other.

Example:

```text
2 2 1 1 1 2 2
```

The majority element appears more than all other elements combined.

Therefore, even after repeatedly cancelling different pairs:

```text
2 vs 1
```

the majority element cannot be completely cancelled.

The remaining candidate will be the majority element.

---

# Dry Run

Input:

```text
nums = [2, 2, 1, 1, 1, 2, 2]
```

Initially:

```text
candidate = 0
count = 0
```

---

## Step 1

Current:

```text
num = 2
```

Since:

```text
count == 0
```

Choose:

```text
candidate = 2
```

Current number equals candidate:

```text
count++
```

Now:

```text
candidate = 2
count = 1
```

---

## Step 2

Current:

```text
num = 2
```

It matches the candidate.

```text
count = 2
```

State:

```text
candidate = 2
count = 2
```

---

## Step 3

Current:

```text
num = 1
```

It is different from the candidate.

```text
count--
```

Now:

```text
candidate = 2
count = 1
```

Visualization:

```text
2 cancels with 1
```

---

## Step 4

Current:

```text
num = 1
```

Again different.

```text
count--
```

Now:

```text
candidate = 2
count = 0
```

---

## Step 5

Current:

```text
num = 1
```

Since:

```text
count == 0
```

Choose a new candidate:

```text
candidate = 1
```

Then increase count:

```text
count = 1
```

---

## Step 6

Current:

```text
num = 2
```

Different from candidate `1`.

```text
count--
```

Now:

```text
candidate = 1
count = 0
```

---

## Step 7

Current:

```text
num = 2
```

Since count is `0`:

```text
candidate = 2
```

Increase count:

```text
count = 1
```

Final candidate:

```text
2
```

Answer:

```text
2
```

---

# Important Visualization

Imagine this process:

```text
Majority Element vs Other Element
```

Different pairs cancel each other:

```text
2 - 1  → Cancel
2 - 1  → Cancel
```

Because the majority element appears more than:

```text
n / 2 times
```

there are not enough other elements to cancel all of it.

Therefore, the majority element survives as the final candidate.

---

# Why Does `count == 0` Matter?

When:

```text
count == 0
```

it means that, so far, the candidate and different elements have cancelled each other.

So we can start fresh:

```cpp
candidate = num;
```

The current number becomes the new possible candidate.

---

# Algorithm

1. Initialize:

```text
count = 0
candidate = 0
```

2. Traverse every element.

3. If `count == 0`, select the current element as candidate.

4. If the current element equals the candidate:

```text
count++
```

5. Otherwise:

```text
count--
```

6. After traversal, return the candidate.

---

# Complexity

| Approach | Time Complexity | Space Complexity |
|---|---:|---:|
| Brute Force | O(n²) | O(1) |
| HashMap | O(n) | O(n) |
| Boyer-Moore | O(n) | O(1) ✅ |

---

# Why Is Boyer-Moore Optimal?

Every element must be checked at least once.

Therefore, the minimum possible time is:

```text
O(n)
```

Boyer-Moore achieves:

```text
Time = O(n)
Space = O(1)
```

So it is the optimal approach when a majority element is guaranteed to exist.

---

# Important Condition

This version directly returns the final candidate because the problem guarantees:

```text
A majority element always exists.
```

If the problem does **not** guarantee a majority element, we need one extra traversal to verify that the candidate actually appears more than:

```text
n / 2
```

times.

---

# Key Takeaways

✅ `count` represents the balance of the current candidate.

✅ Same element:

```text
count++
```

✅ Different element:

```text
count--
```

✅ When:

```text
count == 0
```

choose a new candidate.

---

# Revision Trick

Remember:

```text
Same → Support candidate → count++

Different → Cancel candidate → count--

Count becomes 0 → Choose new candidate
```

The majority element survives all cancellations.

---

# Pattern Used

- Boyer-Moore Voting Algorithm
- Greedy Cancellation
- Candidate Tracking
- Frequency Problem Optimization