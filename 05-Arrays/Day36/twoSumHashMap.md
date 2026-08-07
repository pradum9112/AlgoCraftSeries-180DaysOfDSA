# 📘 Day 36 - Two Sum (HashMap)

## Problem Statement

Given an integer array `nums` and an integer `target`, return the **indices** of the two numbers such that they add up to the target.

You may assume that exactly one solution exists.

---

## Example

### Input

```
nums = [2,7,11,15]

target = 9
```

### Output

```
[0,1]
```

### Explanation

```
nums[0] + nums[1]

2 + 7

= 9
```

Hence,

```
Answer = [0,1]
```

---

# Approach

Instead of checking every pair,

store each number inside a HashMap.

For every current element,

calculate

```
Complement = Target - Current Number
```

Then simply check

```
Has this complement already appeared?
```

If Yes,

return both indices.

Otherwise,

store the current element for future use.

---

# Algorithm

For every element

```
Current = nums[i]
```

Calculate

```
Complement = Target - Current
```

If

```
Complement
```

already exists inside HashMap,

return

```
Previous Index

Current Index
```

Otherwise

store

```
Current Number → Current Index
```

inside HashMap.

---

# Dry Run

Input

```
nums = [2,7,11,15]

target = 9
```

Initially

```
HashMap = { }
```

---

### i = 0

Current Number

```
2
```

Need

```
9 - 2 = 7
```

HashMap

```
{}
```

7 not found.

Store

```
2 → 0
```

HashMap

```
{
2 → 0
}
```

---

### i = 1

Current Number

```
7
```

Need

```
9 - 7 = 2
```

HashMap

```
{
2 → 0
}
```

Found.

Return

```
{0,1}
```

---

# Visualization

Array

```
Index

0   1   2   3

2   7  11  15
```

Current

```
2
```

Need

```
7
```

Not found.

Store

```
2 → 0
```

↓

Current

```
7
```

Need

```
2
```

Found.

Return

```
0 1
```

---

# Why HashMap?

HashMap stores

```
Value → Index
```

Example

```
5 → 3
```

means

```
Value 5 is present at Index 3
```

Searching inside HashMap takes

```
O(1)
```

average time.

---

# Time Complexity

## Current Solution

```
O(n)
```

Only one traversal of the array.

---

## Best Possible

```
O(n)
```

This is already the optimal solution because every element must be visited at least once.

---

# Space Complexity

```
O(n)
```

HashMap stores array elements.

---

# Learning

### Pattern Used

- HashMap
- One Pass Traversal

### Concepts Learned

- Complement Technique
- HashMap Lookup
- Value → Index Mapping
- Time Complexity Optimization

---

# Key Takeaways

✅ Check for the complement before storing the current element.

```
Complement = Target - Current Number
```

✅ HashMap gives O(1) average lookup time.

✅ Brute Force takes O(n²).

✅ HashMap reduces the complexity to O(n).

---

# Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n²) | O(1) |
| HashMap | O(n) | O(n) ✅ |

---

# Revision Notes

Remember only one formula:

```
Complement = Target - Current Number
```

Ask yourself:

```
"Have I already seen this complement?"
```

If **YES**, return the answer.

If **NO**, store the current element inside the HashMap.