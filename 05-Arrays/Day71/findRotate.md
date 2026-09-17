# Day71 - Find K Rotation

## Problem Statement

Given a rotated sorted array, find the number of times the array has been rotated.

The rotation count is equal to the **index of the minimum element**.

### Example

**Input**

```text
6
15 18 2 3 6 12
```

**Your Output**

```text
2
```

The minimum element is `2`, and its index is `2`.

Therefore, the array was rotated **2 times**.

---

# Understanding Rotation

Original sorted array:

```text
2 3 6 12 15 18
```

After rotation:

```text
15 18 2 3 6 12
```

The point where the array becomes sorted again tells us the rotation point:

```text
15 18 | 2 3 6 12
       ↑
    minimum
```

Therefore:

```text
Rotation Count = Index of Minimum Element
```

---

# Approach 1 - Linear Search for Minimum

The simplest approach is to traverse the complete array.

We maintain:

```cpp
minValue
minIndex
```

Whenever we find a smaller element, update both.

### Example

```text
15 18 2 3 6 12
```

Initially:

```text
minValue = 15
minIndex = 0
```

Then:

```text
18 → ignore
2  → new minimum
3  → ignore
6  → ignore
12 → ignore
```

Finally:

```text
minValue = 2
minIndex = 2
```

So answer = `2`.

### Complexity

```text
Time:  O(N)
Space: O(1)
```

---

# Approach 2 - Find the Breakpoint

A rotated sorted array has one point where:

```text
nums[i] > nums[i + 1]
```

For:

```text
15 18 2 3 6 12
```

we find:

```text
18 > 2
```

Therefore:

```text
i + 1 = 2
```

is the rotation point.

### Pattern

```text
15 18 | 2 3 6 12
     ↑
breakpoint
       ↑
rotation index
```

### Complexity

```text
Time:  O(N)
Space: O(1)
```

This is slightly more direct than finding the minimum because we are specifically looking for the rotation point.

---

# Approach 3 - Optimal Binary Search

Because the array is originally sorted and only rotated, we can use Binary Search.

Our goal is:

> Find the index where the minimum element exists.

Maintain:

```text
low
high
```

Then:

```cpp
mid = low + (high - low) / 2;
```

Now compare:

```cpp
nums[mid]
```

with:

```cpp
nums[high]
```

---

## Case 1: `nums[mid] > nums[high]`

Example:

```text
15 18 2 3 6 12
      ↑       ↑
     mid     high
```

Here:

```text
18 > 12
```

This means the rotation point/minimum must be **to the right of mid**.

Therefore:

```cpp
low = mid + 1;
```

---

## Case 2: `nums[mid] <= nums[high]`

Example:

```text
15 18 2 3 6 12
      ↑       ↑
     mid     high
```

If:

```text
2 <= 12
```

then the right side is sorted.

The minimum can be:

* `mid`
* or somewhere to the left

So we keep `mid`:

```cpp
high = mid;
```

Notice:

```cpp
high = mid;
```

not:

```cpp
high = mid - 1;
```

because `mid` itself could be the minimum.

---

# Pattern Recognition Clue

When you see:

* sorted array
* rotated sorted array
* minimum element
* rotation count
* expected `O(log N)`

Think:

```text
ROTATED SORTED ARRAY
        ↓
Find which side contains the minimum
        ↓
Binary Search
```

The important question is **not**:

> "How many times was it rotated?"

Instead think:

> **"Where is the minimum element?"**

Because:

```text
rotation count = index of minimum
```

This is the key pattern.

---

# Dry Run - Optimal Binary Search

Input:

```text
[15, 18, 2, 3, 6, 12]
```

### Iteration 1

```text
low = 0
high = 5

mid = 2

nums[mid]  = 2
nums[high] = 12
```

Check:

```text
2 > 12 ❌
```

Therefore minimum is at `mid` or left side.

```text
high = mid
high = 2
```

Search space:

```text
15 18 2
↑     ↑
low  high
```

---

### Iteration 2

```text
low = 0
high = 2

mid = 1

nums[mid]  = 18
nums[high] = 2
```

Check:

```text
18 > 2 ✅
```

Therefore minimum is definitely on the right.

```text
low = mid + 1
low = 2
```

Now:

```text
low = 2
high = 2
```

Loop stops.

Therefore:

```text
answer = low = 2
```

---

# Code

```cpp
class Solution {
public:
    int findKRotation(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }
};
```

---

# Approach Comparison

| Approach      | Main Idea                                   |         Time |    Space |
| ------------- | ------------------------------------------- | -----------: | -------: |
| Linear Search | Minimum element ka index find karo          |         O(N) |     O(1) |
| Breakpoint    | `nums[i] > nums[i+1]` find karo             |         O(N) |     O(1) |
| Binary Search | Minimum wali half ko repeatedly choose karo | **O(log N)** | **O(1)** |

---

# Important Difference: Day70 vs Day71

### Day70

Question tha:

> Minimum element kya hai?

Example:

```text
[15 18 2 3 6 12]
```

Answer:

```text
2
```

### Day71

Question hai:

> Minimum element **kis index par hai?**

Same array:

```text
[15 18 2 3 6 12]
       ↑
      index 2
```

Answer:

```text
2
```

Therefore:

```text
Day70 → Minimum VALUE
Day71 → Minimum INDEX
```

---

# What I Learned

* Rotated sorted array mein minimum element rotation point hota hai.
* Rotation count = minimum element ka index.
* Breakpoint `nums[i] > nums[i+1]` rotation point identify karta hai.
* Binary Search mein `nums[mid]` aur `nums[high]` compare karke decide kar sakte hain ki minimum kis side hai.
* `high = mid` important hai because `mid` itself minimum ho sakta hai.
* Rotated sorted array problems mein **"which half contains the minimum?"** ek important Binary Search pattern hai.

## Key Takeaway

```text
Rotated Sorted Array
        ↓
Find Minimum
        ↓
Minimum ka Index
        ↓
Rotation Count
        ↓
Binary Search
        ↓
O(log N)
```
