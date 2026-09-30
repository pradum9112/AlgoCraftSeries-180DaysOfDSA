# Day 84 — Find Peak Element

## 📌 Problem

Given an array `arr`, find the index of a **peak element**.

An element is a peak if it is greater than its adjacent elements.

For an element at index `i`:

```text
arr[i] > arr[i - 1]
AND
arr[i] > arr[i + 1]
```

For boundary elements, only the existing neighbor needs to be considered.

Return the index of any valid peak element.

### Example

```text
Input:
arr = [1, 2, 3, 1]

Output:
2
```

Because:

```text
arr[2] = 3
```

and:

```text
3 > 2
3 > 1
```

Therefore index `2` is a peak.

---

# 🔹 Approach 1 — Linear Search

## 💡 Idea

We can simply check every possible position.

First handle the boundary cases:

```text
First element
Last element
```

Then check every middle element.

For a middle element `i`, check:

```text
arr[i] > arr[i-1]
AND
arr[i] > arr[i+1]
```

The first element satisfying this condition is a valid peak.

---

## 🧠 Pattern Recognition Clue

When a problem asks:

> **Find an element satisfying a local condition**

first ask:

```text
Can I check every position?
```

Here, a peak can be verified using only its neighbors.

So the direct pattern is:

```text
Check each index
      ↓
Compare with neighbors
      ↓
Return first valid peak
```

However, this problem has an additional property that allows us to do better than linear search.

---

## 🔄 Dry Run

Consider:

```text
arr = [1, 2, 3, 1]
```

### Index 0

```text
1 > 2
```

False.

---

### Index 1

```text
2 > 1  → true
2 > 3  → false
```

Not a peak.

---

### Index 2

```text
3 > 2  → true
3 > 1  → true
```

Peak found.

```text
Answer = 2
```

---

## ⏱️ Time Complexity

We may check every element:

```text
O(N)
```

## 💾 Space Complexity

No additional data structure is used:

```text
O(1)
```

---

# 🔹 Approach 2 — Binary Search

## 💡 Key Observation

The important observation is the **slope around `mid`**.

Suppose:

```text
arr[mid] > arr[mid - 1]
```

Then we are currently moving upward.

There are two possibilities:

```text
        / 
       /
      /     → eventually reaches a peak
```

or the array may continue increasing.

In either case, there must be a peak on the **right side**.

So:

```text
arr[mid] > arr[mid - 1]
        ↓
Peak lies on right
        ↓
low = mid + 1
```

On the other hand, if:

```text
arr[mid] < arr[mid - 1]
```

we are moving downward.

Therefore a peak exists on the **left side**, including potentially around `mid`.

So:

```text
arr[mid] < arr[mid - 1]
        ↓
Peak lies on left
        ↓
high = mid - 1
```

---

# 🧠 Pattern Recognition — Important

This is a useful Binary Search pattern that is slightly different from ordinary sorted-array Binary Search.

The array itself **does not need to be sorted**.

Instead, we use the **direction/slope** to eliminate half of the search space.

Ask yourself:

### Step 1

Can I determine something about the answer by comparing neighboring elements?

```text
arr[mid] vs arr[mid-1]
arr[mid] vs arr[mid+1]
```

### Step 2

Does that comparison tell me which side contains a peak?

Yes.

Therefore:

```text
Local slope
    ↓
Determine direction
    ↓
Discard half
    ↓
Binary Search
```

### 🔑 Recognition Clue

Whenever you see a problem involving:

* peak
* mountain
* increasing/decreasing slope
* local maximum
* local minimum
* bitonic behavior

ask:

> **Can the direction around `mid` tell me which half contains the answer?**

If yes, Binary Search may be possible even when the entire array is not sorted.

---

# 🔄 Binary Search Dry Run

Consider:

```text
arr = [1, 2, 3, 1]
```

Boundary checks:

```text
arr[0] > arr[1]?
1 > 2 → false

arr[3] > arr[2]?
1 > 3 → false
```

So search:

```text
low = 1
high = 2
```

---

### Step 1

