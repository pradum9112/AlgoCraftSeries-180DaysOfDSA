# Rotate Array by K Positions (Left Rotation) - Brute Force

## 📝 Problem Statement

Given an array `nums` of size `N` and an integer `K`, rotate the array **K positions towards the left**.

The rotation should be performed **in-place**.

---

## Example

### Input

```
nums = [1,2,3,4,5]
k = 2
```

### Output

```
[3,4,5,1,2]
```

---

# 💡 Approach

One left rotation can be done by

1. Store the first element.
2. Shift every element one position towards the left.
3. Put the stored element at the last position.

To rotate by **K positions**, simply repeat this process **K times**.

Before rotating,

```
k = k % n
```

because after every `n` rotations, the array becomes the same again.

---

# 🔍 Dry Run

## Input

```
nums = [1,2,3,4,5]

k = 2
```

Since

```
k = 2 % 5 = 2
```

We perform two left rotations.

---

# First Rotation

Initial Array

```
1 2 3 4 5
```

Store

```
temp = 1
```

Shift elements

```
2 2 3 4 5
```

```
2 3 3 4 5
```

```
2 3 4 4 5
```

```
2 3 4 5 5
```

Place temp at last

```
2 3 4 5 1
```

---

# Second Rotation

Current Array

```
2 3 4 5 1
```

Store

```
temp = 2
```

Shift elements

```
3 3 4 5 1
```

```
3 4 4 5 1
```

```
3 4 5 5 1
```

```
3 4 5 1 1
```

Place temp

```
3 4 5 1 2
```

---

## ✅ Final Answer

```
[3,4,5,1,2]
```

---

# 📄 Pen & Paper Dry Run

| Rotation | Stored temp | Array After Rotation |
|-----------|------------|----------------------|
|Initial|-|1 2 3 4 5|
|1|1|2 3 4 5 1|
|2|2|3 4 5 1 2|

---

# 🧠 Why do we use `k % n`?

Suppose

```
nums = [1,2,3,4,5]
```

```
n = 5
```

If

```
k = 7
```

then

```
7 % 5 = 2
```

Rotating 7 times gives exactly the same result as rotating only 2 times.

This avoids unnecessary work.

---

# ⚠️ Edge Cases

### Case 1

```
nums = [5]

k = 10
```

Output

```
[5]
```

---

### Case 2

```
nums = [1,2,3]

k = 3
```

Output

```
[1,2,3]
```

---

### Case 3

```
nums = [1,2,3]

k = 4
```

```
k = 4 % 3 = 1
```

Output

```
[2,3,1]
```

---

# ⏱️ Time Complexity

Outer loop runs

```
k
```

times.

Each rotation shifts

```
n
```

elements.

Therefore,

```
Time Complexity = O(N × K)
```

---

# 💾 Space Complexity

```
O(1)
```

Only one temporary variable is used.

---

# 🎯 Key Learning

- Perform one left rotation using shifting.
- Repeat the process K times.
- Always reduce rotations using

```
k = k % n
```

- This is the brute force approach.
- Better solutions exist with **O(N)** time using the Reversal Algorithm.