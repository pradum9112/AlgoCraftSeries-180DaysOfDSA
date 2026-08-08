# 📘 Day 37 - Sort 0s, 1s and 2s

## Problem Statement

Given an array containing only `0`, `1`, and `2`, sort the array in ascending order.

The solution should be done without using a built-in sorting function.

---

## Example

### Input

```text
6
2 0 2 1 1 0
```

### Output

```text
0 0 1 1 2 2
```

---

# Approach

We use the **Dutch National Flag Algorithm**.

We maintain three pointers:

```text
low
mid
high
```

The array is divided into four regions:

```text
[ 0s | 1s | Unknown | 2s ]
```

Initially, almost the entire array is unknown.

We use `mid` to inspect the unknown elements.

---

# Pointer Meaning

### `low`

Everything before `low` is already `0`.

```text
[ 0 0 0 | ... ]
        ↑
       low
```

### `mid`

`mid` points to the first element of the unknown region.

```text
[ 0s | Unknown | 2s ]
       ↑
      mid
```

### `high`

Everything after `high` is already `2`.

```text
[ ... | 2 2 2 ]
            ↑
           high
```

---

# Rules

We inspect:

```cpp
nums[mid]
```

## Case 1: `nums[mid] == 0`

`0` belongs to the left side.

```cpp
swap(nums[low], nums[mid]);

low++;
mid++;
```

Why increase both?

Because after the swap, the `0` is in its correct region and the new `mid` element also needs to be processed.

---

## Case 2: `nums[mid] == 1`

`1` already belongs in the middle.

So simply:

```cpp
mid++;
```

---

## Case 3: `nums[mid] == 2`

`2` belongs to the right side.

```cpp
swap(nums[mid], nums[high]);

high--;
```

### Important

We **do NOT increase `mid`** here.

Why?

Because the element coming from `high` has not been checked yet.

---

# Dry Run

Input:

```text
nums = [2, 0, 2, 1, 1, 0]
```

Initially:

```text
low = 0
mid = 0
high = 5
```

Array:

```text
[2, 0, 2, 1, 1, 0]
 ↑              ↑
L/M            H
```

---

## Step 1

```text
nums[mid] = 2
```

2 belongs on the right.

Swap `nums[mid]` and `nums[high]`.

```text
[0, 0, 2, 1, 1, 2]
 ↑              ↑
L/M            H
```

Then:

```text
high--
```

Now:

```text
low = 0
mid = 0
high = 4
```

`mid` does not increase.

---

## Step 2

```text
nums[mid] = 0
```

0 belongs on the left.

```text
swap(nums[low], nums[mid])
```

Array remains:

```text
[0, 0, 2, 1, 1, 2]
```

Then:

```text
low++;
mid++;
```

Now:

```text
low = 1
mid = 1
high = 4
```

---

## Step 3

Again:

```text
nums[mid] = 0
```

Move it to the left.

```text
[0, 0, 2, 1, 1, 2]
```

Pointers:

```text
low = 2
mid = 2
high = 4
```

---

## Step 4

```text
nums[mid] = 2
```

Move it to the right.

```text
swap(nums[mid], nums[high])
```

Array:

```text
[0, 0, 1, 1, 2, 2]
       ↑  ↑
      M   H
```

Then:

```text
high--;
```

Now:

```text
low = 2
mid = 2
high = 3
```

Again, `mid` does not increase.

---

## Step 5

```text
nums[mid] = 1
```

1 belongs in the middle.

Simply:

```text
mid++;
```

Now:

```text
low = 2
mid = 3
high = 3
```

---

## Step 6

Again:

```text
nums[mid] = 1
```

So:

```text
mid++;
```

Now:

```text
low = 2
mid = 4
high = 3
```

Condition:

```cpp
mid <= high
```

is false.

Loop ends.

---

# Final Array

```text
[0, 0, 1, 1, 2, 2]
```

---

# Visualization

At any point, think of the array like this:

```text
          low       mid       high
           ↓         ↓          ↓
[ 0 0 0 | 1 1 |  ? ? ? | 2 2 2 ]
                   ↑
               Unknown
```

The important part is the **unknown region**.

`mid` keeps reducing this unknown region.

---

# Why is it called Dutch National Flag Algorithm?

The algorithm divides the array into three regions:

```text
0 region | 1 region | 2 region
```

This is similar to dividing the three colors of the Dutch flag:

```text
Red | White | Blue
```

That's why it is commonly called the **Dutch National Flag Algorithm**.

---

# Time Complexity

We traverse the array only once.

```text
O(n)
```

---

# Space Complexity

We only use three pointers.

```text
O(1)
```

No extra array is required.

---

# Comparison with Normal Sorting

A normal sorting algorithm could take:

```text
O(n log n)
```

depending on the algorithm.

But because this problem contains only:

```text
0, 1, 2
```

we can exploit this special structure and solve it in:

```text
O(n)
```

with:

```text
O(1)
```

extra space.

---

# Learning

## Pattern

- Three Pointers
- Partitioning
- Dutch National Flag Algorithm

## Important Concepts

- `low`
- `mid`
- `high`
- Unknown Region
- In-place Sorting

---

# Golden Rule

Remember:

```text
0 → LEFT
1 → MIDDLE
2 → RIGHT
```

Pointer movement:

```text
0 → low++, mid++

1 → mid++

2 → high--
```

### Most Important Point

When:

```text
nums[mid] == 2
```

do **not** increment `mid`.

Because the element coming from `high` is still unknown.

---

# Complexity Summary

| Approach | Time | Space |
|---|---:|---:|
| Normal Sorting | O(n log n) | Depends |
| Dutch National Flag | **O(n)** | **O(1)** |

---

# Revision Question

Before looking at the code, ask yourself:

> If `nums[mid] == 0`, where should it go?

Answer:

```text
LEFT
```

> If `nums[mid] == 1`?

```text
MIDDLE
```

> If `nums[mid] == 2`?

```text
RIGHT
```

And remember:

```text
2 → high--
```

but **`mid` stays there** until the new element coming from the right is checked.