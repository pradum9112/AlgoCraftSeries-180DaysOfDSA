# Day 64 — Search Insert Position

## Problem Statement

Given a sorted array of distinct integers `nums` and a target value `target`, return the index if the target is found.

If the target is not found, return the index where it would be inserted in order.

The solution must have `O(log N)` time complexity.

---

## Example

```text
Input:
nums = [1, 3, 5, 6]
target = 5

Output:
2
```

Because `5` already exists at index `2`.

---

## Example 2

```text
Input:
nums = [1, 3, 5, 6]
target = 2

Output:
1
```

Because `2` should be inserted between `1` and `3`.

```text
[1, 2, 3, 5, 6]
    ↑
  index 1
```

---

# Important Observation

Search Insert Position is essentially **Lower Bound**.

We need:

> **First index where `nums[i] >= target`**

Therefore:

```text
Search Insert Position
          ↓
      Lower Bound
          ↓
     Binary Search
```

---

# Connection with Previous Days

### Day 62 — Lower Bound

```text
First index where nums[i] >= x
```

### Day 63 — Upper Bound

```text
First index where nums[i] > x
```

### Day 64 — Search Insert Position

```text
First index where nums[i] >= target
```

Therefore:

```text
Day 62 = Day 64 pattern
```

Bas Day 64 mein problem ki language "insert position" hai, while Day 62 mein directly "lower bound" bola gaya tha.

---

# Pattern Recognition

Problem mein agar:

* Array sorted hai
* Target search karna hai
* Agar target nahi mile to insertion position chahiye
* First position where element is `>= target`

to immediately think:

```text
Sorted Array
     ↓
First position >= target
     ↓
Lower Bound
     ↓
Binary Search
```

### Pattern Clue

```text
"Where should target go?"
           ↓
"First element >= target"
           ↓
      Search Insert
```

---

# Approach 1 — Linear Search

## Idea

Array ko left se right traverse karo.

Jahan pehli baar:

```cpp
nums[i] >= target
```

mil jaye, wahi insertion position hai.

Agar koi element `>= target` nahi mila, target array ke end mein insert hoga.

Therefore return:

```cpp
n
```

---

## Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] >= target)
                return i;
        }

        return n;
    }
};
```

---

## Dry Run

```text
nums = [1, 3, 5, 6]
target = 2
```

|  i | nums[i] | nums[i] >= 2? |
| -: | ------: | ------------- |
|  0 |       1 | No            |
|  1 |       3 | Yes           |

Therefore:

```text
Answer = 1
```

Target `2` ko index `1` par insert karna chahiye.

---

# Complexity

```text
Time  = O(N)
Space = O(1)
```

---

# Approach 2 — Binary Search

Array sorted hai, so linear search ko optimize karke Binary Search use kar sakte hain.

We maintain:

```cpp
int ans = n;
```

Initially assume karte hain ki target ko array ke end mein insert karna padega.

---

## Case 1 — `nums[mid] >= target`

Agar current element target se greater/equal hai:

```cpp
nums[mid] >= target
```

to `mid` ek possible answer hai.

```cpp
ans = mid;
```

Lekin hume **first valid position** chahiye.

Isliye left side mein search continue karenge:

```cpp
high = mid - 1;
```

---

## Case 2 — `nums[mid] < target`

Current element target se chhota hai.

Sorted array hone ki wajah se `mid` ke left mein bhi target nahi mil sakta.

Isliye:

```cpp
low = mid + 1;
```

---

# Binary Search Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
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
nums = [1, 3, 5, 6]
target = 2
```

Initial:

```text
low = 0
high = 3
ans = 4
```

### Iteration 1

```text
mid = 1
nums[1] = 3
```

Check:

```text
3 >= 2 → true
```

So:

```text
ans = 1
high = 0
```

Now:

```text
low = 0
high = 0
ans = 1
```

### Iteration 2

```text
mid = 0
nums[0] = 1
```

Check:

```text
1 >= 2 → false
```

Therefore:

```text
low = 1
```

Now:

```text
low = 1
high = 0
```

Loop ends.

Final:

```text
ans = 1
```

Therefore:

```text
Answer = 1
```

---

# Another Dry Run — Target Greater Than All

```text
nums = [1, 3, 5, 6]
target = 7
```

Initially:

```text
ans = 4
```

Binary Search mein har baar:

```text
nums[mid] < 7
```

milega.

So `low` continuously right move karega.

Eventually:

```text
low = 4
high = 3
```

Loop ends.

`ans` kabhi update nahi hua, so:

```text
ans = n = 4
```

Target ko index `4` par insert karna hai.

```text
[1, 3, 5, 6, 7]
             ↑
           index 4
```

---

# Why `ans = n`?

Ye Lower Bound jaisa hi concept hai.

Suppose:

```text
nums = [1, 3, 5, 6]
target = 10
```

Koi element:

```text
>= 10
```

nahi hai.

So insertion position:

```text
n = 4
```

