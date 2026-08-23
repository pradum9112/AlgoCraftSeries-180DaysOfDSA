# 📘 Day 51 — 3Sum

## Problem Statement

Given an integer array `nums`, find all unique triplets:

```text
[a, b, c]
```

such that:

```text
a + b + c = 0
```

The answer must not contain duplicate triplets.

---

# Example

### Input

```text
6
-1 0 1 2 -1 -4
```

### Output

```text
[-1 -1 2]
[-1 0 1]
```

Because:

```text
-1 + -1 + 2 = 0

-1 + 0 + 1 = 0
```

---

# Approach 1 — Brute Force

The most direct approach is to select three elements.

```text
i
 ↓
j
 ↓
k
```

We use three loops:

```cpp
for (int i = 0; i < n; i++) {

    for (int j = i + 1; j < n; j++) {

        for (int k = j + 1; k < n; k++) {

            if (nums[i] + nums[j] + nums[k] == 0) {
                ...
            }
        }
    }
}
```

Whenever the sum is zero, we have found a valid triplet.

---

## Why do we sort the triplet?

Suppose we find:

```text
[1, -1, 0]
```

Another iteration might find:

```text
[-1, 0, 1]
```

They are actually the same triplet.

So we sort every triplet:

```text
[-1, 0, 1]
```

Now both become identical.

Then:

```cpp
set<vector<int>> st;
```

automatically removes duplicates.

---

## Complexity

```text
Three loops → O(n³)

Sorting each triplet → O(1)
because there are only 3 elements.

Total:

Time = O(n³)
```

---

# Approach 2 — HashSet

We can remove one loop.

Instead of searching for the third element with another loop, use a HashSet.

Suppose:

```text
nums[i] + nums[j] + third = 0
```

Then:

```text
third = -(nums[i] + nums[j])
```

So after fixing `i` and `j`, we calculate what number is required.

```cpp
int third = -(nums[i] + nums[j]);
```

Then ask:

```cpp
if (hashset.find(third) != hashset.end())
```

If it exists, we found a valid triplet.

---

# Why HashSet Works

Suppose:

```text
nums = [-1, 0, 1]
```

Fix:

```text
i = -1
j = 0
```

We need:

```text
third = -(-1 + 0)
```

Therefore:

```text
third = 1
```

If `1` is already present in our HashSet:

```text
-1 + 0 + 1 = 0
```

So we found a triplet.

---

## Complexity

Two loops:

```text
O(n²)
```

HashSet lookup is average:

```text
O(1)
```

Therefore:

```text
Time = O(n²) average
Space = O(n)
```

We improved the time dramatically, but we are using extra memory.

---

# Approach 3 — Sorting + Two Pointer

This is the optimal approach.

The key idea is:

```text
Sort the array
       ↓
Fix one element
       ↓
Use two pointers for the remaining two elements
```

---

# Step 1 — Sort

Example:

```text
Original:

[-1, 0, 1, 2, -1, -4]
```

After sorting:

```text
[-4, -1, -1, 0, 1, 2]
```

Now the array has an important property:

```text
left → smaller values
right → larger values
```

This allows us to intelligently move the pointers.

---

# Step 2 — Fix One Element

Suppose:

```text
i = -1
```

We now need two numbers whose sum is:

```text
0 - (-1)
```

which is:

```text
1
```

So we need:

```text
nums[left] + nums[right] = 1
```

---

# Step 3 — Two Pointers

Start:

```text
left = i + 1
right = n - 1
```

For:

```text
[-4, -1, -1, 0, 1, 2]
```

if:

```text
i = -1
```

we have:

```text
       i   left           right
       ↓    ↓               ↓
[-4,  -1,  -1,  0,  1,    2]
```

Calculate:

```text
sum = nums[i] + nums[left] + nums[right]
```

---

# The Three Cases

## Case 1 — sum == 0

We found the answer.

```cpp
ans.push_back({
    nums[i],
    nums[left],
    nums[right]
});
```

Then move both pointers:

```text
left++
right--
```

---

## Case 2 — sum < 0

Our sum is too small.

Example:

```text
sum = -3
```

Because the array is sorted, increasing `left` gives us a larger number.

Therefore:

```cpp
left++;
```

Visualization:

```text
small ← left       right
```

Move:

```text
left →
```

to increase the sum.

