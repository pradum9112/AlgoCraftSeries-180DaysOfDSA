# Move Zeroes to the End (Optimal - Two Pointer)

## 📝 Problem Statement

Given an integer array `nums`, move all the zeroes to the end while maintaining the relative order of the non-zero elements.

The operation should be performed **in-place** without creating another array.

---

## Example

### Input

```
nums = [1,0,2,0,3,4]
```

### Output

```
[1,2,3,4,0,0]
```

---

# 💡 Approach

Instead of shifting every zero repeatedly, we use two pointers.

- Find the first zero.
- Store its index in `j`.
- Traverse the remaining array.
- Whenever a non-zero element is found,
  - Swap it with `nums[j]`.
  - Increment `j`.

Finally, all non-zero elements come to the front and all zeroes automatically move to the end.

---

# 🔍 Dry Run

## Input

```
nums = [1,0,2,0,3,4]
```

Initial

```
1 0 2 0 3 4
```

---

## Step 1

Find the first zero.

```
j = 1
```

```
1 0 2 0 3 4
  ^
  j
```

---

## Step 2

```
i = 2

nums[2] = 2
```

Non-zero found.

Swap

```
swap(nums[2], nums[1])
```

Array

```
1 2 0 0 3 4
```

Increment

```
j = 2
```

---

## Step 3

```
i = 3

nums[3] = 0
```

Zero found.

No swap.

```
1 2 0 0 3 4
```

---

## Step 4

```
i = 4

nums[4] = 3
```

Swap

```
swap(nums[4], nums[2])
```

Array

```
1 2 3 0 0 4
```

Increment

```
j = 3
```

---

## Step 5

```
i = 5

nums[5] = 4
```

Swap

```
swap(nums[5], nums[3])
```

Array

```
1 2 3 4 0 0
```

Increment

```
j = 4
```

---

## ✅ Final Answer

```
[1,2,3,4,0,0]
```

---

# 📄 Pen & Paper Dry Run

| Step | j | Current Element | Array |
|------|---|-----------------|-------|
|Initial|1|-|1 0 2 0 3 4|
|Swap 2|2|2|1 2 0 0 3 4|
|Skip Zero|2|0|1 2 0 0 3 4|
|Swap 3|3|3|1 2 3 0 0 4|
|Swap 4|4|4|1 2 3 4 0 0|

---

# 🧠 Why Does It Work?

Pointer `j` always points to the **leftmost zero**.

Whenever a non-zero element is found,

```
swap(non-zero, zero)
```

After swapping,

- the non-zero moves to the correct position,
- `j` moves forward,
- and now `j` points to the next zero.

Thus every non-zero element is placed exactly once.

---

# ⚠️ Edge Cases

### Case 1

```
[0,0,0]
```

Output

```
0 0 0
```

---

### Case 2

```
[1,2,3]
```

No zero exists.

Output

```
1 2 3
```

---

### Case 3

```
[0]
```

Output

```
0
```

---

### Case 4

```
[1]
```

Output

```
1
```

---

# ⏱️ Time Complexity

- Finding the first zero

```
O(N)
```

- Traversing the remaining array

```
O(N)
```

Overall,

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

| Approach | Time | Space |
|----------|------|-------|
|Brute Force (Repeated Shifting)|O(N²)|O(1)|
|Two Pointer (Optimal)|O(N)|O(1)|

---

# 🎯 Key Learning

- Find the first zero.
- Keep pointer `j` at the first zero.
- Traverse the remaining array.
- Swap every non-zero element with `nums[j]`.
- Increment `j` after every swap.
- This preserves the relative order of all non-zero elements while moving all zeroes to the end.