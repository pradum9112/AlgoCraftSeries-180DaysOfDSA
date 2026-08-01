# Linear Search

## 📝 Problem Statement

Given an array `nums` of size `N` and an integer `target`, return the index of the target element.

If the target element is not present in the array, return `-1`.

---

## Example 1

### Input

```
nums = [4, 7, 1, 9, 5]
target = 9
```

### Output

```
3
```

### Explanation

The target element `9` is present at index `3`.

---

## Example 2

### Input

```
nums = [2,4,6,8]
target = 5
```

### Output

```
-1
```

### Explanation

The target element is not present in the array.

---

# 💡 Approach Used

We traverse the array from left to right.

- Compare each element with the target.
- If both are equal, immediately return its index.
- If the loop finishes and the target is still not found, return `-1`.

Since every element is checked one by one, this algorithm is called **Linear Search**.

---

# 🔍 Dry Run

## Input

```
nums = [4,7,1,9,5]
target = 9
```

Array Size

```
n = 5
```

---

### Iteration 1

```
i = 0

nums[0] = 4

4 == 9 ?

False
```

Move to next index.

---

### Iteration 2

```
i = 1

nums[1] = 7

7 == 9 ?

False
```

Move to next index.

---

### Iteration 3

```
i = 2

nums[2] = 1

1 == 9 ?

False
```

Move to next index.

---

### Iteration 4

```
i = 3

nums[3] = 9

9 == 9 ?

True
```

Return

```
3
```

The function stops immediately.

---

## Final Answer

```
3
```

---

# 📄 Pen & Paper Dry Run

| Iteration | Index | Element | Comparison | Result |
|-----------|------:|--------:|-----------|--------|
|1|0|4|4 == 9|False|
|2|1|7|7 == 9|False|
|3|2|1|1 == 9|False|
|4|3|9|9 == 9|True → Return 3|

---

# 🚀 Complexity Analysis

## ✅ Current Solution Used

### Approach

Linear Search

### Time Complexity

| Case | Complexity |
|------|------------|
|Best Case|O(1)|
|Average Case|O(N)|
|Worst Case|O(N)|

### Space Complexity

```
O(1)
```

### Why?

In the worst case, the target may be at the last index or may not exist at all.

Therefore, we have to traverse the entire array.

---

# ⚡ Can This Be Optimized?

## Case 1 : Array is Unsorted

Best Possible Time Complexity

```
O(N)
```

Reason:

Since the array is unsorted, we have no information about where the target might be.

Every element may need to be checked.

So **Linear Search is already the optimal solution**.

---

## Case 2 : Array is Sorted

Better Approach

```
Binary Search
```

Time Complexity

```
O(log N)
```

Space Complexity

```
O(1)
```

Condition

The array **must be sorted**.

---

# 📊 Complexity Comparison

| Approach | Condition | Time | Space |
|----------|-----------|------|-------|
|Linear Search|Sorted / Unsorted|O(N)|O(1)|
|Binary Search|Sorted Array|O(log N)|O(1)|

---

# 🧠 Interview Thinking

Whenever a searching problem appears, think in this order:

### Step 1

Is the array sorted?

✅ Yes

→ Think about **Binary Search**

---

❌ No

→ Linear Search is usually the first approach.

---

### Step 2

Are there multiple search queries?

If yes,

Think about

- Hashing
- unordered_map
- map

instead of searching repeatedly.

---

# 🎯 Learning From This Problem

✔️ Linear traversal of an array

✔️ Searching in an unsorted array

✔️ Returning immediately after finding the target

✔️ Difference between sorted and unsorted searching

✔️ Why Binary Search is faster

✔️ When Linear Search is already the optimal solution

---

# ⭐ Key Takeaway

- Linear Search checks every element one by one.
- It works on both sorted and unsorted arrays.
- For an **unsorted array**, O(N) is the best possible complexity.
- For a **sorted array**, Binary Search reduces the complexity to O(log N).
- Always identify whether the input is sorted before choosing the searching algorithm.