# Rotate Array by K Positions (Optimal - Reversal Algorithm)

## 📝 Problem Statement

Given an array `nums` of size `N` and an integer `K`, rotate the array **K positions towards the left**.

The rotation should be performed **in-place** using the optimal approach.

---

## Example

### Input

```
nums = [1,2,3,4,5,6,7]
k = 2
```

### Output

```
[3,4,5,6,7,1,2]
```

---

# 💡 Intuition

Instead of shifting the array **K times**, we can rotate the array using **three reverse operations**.

Steps:

1. Reverse the first `K` elements.
2. Reverse the remaining `N-K` elements.
3. Reverse the complete array.

This completes the left rotation in linear time.

---

# 🔍 Dry Run

## Input

```
nums = [1,2,3,4,5,6,7]

k = 2
```

```
n = 7

k = k % n

k = 2
```

---

# Step 1 : Reverse First K Elements

Reverse

```
1 2
```

Array becomes

```
2 1 3 4 5 6 7
```

---

# Step 2 : Reverse Remaining Elements

Reverse

```
3 4 5 6 7
```

Array becomes

```
2 1 7 6 5 4 3
```

---

# Step 3 : Reverse Complete Array

Reverse

```
2 1 7 6 5 4 3
```

Array becomes

```
3 4 5 6 7 1 2
```

---

## ✅ Final Answer

```
[3,4,5,6,7,1,2]
```

---

# 🖊️ Dry Run of reverseArray()

Suppose we call

```
reverseArray(nums,0,6)
```

Initial Array

```
1 2 3 4 5 6 7

start = 0
end = 6
```

---

### Iteration 1

Swap

```
1 ↔ 7
```

Array

```
7 2 3 4 5 6 1
```

Update

```
start = 1
end = 5
```

---

### Iteration 2

Swap

```
2 ↔ 6
```

Array

```
7 6 3 4 5 2 1
```

Update

```
start = 2
end = 4
```

---

### Iteration 3

Swap

```
3 ↔ 5
```

Array

```
7 6 5 4 3 2 1
```

Update

```
start = 3
end = 3
```

Loop stops because

```
start < end

3 < 3

False
```

Final

```
7 6 5 4 3 2 1
```

---

# 🧠 Why Does This Algorithm Work?

Suppose the array is divided into two parts.

```
A = First K Elements

B = Remaining Elements
```

Original

```
A | B
```

Example

```
1 2 | 3 4 5 6 7
```

After reversing A

```
2 1 | 3 4 5 6 7
```

After reversing B

```
2 1 | 7 6 5 4 3
```

After reversing the whole array

```
3 4 5 6 7 | 1 2
```

The two parts exchange their positions while maintaining their original order.

---

# 📄 Pen & Paper Dry Run

| Step | Array |
|------|-------|
|Original|1 2 3 4 5 6 7|
|Reverse First K|2 1 3 4 5 6 7|
|Reverse Remaining|2 1 7 6 5 4 3|
|Reverse Whole|3 4 5 6 7 1 2|

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

```
k = 3 % 3 = 0
```

Output

```
[1,2,3]
```

---

### Case 3

```
nums = [1,2,3]

k = 5
```

```
k = 5 % 3 = 2
```

Output

```
[3,1,2]
```

---

# ⏱️ Time Complexity

Three reverse operations are performed.

Each reverse takes

```
O(N)
```

Therefore,

```
Time Complexity = O(N)
```

---

# 💾 Space Complexity

```
O(1)
```

No extra array is used.

---

# 📊 Comparison

| Approach | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
|Brute Force (Shift K Times)|O(N × K)|O(1)|
|Reversal Algorithm|O(N)|O(1)|

---

# 🎯 Key Learning

- Left rotation can be done without shifting elements repeatedly.
- Reverse the first part.
- Reverse the second part.
- Reverse the entire array.
- Always use

```
k = k % n
```

to avoid unnecessary rotations.
- The Reversal Algorithm is the optimal in-place solution and is frequently asked in coding interviews.