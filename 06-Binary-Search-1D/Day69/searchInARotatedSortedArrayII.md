# Day69 — Search in Rotated Sorted Array II

## Problem

Given a rotated sorted array `nums` that may contain **duplicates**, search for a target `k`.

Return:

* `true` if `k` exists.
* `false` otherwise.

### Example

```text
Input:
nums = [2, 5, 6, 0, 0, 1, 2]
k = 0

Output:
true
```

---

# Difference Between Day68 and Day69

### Day68

Search in rotated sorted array **without duplicates**.

```text
[4, 5, 6, 7, 0, 1, 2]
```

At least one half can always be identified as sorted.

### Day69

Duplicates are allowed.

```text
[2, 5, 6, 0, 0, 1, 2]
```

Now sometimes we cannot determine which half is sorted.

This is the main difficulty of Day69.

---

# Approach — Modified Binary Search

At every iteration:

1. Find `mid`.
2. If `nums[mid] == k`, return `true`.
3. Check for duplicate ambiguity.
4. Otherwise identify the sorted half.
5. Check whether target lies inside that sorted half.
6. Eliminate the opposite half.

---

# Step 1 — Target Found

```cpp
if (nums[mid] == k) {
    return true;
}
```

If the middle element itself is the target, we're done.

---

# Step 2 — Handle Duplicate Ambiguity

This is the most important addition compared with Day68.

Suppose:

```text
nums = [1, 0, 1, 1, 1]
```

We might have:

```text
low
 ↓
[1, 0, 1, 1, 1]
        ↑     ↑
       mid   high
```

Here:

```text
nums[low] = 1
nums[mid] = 1
nums[high] = 1
```

So:

```cpp
nums[low] == nums[mid] && nums[mid] == nums[high]
```

is true.

We cannot determine whether the left or right half gives us useful sorted information.

Therefore:

```cpp
low++;
high--;
```

We safely remove the duplicate boundary elements.

```cpp
if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
    low++;
    high--;
    continue;
}
```

This is the key difference from Day68.

---

# Step 3 — Check Left Half

After removing the ambiguous duplicate case:

```cpp
if (nums[low] <= nums[mid])
```

means the left half is sorted.

Example:

```text
[4, 5, 6, 7, 0, 1, 2]
 ↑       ↑
low     mid
```

Left half:

```text
[4, 5, 6, 7]
```

is sorted.

---

# Step 4 — Is Target Inside Left Half?

If:

```cpp
nums[low] <= k && k < nums[mid]
```

then target lies in the sorted left half.

So:

```cpp
high = mid - 1;
```

Otherwise:

```cpp
low = mid + 1;
```

---

# Step 5 — Right Half is Sorted

If the left half isn't sorted, the right half is sorted.

```cpp
else
```

Check:

```cpp
nums[mid] < k && k <= nums[high]
```

If target lies in the right sorted half:

```cpp
low = mid + 1;
```

Otherwise:

```cpp
high = mid - 1;
```

---

# Dry Run

Consider:

```text
nums = [2, 5, 6, 0, 0, 1, 2]
k = 0
```

### Iteration 1

```text
low = 0
high = 6

mid = 3
nums[mid] = 0
```

Target found immediately.

```text
return true
```

---

# Duplicate Ambiguity Dry Run

Consider:

```text
nums = [1, 0, 1, 1, 1]
k = 0
```

Initially:

```text
low = 0
high = 4
mid = 2
```

Values:

```text
nums[low] = 1
nums[mid] = 1
nums[high] = 1
```

So:

```text
nums[low] == nums[mid] == nums[high]
```

We cannot identify the sorted half.

Therefore:

```text
low++
high--
```

Now:

```text
low = 1
high = 3
```

Search space becomes:

```text
[0, 1, 1]
 ↑     ↑
low   high
```

Next:

```text
mid = 2
nums[mid] = 1
```

Left half is sorted:

```text
nums[low] <= nums[mid]

0 <= 1
```

Target:

```text
k = 0
```

lies in:

```text
[nums[low], nums[mid])
```

because:

```text
0 <= 0 < 1
```

Therefore:

```text
high = mid - 1
```

Now:

```text
low = 1
high = 1
```

```text
mid = 1
nums[mid] = 0
```

Target found.

```text
return true
```

---

# Pattern Recognition

When you see:

* sorted array
* rotated
* duplicates allowed
* search for target

Think:

> **Modified Binary Search + Duplicate Handling**

The decision process:

```text
Target == mid?
       |
      YES → true
       |
      NO
       ↓
low == mid == high?
       |
      YES → low++, high--
       |
      NO
       ↓
Which half is sorted?
    /          \
 LEFT          RIGHT
  |              |
Target in      Target in
left?          right?
 /   \          /   \
Yes  No       Yes   No
 |    |        |     |
L    R         R     L
```

---

# Why Day68 Logic Alone Fails?

Day68 assumes that we can identify the sorted half.

But consider:

```text
[1, 0, 1, 1, 1]
```

We have:

```text
low = 1
mid = 1
high = 1
```

The values don't tell us whether the rotation point is on the left or right.

So this condition:

```cpp
if (nums[low] <= nums[mid])
```

doesn't provide enough information.

We first remove the duplicate ambiguity.

---

# Complexity

Normally binary search:

```text
O(log N)
```

But duplicates can cause repeated shrinking:

```cpp
low++;
high--;
```

For example:

```text
[1, 1, 1, 1, 1, 1, 1]
```

We may have to inspect many elements.

Therefore:

* Average Time: `O(log N)`
* Worst-case Time: `O(N)`
* Space: `O(1)`

This is an important interview point.

---

# Day68 vs Day69

| Feature               | Day68        | Day69               |
| --------------------- | ------------ | ------------------- |
| Rotated               | Yes          | Yes                 |
| Duplicates            | No           | Yes                 |
| Binary Search         | Yes          | Yes                 |
| Sorted-half detection | Direct       | Sometimes ambiguous |
| Duplicate handling    | Not required | Required            |
| Worst-case            | `O(log N)`   | `O(N)`              |
| Space                 | `O(1)`       | `O(1)`              |

---

# Connection With Previous Days

### Day61

Normal Binary Search

```text
Sorted Array
→ Binary Search
```

### Day66

First & Last Position

```text
Find boundaries using Binary Search
```

### Day67

Count Occurrences

```text
Last - First + 1
```

### Day68

Rotated Sorted Array

```text
Find sorted half
→ Search target
```

### Day69

Rotated Sorted Array + Duplicates

```text
Duplicate ambiguity
→ remove boundaries
→ find sorted half
→ search target
```

So the progression is:

```text
Normal Binary Search
        ↓
Boundary Binary Search
        ↓
Rotated Binary Search
        ↓
Rotated Binary Search + Duplicates
```

---

# Common Mistakes

## 1. Forgetting duplicate handling

Don't directly apply Day68 code.

You need:

```cpp
if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
    low++;
    high--;
    continue;
}
```

---

## 2. Using `return mid` instead of `return true`

The function returns:

```cpp
bool
```

Therefore:

```cpp
return true;
```

when target is found.

And:

```cpp
return false;
```

when the search finishes.

---

## 3. Assuming complexity is always O(log N)

Because of duplicates:

```text
Worst case = O(N)
```

This is one of the key interview differences between Day68 and Day69.

---

# One-Line Revision

> **Rotated + duplicates → first handle `low == mid == high`, then find the sorted half.**

### Memory Trick

```text
Day68:
Sorted half → Search

Day69:
Same + Duplicates → Shrink → Sorted half → Search
```
