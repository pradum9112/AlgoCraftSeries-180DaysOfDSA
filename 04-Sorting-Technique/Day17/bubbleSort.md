# Bubble Sort

## 📌 Problem Statement

Given an integer array `nums`, sort the array in **ascending order** using the **Bubble Sort** algorithm.

Bubble Sort repeatedly compares **adjacent elements** and swaps them if they are in the wrong order. After each pass, the largest element moves to its correct position at the end of the array.

---

## 📝 Example

### Input

```text
nums = [64, 34, 25, 12, 22]
```

### Output

```text
[12, 22, 25, 34, 64]
```

### Explanation

Initially

```text
[64, 34, 25, 12, 22]
```

Pass 1

```text
64 and 34 → Swap

[34,64,25,12,22]

64 and 25 → Swap

[34,25,64,12,22]

64 and 12 → Swap

[34,25,12,64,22]

64 and 22 → Swap

[34,25,12,22,64]
```

Largest element (**64**) reaches its correct position.

---

# 💡 Approach

Bubble Sort works by repeatedly comparing two adjacent elements.

If

```text
Left Element > Right Element
```

then swap them.

After every pass,

- the **largest element "bubbles up"** to the last unsorted position.
- therefore, the next pass doesn't need to check that position again.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [64, 34, 25, 12, 22]
```

Initially

```text
[64,34,25,12,22]
```

Size

```cpp
n = 5
```

---

# Pass 1

```cpp
i = 0
```

Initially

```cpp
swapped = false
```

### j = 0

Compare

```text
64 > 34
```

✅ True

Swap

```text
[34,64,25,12,22]
```

```cpp
swapped = true;
```

---

### j = 1

Compare

```text
64 > 25
```

✅ True

Swap

```text
[34,25,64,12,22]
```

---

### j = 2

Compare

```text
64 > 12
```

✅ True

Swap

```text
[34,25,12,64,22]
```

---

### j = 3

Compare

```text
64 > 22
```

✅ True

Swap

```text
[34,25,12,22,64]
```

Largest element is now fixed.

---

# Pass 2

```cpp
i = 1
```

Only check till

```cpp
n-i-1

=

5-1-1

=

3
```

Current array

```text
[34,25,12,22,64]
```

### j = 0

```text
34 > 25
```

✅ Swap

```text
[25,34,12,22,64]
```

---

### j = 1

```text
34 > 12
```

✅ Swap

```text
[25,12,34,22,64]
```

---

### j = 2

```text
34 > 22
```

✅ Swap

```text
[25,12,22,34,64]
```

34 reaches its correct position.

---

# Pass 3

Current array

```text
[25,12,22,34,64]
```

### j = 0

```text
25 > 12
```

✅ Swap

```text
[12,25,22,34,64]
```

---

### j = 1

```text
25 > 22
```

✅ Swap

```text
[12,22,25,34,64]
```

25 reaches its correct position.

---

# Pass 4

Current array

```text
[12,22,25,34,64]
```

Only compare

```text
12 > 22
```

❌ False

No swap occurs.

---

# Final Answer

```text
[12,22,25,34,64]
```

---

# 🤔 Why do we use

```cpp
nums.size()-i-1
```

After every pass,

the largest element reaches its correct position.

Example

After Pass 1

```text
[34,25,12,22,64]
                 ↑
```

64 is already sorted.

No need to compare it again.

After Pass 2

```text
[25,12,22,34,64]
              ↑  ↑
```

34 and 64 are sorted.

So the inner loop becomes smaller after every pass.

---

# 🤔 Why do we use

```cpp
bool swapped
```

Suppose

```text
[1,2,3,4,5]
```

Already sorted.

During the first pass,

no swap happens.

So

```cpp
swapped = false
```

Then

```cpp
if(!swapped)
    break;
```

The algorithm immediately stops.

Without this optimization,

Bubble Sort would still perform unnecessary passes.


---

# 📊 Complexity Analysis

## Worst Case

Reverse Sorted Array

```text
[5,4,3,2,1]
```

Every comparison results in a swap.

Time Complexity

```text
O(N²)
```

---

## Average Case

Random Array

```text
O(N²)
```

---

## Best Case

Already Sorted Array

```text
[1,2,3,4,5]
```

No swap occurs during the first pass.

Algorithm stops immediately.

Time Complexity

```text
O(N)
```

---

## Space Complexity

Only a boolean variable is used.

```text
O(1)
```

---

# ⚖️ Bubble Sort vs Selection Sort

| Feature | Bubble Sort | Selection Sort |
|:--------|:-----------:|:--------------:|
| Method | Adjacent Swaps | Find Minimum |
| Stable | ✅ Yes | ❌ No |
| Best Case | O(N) | O(N²) |
| Average | O(N²) | O(N²) |
| Worst | O(N²) | O(N²) |
| Swaps | Many | At most N-1 |

---

# ⚠️ Common Mistakes

❌ Forgetting

```cpp
swapped = false;
```

inside the outer loop.

---

❌ Writing

```cpp
j < n
```

instead of

```cpp
j < n-i-1
```

which causes

```cpp
nums[j+1]
```

to go out of bounds.

---

❌ Forgetting

```cpp
if(!swapped)
    break;
```

Optimization.

---

# 📚 What I Learned

- How Bubble Sort compares adjacent elements.
- Why the largest element reaches the end after every pass.
- Why the inner loop becomes smaller after each iteration.
- How the `swapped` flag optimizes the algorithm.
- Why Bubble Sort can run in **O(N)** for an already sorted array.

---

# 📝 30-Second Revision Notes

✔ Compare adjacent elements.

✔ Swap if left element is greater.

✔ Largest element reaches the end after every pass.

✔ Reduce inner loop size after each pass.

✔ Use `swapped` to stop early if the array is already sorted.

✔ Best Case → **O(N)**

✔ Average Case → **O(N²)**

✔ Worst Case → **O(N²)**

✔ Space Complexity → **O(1)**

---

# 💡 Interview Takeaways

Bubble Sort is easy to implement and demonstrates the concept of **adjacent swapping**.

Its optimized version performs well on nearly sorted arrays because it can terminate early using the `swapped` flag.

> **Key Insight:** Bubble Sort is the only basic sorting algorithm among Bubble, Selection, and Insertion Sort whose optimized version achieves **O(N)** time complexity for an already sorted array by detecting that no swaps occurred during a pass.