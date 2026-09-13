# Day68 — Search in Rotated Sorted Array

## Problem

Given a sorted array that has been rotated at some pivot, search for a target `k`.

Return the index of `k` if it exists. Otherwise return `-1`.

### Example

```text
Input:
nums = [4, 5, 6, 7, 0, 1, 2]
k = 0

Output:
4
```

---

# What is a Rotated Sorted Array?

Original sorted array:

```text
[0, 1, 2, 4, 5, 6, 7]
```

After rotation:

```text
[4, 5, 6, 7, 0, 1, 2]
```

The complete array is no longer sorted.

But there is an important property:

> At every binary-search step, at least one half is sorted.

For example:

```text
[4, 5, 6, 7, 0, 1, 2]
 ↑       ↑   ↑       ↑
low     mid       high
```

Left half:

```text
[4, 5, 6, 7]
```

is sorted.

Right half:

```text
[0, 1, 2]
```

is also sorted in this example.

In other iterations, only one side may be clearly sorted.

---

# Approach — Modified Binary Search

Normal binary search assumes the complete search range is sorted.

Here the complete array is not sorted, so we cannot directly compare `k` with `nums[mid]` and decide one side.

Instead:

1. Find `mid`.
2. Check whether left half is sorted.
3. If left half is sorted, check whether target belongs to that range.
4. Otherwise search the right half.
5. If left half is not sorted, right half must be sorted.
6. Check whether target belongs to the right sorted range.
7. Otherwise search the left half.

---

# Step 1 — Target Found

```cpp
if (nums[mid] == k) {
    return mid;
}
```

Nothing more to do.

---

# Step 2 — Check Left Half

```cpp
if (nums[low] <= nums[mid])
```

If this is true, the left half is sorted.

Example:

```text
[4, 5, 6, 7, 0, 1, 2]
 ↑       ↑
low     mid
```

```text
nums[low] = 4
nums[mid] = 7
```

Since:

```text
4 <= 7
```

left half is sorted:

```text
[4, 5, 6, 7]
```

---

# Step 3 — Is Target Inside Sorted Left Half?

If left half is sorted:

```cpp
if (nums[low] <= k && k < nums[mid])
```

Then target is inside the left half.

So:

```cpp
high = mid - 1;
```

Otherwise target must be on the right:

```cpp
low = mid + 1;
```

---

# Step 4 — Right Half is Sorted

If:

```cpp
nums[low] > nums[mid]
```

then the left half is not sorted, so the right half is sorted.

Example:

```text
[6, 7, 0, 1, 2, 4, 5]
 ↑       ↑       ↑
low     mid     high
```

Right half:

```text
[1, 2, 4, 5]
```

is sorted.

Now check whether target lies in this range:

```cpp
if (nums[mid] < k && k <= nums[high])
```

If yes:

```cpp
low = mid + 1;
```

Otherwise:

```cpp
high = mid - 1;
```

---

# Dry Run

```text
nums = [4, 5, 6, 7, 0, 1, 2]
k = 0
```

### Iteration 1

```text
low = 0
high = 6
mid = 3

nums[mid] = 7
```

Target `0` is not `7`.

Check left half:

```text
nums[low] <= nums[mid]

4 <= 7
```

True.

Therefore left half is sorted:

```text
[4, 5, 6, 7]
```

Is `0` inside this range?

```text
4 <= 0 && 0 < 7
```

False.

Therefore target is on the right:

```text
low = mid + 1
```

Now:

```text
low = 4
high = 6
```

---

### Iteration 2

```text
[4, 5, 6, 7, 0, 1, 2]
             ↑     ↑
            low   high
```

```text
mid = 5
nums[mid] = 1
```

Target `0` is not `1`.

Check left half:

```text
nums[low] <= nums[mid]

0 <= 1
```

True.

Left half is sorted:

```text
[0, 1]
```

Is target `0` inside it?

```text
0 <= 0 && 0 < 1
```

True.

So:

```text
high = mid - 1
```

```text
high = 4
```

---

### Iteration 3

```text
low = 4
high = 4
mid = 4

nums[mid] = 0
```

Target found.

```text
return 4;
```

### Answer

```text
4
```

---

# Pattern Recognition

Whenever you see:

* sorted array
* rotated array
* search for a target
* `O(log N)` expected

Immediately think:

> **Modified Binary Search**

The most important question at every iteration is:

```text
Which half is sorted?
```

Then:

```text
Does target belong to that sorted half?
```

---

# Important Logic

Remember this decision tree:

```text
                Find mid
                   |
             nums[mid] == k?
                /       \
              Yes       No
              |          |
           return      Which half
                        is sorted?
                       /           \
                Left sorted    Right sorted
                    |               |
              Target in left?   Target in right?
                /     \           /       \
              Yes     No        Yes       No
               |       |         |          |
          high=mid-1 low=mid+1 low=mid+1 high=mid-1
```

---

# Why Normal Binary Search Does Not Work?

Normal binary search does:

```text
if target < nums[mid]
    go left
else
    go right
```

This depends on the **whole search range being sorted**.

For:

```text
[4, 5, 6, 7, 0, 1, 2]
```

that assumption is false.

So we first identify the sorted half and use that half's boundaries to decide where the target can exist.

---

# Complexity

At every iteration, approximately half of the search space is eliminated.

Therefore:

```text
Time  = O(log N)
Space = O(1)
```

This is the main advantage over linear search `O(N)`.

---

# Connection With Previous Days

Day61:

```text
Search in Sorted Array
→ Normal Binary Search
```

Day62:

```text
Lower Bound
→ First index where arr[i] >= target
```

Day63:

```text
Upper Bound
→ First index where arr[i] > target
```

Day64:

```text
Search Insert Position
→ Lower-bound style binary search
```

Day65:

```text
Floor & Ceil
→ Binary Search
```

Day66:

```text
First & Last Position
→ Binary Search
```

Day67:

```text
Count Occurrences
→ First + Last Position
```

Day68:

```text
Rotated Sorted Array
→ Modified Binary Search
```

So Day68 is an important jump:

> **Normal Binary Search → Modified Binary Search**

---

# Common Mistakes

### 1. Forgetting the sorted-half check

Don't directly do:

```cpp
if (k < nums[mid])
```

First determine which half is sorted.

---

### 2. Wrong left-half condition

Correct:

```cpp
nums[low] <= nums[mid]
```

This includes the case where:

```text
low == mid
```

which can happen when only one element remains.

---

### 3. Wrong target range

For sorted left half:

```cpp
nums[low] <= k && k < nums[mid]
```

Notice the upper boundary is `< nums[mid]`.

Why?

Because:

```cpp
nums[mid] == k
```

was already checked at the beginning.

For sorted right half:

```cpp
nums[mid] < k && k <= nums[high]
```

---

# One-Line Revision

> **Rotated array → find the sorted half → check target range → eliminate the other half.**

### Memory Trick

```text
LEFT SORTED  → target in [low, mid)  → LEFT
RIGHT SORTED → target in (mid, high] → RIGHT
```
