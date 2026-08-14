# 📘 Leaders in an Array

## Problem Statement

Given an array of integers, find all the **leaders** in the array.

An element is called a leader if it is **greater than all the elements to its right**.

The rightmost element is always a leader because there is no element to its right.

---

## Example

### Input

```text
10 22 12 3 0 6
```

### Output

```text
22 12 6
```

### Explanation

For:

```text
10 22 12 3 0 6
```

Check each element:

```text
10 → elements to right contain 22 → Not leader

22 → greater than 12, 3, 0, 6 → Leader

12 → greater than 3, 0, 6 → Leader

3 → 6 is greater → Not leader

0 → 6 is greater → Not leader

6 → rightmost element → Leader
```

Therefore:

```text
Leaders = [22, 12, 6]
```

---

# Optimal Approach

Instead of checking every element against all elements to its right, traverse the array from **right to left**.

We maintain:

```cpp
maxFromRight
```

This stores the maximum element we have seen so far from the right side.

---

# Core Idea

Start from the last element.

The last element is automatically a leader.

Then for every element:

```text
If current element > maxFromRight
        ↓
     Leader
```

After checking the element:

```cpp
maxFromRight = nums[i];
```

---

# Why Traverse From Right?

The definition of a leader depends on the elements **to the right**.

So instead of repeatedly looking toward the right, we process the right side first.

For example:

```text
10 22 12 3 0 6
            ↑
          Start
```

Then move:

```text
10 22 12 3 0 6
         ← ← ← ←
```

This allows us to remember the maximum value on the right.

---

# Dry Run

Consider:

```text
nums = [10, 22, 12, 3, 0, 6]
```

Initially:

```text
maxFromRight = INT_MIN
result = []
```

---

## Step 1

Current:

```text
6
```

Compare:

```text
6 > INT_MIN
```

True.

Therefore:

```text
6 is a leader
```

Add:

```text
result = [6]
```

Update:

```text
maxFromRight = 6
```

---

## Step 2

Current:

```text
0
```

Compare:

```text
0 > 6
```

False.

So:

```text
0 is not a leader
```

`maxFromRight` remains:

```text
6
```

---

## Step 3

Current:

```text
3
```

Compare:

```text
3 > 6
```

False.

Not a leader.

---

## Step 4

Current:

```text
12
```

Compare:

```text
12 > 6
```

True.

So:

```text
12 is a leader
```

Result:

```text
[6, 12]
```

Update:

```text
maxFromRight = 12
```

---

## Step 5

Current:

```text
22
```

Compare:

```text
22 > 12
```

True.

Leader.

Result:

```text
[6, 12, 22]
```

Update:

```text
maxFromRight = 22
```

---

## Step 6

Current:

```text
10
```

Compare:

```text
10 > 22
```

False.

Not a leader.

---

# Current Result

Because we traversed from right to left:

```text
result = [6, 12, 22]
```

But the original array's order should be maintained.

So reverse:

```cpp
reverse(result.begin(), result.end());
```

Final:

```text
[22, 12, 6]
```

---

# Visualization

Think of `maxFromRight` as a person standing on the right side and remembering the **tallest person seen so far**.

```text
10  22  12  3  0  6
                    ↑
                 tallest
```

Move left:

```text
10  22  12  3  0  6
                ↑
              6
```

Then:

```text
10  22  12  3  0  6
            ↑
           3 < 6
```

Not leader.

Then:

```text
10  22  12  3  0  6
         ↑
        12 > 6
```

Leader.

Then:

```text
10  22  12  3  0  6
     ↑
    22 > 12
```

Leader.

The important idea is:

```text
Current > Maximum on Right
          ↓
        Leader
```

---

# Why `maxFromRight` Works

Suppose we are checking:

```text
12
```

Elements to its right are:

```text
3 0 6
```

We don't need to compare `12` with all three separately.

We already know:

```text
maximum of right side = 6
```

So simply:

```text
12 > 6
```

If this is true, then `12` is automatically greater than every element on its right.

---

# Why Do We Reverse the Result?

We traverse:

```text
Right → Left
```

So leaders are discovered in reverse order.

For example:

```text
Original order:

22 12 6
```

During traversal we discover:

```text
6 12 22
```

Therefore:

```cpp
reverse(result.begin(), result.end());
```

gives:

```text
22 12 6
```

---

# Complexity

We traverse the array only once:

```text
Time = O(n)
```

We store the leaders in another vector:

```text
Space = O(n)
```

Therefore:

```text
Time  = O(n)
Space = O(n)
```

The output itself can contain `O(n)` elements, so this extra space is natural for the returned result.

---

# Brute Force vs Optimal

## Brute Force

For every element, check all elements to its right.

```text
Time  = O(n²)
Space = O(n)
```

## Optimal

Traverse from right to left and maintain the maximum.

```text
Time  = O(n)
Space = O(n)
```

The important optimization is:

```text
Don't repeatedly search the right side.
Remember its maximum.
```

---

# Key Learning

This problem teaches an important pattern:

```text
RIGHT → LEFT
      +
MAXIMUM SO FAR
```

Whenever a problem asks:

> "Is this element greater than everything to its right?"

Think:

```text
Traverse from right
        ↓
Maintain maximum
        ↓
Compare current with maximum
```

---

# Quick Revision

Remember:

```cpp
int maxFromRight = INT_MIN;

for (int i = n - 1; i >= 0; i--) {

    if (nums[i] > maxFromRight) {

        result.push_back(nums[i]);

        maxFromRight = nums[i];
    }
}
```

Then:

```cpp
reverse(result.begin(), result.end());
```

### Pattern

```text
RIGHT → LEFT
     ↓
MAX SO FAR
     ↓
CURRENT > MAX?
     ↓
   LEADER
```

### Complexity

```text
Time  = O(n)
Space = O(n)
```