# Day 66 — Find First and Last Position of Element in Sorted Array

## Problem

Given a sorted array `nums` and a target value `target`, find the **first and last position** of the target.

If the target does not exist, return:

```text
[-1, -1]
```

### Example

```text
Input:
nums = [5, 7, 7, 8, 8, 10]
target = 8

Output:
[3, 4]
```

---

## Approach 1 — Linear Search

Traverse the complete array.

* Initially `first = -1` and `last = -1`.
* Whenever `nums[i] == target`:

  * If this is the first occurrence, store `first = i`.
  * Keep updating `last = i`.
* At the end, return `{first, last}`.

### Complexity

* **Time:** `O(N)`
* **Space:** `O(1)`

### Important Correction

A simple linear-search implementation like:

```cpp
if (nums[i] == target)
    return {i, i + 1};
```

is incorrect.

For:

```text
[5, 7, 7, 8, 8, 10]
```

target `8` occurs at indices `3` and `4`, so the answer must be:

```text
[3, 4]
```

not:

```text
[3, 4]
```

by coincidence only. For three or more occurrences, `i + 1` would fail.

The correct idea is to keep updating `last`.

---

## Approach 2 — Binary Search

Because the array is sorted, we can use binary search.

We perform **two binary searches**:

1. Find the **first occurrence**
2. Find the **last occurrence**

A helper function `findBound()` handles both cases.

### Finding First Occurrence

When:

```cpp
nums[mid] == target
```

we found the target, but there may be another target on the left.

So:

```cpp
ans = mid;
high = mid - 1;
```

We continue searching left.

### Finding Last Occurrence

When:

```cpp
nums[mid] == target
```

we found the target, but there may be another target on the right.

So:

```cpp
ans = mid;
low = mid + 1;
```

We continue searching right.

### Complexity

Each binary search takes `O(log N)`.

We perform two searches:

* **Time:** `O(log N)`
* **Space:** `O(1)`

---

## Dry Run

```text
nums = [5, 7, 7, 8, 8, 10]
target = 8
```

### First Occurrence

Search for `8`.

```text
low = 0
high = 5
mid = 2

nums[2] = 7 < 8
low = 3
```

Now:

```text
low = 3
high = 5
mid = 4

nums[4] = 8
```

Target found.

Store:

```text
ans = 4
```

Because we need the **first** occurrence, search left:

```text
high = 3
```

Now:

```text
low = 3
high = 3
mid = 3

nums[3] = 8
```

Again target found.

```text
ans = 3
high = 2
```

Search ends.

Therefore:

```text
first = 3
```

### Last Occurrence

Search again.

Eventually:

```text
mid = 4
nums[4] = 8
```

Target found:

```text
ans = 4
```

Because we need the **last** occurrence, search right:

```text
low = 5
```

`nums[5] = 10 > 8`, so search ends.

Therefore:

```text
last = 4
```

Final answer:

```text
[3, 4]
```

---

## Pattern Recognition

This Day is directly connected to the previous binary-search days.

| Day   | Problem                | Binary Search Condition             |
| ----- | ---------------------- | ----------------------------------- |
| Day62 | Lower Bound            | First `>= x`                        |
| Day63 | Upper Bound            | First `> x`                         |
| Day64 | Search Insert Position | First `>= target`                   |
| Day65 | Floor & Ceil           | Largest `<= x`, smallest `>= x`     |
| Day66 | First & Last Position  | First `== target`, Last `== target` |

### Key Pattern

Whenever the question says:

* first occurrence
* last occurrence
* first position
* last position
* leftmost
* rightmost

think:

> **Binary Search + Continue Searching After Finding Target**

Finding the target once is not enough.

The important question is:

> "Target mil gaya, ab kis direction mein aur search karna hai?"

* **First occurrence → go LEFT**
* **Last occurrence → go RIGHT**

---

## Main Idea to Remember

Normal binary search:

```text
Target mil gaya → return
```

Boundary binary search:

```text
Target mil gaya
        ↓
Answer store karo
        ↓
Aur boundary search karo
```

For first:

```text
target found → left
```

For last:

```text
target found → right
```

This is the main concept of Day66.

---

## Common Mistakes

### 1. Target milte hi return kar dena

```cpp
if (nums[mid] == target)
    return mid;
```

This only finds **an occurrence**, not necessarily the first or last.

### 2. Linear search mein `i + 1` ko last index maan lena

```cpp
return {i, i + 1};
```

This fails when the target appears more than twice.

### 3. First occurrence ke liye right jana

First occurrence chahiye, so target milne ke baad:

```cpp
high = mid - 1;
```

### 4. Last occurrence ke liye left jana

Last occurrence chahiye, so target milne ke baad:

```cpp
low = mid + 1;
```

---

## Test Cases

### Test 1

```text
nums = [5, 7, 7, 8, 8, 10]
target = 8

Output:
[3, 4]
```

### Test 2

```text
nums = [5, 7, 7, 8, 8, 10]
target = 6

Output:
[-1, -1]
```

### Test 3

```text
nums = [1]
target = 1

Output:
[0, 0]
```

### Test 4

```text
nums = [2, 2, 2, 2]
target = 2

Output:
[0, 3]
```

### Test 5

```text
nums = []
target = 5

Output:
[-1, -1]
```

---

## What I Learned

* Binary search can find **boundaries**, not just an element.
* First occurrence requires continuing toward the **left**.
* Last occurrence requires continuing toward the **right**.
* A helper function can avoid duplicating binary-search logic.
* Sorted arrays allow us to reduce the search from `O(N)` to `O(log N)`.

### One-Line Revision

> **First = target mile → LEFT, Last = target mile → RIGHT.**
