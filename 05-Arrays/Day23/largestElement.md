# Largest Element in an Array

## 📌 Problem Statement

Given an integer array `nums`, find and return the largest element present in the array.

---

## 📝 Example

### Input

```text
nums = [2,5,1,3,0]
```

### Output

```text
5
```

---

# 💡 Approach

We keep one variable called **maxElement**.

Initially,

```cpp
maxElement = nums[0];
```

Now traverse the array from left to right.

For every element,

compare it with the current maximum.

If the current element is larger,

update the maximum.

After the loop finishes,

the maximum variable contains the largest element.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [2,5,1,3,0]
```

Initial

```cpp
maxElement = nums[0];
```

Current

```text
maxElement = 2
```

---

## Iteration 1

```cpp
i = 0
```

Current Element

```text
nums[0] = 2
```

Check

```text
2 > 2 ?

No
```

Current Maximum

```text
2
```

---

## Iteration 2

```cpp
i = 1
```

Current Element

```text
5
```

Check

```text
5 > 2 ?

Yes
```

Update

```text
maxElement = 5
```

---

## Iteration 3

```cpp
i = 2
```

Current Element

```text
1
```

Check

```text
1 > 5 ?

No
```

Maximum remains

```text
5
```

---

## Iteration 4

```cpp
i = 3
```

Current Element

```text
3
```

Check

```text
3 > 5 ?

No
```

Maximum remains

```text
5
```

---

## Iteration 5

```cpp
i = 4
```

Current Element

```text
0
```

Check

```text
0 > 5 ?

No
```

Maximum remains

```text
5
```

---

# Final Answer

```text
Largest Element = 5
```

---

# 🤔 Why do we keep one variable?

Suppose

```text
2 5 1 3 0
```

Initially

```text
Maximum = 2
```

Whenever we find a larger element,

we replace the old maximum.

So only one variable is enough.

---

# 📊 Time Complexity

There is only one traversal of the array.

```text
O(N)
```

where **N** is the size of the array.

---

# 📊 Space Complexity

Only one extra variable is used.

```text
O(1)
```

---

# ⚠️ Common Mistakes

❌ Initializing

```cpp
int maxElement = -1;
```

This fails if all elements are negative.

Example

```text
[-10,-5,-8]
```

Correct initialization

```cpp
int maxElement = nums[0];
```

---

❌ Returning inside the loop.

Always return after the loop completes.

---

# 📚 What I Learned

- How to find the maximum element using a single traversal.
- Why only one variable is enough.
- Why initializing with the first element is safer than `-1`.
- Time Complexity is **O(N)**.
- Space Complexity is **O(1)**.

---

# 📝 30-Second Revision Notes

✔ Initialize maximum with first element.

✔ Traverse the array once.

✔ Update maximum whenever a larger element is found.

✔ Time → **O(N)**

✔ Space → **O(1)**

---

# 💡 Interview Takeaways

Finding the largest element is one of the simplest examples of an **array traversal**. It teaches how to maintain a running answer while scanning the array only once.

> **Key Insight:** Keep track of the best (largest) value seen so far and update it whenever a larger element appears.