```text
mid = 1
```

Values:

```text
arr[mid] = 2
arr[mid-1] = 1
arr[mid+1] = 3
```

Check:

```text
2 > 1 → true
```

But:

```text
2 > 3 → false
```

So `mid` isn't a peak.

Since:

```text
arr[mid] > arr[mid-1]
```

we are on an increasing slope.

Therefore:

```text
peak lies on right
```

Move:

```text
low = mid + 1
```

So:

```text
low = 2
high = 2
```

---

### Step 2

```text
mid = 2
```

Check:

```text
arr[2] > arr[1]
3 > 2 → true

arr[2] > arr[3]
3 > 1 → true
```

Peak found.

```text
Answer = 2
```

---

# 📌 Why the Binary Search Works

Imagine the array like a landscape:

```text
       /\
      /  \
     /    \
____/      \____
```

If you stand on an increasing slope:

```text
arr[mid] > arr[mid-1]
```

there must be a peak somewhere to the right.

If you stand on a decreasing slope:

```text
arr[mid] < arr[mid-1]
```

there must be a peak somewhere to the left.

This lets us discard half of the search space at every step.

---

# ⚖️ Approach Comparison

| Feature                  | Linear Search     | Binary Search |
| ------------------------ | ----------------- | ------------- |
| Technique                | Sequential Search | Binary Search |
| Array Sorted Required    | ❌                 | ❌             |
| Uses Neighbor Comparison | ✅                 | ✅             |
| Search Space Reduction   | ❌                 | ✅             |
| Time                     | `O(N)`            | `O(log N)`    |
| Space                    | `O(1)`            | `O(1)`        |
| Optimal                  | ❌                 | ✅             |

---

# 🚨 Edge Cases

### 1. Single element

```text
arr = [5]
```

The only element is a peak.

```text
Answer = 0
```

---

### 2. First element is peak

```text
arr = [5, 3, 2, 1]
```

Since:

```text
5 > 3
```

index `0` is a peak.

---

### 3. Last element is peak

```text
arr = [1, 2, 3, 5]
```

Since:

```text
5 > 3
```

index `3` is a peak.

---

### 4. Peak in the middle

```text
arr = [1, 2, 5, 3, 4]
```

Index `2` is a peak because:

```text
5 > 2
5 > 3
```

---

# 🔧 Code Variations

## Variation 1 — Linear

The main idea is simply:

```text
Check every index
→ compare with neighbors
→ return when peak found
```

Complexity:

```text
O(N)
```

---

## Variation 2 — Binary Search

The optimized idea is:

```text
mid is peak
        ↓
      return

otherwise

increasing slope
        ↓
    search right

decreasing slope
        ↓
    search left
```

Complexity:

```text
O(log N)
```

---

# 🎯 Core Pattern to Remember

The biggest learning from this problem is **not simply finding a peak**.

Remember:

```text
Array is NOT sorted
        ↓
But local slope gives information
        ↓
Increasing → go right
Decreasing → go left
        ↓
Discard half
        ↓
Binary Search
```

### Pattern

**Binary Search using slope / local direction**

### Optimal Complexity

```text
Time:  O(log N)
Space: O(1)
```

---

# 🧠 What I Learned

* A peak element is greater than its adjacent elements.
* Linear Search can directly check every position.
* Boundary elements need separate handling.
* The array does not have to be globally sorted for Binary Search.
* The local slope around `mid` tells us where a peak must exist.
* Increasing slope → search right.
* Decreasing slope → search left.
* This allows us to discard half of the search space.
* The optimized solution reduces:

```text
O(N) → O(log N)
```

---

# 🎯 Revision Shortcut

```text
Find Peak
    ↓
Check boundaries
    ↓
mid
    ↓
Is mid a peak?
    ├── YES → return mid
    │
    └── NO
         ↓
    arr[mid] > arr[mid-1] ?
         ├── YES → RIGHT
         └── NO  → LEFT
```

**Pattern:** `Binary Search on Local Slope`

**Optimal:** `O(log N)` time, `O(1)` space.
