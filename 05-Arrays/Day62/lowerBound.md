# Day 62 — Lower Bound

## Problem Statement

Given a sorted array `nums` and an integer `x`, find the **index of the first element greater than or equal to `x`**.

If no such element exists, return `n`, where `n` is the size of the array.

### Example

```text
Input:
nums = [1, 2, 4, 4, 6, 8]
x = 4

Output:
2
```

Explanation:

```text
Index:  0  1  2  3  4  5
Array: [1, 2, 4, 4, 6, 8]
              ↑
              2
```

Index `2` is the first position where `nums[i] >= 4`.

---

# What is Lower Bound?

Lower Bound means:

> **First index `i` such that `nums[i] >= x`.**

There are three possible situations:

### Case 1 — Exact value exists

```text
nums = [1, 2, 4, 4, 6]
x = 4
```

Answer:

```text
2
```

Because index `2` is the first position satisfying `nums[i] >= 4`.

### Case 2 — `x` does not exist

```text
nums = [1, 2, 5, 7]
x = 4
```

Answer:

```text
2
```

Because:

```text
nums[2] = 5 >= 4
```

### Case 3 — Every element is smaller than `x`

```text
nums = [1, 2, 3, 4]
x = 8
```

No valid index exists.

Therefore:

```text
answer = n = 4
```

---

# Pattern Recognition

Jab problem me ye words dikhein:

* Sorted array
* First element
* Greater than or equal to
* `>= x`
* First valid position

to immediately socho:

> **Binary Search → Lower Bound**

### Pattern Clue

```text
Sorted + First Position + >=
             ↓
        Lower Bound
             ↓
       Binary Search
```

---

# Approach 1 — Linear Search

## Idea

Array ko left se right traverse karo.

Jahan pehli baar:

```cpp
nums[i] >= x
```

mile, wahi answer hai.

Agar pura array traverse ho gaya aur koi valid element nahi mila, return `n`.

## Algorithm

1. Start from index `0`.
2. Check `nums[i] >= x`.
3. Agar true hai, return `i`.
4. Agar koi element satisfy nahi karta, return `n`.

## Code

