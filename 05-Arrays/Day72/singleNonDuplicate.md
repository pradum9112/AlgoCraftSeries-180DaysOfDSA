# Day72 - Single Non-Duplicate Element

## Problem Statement

Given a sorted array where every element appears exactly twice except one element that appears only once, find the single element.

### Example

**Input**

```text
9
1 1 2 3 3 4 4 8 8
```

**Your Output**

```text
2
```

---

# Approaches

## Approach 1 - Brute Force / HashMap

Har element ki frequency count karo.

```cpp
unordered_map<int, int> mpp;
```

Then jis element ki frequency `1` hai, wahi answer hai.

### Complexity

```text
Time:  O(N)
Space: O(N)
```

---

# Approach 2 - XOR

Is problem mein har element exactly 2 baar hai except one.

XOR ki important properties:

```text
x ^ x = 0
x ^ 0 = x
```

Therefore pairs automatically cancel ho jaate hain.

Example:

```text
1 ^ 1 ^ 2 ^ 3 ^ 3
```

Pairs cancel:

```text
(1 ^ 1) ^ 2 ^ (3 ^ 3)
```

```text
0 ^ 2 ^ 0
```

```text
2
```

Therefore answer `2`.

### Complexity

```text
Time:  O(N)
Space: O(1)
```

---

# Approach 3 - Binary Search

Because the array is **sorted**, we can do better than `O(N)`.

Normal situation:

```text
index:  0 1  2 3  4 5
value:  1 1  3 3  5 5
```

Pairs follow:

```text
even index → odd index
```

For example:

```text
(0,1)
(2,3)
(4,5)
```

But when the single element appears, this pattern breaks.

Example:

```text
index:  0 1  2  3 4  5 6
value:  1 1  2  3 3  4 4
```

Before the single element:

```text
0-1
```

After the single element, pairing shifts:

```text
3-4
5-6
```

So we can use this pairing pattern to decide which half contains the answer.

---

# Binary Search Logic

For `mid`:

### Case 1 - `mid` itself is single

```cpp
nums[mid] != nums[mid - 1]
&&
nums[mid] != nums[mid + 1]
```

Then:

```text
answer = nums[mid]
```

---

### Case 2 - Correct pairing exists

If:

```text
mid is odd
AND
nums[mid] == nums[mid-1]
```

then the pair is correctly aligned.

Or:

```text
mid is even
AND
nums[mid] == nums[mid+1]
```

then the pair is correctly aligned.

This means the single element is **after mid**.

```cpp
low = mid + 1;
```

---

### Case 3 - Pairing is broken

Otherwise, the single element is **before mid**.

```cpp
high = mid - 1;
```

---

# Pattern Recognition Clue

When you see:

```text
Sorted Array
+
Pairs
+
One Single Element
+
O(log N)
```

Think:

```text
Binary Search
     ↓
Check pair alignment
     ↓
Before single → even-odd
After single  → odd-even
     ↓
Find broken pair
```

The most important question is:

> **"Kya pair apne expected even-odd positions par hai?"**

If yes:

```text
single element → right
```

If no:

```text
single element → left
```

---

# Dry Run

Array:

```text
[1, 1, 2, 3, 3, 4, 4, 8, 8]
```

### Initial

```text
low = 1
high = 7
```

### Iteration 1

```text
mid = 4
nums[mid] = 3
```

Pair:

```text
nums[3] = 3
nums[4] = 3
```

`mid` is even and pair is on the left.

Expected for an even index is:

```text
mid → mid + 1
```

but actual pair is:

```text
mid - 1 → mid
```

So pairing is broken.

Therefore:

```text
single element → left
```

```cpp
high = mid - 1;
```

Now:

```text
low = 1
high = 3
```

---

### Iteration 2

```text
mid = 2
nums[mid] = 2
```

Neighbors:

```text
nums[1] = 1
nums[3] = 3
```

Both are different from `2`.

Therefore:

```text
2 is the single element.
```

### Final Answer

```text
2
```

---

# Code - Optimal

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];

        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {

                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
```

---

# Complexity Comparison

| Approach              | Idea                   |         Time |    Space |
| --------------------- | ---------------------- | -----------: | -------: |
| Brute Force / HashMap | Frequency count        |         O(N) |     O(N) |
| XOR                   | Duplicate pairs cancel |         O(N) | **O(1)** |
| Binary Search         | Pair-position pattern  | **O(log N)** | **O(1)** |

---

# Important Observation

XOR approach has:

```text
O(N) time
O(1) space
```

Binary Search has:

```text
O(log N) time
O(1) space
```

So for this problem, **Binary Search is the optimal approach when the sorted-array property is available and we are targeting the best time complexity.**

---

# What I Learned

* Sorted arrays can provide extra structure for Binary Search.
* Paired elements normally follow an `even → odd` index pattern.
* The single element breaks this pattern.
* After the single element, the pairing pattern shifts.
* Pair alignment can tell us which half contains the answer.
* `mid` itself can be checked by comparing its neighbors.
* Binary Search reduces the search space from `N` to approximately `N/2` at every step.

## Key Takeaway

```text
Sorted + Pairs + One Single
            ↓
      Check pair pattern
            ↓
   Is pairing correctly aligned?
       ↙             ↘
     YES              NO
      ↓                ↓
   Go Right          Go Left
            ↓
       O(log N)
```
