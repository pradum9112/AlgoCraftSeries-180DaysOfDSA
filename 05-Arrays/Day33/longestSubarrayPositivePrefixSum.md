# 📘 Day 33 - Longest Subarray with Sum K (Prefix Sum + HashMap - Positive Numbers)

## Problem Statement

Given an array of **positive integers** `nums` and an integer `k`, find the length of the **longest subarray** whose sum is exactly equal to `k`.

---

## Example

### Input

```
nums = [1,2,3,1,1,1]

k = 6
```

### Output

```
3
```

Explanation

The longest subarray is

```
[1,2,3]
```

Length = **3**

---

# Approach

Instead of checking every subarray,

store the **Prefix Sum** in a HashMap.

For every index,

```
current_sum += nums[i]
```

Now check

```
current_sum - k
```

If it already exists in the map,

then the subarray between those two indices has sum `k`.

---

# Algorithm

For every element

1. Update Prefix Sum

```
sum += nums[i]
```

2. If

```
sum == k
```

answer becomes

```
i+1
```

3. Otherwise check

```
sum-k
```

inside HashMap.

4. Store the current Prefix Sum if it appears for the first time.

---

# Dry Run

Input

```
nums = [1,2,3,1,1]

k = 6
```

| Index | Element | Prefix Sum | HashMap | Answer |
|------:|--------:|-----------:|---------|--------|
|0|1|1|{1→0}|0|
|1|2|3|{1→0,3→1}|0|
|2|3|6|{1→0,3→1,6→2}|3|
|3|1|7|Need 1 → Found|3|
|4|1|8|Need 2 → Not Found|3|

Final Answer

```
3
```

---

# Time Complexity

Current Solution

```
O(n)
```

---

## Best Possible

For **positive-only arrays**, an even better approach exists:

```
Sliding Window
```

Time

```
O(n)
```

Space

```
O(1)
```

So although Prefix Sum is already O(n), Sliding Window is preferred because it uses constant extra space.

---

# Space Complexity

```
O(n)
```

HashMap stores Prefix Sums.

---

# Why does this work?

We know

```
Current Prefix Sum = S
```

If

```
S - K
```

already appeared earlier,

then the elements between those two Prefix Sums must add up to exactly `K`.

---

# Why store only the first occurrence?

Example

```
Prefix Sum = 5
```

appears at

```
Index 2
Index 5
```

We store

```
5 → 2
```

instead of

```
5 → 5
```

because using the first occurrence always gives the **longest possible subarray**.

---

# Learning

Pattern Used

- Prefix Sum
- HashMap

Concepts Learned

- Prefix Sum
- HashMap
- First Occurrence Rule
- Longest Subarray Pattern

---

# Key Takeaways

✅ Works for positive arrays.

✅ Time Complexity = **O(n)**.

❌ Uses **O(n)** extra space.

👉 In the next step (Day35), this approach is optimized further using **Sliding Window**, which also runs in **O(n)** but reduces the extra space to **O(1)** for positive arrays.