```cpp
class Solution {
public:
    int lowerBound(vector<int>& nums, int x) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] >= x)
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

|  i | nums[i] | nums[i] >= 4? |
| -: | ------: | ------------- |
|  0 |       1 | No            |
|  1 |       2 | No            |
|  2 |       4 | Yes           |

Return:

```text
2
```

## Complexity

```text
Time  = O(N)
Space = O(1)
```

---

# Approach 2 — Binary Search

Array sorted hai, isliye linear search ko optimize karke Binary Search use kar sakte hain.

Hume first valid index chahiye.

Hum ek variable maintain karenge:

```cpp
int ans = n;
```

Initially maan lete hain ki koi valid index nahi mila.

---

## Binary Search Logic

### Case 1

```cpp
nums[mid] >= x
```

Current `mid` valid answer ho sakta hai.

Isliye:

```cpp
ans = mid;
```

Lekin hume **first** valid index chahiye.

To aur left search karenge:

```cpp
high = mid - 1;
```

---

### Case 2

```cpp
nums[mid] < x
```

Current element chhota hai.

Aur array sorted hai, therefore `mid` ke left ke elements bhi chhote ya equal honge.

Isliye left side me answer nahi ho sakta.

Move right:

```cpp
low = mid + 1;
```

---

# Code

```cpp
class Solution {
public:
    int lowerBound(vector<int>& nums, int x) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= x) {
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
4 >= 4 → true
```

Therefore:

```text
ans = 2
high = 1
```

Now:

```text
low = 0
high = 1
ans = 2
```

### Iteration 2

```text
mid = 0
nums[0] = 1
```

Check:

```text
1 >= 4 → false
```

Therefore:

```text
low = 1
```

Now:

```text
low = 1
high = 1
ans = 2
```

### Iteration 3

```text
mid = 1
nums[1] = 2
```

Check:

```text
2 >= 4 → false
```

Therefore:

```text
low = 2
```

Now:

```text
low = 2
high = 1
```

Loop ends.

Final:

```text
ans = 2
```

Therefore:

```text
Answer = 2
```

---

# Why `ans = n`?

Ye bahut important hai.

Suppose:

```text
nums = [1, 2, 3, 4]
x = 10
```

Koi bhi element:

```text
>= 10
```

nahi hai.

Therefore answer should be:

```text
n = 4
```

Isi liye:

```cpp
int ans = n;
```

rakha hai.

Agar valid element milta hai to `ans` update hota rahega.

Agar nahi milta, `ans` automatically `n` rahega.

---

# Why `high = mid - 1`?

Suppose:

```text
nums = [1, 2, 4, 4, 4, 7]
x = 4
```

Agar:

```text
mid = 3
nums[mid] = 4
```

mil gaya.

Index `3` valid hai, lekin hume **first** valid index chahiye.

Ho sakta hai index `2` bhi valid ho.

Isliye:

```cpp
ans = mid;
high = mid - 1;
```

Hum left side me continue search karte hain.

---

# Lower Bound ka Mental Model

Isko aise imagine karo:

```text
nums = [1, 2, 3, 4, 4, 4, 7, 9]
                  ↑
             Lower Bound
                 x=4
```

Array ko do parts me divide kar sakte hain:

```text
nums < x       nums >= x
[1  2  3] | [4  4  4  7  9]
            ↑
          answer
```

Lower Bound simply **right part ka first index** hai.

---

# Approach Comparison

| Feature                | Linear Search | Binary Search    |
| ---------------------- | ------------- | ---------------- |
| Array sorted required? | No            | Yes              |
| Search technique       | Sequential    | Divide & Conquer |
| Time                   | O(N)          | **O(log N)**     |
| Space                  | O(1)          | O(1)             |
| First `>= x`           | Yes           | Yes              |
| Best for sorted array  | No            | **Yes**          |

---

# Common Mistakes

### 1. `>` aur `>=` confuse karna

Lower Bound:

```cpp
nums[i] >= x
```

Not:

```cpp
nums[i] > x
```

`>` wala concept **Upper Bound** hai.

---

### 2. Valid answer milne ke baad search stop kar dena

Binary Search me:

```cpp
if (nums[mid] >= x)
    return mid;
```

galat ho sakta hai.

Kyunki `mid` valid hai, but usse pehle bhi valid index ho sakta hai.

Correct:

```cpp
ans = mid;
high = mid - 1;
```

---

### 3. `ans = 0` initialize karna

Wrong:

```cpp
int ans = 0;
```

Correct:

```cpp
int ans = n;
```

Kyuki initially maan rahe hain ki koi valid position nahi mili.

---

### 4. No valid element case bhool jana

```text
nums = [1, 2, 3]
x = 10
```

Answer:

```text
3
```

not `-1`.

Lower Bound convention me answer `n` hota hai.

---

# Test Cases

### Test Case 1

```text
Input:
nums = [1, 2, 4, 4, 6, 8]
x = 4

Output:
2
```

### Test Case 2

```text
Input:
nums = [1, 2, 5, 7]
x = 4

Output:
2
```

### Test Case 3

```text
Input:
nums = [1, 2, 3, 4]
x = 10

Output:
4
```

### Test Case 4

```text
Input:
nums = [1, 2, 3, 4]
x = 1

Output:
0
```

### Test Case 5

```text
Input:
nums = [4, 4, 4, 4]
x = 4

Output:
0
```

---

# Interview Thinking

Question:

> "Find first element greater than or equal to X in sorted array."

Think:

```text
Sorted Array
     ↓
Need first valid position
     ↓
Condition = nums[i] >= x
     ↓
Lower Bound
     ↓
Binary Search
```

Core template:

```cpp
int low = 0;
int high = n - 1;
int ans = n;

while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] >= x) {
        ans = mid;
        high = mid - 1;
    }
    else {
        low = mid + 1;
    }
}

return ans;
```

---

# Final Cheat Sheet

```text
Lower Bound
= First index where nums[i] >= x
```

```text
Condition true
    ↓
Store answer
    ↓
Go LEFT
```

```text
Condition false
    ↓
Go RIGHT
```

### Pattern

```text
Sorted + First + >=
        ↓
   Lower Bound
        ↓
 Binary Search
```

### Complexity

```text
Time  = O(log N)
Space = O(1)
```
