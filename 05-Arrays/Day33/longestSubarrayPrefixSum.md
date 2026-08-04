# 📘 Day 33 - Longest Subarray with Sum K (Prefix Sum + HashMap)

## Problem Statement

Given an integer array `nums` and an integer `k`, return the length of the **longest subarray** whose sum is equal to `k`.

---

## Example

Input

```
nums = [1,2,3,1,1,1,1]
k = 6
```

Output

```
4
```

Explanation

```
3 + 1 + 1 + 1 = 6

Length = 4
```

---

# Approach

We use two concepts:

- Prefix Sum
- HashMap

Instead of calculating every subarray sum, we keep a running sum.

```
current_sum += nums[i]
```

If

```
current_sum == k
```

then the subarray starts from index **0**.

Otherwise,

we check

```
current_sum - k
```

inside the HashMap.

If it exists,

then the subarray between

```
previous_index + 1

to

current_index
```

has sum **k**.

---

# Why current_sum - k ?

Suppose

Current Prefix Sum

```
20
```

Target

```
k = 8
```

If there was previously

```
12
```

stored,

then

```
20 - 12 = 8
```

Hence,

the subarray between those indices has sum **8**.

---

# Dry Run

Input

```
nums = [1,2,3,1,1,1,1]

k = 6
```

Initially

```
current_sum = 0

max_len = 0

map = {}
```

---

## i = 0

```
current_sum = 1
```

Need

```
1 - 6 = -5
```

Not found.

Store

```
1 → 0
```

---

## i = 1

```
current_sum = 3
```

Need

```
3 - 6 = -3
```

Not found.

Store

```
3 → 1
```

---

## i = 2

```
current_sum = 6
```

Current sum equals k.

```
Length = 3
```

Update

```
max_len = 3
```

Store

```
6 → 2
```

---

## i = 3

```
current_sum = 7
```

Need

```
7 - 6 = 1
```

Map contains

```
1 → 0
```

Length

```
3 - 0 = 3
```

max_len remains

```
3
```

Store

```
7 → 3
```

---

## i = 4

```
current_sum = 8
```

Need

```
2
```

Not found.

Store

```
8 → 4
```

---

## i = 5

```
current_sum = 9
```

Need

```
3
```

Map contains

```
3 → 1
```

Length

```
5 - 1 = 4
```

Update

```
max_len = 4
```

Store

```
9 → 5
```

---

## i = 6

```
current_sum = 10
```

Need

```
4
```

Not found.

Store

```
10 → 6
```

---

Final Answer

```
4
```

---

# Why store only first occurrence?

Suppose

```
Prefix Sum = 6
```

comes at

```
index = 2
```

Again comes at

```
index = 5
```

If we overwrite,

```
6 → 5
```

then future subarrays become shorter.

To get the **longest subarray**, we always keep the **first occurrence**.

Therefore,

```
if(prefix_map.find(current_sum)==prefix_map.end())
```

is necessary.

---

# Time Complexity

Current Solution

```
O(n)
```

Each element is visited once.

---

Best Possible

```
O(n)
```

Cannot be improved.

---

# Space Complexity

```
O(n)
```

HashMap stores prefix sums.

---

# Learning

Pattern Used

- Prefix Sum
- HashMap
- Longest Subarray

Important Formula

```
current_sum - k
```

If this exists,

then the subarray between those indices has sum **k**.

---

# Key Takeaways

✅ Prefix Sum stores cumulative sum.

✅ HashMap stores first occurrence.

✅ Store only first occurrence to maximize length.

✅ This approach works for

- Positive Numbers
- Negative Numbers
- Mixed Arrays

Unlike Sliding Window.