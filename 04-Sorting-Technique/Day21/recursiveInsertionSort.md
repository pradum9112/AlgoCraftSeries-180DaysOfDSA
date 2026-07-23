# Recursive Insertion Sort

## 📌 Problem Statement

Given an integer array `nums`, sort the array in **non-decreasing order** using **Recursive Insertion Sort**.

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

# 💡 Why is it called Recursive Insertion Sort?

Just like Iterative Insertion Sort,

we insert one element into its correct position.

The only difference is

instead of using an outer loop,

we use **Recursion**.

Every recursive call sorts

```text
First n-1 elements
```

Then

the nth element is inserted into its correct position.

---

# 💡 Approach

For every recursive call

1. Sort first `n-1` elements.
2. Store last element as `key`.
3. Shift larger elements.
4. Insert key at correct position.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [7,4,1,5,3]
```

Initial Call

```cpp
helper(nums,5)
```

---

# Recursive Calls

```text
helper(5)

↓

helper(4)

↓

helper(3)

↓

helper(2)

↓

helper(1)
```

Base Case

```cpp
if(n<=1)
    return;
```

One element is already sorted.

Now recursion starts returning.

---

# Return 1

Current Array

```text
[7,4,1,5,3]
```

Current Call

```cpp
helper(2)
```

Current Element

```cpp
key = nums[1]

=

4
```

Compare

```text
7 > 4
```

Shift

```text
[7,7,1,5,3]
```

Insert

```text
[4,7,1,5,3]
```

Now

```text
First 2 elements are sorted.
```

---

# Return 2

Current Call

```cpp
helper(3)
```

Current Array

```text
[4,7,1,5,3]
```

Current Element

```cpp
key = 1
```

Compare

```text
7 >1
```

Shift

```text
[4,7,7,5,3]
```

Compare

```text
4 >1
```

Shift

```text
[4,4,7,5,3]
```

Insert

```text
[1,4,7,5,3]
```

Now

```text
First 3 elements are sorted.
```

---

# Return 3

Current Call

```cpp
helper(4)
```

Current Array

```text
[1,4,7,5,3]
```

Current Element

```cpp
key = 5
```

Compare

```text
7 >5
```

Shift

```text
[1,4,7,7,3]
```

Compare

```text
4 >5

No
```

Insert

```text
[1,4,5,7,3]
```

Now

```text
First 4 elements are sorted.
```

---

# Return 4

Current Call

```cpp
helper(5)
```

Current Array

```text
[1,4,5,7,3]
```

Current Element

```cpp
key = 3
```

Compare

```text
7 >3
```

Shift

```text
[1,4,5,7,7]
```

Compare

```text
5 >3
```

Shift

```text
[1,4,5,5,7]
```

Compare

```text
4 >3
```

Shift

```text
[1,4,4,5,7]
```

Compare

```text
1 >3

No
```

Insert

```text
[1,3,4,5,7]
```

Entire array becomes sorted.

---

# Final Result

```text
[1,3,4,5,7]
```

---

# 🤔 Why do we call

```cpp
helper(nums,n-1);
```

Because

before inserting

```text
nth element
```

the first

```text
n−1 elements
```

must already be sorted.

Recursion does exactly that.

---

# 🤔 Why do we store

```cpp
key
```

Suppose

```text
[4,7,1]
```

If we start shifting immediately,

we lose

```text
1
```

So first

```cpp
key = nums[n-1];
```

Then shifting begins safely.

---

# 📊 Time Complexity

Suppose

```text
N = 5
```

Recursive Calls

```text
5

↓

4

↓

3

↓

2

↓

1
```

Insertion Work

```text
1

+

2

+

3

+

4
```

Total

```text
N(N−1)/2
```

Hence

```text
O(N²)
```

---

## Best Case

Already Sorted

Every insertion takes only one comparison.

```text
O(N)
```

---

## Average Case

```text
O(N²)
```

---

## Worst Case

Reverse Sorted

Every insertion shifts all previous elements.

```text
O(N²)
```

---

# 📊 Space Complexity

Recursive Stack

```text
helper(5)

↓

helper(4)

↓

helper(3)

↓

helper(2)

↓

helper(1)
```

Maximum Calls

```text
N
```

Therefore

```text
Space Complexity

O(N)
```

---

# ⚠️ Common Mistakes

❌ Writing

```cpp
helper(nums,n);
```

inside helper.

It causes infinite recursion.

---

❌ Forgetting

```cpp
key
```

before shifting.

---

❌ Forgetting

```cpp
nums[j+1]=key;
```

after the while loop.

---

# 📚 What I Learned

- How to convert Iterative Insertion Sort into Recursion.
- Why recursion first sorts `n-1` elements.
- Why key is stored before shifting.
- Why insertion happens during recursion return.
- Difference between recursive Bubble Sort and recursive Insertion Sort.

---

# 📝 30-Second Revision Notes

✔ Sort first `n-1` elements recursively.

✔ Store last element as key.

✔ Shift larger elements.

✔ Insert key.

✔ Stop when `n<=1`.

✔ Best Case → **O(N)**

✔ Average Case → **O(N²)**

✔ Worst Case → **O(N²)**

✔ Space → **O(N)** (Recursion Stack)

---

# 💡 Interview Takeaways

Recursive Insertion Sort demonstrates how recursion can replace the outer loop of the iterative algorithm. The recursive call ensures that the first `n-1` elements are already sorted, after which the last element is inserted into its correct position.

> **Key Insight:** Recursion sorts the prefix of the array first, and every returning call inserts exactly one new element into its proper position.