# Day 63 — Upper Bound

## Problem Statement

Given a sorted array `nums` and an integer `x`, find the **index of the first element strictly greater than `x`**.

If no such element exists, return `n`, where `n` is the size of the array.

---

## Example

```text
Input:
nums = [1, 2, 4, 4, 6, 8]
x = 4

Output:
4
```

Array:

```text
Index:  0  1  2  3  4  5
Array: [1, 2, 4, 4, 6, 8]
                    ↑
                    4
```

Index `4` par `6 > 4` hai.

Isliye answer `4`.

---

# What is Upper Bound?

Upper Bound means:

> **First index `i` such that `nums[i] > x`.**

Notice the important difference:

```text
Lower Bound:
nums[i] >= x

Upper Bound:
nums[i] > x
```

---

# Lower Bound vs Upper Bound

For:

```text
nums = [1, 2, 4, 4, 6, 8]
x = 4
```

### Lower Bound

First element `>= 4`:

```text
[1, 2, 4, 4, 6, 8]
       ↑
       2
```

Answer:

```text
2
```

### Upper Bound

First element `> 4`:

```text
[1, 2, 4, 4, 6, 8]
               ↑
               4
```

Answer:

```text
4
```

So:

```text
Lower Bound = 2
Upper Bound = 4
```

---

# Pattern Recognition

Question mein agar dikhe:

* Sorted array
* First element greater than `x`
* Strictly greater than
* `> x`

Immediately think:

```text
Sorted Array
     ↓
First position
     ↓
nums[i] > x
     ↓
Upper Bound
     ↓
Binary Search
```

### Pattern Clue

```text
First >= x  → Lower Bound

First > x   → Upper Bound
```

---

# Approach 1 — Linear Search

## Idea

Array ko left se right traverse karo.

Jahan pehli baar:

```cpp
nums[i] > x
```

mile, wahi answer hai.

Agar koi element greater nahi mila:

```cpp
return n;
```

## Code

```cpp
class Solution {
public:
    int upperBound(vector<int>& nums, int x) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > x)
                return i;
        }

        return n;
    }
};
```

## Dry Run

```text
nums = [1, 2, 4, 4, 6, 8]
x = 4
```

|  i | nums[i] | nums[i] > 4? |
| -: | ------: | ------------ |
|  0 |       1 | No           |
|  1 |       2 | No           |
|  2 |       4 | No           |
|  3 |       4 | No           |
|  4 |       6 | Yes          |

Therefore:

```text
Answer = 4
```

## Complexity

```text
Time  = O(N)
Space = O(1)
```

---

# Approach 2 — Binary Search

Array sorted hai, therefore Binary Search use kar sakte hain.

Maintain:

```cpp
int ans = n;
```

Initially assume karte hain ki koi element `> x` nahi mila.

---

## Case 1 — `nums[mid] > x`

Current `mid` valid answer hai.

```cpp
ans = mid;
```

But hume **first** valid position chahiye.

Isliye left search karo:

```cpp
high = mid - 1;
```

---

## Case 2 — `nums[mid] <= x`

Current element valid nahi hai.

Because array sorted hai, `mid` ke left ke elements bhi:

```text
<= nums[mid] <= x
```

hon­ge.

Therefore left side mein answer impossible hai.

Move right:

```cpp
low = mid + 1;
```

---

# Binary Search Code

```cpp
class Solution {
public:
    int upperBound(vector<int>& nums, int x) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
```

---

# Detailed Dry Run

```text
nums = [1, 2, 4, 4, 6, 8]
x = 4
```

Initial:

```text
low = 0
high = 5
ans = 6
```

### Iteration 1

```text
mid = 2
nums[2] = 4
```

Check:

```text
4 > 4 → false
```

Therefore:

```text
low = mid + 1
low = 3
```

---

### Iteration 2

```text
low = 3
high = 5

mid = 4
nums[4] = 6
```

Check:

```text
6 > 4 → true
```

So:

```text
ans = 4
high = 3
```

---

### Iteration 3

```text
low = 3
high = 3

mid = 3
nums[3] = 4
```

Check:

```text
4 > 4 → false
```

