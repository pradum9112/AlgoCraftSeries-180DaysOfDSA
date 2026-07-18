# Selection Sort

## 📌 Problem Statement

Given an integer array `nums`, sort the array in **ascending order** using the **Selection Sort** algorithm.

Selection Sort repeatedly finds the **smallest element** from the unsorted part of the array and places it at its correct position.

---

## 📝 Example

### Input

```text
nums = [64, 25, 12, 22, 11]
```

### Output

```text
[11, 12, 22, 25, 64]
```

### Explanation

Initially

```text
[64, 25, 12, 22, 11]
```

Pass 1

```text
Smallest = 11

Swap 64 ↔ 11

[11, 25, 12, 22, 64]
```

Pass 2

```text
Smallest = 12

Swap 25 ↔ 12

[11, 12, 25, 22, 64]
```

Pass 3

```text
Smallest = 22

Swap 25 ↔ 22

[11, 12, 22, 25, 64]
```

Pass 4

```text
Smallest = 25

Already in correct position.
```

Sorted Array

```text
[11, 12, 22, 25, 64]
```

---

# 💡 Approach

Selection Sort divides the array into two parts:

- **Sorted Part** (Left Side)
- **Unsorted Part** (Right Side)

For every index:

- Find the smallest element in the unsorted part.
- Swap it with the current index.
- Increase the size of the sorted part by one.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [64, 25, 12, 22, 11]
```

Initially

```text
[64, 25, 12, 22, 11]
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

Initialize

```cpp
mi = i = 0
```

Current Minimum

```text
64
```

---

### Inner Loop

```cpp
j = 1
```

Compare

```text
25 < 64
```

✅ True

Update

```cpp
mi = 1
```

---

```cpp
j = 2
```

Compare

```text
12 < 25
```

✅ True

Update

```cpp
mi = 2
```

---

```cpp
j = 3
```

Compare

```text
22 < 12
```

❌ False

---

```cpp
j = 4
```

Compare

```text
11 < 12
```

✅ True

Update

```cpp
mi = 4
```

---

Minimum found

```text
11
```

Swap

```cpp
swap(nums[0], nums[4]);
```

Array becomes

```text
[11, 25, 12, 22, 64]
```

Sorted Part

```text
[11]
```

---

# Pass 2

```cpp
i = 1
```

Initialize

```cpp
mi = 1
```

Minimum

```text
25
```

---

### Inner Loop

Compare

```text
12 < 25
```

✅

```cpp
mi = 2
```

Compare

```text
22 < 12
```

❌

Compare

```text
64 < 12
```

❌

Minimum

```text
12
```

Swap

```cpp
swap(nums[1], nums[2]);
```

Array

```text
[11, 12, 25, 22, 64]
```

Sorted Part

```text
[11,12]
```

---

# Pass 3

```cpp
i = 2
```

Minimum

```text
25
```

Compare

```text
22 < 25
```

✅

Update

```cpp
mi = 3
```

Compare

```text
64 < 22
```

❌

Swap

```cpp
swap(nums[2], nums[3]);
```

Array

```text
[11,12,22,25,64]
```

Sorted Part

```text
[11,12,22]
```

---

# Pass 4

```cpp
i = 3
```

Minimum

```text
25
```

Compare

```text
64 < 25
```

❌

No smaller element found.

Since

```cpp
mi == i
```

No swap occurs.

Array remains

```text
[11,12,22,25,64]
```

---

# Pass 5

```cpp
i = 4
```

Only one element remains.

Already sorted.

---

# Final Answer

```text
[11,12,22,25,64]
```

---

# 🤔 Why do we use `mi`?

`mi` stores the **index of the smallest element** found so far.

Initially

```cpp
mi = i;
```

While traversing the unsorted part,

if a smaller element is found,

```cpp
mi = j;
```

At the end of the inner loop,

`mi` points to the smallest element.

Finally,

```cpp
swap(nums[i], nums[mi]);
```

places it in its correct position.

---

# 🤔 Why check

```cpp
if(mi != i)
```

Suppose

```text
[1,2,3,4]
```

Smallest element is already at index `i`.

Without this condition,

```cpp
swap(nums[i], nums[i]);
```

would execute unnecessarily.

This condition avoids useless swaps.

---

# 📊 Complexity Analysis

## Outer Loop

Runs

```text
N times
```

---

## Inner Loop

Runs

```text
N-1

N-2

N-3

...

1
```

Total Comparisons

```text
(N-1)+(N-2)+...+1

=

N(N-1)/2
```

Therefore

```text
O(N²)
```

---

## Time Complexity

| Case | Complexity |
|:----:|:----------:|
| Best | O(N²) |
| Average | O(N²) |
| Worst | O(N²) |

Selection Sort always checks the remaining elements, even if the array is already sorted.

---

## Space Complexity

Only two extra variables are used.

```text
mi

temp (inside swap)
```

Therefore

```text
O(1)
```

---

# ⚖️ Selection Sort vs Bubble Sort

| Feature | Selection Sort | Bubble Sort |
|:--------|:--------------:|:-----------:|
| Finds | Minimum Element | Adjacent Swaps |
| Swaps | At most N-1 | Many |
| Stable | ❌ No | ✅ Yes |
| Best Case | O(N²) | O(N) (Optimized) |
| Space | O(1) | O(1) |

---

# ⚠️ Common Mistakes

❌ Writing

```cpp
swap(nums[i], nums[j]);
```

instead of

```cpp
swap(nums[i], nums[mi]);
```

---

❌ Forgetting

```cpp
mi = i;
```

at the start of every outer loop.

---

❌ Updating

```cpp
mi = nums[j];
```

instead of

```cpp
mi = j;
```

Remember,

`mi` stores the **index**, not the value.

---

# 📚 What I Learned

- How Selection Sort works.
- How to divide the array into sorted and unsorted parts.
- Why we keep track of the minimum index.
- Why only one swap is performed in each pass.
- Why Selection Sort always takes **O(N²)** time.

---

# 📝 30-Second Revision Notes

✔ Divide the array into sorted and unsorted parts.

✔ Find the minimum element in the unsorted part.

✔ Swap it with the first unsorted element.

✔ Repeat until the array is sorted.

✔ One swap per pass.

✔ Time Complexity → **O(N²)**

✔ Space Complexity → **O(1)**

---

# 💡 Interview Takeaways

Selection Sort is simple and performs **fewer swaps** than Bubble Sort.

However, it still performs **O(N²)** comparisons even if the array is already sorted, making it inefficient for large datasets.

> **Key Insight:** Selection Sort minimizes the number of swaps (at most **N−1**) but not the number of comparisons. It is mainly useful for learning sorting fundamentals rather than for practical large-scale sorting.