---

## Case 3 — sum > 0

Our sum is too large.

Because the array is sorted, decreasing `right` gives us a smaller number.

Therefore:

```cpp
right--;
```

Visualization:

```text
left       right →
                 smaller
```

Move:

```text
right ←
```

to decrease the sum.

---

# Dry Run

Array:

```text
[-1, 0, 1, 2, -1, -4]
```

Sorted:

```text
[-4, -1, -1, 0, 1, 2]
```

---

## i = 0

```text
nums[i] = -4
```

Start:

```text
left = 1
right = 5
```

Values:

```text
-4 + (-1) + 2 = -3
```

Sum is negative:

```text
-3 < 0
```

Therefore:

```text
left++
```

---

Next:

```text
-4 + (-1) + 2 = -3
```

Again:

```text
left++
```

Continue moving `left`.

Since `-4` is too small, no valid triplet can be formed with it.

---

## i = 1

```text
nums[i] = -1
```

Start:

```text
left = 2
right = 5
```

Values:

```text
-1 + (-1) + 2 = 0
```

Found:

```text
[-1, -1, 2]
```

Move:

```text
left++
right--
```

Now:

```text
left = 3
right = 4
```

Calculate:

```text
-1 + 0 + 1 = 0
```

Found:

```text
[-1, 0, 1]
```

Move both pointers.

Now:

```text
left >= right
```

Stop.

---

# Why Skip Duplicates?

Consider:

```text
[-1, -1, 0, 1, 2]
```

If we use the first `-1` and then use the second `-1` as another starting point, we may generate duplicate triplets.

Therefore:

```cpp
if (i > 0 && nums[i] == nums[i - 1])
    continue;
```

means:

```text
Same starting value?
Skip it.
```

---

# Duplicate Left and Right Values

After finding a valid triplet, we also skip duplicate values:

```cpp
while (left < right &&
       nums[left] == nums[left + 1]) {
    left++;
}
```

and:

```cpp
while (left < right &&
       nums[right] == nums[right - 1]) {
    right--;
}
```

This ensures unique triplets.

---

# Why Sorting Is So Powerful Here

Sorting gives us two major benefits:

### 1. Duplicate handling

Equal values become adjacent:

```text
-1 -1 -1
```

So we can skip them easily.

### 2. Two-pointer movement

Because:

```text
left side → smaller
right side → larger
```

we know exactly which pointer to move.

```text
sum < 0
   ↓
Need larger value
   ↓
left++

sum > 0
   ↓
Need smaller value
   ↓
right--
```

This is the core reason the two-pointer approach works.

---

# Three Approaches Comparison

| Approach | Time | Extra Space | Main Idea |
|---|---:|---:|---|
| Brute Force | O(n³) | Output/Set | Check every triplet |
| HashSet | O(n²) average | O(n) | Find required third value |
| **Two Pointer** | **O(n²)** | **O(1)** | Sort + two pointers |

---

# Learning Progression

Day 51 is a very important optimization pattern:

```text
Brute Force
    ↓
3 loops
    ↓
O(n³)

        ↓ optimization

HashSet
    ↓
Remove one loop
    ↓
O(n²)
    ↓
Extra O(n) space

        ↓ optimization

Sorting + Two Pointer
    ↓
O(n²)
    ↓
O(1) extra space
```

---

# Key Pattern to Remember

When you see:

```text
Find 3 numbers
whose sum = target
```

think:

```text
Fix one number
        ↓
2-Sum problem remains
        ↓
Sort
        ↓
Two Pointer
```

For 3Sum:

```text
nums[i] + nums[left] + nums[right] = 0
```

Then:

```text
sum < 0  → left++

sum > 0  → right--

sum == 0 → store answer + move both
```

---

# Final Complexity

### Brute Force

```text
Time  = O(n³)
```

### HashSet

```text
Time  = O(n²) average
Space = O(n)
```

### Optimal

```text
Time  = O(n²)
Space = O(1) extra
```

---

# Day 51 Learning Focus

The most important thing to remember is not the code.

Remember this transformation:

```text
3Sum
  ↓
Fix one number
  ↓
Remaining problem = 2Sum
  ↓
Sorted array
  ↓
Two pointers
```

And the pointer rule:

```text
sum < 0  → left++
sum > 0  → right--
sum == 0 → answer found
```