Therefore:

```text
low = 4
```

Now:

```text
low = 4
high = 3
```

Loop ends.

Final:

```text
ans = 4
```

Therefore:

```text
Answer = 4
```

---

# Why `high = mid - 1`?

Suppose:

```text
nums = [1, 2, 5, 5, 5, 7]
x = 5
```

Suppose:

```text
mid = 5
nums[mid] = 7
```

`7 > 5`, so index `5` is valid.

But perhaps index `2`, `3`, or `4` could also be valid.

Therefore:

```cpp
ans = mid;
high = mid - 1;
```

We search left for an earlier valid index.

---

# Why `low = mid + 1`?

Suppose:

```text
nums[mid] = 5
x = 5
```

Condition:

```text
5 > 5 → false
```

So `mid` is not valid.

And because the array is sorted, everything before `mid` is also `<= 5`.

Therefore answer must be to the right:

```cpp
low = mid + 1;
```

---

# Why `ans = n`?

Consider:

```text
nums = [1, 2, 3, 4]
x = 10
```

There is no element:

```text
> 10
```

So Upper Bound is:

```text
n = 4
```

That's why:

```cpp
int ans = n;
```

is used.

---

# Important Edge Cases

## 1. `x` smaller than every element

```text
nums = [5, 6, 7, 8]
x = 2
```

Answer:

```text
0
```

Because `nums[0] = 5 > 2`.

---

## 2. `x` equal to duplicate elements

```text
nums = [1, 3, 3, 3, 5]
x = 3
```

Upper Bound:

```text
4
```

because index `4` is the first position where:

```text
5 > 3
```

---

## 3. `x` greater than every element

```text
nums = [1, 2, 3, 4]
x = 10
```

Answer:

```text
4
```

---

# Common Mistakes

### Mistake 1 — Using `>=`

Wrong for Upper Bound:

```cpp
if (nums[mid] >= x)
```

Correct:

```cpp
if (nums[mid] > x)
```

---

### Mistake 2 — Going left incorrectly

Wrong:

```cpp
high = mid;
```

Correct:

```cpp
high = mid - 1;
```

Once `mid` has already been saved as an answer, we need to search strictly before it.

---

### Mistake 3 — Moving `high` when condition is false

Wrong:

```cpp
else
    high--;
```

Correct:

```cpp
else
    low = mid + 1;
```

Because when:

```text
nums[mid] <= x
```

the answer must be on the **right**.

---

# Complexity Comparison

| Approach      |         Time | Space |
| ------------- | -----------: | ----: |
| Linear Search |         O(N) |  O(1) |
| Binary Search | **O(log N)** |  O(1) |

---

# Lower Bound + Upper Bound Together

Ye dono ab ek saath yaad karo:

```text
Lower Bound
    ↓
First nums[i] >= x
```

```text
Upper Bound
    ↓
First nums[i] > x
```

Example:

```text
nums = [1, 2, 4, 4, 4, 6, 8]
x = 4
```

```text
Lower Bound → index 2
Upper Bound → index 5
```

Visual:

```text
          Lower                 Upper
            ↓                     ↓
[1, 2, | 4, 4, 4 |, 6, 8]
       2           5
```

---

# Very Important Connection

Duplicate elements ke case mein:

```text
Count of x
=
Upper Bound(x) - Lower Bound(x)
```

For:

```text
[1, 2, 4, 4, 4, 6, 8]
```

and `x = 4`:

```text
Upper Bound = 5
Lower Bound = 2

Count = 5 - 2
      = 3
```

Ye Lower Bound aur Upper Bound ka bahut important application hai.

---

# Final Cheat Sheet

```text
LOWER BOUND
First index where:
nums[i] >= x
```

```text
UPPER BOUND
First index where:
nums[i] > x
```

Binary Search:

```cpp
if (nums[mid] > x) {
    ans = mid;
    high = mid - 1;
}
else {
    low = mid + 1;
}
```

### Pattern

```text
Sorted
  +
First Valid Position
  +
> x
  ↓
Upper Bound
  ↓
Binary Search
```

### Complexity

```text
Time  = O(log N)
Space = O(1)
```
