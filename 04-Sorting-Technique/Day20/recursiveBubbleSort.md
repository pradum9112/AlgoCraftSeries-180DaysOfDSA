# Recursive Bubble Sort

## 📌 Problem Statement

Given an integer array `nums`, sort the array in **non-decreasing order** using the **Recursive Bubble Sort** algorithm.

A non-decreasing array means every element is greater than or equal to its previous element.

---

## 📝 Example

### Input

```text
nums = [7,4,1,5,3]
```

### Output

```text
[1,3,4,5,7]
```

---

# 💡 Why is it called Bubble Sort?

Imagine bubbles inside water.

The **lighter bubble** moves upward.

Similarly,

during every pass,

the **largest element keeps moving towards the end** by repeatedly swapping adjacent elements.

Example

```text
7 4 1 5 3

↓

4 7 1 5 3

↓

4 1 7 5 3

↓

4 1 5 7 3

↓

4 1 5 3 7
```

Notice

```text
7
```

has reached its correct position.

Like a bubble rising to the top,

the largest element "bubbles up" to the end.

Hence the name

```text
Bubble Sort
```

---

# 💡 Approach

Instead of using two loops,

we use

```text
One Loop

+

Recursion
```

For every recursive call

1. Compare adjacent elements.
2. Swap if needed.
3. Largest element reaches the end.
4. Ignore the last sorted element.
5. Call recursion for the remaining array.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [7,4,1,5,3]
```

Initial Call

```cpp
bubbleSortHelper(nums,5)
```

---

# Pass 1

Current Array

```text
[7,4,1,5,3]
```

Loop

### Compare

```text
7 > 4
```

Swap

```text
[4,7,1,5,3]
```

---

Compare

```text
7 > 1
```

Swap

```text
[4,1,7,5,3]
```

---

Compare

```text
7 > 5
```

Swap

```text
[4,1,5,7,3]
```

---

Compare

```text
7 > 3
```

Swap

```text
[4,1,5,3,7]
```

Largest element

```text
7
```

is now fixed.

Recursive Call

```cpp
bubbleSortHelper(nums,4)
```

---

# Pass 2

Current Array

```text
[4,1,5,3,7]
```

Compare

```text
4 > 1
```

Swap

```text
[1,4,5,3,7]
```

---

Compare

```text
4 > 5
```

No Swap

---

Compare

```text
5 > 3
```

Swap

```text
[1,4,3,5,7]
```

Largest in remaining part

```text
5
```

is fixed.

Recursive Call

```cpp
bubbleSortHelper(nums,3)
```

---

# Pass 3

Current Array

```text
[1,4,3,5,7]
```

Compare

```text
1 > 4
```

No Swap

---

Compare

```text
4 > 3
```

Swap

```text
[1,3,4,5,7]
```

Largest

```text
4
```

is fixed.

Recursive Call

```cpp
bubbleSortHelper(nums,2)
```

---

# Pass 4

Current Array

```text
[1,3,4,5,7]
```

Compare

```text
1 > 3
```

No Swap

Recursive Call

```cpp
bubbleSortHelper(nums,1)
```

---

# Base Case

```cpp
if(n<=1)
    return;
```

Now

```text
n = 1
```

Only one element remains.

A single element is already sorted.

Recursion stops.

---

# Final Result

```text
[1,3,4,5,7]
```

---

# 🤔 Why do we call

```cpp
bubbleSortHelper(nums,n-1);
```

After one complete pass,

the largest element reaches its correct position.

Example

After Pass 1

```text
[4,1,5,3,7]
```

The last element

```text
7
```

is already sorted.

No need to compare it again.

So,

next recursive call becomes

```cpp
n-1
```

which ignores the last sorted element.

---

# 🤔 Why Base Case?

```cpp
if(n<=1)
```

Suppose

```text
[1]
```

Only one element remains.

Nothing is left to sort.

So recursion stops.

---

# 📊 Time Complexity (Visualization)

Suppose

```text
N = 5
```

Pass 1

```text
4 Comparisons
```

Pass 2

```text
3 Comparisons
```

Pass 3

```text
2 Comparisons
```

Pass 4

```text
1 Comparison
```

Total

```text
4+3+2+1

=

10
```

Formula

```text
N(N-1)/2
```

Therefore

```text
O(N²)
```

---

## Best Case

Already sorted array.

Since this implementation **does not use a swapped flag**,

it still performs all recursive calls.

```text
O(N²)
```

---

## Average Case

```text
O(N²)
```

---

## Worst Case

```text
O(N²)
```

---

# 📊 Space Complexity

No extra array is used.

However,

recursive function calls are stored in the call stack.

Maximum recursive calls

```text
N
```

Therefore

```text
Space Complexity

O(N)
```

---

# ⚖️ Iterative vs Recursive Bubble Sort

| Feature | Iterative | Recursive |
|:--------|:---------:|:---------:|
| Logic | Loops | Recursion |
| Time | O(N²) | O(N²) |
| Extra Space | O(1) | O(N) |
| Stable | ✅ | ✅ |

---

# ⚠️ Common Mistakes

❌ Writing

```cpp
bubbleSortHelper(nums,n);
```

instead of

```cpp
bubbleSortHelper(nums,n-1);
```

This causes unnecessary work.

---

❌ Forgetting the base case.

```cpp
if(n<=1)
```

Without it,

recursion never stops.

---

❌ Running the loop till

```cpp
i<n
```

instead of

```cpp
i<n-1
```

This causes

```cpp
nums[i+1]
```

to access an invalid index.

---

# 📚 What I Learned

- How Bubble Sort works using recursion.
- Why the largest element reaches the end after every pass.
- Why recursion reduces the problem size using `n-1`.
- Why recursion requires additional stack space.
- Why this implementation has **O(N²)** time complexity.

---

# 📝 30-Second Revision Notes

✔ Compare adjacent elements.

✔ Swap if left element is greater.

✔ Largest element reaches the end after one pass.

✔ Reduce the array size by one.

✔ Stop when `n <= 1`.

✔ Time Complexity → **O(N²)**

✔ Space Complexity → **O(N)** (Recursion Stack)

✔ Stable Sorting Algorithm.

---

# 💡 Interview Takeaways

Recursive Bubble Sort demonstrates how a nested-loop algorithm can be transformed into recursion. While it is not preferred in production because of the extra recursion stack, it is an excellent exercise for understanding recursion and the Bubble Sort process.

> **Key Insight:** After every recursive call, one more largest element reaches its final position, reducing the unsorted portion of the array by one.