isliye:

```cpp
int ans = n;
```

---

# Why `high = mid - 1`?

Suppose:

```text
nums = [1, 3, 5, 6]
target = 5
```

Suppose:

```text
mid = 2
nums[mid] = 5
```

`mid` valid answer hai.

But hume first valid position chahiye.

Ho sakta hai left mein bhi koi valid position ho.

Therefore:

```cpp
ans = mid;
high = mid - 1;
```

---

# Why `low = mid + 1`?

Suppose:

```text
nums[mid] < target
```

For example:

```text
nums[mid] = 3
target = 5
```

`3` target se chhota hai.

Sorted array mein `mid` ke left ke elements `3` se bhi chhote/equal honge.

Therefore left side mein answer impossible hai.

Move right:

```cpp
low = mid + 1;
```

---

# Commented Code Correction

Tumhara original Linear Search:

```cpp
for(int i=0; i<n-1; i++){
    if(nums[i]>=target) return i;
}
return n;
```

isme:

```cpp
i < n - 1
```

ki wajah se last index skip ho raha hai.

Correct:

```cpp
for(int i=0; i<n; i++){
    if(nums[i]>=target)
        return i;
}

return n;
```

### Example jahan bug dikhega

```text
nums = [1, 3, 5, 6]
target = 6
```

Correct answer:

```text
3
```

Lekin `i < n-1` mein loop:

```text
i = 0
i = 1
i = 2
```

tak jayega.

Index `3` check hi nahi karega.

Then incorrectly:

```text
return n
return 4
```

---

# Approach Comparison

| Feature               | Linear Search | Binary Search    |
| --------------------- | ------------- | ---------------- |
| Sorted array          | Required? No  | **Yes**          |
| Technique             | Sequential    | Divide & Conquer |
| Time                  | O(N)          | **O(log N)**     |
| Space                 | O(1)          | O(1)             |
| Finds insert position | Yes           | Yes              |
| Interview optimal     | No            | **Yes**          |

---

# Search Insert Position = Lower Bound

This is the most important takeaway from Day 64.

```text
Search Insert Position
          ↓
First index where
nums[i] >= target
          ↓
       Lower Bound
          ↓
    Binary Search
```

So if you already know Lower Bound, this problem becomes almost automatic.

---

# Test Cases

### Test Case 1 — Target Exists

```text
Input:
nums = [1, 3, 5, 6]
target = 5

Output:
2
```

### Test Case 2 — Insert in Middle

```text
Input:
nums = [1, 3, 5, 6]
target = 2

Output:
1
```

### Test Case 3 — Insert at Beginning

```text
Input:
nums = [1, 3, 5, 6]
target = 0

Output:
0
```

### Test Case 4 — Insert at End

```text
Input:
nums = [1, 3, 5, 6]
target = 7

Output:
4
```

### Test Case 5 — Single Element

```text
Input:
nums = [5]
target = 5

Output:
0
```

### Test Case 6 — Single Element, Insert After

```text
Input:
nums = [5]
target = 8

Output:
1
```

---

# Common Mistakes

### 1. `i < n - 1`

Linear search mein:

```cpp
i < n - 1
```

last element skip karta hai.

Use:

```cpp
i < n
```

---

### 2. `>` use karna

Search Insert Position ke liye:

```cpp
nums[i] >= target
```

chahiye.

Not:

```cpp
nums[i] > target
```

`>` use karoge to Upper Bound ban jayega.

---

### 3. Exact target milne par hi answer return karna

Problem sirf target search nahi kar raha.

Example:

```text
nums = [1, 3, 5, 6]
target = 2
```

Target array mein nahi hai.

Still answer:

```text
1
```

hai.

Isliye condition:

```cpp
nums[mid] >= target
```

hai.

---

# Three-Day Binary Search Connection

```text
Day 62
Lower Bound
First >= x
```

```text
Day 63
Upper Bound
First > x
```

```text
Day 64
Search Insert Position
First >= target
```

Therefore:

```text
Day 62 ──────────────┐
                     ↓
                Same Pattern
                     ↑
Day 64 ──────────────┘
```

Aur Day 63 mein comparison change:

```text
>=  → Lower Bound
>   → Upper Bound
```

---

# Final Cheat Sheet

```text
LOWER BOUND
First index where nums[i] >= x
```

```text
UPPER BOUND
First index where nums[i] > x
```

```text
SEARCH INSERT POSITION
First index where nums[i] >= target
```

Binary Search pattern for Day 64:

```cpp
int low = 0;
int high = n - 1;
int ans = n;

while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] >= target) {
        ans = mid;
        high = mid - 1;
    }
    else {
        low = mid + 1;
    }
}

return ans;
```

### Complexity

```text
Time  = O(log N)
Space = O(1)
```

### Pattern to remember

```text
Sorted Array
     +
First position >= target
     ↓
Lower Bound
     ↓
Search Insert Position
     ↓
Binary Search
```
